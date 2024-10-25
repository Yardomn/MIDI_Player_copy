/*
 * endian_converter.h
 *
 *  Created on: Feb 14, 2024
 *      Author: raymo
 */

#ifndef INC_PROJECT_ENDIAN_CONVERTER_H_
#define INC_PROJECT_ENDIAN_CONVERTER_H_

#include <stdint.h>

uint16_t convert_to_uint16 (uint8_t* p_value);
uint32_t convert_to_uint32 (uint8_t* p_value);

#endif /* INC_PROJECT_ENDIAN_CONVERTER_H_ */
