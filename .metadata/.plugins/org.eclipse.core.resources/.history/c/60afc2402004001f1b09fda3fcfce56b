/*
 * play_song.c
 *
 *  Created on: Apr 21, 2024
 *      Author: raymo
 */


#include "printf.h"
#include "tone.h"
#include "song.h"
#include "midi_header.h"
#include "project.h"
#include "endian_converter.h"
#include "systick_handler.h"
#include <stdint.h>
#include <stdlib.h>


struct midiEvent{
	uint32_t delay;
	uint8_t type;
	uint8_t key;
	uint8_t velocity;
};

struct midiEvent* notes[450];
static int num_events = 0;
static int count_start = 0;

int get_count_start(){
	return count_start;
}

uint32_t parseDelay(uint8_t* delay) {
    uint32_t value = 0;
    uint8_t byte;

    do {
        byte = *(delay++);
        value = (value << 7) | (byte & 0x7F);
    } while (byte & 0x80);

    return value;
}

int get_track_start(unsigned char* p_song, int size){
	int track_index = 0;
	for(int i = 0; i<size;i++){
		//printf("%ld\n", get_counter());
		if (p_song[i] == 0x4d && p_song[i+1] == 0x54 && p_song[i+2] == 0x72 && p_song[i+3] == 0x6b){
			track_index = i+8;
		}
	}
	//printf("%ld\n", track_index);
	//printf("track index found\n");
	return track_index;
}

void parse_song(unsigned char* p_song, int track_start, int size){
	int i = track_start;
	uint8_t delay_buffer[10];
	while(i<size){
		int delay_index = 0;
		struct midiEvent* curr = malloc(sizeof(struct midiEvent));
		while(p_song[i] & 0x80){
			delay_buffer[delay_index] = p_song[i];
			delay_index++;
			i++;
		}
		delay_buffer[delay_index] = p_song[i];
		i++;
		if((p_song[i] & 0xF0) == 0x90){
			curr->delay = parseDelay(delay_buffer);
			curr->type = p_song[i];
			curr->key = p_song[i+1];
			curr->velocity = p_song[i+2];
			i+=3;
			notes[num_events] = curr;
			num_events++;
		} else if((p_song[i] & 0xF0) == 0x80){
			curr->delay = parseDelay(delay_buffer);
			curr->type = p_song[i];
			curr->key = 0;
			curr->velocity = 0;
			i+=2;
			notes[num_events] = curr;
			num_events++;
		}
	}
	for(int j = 0; j<num_events; j++){
		free(notes[j]);
	}
}

void play_song(){
	struct header* song_header = get_header();
	int miditicks = get_tempo(get_song(get_song_num()).p_song, get_song(get_song_num()).size) / (convert_to_uint16((uint8_t *)&song_header->division));
	int song_delay = 0;
	count_start = get_count();
	for(int i = 0; i < num_events; i++){
		if((notes[i]->type & 0xF0) == 0x90){
			int delay = (notes[i+1]->delay)*miditicks;
			song_delay += delay;
			add_tone(notes[i]->key, notes[i]->velocity);
			//printf("tone added");
			play_tones(song_delay);
		} else{
			int delay = (notes[i+1]->delay)*miditicks;
			song_delay += delay;
			remove_tone(notes[i]->key);
			//printf("tone removed");
			play_tones(song_delay);
		}
		printf("played tone");
	}
	num_events = 0;
}
