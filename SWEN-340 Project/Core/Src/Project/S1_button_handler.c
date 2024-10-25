/*
 * S1_button_handler.c
 *
 *  Created on: Mar 19, 2024
 *      Author: raymo
 */

#include "printf.h"
#include "GPIO.h"
#include "main.h"
#include "project.h"
#include "stm32l4xx.h"
#include "systick_handler.h"


static int button_pressed = 0;
static int manual_active = 0;
static int count_start = 0;

void S1_button_enable(){
	//enables interrupts for the S1 switch
	NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void S1_button_disable(){
	//disables interrupts for the S1 switch
	NVIC_DisableIRQ(EXTI9_5_IRQn);
}

void EXTI9_5_IRQHandler(){
	//Interrupt handler for S1 switch
	button_pressed ++;

	if(button_pressed == 1){
		count_start = get_count();
	}
	HAL_GPIO_EXTI_IRQHandler(S1_Pin);
}

int Get_button_pressed(){
	//getter for button_pressed
	//output - int of whether the button was pressed in the last second
	return button_pressed;
}

void set_manual_active(){
	manual_active = 1;
}

void set_manual_unactive(){
	manual_active = 0;
}

void manual_mode_loop(){
	//method to allow systick to increment count for the button timer
	while(manual_active == 1){
		if(count_start != 0){
			if((get_count()-count_start) >= 1000000){
				if(button_pressed > 2){
					next_song();
					button_pressed = 0;
					count_start = 0;
				}else if(button_pressed == 1){
					//If button is pressed once it has not been let go, so it is held
					Set_LED_status(0);
					button_pressed = 0;
					count_start = 0;
				}else{
					//handler for one button press
					count_start = 0;
					button_pressed = 0;
					Toggle_LED_status();
				}
			}
		}
	}
	read_input();
}

