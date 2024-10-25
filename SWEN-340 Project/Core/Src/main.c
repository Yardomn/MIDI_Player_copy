// main.c with demo
// Updated and refactored Larry Kiser copyright 2021


// include project specific header files
#include <local_button_handler.h>
#include "error_handler.h"
#include "SysClock.h"
#include "LED.h"
#include "UART.h"
#include "demo.h"
#include "project.h"
#include "systick.h"
#include "midi_header.h"
#include "GPIO.h"
#include "USARTinterrupt.h"
#include "play_song.h"
#include "song.h"
#include <stdio.h>
#include <USARTinterrupt.h>

	
int main(void){

//	// initialization code
	System_Clock_Init(); // set System Clock = 80 MHz
	LED_Init(LED_PIN); //Initializes LED
	UART2_Init(); //Initializes USART2
	print_help(); //prints help message
	init_systick(); //Sets up systick interrupts
	setup(); //Sets up Blue button interrupts
	setup_USART(); //Sets up USART interrupts
	read_input();
}

