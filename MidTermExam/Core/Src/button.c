/*
 * button.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Welcome
 */
#include "button.h"


int keyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int keyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};// trạng thái ổn định trước đó
int timerForKeyPress = 200;// nhấn đè thì 3s mới xử lý

int button_RESET_flag = 0;
int button_INC_flag = 0;
int button_DEC_flag = 0;

int button_RESET_LongPressed_flag = 0;
int button_INC_LongPressed_flag = 0;
int button_DEC_LongPressed_flag = 0;


int isButton_RESET_Pressed()
{
	if(button_RESET_flag == 1)
	{
		button_RESET_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton_INC_Pressed()
{
	if(button_INC_flag == 1)
	{
		button_INC_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton_DEC_Pressed()
{
	if(button_DEC_flag == 1)
	{
		button_DEC_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton_RESET_LongPressed(){
	if(button_RESET_LongPressed_flag == 1){
		button_RESET_LongPressed_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton_INC_LongPressed(){
	if(button_INC_LongPressed_flag == 1){
		button_INC_LongPressed_flag = 0;
		return 1;
	}
	else return 0;
}
int isButton_DEC_LongPressed(){
	if(button_DEC_LongPressed_flag == 1){
		button_DEC_LongPressed_flag = 0;
		return 1;
	}
	else return 0;
}

void getKeyInput()
{
	for(int i = 0; i < 3; i++){
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
		if(i == 0){
			keyReg2[i] = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
			if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
			{
				if(keyReg3[i] != keyReg2[i]) //trường hợp nhấn thả
				{
					keyReg3[i] = keyReg2[i]; // cập nhật lại keyReg3
					if(keyReg2[i] == PRESSED_STATE)
					{
						//TODO
						button_RESET_flag = 1;
						timerForKeyPress = 200;
					}
				}
				else
				{// trường hợp nhấn đè
					if(keyReg2[i] == PRESSED_STATE){
						timerForKeyPress--;
						if(timerForKeyPress == 0)
						{
							//if(keyReg2 == PRESSED_STATE)
							//{
								//TODO
								button_RESET_LongPressed_flag = 1;
							//}
							timerForKeyPress = 200;
						}
					}

				}

			}
		}
		if(i == 1){
			keyReg0[i] = keyReg1[i];
			keyReg1[i] = keyReg2[i];
			keyReg2[i] = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
			if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
			{
				if(keyReg3[i] != keyReg2[i]) //trường hợp nhấn thả
				{
					keyReg3[i] = keyReg2[i]; // cập nhật lại keyReg3
					if(keyReg2[i] == PRESSED_STATE)
					{
						//TODO
						button_INC_flag = 1;
						timerForKeyPress = 200;
					}
				}
				else
				{// trường hợp nhấn đè
					if(keyReg2[i] == PRESSED_STATE){
						timerForKeyPress--;
						if(timerForKeyPress == 0)
						{
							//if(keyReg2 == PRESSED_STATE)
							//{
								//TODO
								button_INC_LongPressed_flag = 1;
							//}
							timerForKeyPress = 200;
						}
					}

				}

			}
		}
		if(i == 2){
			keyReg0[i] = keyReg1[i];
			keyReg1[i] = keyReg2[i];
			keyReg2[i] = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
			if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
			{
				if(keyReg3[i] != keyReg2[i]) //trường hợp nhấn thả
				{
					keyReg3[i] = keyReg2[i]; // cập nhật lại keyReg3
					if(keyReg2[i] == PRESSED_STATE)
					{
						//TODO
						button_DEC_flag = 1;
						timerForKeyPress = 200;
					}
				}
				else
				{// trường hợp nhấn đè
					if(keyReg2[i] == PRESSED_STATE){
						timerForKeyPress--;
						if(timerForKeyPress == 0)
						{
							//if(keyReg2 == PRESSED_STATE)
							//{
								//TODO
								button_DEC_LongPressed_flag = 1;
							//}
							timerForKeyPress = 200;
						}
					}
				}
			}
		}

	}
}
