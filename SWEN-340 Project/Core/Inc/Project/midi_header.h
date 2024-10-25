/*
 * midi_header.h
 *
 *  Created on: Mar 3, 2024
 *      Author: raymo
 */

#ifndef INC_PROJECT_MIDI_HEADER_H_
#define INC_PROJECT_MIDI_HEADER_H_

#include <stdint.h>

struct header{
	char chunk_type[4];
	uint32_t length;
	uint16_t format;
	uint16_t ntrks;
	uint16_t division;
};

struct header* get_header();
int get_tempo(unsigned char* song, int size);
void use_header();
void print_copyright(unsigned char* song, int size);
void print_title(unsigned char* song, int size);
void print_tempo(unsigned char* song, int size);
void print_song_info(int song_num);

#endif /* INC_PROJECT_MIDI_HEADER_H_ */
