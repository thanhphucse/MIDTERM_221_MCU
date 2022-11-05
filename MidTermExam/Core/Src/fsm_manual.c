/*
 * fsm_manual.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Welcome
 */
#include "fsm_manual.h"
#include "global.h"
#include "software_timer.h"
#include "button.h"

//void fsm_manual_run()
//{
//	switch(status){
//		case MAN_RED:
//			//TODO
//			setRed();
//			// chuyển về chế độ automatic
//			if(timer1_flag == 1){
//				status = INIT;
//				setTimer1(5000);
//			}
//
//			//if(isButton1Pressed() == 1){
//			if(isButton1LongPressed() == 1){
//				status = MAN_GREEN;
//				setTimer1(10000);
//			}
//
//			break;
//		case MAN_GREEN:
//			//TODO
//			setGreen();
//			// chuyển về chế độ automatic
//			if(timer1_flag == 1){
//				status = INIT;
//				setTimer1(5000);
//			}
//
//			//if(isButton1Pressed() == 1){
//			if(isButton1LongPressed() == 1){
//				status = MAN_YELLOW;
//				setTimer1(10000);
//			}
//
//			break;
//		case MAN_YELLOW:
//			//TODO
//			setYellow();
//			// chuyển về chế độ automatic
//			if(timer1_flag == 1){
//				status = INIT;
//				setTimer1(5000);
//			}
//
//			//if(isButton1Pressed() == 1){
//			if(isButton1LongPressed() == 1){
//				status = MAN_RED;
//				setTimer1(10000);
//			}
//
//			break;
//		default:
//			break;
//	}
//}
