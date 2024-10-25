/*
 * printer.c
 *
 * Created on: Jan 25, 2024
 * Author: Raymond Babich
 */
#include <stdio.h>
#include <stdarg.h>
#include "printf.h"
#include "UART.h"

char buffer[80];

int printf(const char *format, ...) {
	//formatted printer
	va_list aptr;
	int ret;
	va_start(aptr, format);
	ret = vsprintf(buffer, format, aptr);
	va_end(aptr);
	if (buffer[ret-1] == '\n'){
		buffer[ret-1] = '\r';
		buffer[ret] = '\n';
		buffer[ret+1] = 0;
		ret++;
	}
	USART_Write(USART2, (uint8_t*)buffer, ret);
	return ret;
}

int putns(const char *str, int size){
	//Prints a certain size of string
	int ret = snprintf(buffer, size+1, "%s", str);
	USART_Write(USART2, (unsigned char*)buffer, ret);
	USART_Write(USART2, (unsigned char*)"\r\n", 2);
	return ret;
}

int puts(const char *str){
	//Prints a string with a new line after
	int ret = sprintf(buffer, "%s\r\n", str);
	USART_Write(USART2, (uint8_t*) buffer, ret);
	return ret;
}

int putchar(int c){
	//prints a char
	USART_Write(USART2, (uint8_t*) &c, 1);
	return c;
}
