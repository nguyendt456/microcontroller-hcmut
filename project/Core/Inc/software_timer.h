/*
 * software_timer.h
 *
 *  Created on: Jan 5, 2023
 *      Author: bronzewhale
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer1_counter;

extern int timer2_flag;
extern int timer2_counter;

extern int timer3_flag;
extern int timer3_counter;

extern int timer4_flag;
extern int timer4_counter;

extern int timer5_flag;
extern int timer5_counter;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
