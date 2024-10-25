/*
 * endian_converter.c
 *
 *  Created on: Feb 13, 2024
 *      Author: raymo
 */

#include <stdio.h>
#include <stdint.h>

uint16_t convert_to_uint16 (uint8_t* p_value){
	uint16_t value = (p_value[0] & 0xFF) << 8;
	value += (p_value[1] & 0xFF);
	return value;
}

uint32_t convert_to_uint32 (uint8_t* p_value){
	uint32_t value = (uint32_t)(p_value[0] & 0xFF) << 24;
	value += (uint32_t)(p_value[1] & 0xFF) << 16;
	value += (uint32_t)(p_value[2] & 0xFF) << 8;
	value += (uint32_t)p_value[3];
	return value;
}
