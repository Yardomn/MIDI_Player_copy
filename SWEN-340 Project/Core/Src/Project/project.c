/*
 * project.c
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

//project includes
#include "project.h"
#include "printf.h"
#include "systick.h"
#include "midi_header.h"
#include "USARTinterrupt.h"
#include "LED.h"
#include "S1_button_handler.h"
#include "play_song.h"
#include "song.h"
//standard includes
#include <string.h>
#include <stdint.h>
#include <stdio.h>

//project state variables
static int LED_status = 1;
static int song_num = 5;
static char input_buffer[80];
static int buffer_ind = 0;
static int remote_state = 1;

//Prints message to tell users which mode they are in
void print_help(){
	if(remote_state==1){
		//Prints help message for Remote mode
		printf("\n***REMOTE LED CONTROL MENU***\n");
		printf("Available User Commands\n");
		printf("NEXT - Show next song info\n");
		printf("PLAY - Play the song (LED on)\n");
		printf("PAUSE - Pause the song (LED flash)\n");
		printf("STOP - Stop the song (LED off)\n");
	} else{
		//Prints message for Local mode
		printf("***MANUAL OVERRIDE MODE ACTIVE***\n");
	}
}

//Method to call when blue button is pressed to toggle between modes
void toggle_mode(){
	if(remote_state==1){
		//disables USART and enables S1 switch interrupts for Local mode
		remote_state--;
		print_help();
		S1_button_enable();
		set_manual_active();
		disable_USART();
	} else{
		//enables USART and disables S1 switch interrupts for Remote mode
		remote_state++;
		enable_USART();
		S1_button_disable();
		set_manual_unactive();
		print_help();
	}
}

//remote_state getter
//output - remote state boolean
int get_remote_state(){
	return remote_state;
}

//getter for song number
//output - song_num
int get_song_num(){
	return song_num;
}

//increments the song number correctly then prints the info for the next song
void next_song(){
	if(song_num >= 4){
		song_num = 0;
	} else{
		song_num++;
	}
	print_song_info(song_num);
}

//Calls the correct LED function
void LED_Controller(){
	if(LED_status == 0){
		LED_Off(LED_PIN);
	} else if(LED_status == 1){
		LED_Toggle(LED_PIN);
	} else if(LED_status == 2){
		LED_On(LED_PIN);
	}
}

//method to toggle between play and pause for S1 switch
void Toggle_LED_status(){
	if(LED_status == 2){
		LED_status = 1;
	} else{
		LED_status = 2;
		int track_start = get_track_start(get_song(song_num).p_song, get_song(song_num).size);
		parse_song(get_song(song_num).p_song, track_start, get_song(song_num).size);
		play_song();
	}
}

//setter method for LED_status
//status: new status for LED, can only be 0, 1, or 2
void Set_LED_status(int status){
	LED_status = status;
}

//gets called every time USART interrupts
//input - the byte USART reads
void fill_buffer(char input){
	input_buffer[buffer_ind] = input;
	buffer_ind += 1;
}
//polls until new line is pressed then reads the buffer. Recursively calls itself to keep polling
void read_input(){
	while(input_buffer[buffer_ind-1] != '\r'){
		if(remote_state == 0){
			manual_mode_loop();
			return;
		}
	}
	//printf("\nread new line");
	if (strcmp("NEXT\r", input_buffer) == 0){
		next_song();
	} else if (strcmp("PLAY\r", input_buffer) == 0){
		if(song_num>4){
			printf("Use NEXT command to get to first song.");
		}else{
			LED_status = 2;
			int track_start = get_track_start(get_song(song_num).p_song, get_song(song_num).size);
			parse_song(get_song(song_num).p_song, track_start, get_song(song_num).size);
			play_song();
		}
	} else if (strcmp("PAUSE\r", input_buffer) == 0){
		Set_LED_status(1);
	} else if (strcmp("STOP\r", input_buffer) == 0){
		Set_LED_status(0);
	} else if (strcmp("HELP\r", input_buffer) == 0){
		print_help();
	} else{
		printf("Invalid Command");
	}
	printf("\n");
	memset(input_buffer, 0, strlen(input_buffer));
	buffer_ind = 0;
	read_input();
}


