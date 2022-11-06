/*
 * soft_ware.h
 *
 *  Created on: Oct 4, 2022
 *      Author: Welcome
 */
#include <fsm_simple_buttons.h>
#include "global.h"
#include "main.h"
#include "button.h"

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TICK 10

extern int timer1_counter;
extern int timer1_flag;

extern int timer2_counter;
extern int timer2_flag;

extern int timer3_counter;
extern int timer3_flag;

void setTimer1(int duration);

void setTimer2(int duration);

void setTimer3(int duration);

void timeRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
