/*
 * hw4.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Raymond Babich
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "LED.h"
#include "UART.h"
#include "systick.h"

static int count = 0;
static char buffer[80];

int read_and_print_byte_Nonblocking (){

	uint8_t byte = USART_Read_Nonblocking(USART2);
	putchar(byte);
	if(byte == '\r'){
		putchar('\n');
	}
	return byte;
}

char* readline_Nonblocking(){
	char byte = 0;
	int i;
	for (i = 0; (byte!= '\r') && (i< sizeof(buffer)); i++){
		byte = read_and_print_byte_Nonblocking();
		buffer[i] = byte;
	}
	buffer[i-1] = 0;
	return buffer;
}

// This function is to read from the UART port and toggle LED
void demo_of_UART_Read_Nonblocking(){

	read_and_print_byte_Nonblocking();
	delay_systick() ;
	count+=1;
	if(count == 1000){
		// Toggle LED
		LED_Toggle(LED_PIN);
		count = 0;
	}
}

void run_demo_Nonblocking(){

	// Run a loop to read, echo and toggle LED
	while (1)
	{
		//demo_of_UART_Read_Nonblocking();
		demo_of_UART_Read_Nonblocking();
	}
}
