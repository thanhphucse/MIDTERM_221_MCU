/*
 * fsm_automatic.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Welcome
 */
#include "fsm_simple_buttons.h"
#include "global.h"
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "control_led_7SEG.h"

void fsm_simple_buttons_run(){
	switch(status)
	{
		case INIT:
			status = reset;
			break;
		case reset:
			counter = 0;
			display7SEG(counter);
			if(isButton_RESET_Pressed() == 1) status = reset;
			if(isButton_DEC_Pressed() == 1){
				counter = 9;
				status = VALUE_MAX;
			}
			if(isButton_INC_Pressed() == 1) {
				counter ++;
				status = INCREASE;
			}

			// chuyển sang trạng thái nhấn đè 3s
			if(isButton_DEC_LongPressed() == 1){
				counter--;
				status = LONG_DEC;
			}
			if(isButton_INC_LongPressed() == 1){
				counter++;
				status = LONG_INC;
			}
			break;
		case INCREASE:
			display7SEG(counter);
			// chuyển về trạng thái countDown
			if(timer3_flag == 1) {
				setTimer3(1000);
				if(counter != 0){
					counter--;
				}
				display7SEG(counter);
				status = COUNT_DOWN;
			}


			if(isButton_INC_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				if(counter == 8){
					counter = 9;
					status = VALUE_MAX;
				}
				else{
					counter ++;
					display7SEG(counter);
					status = INCREASE;
				}

			}
			if(isButton_DEC_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				if(counter == 1){
					status = reset;
				}
				else{
					counter --;
					status = DECREASE;
				}
			}
			if(isButton_RESET_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				status = reset;
			}

			// chuyển sang trạng thái nhấn đè 3s
			if(isButton_DEC_LongPressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				counter--;
				status = LONG_DEC;
			}
			if(isButton_INC_LongPressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				counter++;
				status = LONG_INC;
			}

			break;
		case DECREASE:
			display7SEG(counter);

			// chuyển về trạng thái countDown
			if(timer3_flag == 1) {
				setTimer3(1000);
				if(counter != 0){
					counter--;
				}
				display7SEG(counter);
				status = COUNT_DOWN;
			}


			if(isButton_INC_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				if(counter == 8){
					counter = 9;
					status = VALUE_MAX;
				}
				else{
					counter++;
					status = INCREASE;
				}
			}
			if(isButton_DEC_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				if(counter == 1){
					status = reset;
				}
				else{
					counter--;
					status = DECREASE;
				}

			}
			if(isButton_RESET_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				status = reset;
			}

			// chuyển sang trạng thái nhấn đè 3s
			if(isButton_DEC_LongPressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				counter--;
				status = LONG_DEC;
			}
			if(isButton_INC_LongPressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				counter++;
				status = LONG_INC;
			}

			break;
		case VALUE_MAX:
			display7SEG(counter);
			// chuyển về trạng thái countDown
			if(timer3_flag == 1) {
				setTimer3(1000);
				if(counter != 0){
					counter--;
				}
				display7SEG(counter);
				status = COUNT_DOWN;
			}


			if(isButton_INC_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				status = reset;
			}
			if(isButton_DEC_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				counter --;
				status = DECREASE;
			}
			if(isButton_RESET_Pressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				status = reset;
			}

			// chuyển sang trạng thái nhấn đè 3s
			if(isButton_DEC_LongPressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				counter--;
				status = LONG_DEC;
			}
			if(isButton_INC_LongPressed() == 1){
				setTimer3(10000);// set thời gian đếm ngược cho khoảng thời gian không bấm nút
				counter++;
				status = LONG_INC;
			}
			break;
		default:
			break;

	}
}
