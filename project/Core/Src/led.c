/*
 * led.c
 *
 *  Created on: Jan 5, 2023
 *      Author: bronzewhale
 */


#include "main.h"
#include "global.h"

void clearAllTrafficLight() {
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, RESET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, RESET);
}

void setTraffic(int index, int red, int green, int yellow) {
	switch(index) {
	case 1:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, red);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, green);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, yellow);
		break;
	case 2:
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, red);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, green);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, yellow);
		break;
	default:
		break;
	}
}
void blink_red() {
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
}
void blink_yellow() {
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
}
void blink_green() {
	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
}
