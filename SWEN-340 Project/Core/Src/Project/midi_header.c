/*
 * midi_header.c
 *
 *  Created on: Feb 1, 2024
 *      Author: raymo
 */
#include "endian_converter.h"
#include "midi_header.h"
#include "song.h"
#include "printf.h"
#include "project.h"
#include <stdint.h>



struct song_info{
	char song_name[80];
	char copyright[80];
	uint32_t tempo;
};

struct header* get_header(){
	unsigned char* song = get_song(get_song_num()).p_song;
	struct header* curr_header = (struct header*) song;
	return curr_header;
}

//getter for tempo of a song
//output int tempo - tempo found in midi file
int get_tempo(unsigned char* song, int size){
	for(int i = 0; i<=size; i++){
		if(song[i] == (char)0xFF){
			i++;
			if(song[i] == (char)0x51){
				i+=2;
				int tempo = ((int)(song[i])*65536)+((int)(song[i+1])*256)+((int)(song[i+2]));
				i+=3;
				return tempo;
			}
		}
	}
	return 0;
}

void use_header(){
	//prints the songs header
	unsigned char* song = get_song(0).p_song;
	struct header* song_header = (struct header*) song;
	putns(song_header->chunk_type, 4);
	printf("Length: %lu\n", convert_to_uint32((uint8_t*)&song_header->length));
	printf("Format: %u\n", convert_to_uint16((uint8_t*)&song_header->format));
	printf("Num Tracks: %u\n", convert_to_uint16((uint8_t*)&song_header->ntrks));
	printf("Divisions: %u\n", convert_to_uint16((uint8_t*)&song_header->division));
}

void print_copyright(unsigned char* song, int size){
	//finds the copyright info in the song file and prints it
	for(int i = 0; i<=size; i++){
		if(song[i] == (char)0xFF){
			i++;
			if(song[i] == (char)0x02){
				i++;
				int len = (int)song[i];
				char copyright [len+1];
				for(int j = 0; j<=len; j++){
					copyright[j] = song[i];
					i++;
				}
				copyright[len+1]=0;
				printf("%s\n", copyright);
				return;
			}
		}
	}
}

void print_title(unsigned char* song, int size){
	//finds the title info in the song file and prints it
	for(int i = 0; i<=size; i++){
		if(song[i] == (char)0xFF){
			i++;
			if(song[i] == (char)0x03){
				i++;
				int len = (int)song[i];
				char title [len+1];
				i++;
				for(int j = 0; j<=len; j++){
					title[j] = song[i];
					i++;
				}
				title[len+1]=0;
				printf("%s\n", title);
				return;
			}
		}
	}
}
void print_tempo(unsigned char* song, int size){
	//finds the tempo info in the song file and prints it
	for(int i = 0; i<=size; i++){
		if(song[i] == (char)0xFF){
			i++;
			if(song[i] == (char)0x51){
				i+=2;
				int tempo = ((int)(song[i])*65536)+((int)(song[i+1])*256)+((int)(song[i+2]));
				i+=3;
				printf("%6d\n", tempo);
				return;
			}
		}
	}
}


void print_song_info(int song_num){
	//prints the info for the next song
	song next_song = get_song(song_num);
	print_copyright(next_song.p_song, next_song.size);
	print_title(next_song.p_song, next_song.size);
	print_tempo(next_song.p_song, next_song.size);
}
