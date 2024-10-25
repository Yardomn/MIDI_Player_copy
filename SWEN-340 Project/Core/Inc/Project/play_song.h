/*
 * play_song.h
 *
 *  Created on: Apr 22, 2024
 *      Author: raymo
 */

#ifndef INC_PROJECT_PLAY_SONG_H_
#define INC_PROJECT_PLAY_SONG_H_

int get_count_start();
uint32_t parseDelay(uint8_t* delay);
int get_track_start(unsigned char* p_song, int size);
void parse_song(unsigned char* p_song, int track_start, int size);
void play_song();


#endif /* INC_PROJECT_PLAY_SONG_H_ */
