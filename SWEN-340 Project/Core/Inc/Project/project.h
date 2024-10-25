/*
 * project.h
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#ifndef INC_PROJECT_H_
#define INC_PROJECT_H_

void print_help();
void toggle_mode();
int get_remote_state();
int get_song_num();
void next_song();
void LED_Controller();
void Toggle_LED_status();
void Set_LED_status(int status);
void fill_buffer(char input);
void read_input();

#endif /* INC_PROJECT_H_ */
