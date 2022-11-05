/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: nguye
 */
#include "button.h"
#include "main.h"

int getButtonEvent() {
	if(HAL_GPIO_ReadPin(INC_BUTTON_GPIO_Port, INC_BUTTON_Pin) == PRESSED_STATE) {
		return 0;
	}
	if(HAL_GPIO_ReadPin(DC_BUTTON_GPIO_Port, DC_BUTTON_Pin) == PRESSED_STATE) {
		return 1;
	}
	if(HAL_GPIO_ReadPin(RESET_BUTTON_GPIO_Port, RESET_BUTTON_Pin) == PRESSED_STATE) {
		return 2;
	}
	return -1;
}
