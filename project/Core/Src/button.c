/*
 * button.c
 *
 *  Created on: Jan 5, 2023
 *      Author: bronzewhale
 */


#include "button.h"
#include "main.h"

int getButtonEvent() {
	if(HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin) == PRESSED_STATE) {
		return 0;
	}
	if(HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin) == PRESSED_STATE) {
		return 1;
	}
	if(HAL_GPIO_ReadPin(BUT3_GPIO_Port, BUT3_Pin) == PRESSED_STATE) {
		return 2;
	}
	return -1;
}
