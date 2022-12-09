/*
 * global.h
 *
 *  Created on: Nov 26, 2022
 *      Author: nguye
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define RED_STATE 0
#define YELLOW_STATE 2
#define GREEN_STATE 1

#define MODE_1_MANUAL 1
#define MODE_2_RED 2
#define MODE_3_YELLOW 3
#define MODE_4_GREEN 4

#define MODE_PRINT 7
#define TIME_DURATION_1 5
#define TIME_DURATION_2 6
#define FIRST_TRAFFIC_1 3
#define FIRST_TRAFFIC_2 4
#define SECOND_TRAFFIC_1 1
#define SECOND_TRAFFIC_2 2

extern int timer_duration_firstorder;
extern int timer_duration_secondorder;
extern int first_traffic_light_count_2;
extern int first_traffic_light_count_1;
extern int second_traffic_light_count_2;
extern int second_traffic_light_count_1;
extern int check;
extern int status;
extern int mode;

#endif /* INC_GLOBAL_H_ */
