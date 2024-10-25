/*
 * timer.c
 *
 *  Created on: Feb 13, 2024
 *      Author: raymo
 */
#include <stdio.h>
#include <stdint.h>
#include "printf.h"

struct systick{
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
};

void print_systick(){
	struct systick* stick = (struct systick*) 0xE000E010;

	stick->CSR |= 1 << 2;
	stick->CSR |= 1;
	stick->RVR = 7999999;

	printf("CSR: %ld\n", stick->CSR);
	printf("RVR: %ld\n", stick->RVR);
	printf("CVR: %ld\n", stick->CVR);
	printf("CALIB: %ld\n", stick->CALIB);

	int count = 0;

	while(1){
		if(stick->CVR == 0){
			printf("Current: %3d\r", count/10);
			count++;
		}
	}
}
