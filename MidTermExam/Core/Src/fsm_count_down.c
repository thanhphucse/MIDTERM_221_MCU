/*
 * fsm_count_down.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Welcome
 */

#include "fsm_count_down.h"
#include "fsm_long_press.h"
#include "fsm_simple_buttons.h"
#include "global.h"
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "control_led_7SEG.h"

void fsm_count_down_run(){
	switch(status){
		case COUNT_DOWN:
			if(counter != 0){
				if(timer3_flag == 1){
					counter--;
					display7SEG(counter);
					setTimer3(1000);
				}
			}

			// chuyển về trạng thái nhấn thả
			if(isButton_RESET_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				status = reset;
			}
			if(isButton_DEC_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				if(counter == 1){
					status = reset;
				}
				else{
					counter --;
					display7SEG(counter);
					status = DECREASE;
				}
			}
			if(isButton_INC_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				if(counter == 8){
					counter = 9;
					display7SEG(counter);
					status = VALUE_MAX;
				}
				else{
					counter ++;
					display7SEG(counter);
					status = INCREASE;
				}
			}


			// chuyển về trạng thái nhấn đè
			if(isButton_INC_LongPressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				if(timer2_flag == 1){
					counter++;
					if (counter == 10) counter = 0;
					display7SEG(counter);
					setTimer2(1000);
				}
			}
			if(isButton_DEC_LongPressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				if(timer2_flag == 1){
					counter--;
					if(counter == -1) counter = 9;
					display7SEG(counter);
					setTimer2(1000);
				}
			}
			break;
		default:
			break;
	}
}
