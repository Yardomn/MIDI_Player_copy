/*
 * activity13.c
 *
 *  Created on: Apr 16, 2024
 *      Author: raymo
 */


#include "printf.h"
#include "systick.h"
#include "tone.h"
#include "stdint.h"

void wave(uint32_t duration){
    //float count= 0;
    //uint32_t duration = hertz_to_midi_ticks(frequency);
    int count = 0;
    //printf("%d\n");
    if(count < (duration >> 1)){
        printf("1");
    }
    else{
        printf("0");
    }
}

void run_wave(){
    init_systick();
    float frequency = 2;//0.5; //2
    uint32_t duration = hertz_to_midi_ticks(frequency);
    while(1){
        wave(duration);
    }
}
