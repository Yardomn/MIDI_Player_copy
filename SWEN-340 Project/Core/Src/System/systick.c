#include "systick.h"
#include <stdint.h>


struct sys_tick{
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
};

static struct sys_tick* SysTick = (struct sys_tick*) 0xE000E010;
// This function is to Initialize SysTick registers
void init_systick()
{
	// Use the SysTick global structure pointer to do the following in this
	// exact order with separate lines for each step:
	//
	// Disable SysTick by clearing the CTRL (CSR) register.
	// Set the LOAD (RVR) to 8 million to give us a 100 milliseconds timer.
	// Set the clock source bit in the CTRL (CSR) to the internal clock.
	// Set the enable bit in the CTRL (CSR) to start the timer.
	SysTick->CSR = 0;
	SysTick->RVR = 79;
	SysTick->CSR |= 1 << 2;
	SysTick->CSR |= 1 << 1;
	SysTick->CSR |= 1;
}

// This fuction is to create delay using SysTick timer counter
void delay_systick()
{
	// Using the SysTick global structure pointer do the following:
	// Create a for loop that loops 10 times
	// Inside that for loop check the COUNTFLAG bit in the CTRL (CSR)
	// register in a loop. When that bit is set exit this inner loop
	// to do another pass in the outer loop of 10.
	init_systick();
	for(int i = 0; i<=1; i++){
		int exit = 0;
		while(exit<10){
			if((SysTick->CSR & (1 << 16)) != 0){
				exit++;
			}
		}
	}
}
