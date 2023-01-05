/*
 * led.h
 *
 *  Created on: Jan 5, 2023
 *      Author: bronzewhale
 */

#ifndef INC_LED_H_
#define INC_LED_H_

void clearAllTrafficLight();
void setTraffic(int index, int red, int green, int yellow);
void blink_red();
void blink_yellow();
void blink_green();


#endif /* INC_LED_H_ */
