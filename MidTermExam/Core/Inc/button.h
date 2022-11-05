/*
 * button.h
 *
 *  Created on: Oct 11, 2022
 *      Author: Welcome
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
#include "control_led_7SEG.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET


int isButton_RESET_Pressed();
int isButton_INC_Pressed();
int isButton_DEC_Pressed();

int isButton_RESET_LongPressed();
int isButton_INC_LongPressed();
int isButton_DEC_LongPressed();
#endif /* INC_BUTTON_H_ */
