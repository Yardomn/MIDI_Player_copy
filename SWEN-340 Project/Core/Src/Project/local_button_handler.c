/*
 * local_button_handler.c
 *
 *  Created on: Mar 26, 2024
 *      Author: raymo
 */


#include "printf.h"
#include "GPIO.h"
#include "main.h"
#include "project.h"
#include "USARTinterrupt.h"
#include <stm32l4xx.h>

void setup(){
	//Sets up interrupts for blue button on board
	GPIO_Init();
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(){
	//Handler for when the button gets pressed
	Set_LED_status(0);
	toggle_mode();
	HAL_GPIO_EXTI_IRQHandler(B1_Pin);
}
