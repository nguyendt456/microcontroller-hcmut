/*
 * led.c
 *
 *  Created on: Nov 26, 2022
 *      Author: nguye
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

void setENxState(int EN0, int EN1, int EN2, int EN3, int EN4, int EN5, int EN6) {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, EN0);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, EN1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, EN2);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, EN3);
	HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, EN4);
	HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, EN5);
	HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, EN6);
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
void ledScan() {
	if(status == MODE_PRINT) {
		  setENxState(1, 1, 1, 1, 1, 1, 0);
		  display7SEG(mode, GPIOA, _a_Pin, _b_Pin, _c_Pin, _d_Pin, _e_Pin, _f_Pin, _g_Pin);
		  status = SECOND_TRAFFIC_1;
		  check = 1;
	  }
	  if(status == TIME_DURATION_2) {
		  setENxState(1, 1, 1, 1, 1, 0, 1);
		  display7SEG(timer_duration_secondorder, GPIOA, _a_Pin, _b_Pin, _c_Pin, _d_Pin, _e_Pin, _f_Pin, _g_Pin);
		  status = MODE_PRINT;
	  }
	  if(status == TIME_DURATION_1) {
		  setENxState(1, 1, 1, 1, 0, 1, 1);
		  display7SEG(timer_duration_firstorder, GPIOA, _a_Pin, _b_Pin, _c_Pin, _d_Pin, _e_Pin, _f_Pin, _g_Pin);
		  status = TIME_DURATION_2;
	  }
	  if(status == FIRST_TRAFFIC_2) {
		  setENxState(1, 1, 1, 0, 1, 1, 1);
		  display7SEG(first_traffic_light_count_2, GPIOA, _a_Pin, _b_Pin, _c_Pin, _d_Pin, _e_Pin, _f_Pin, _g_Pin);
		  status = TIME_DURATION_1;
	  }
	  if(status == FIRST_TRAFFIC_1) {
		  setENxState(1, 1, 0, 1, 1, 1, 1);
		  display7SEG(first_traffic_light_count_1, GPIOA, _a_Pin, _b_Pin, _c_Pin, _d_Pin, _e_Pin, _f_Pin, _g_Pin);
		  status = FIRST_TRAFFIC_2;
	  }
	  if(status == SECOND_TRAFFIC_2) {
		  setENxState(1, 0, 1, 1, 1, 1, 1);
		  display7SEG(second_traffic_light_count_2, GPIOA, _a_Pin, _b_Pin, _c_Pin, _d_Pin, _e_Pin, _f_Pin, _g_Pin);
		  status = FIRST_TRAFFIC_1;
	  }
	  if(status == SECOND_TRAFFIC_1 && check == 0) {
		  setENxState(0, 1, 1, 1, 1, 1, 1);
		  display7SEG(second_traffic_light_count_1, GPIOA, _a_Pin, _b_Pin, _c_Pin, _d_Pin, _e_Pin, _f_Pin, _g_Pin);
		  status = SECOND_TRAFFIC_2;
	  }
}
