/*
 * led.h
 *
 *  Created on: Nov 26, 2022
 *      Author: nguye
 */

#ifndef INC_LED_H_
#define INC_LED_H_


void clearAllTrafficLight();
void setENxState(int EN0, int EN1, int EN2, int EN3, int EN4, int EN5, int EN6);
void setTraffic(int index, int red, int green, int yellow);
void blink_red();
void blink_yellow();
void blink_green();
void ledScan();

#endif /* INC_LED_H_ */
