/*
 * button.h
 *
 *  Created on: Jan 5, 2023
 *      Author: bronzewhale
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int getButtonEvent();

#endif /* INC_BUTTON_H_ */
