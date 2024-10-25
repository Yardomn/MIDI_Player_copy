/*
 * hw6.c
 *
 *  Created on: Mar 25, 2024
 *      Author: raymo
 */

#include "UART.h"
#include "main.h"
#include "printf.h"
#include "project.h"
#include <stdint.h>
#include <string.h>
#include <stm32l4xx.h>


static uint8_t byte;

void setup_USART(){
	//enables interrupts for USART2 using NVIC, then then enables interrupts for the RXNIE bit
	NVIC_EnableIRQ(USART2_IRQn);
	USART2->CR1 |= USART_CR1_RXNEIE_Msk;
}

void disable_USART(){
	//disables USART interrupts
	NVIC_DisableIRQ(USART2_IRQn);
}

void enable_USART(){
	//enables USART interrupts
	NVIC_EnableIRQ(USART2_IRQn);
}



void USART2_IRQHandler(){
	//USART2 interrupt handler
	//reads a byte then prints it
	byte = USART_Read(USART2);
	USART_Write(USART2, &byte, 1);
	fill_buffer(byte);
}

