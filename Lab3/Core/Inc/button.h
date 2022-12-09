/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: nguye
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int getButtonEvent();
#endif /* INC_BUTTON_H_ */
