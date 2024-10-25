/*
 * systick_handler.c
 *
 *  Created on: Mar 21, 2024
 *      Author: raymo
 */

#include "systick.h"
#include "S1_button_handler.h"
#include "project.h"
#include "printf.h"
#include "stm32l4xx.h"
#include "main.h"
#include "tone.h"


static int count = 0;

void SysTick_Handler(){
	//Handler for systick interrupts. Is essentially the main loop of the project
	//add_song_counter();
	count++;
	if(count%1000000 == 0){
		//Controls LED
		LED_Controller();
	}
//	if(Get_button_pressed()>0){
//		//If S1 switch has been pressed it will increment a counter for a second
//		increment_count();
//	}
	//printf("interrupted");
}

int get_count(){
	return count;
}

