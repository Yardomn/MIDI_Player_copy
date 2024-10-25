/*
 * activity8.c
 *
 *  Created on: Feb 20, 2024
 *      Author: raymo
 */

#include <stdint.h>
#include "printf.h"
#include "UART.h"

static char buffer[80];
/**
 * Read on e byte from the virtual terminal and print it.
 */
char read_and_print_byte (){

	uint8_t byte = USART_Read(USART2);
	putchar(byte);
	if(byte == '\r'){
		putchar('\n');
	}
	return byte;
}

void read_bytes(){
	while(1){
		read_and_print_byte();
	}
}

char* readline(){
	char byte = 0;
	int i;
	for (i = 0; (byte!= '\r') && (i< sizeof(buffer)); i++){
		byte = read_and_print_byte();
		buffer[i] = byte;
	}
	buffer[i-1] = 0;
	return buffer;
}

void readlines(){
	while(1){
		printf("%s\n", readline());
	}
}
