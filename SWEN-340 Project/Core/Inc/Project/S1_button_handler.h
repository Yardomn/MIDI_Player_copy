/*
 * S1_button_handler.h
 *
 *  Created on: Mar 19, 2024
 *      Author: raymo
 */

#ifndef INC_S1_BUTTON_HANDLER_H_
#define INC_S1_BUTTON_HANDLER_H_

void S1_button_enable();
void S1_button_disable();
void EXTI9_5_IRQHandler();
int Get_button_pressed();
void set_manual_active();
void set_manual_unactive();
void manual_mode_loop();



#endif /* INC_ACTIVITIES_S1_BUTTON_HANDLER_H_ */
