/*
 * scheduler.c
 *
 *  Created on: Dec 9, 2022
 *      Author: nguye
 */

#include "scheduler.h"
#include "main.h"
#include "stdint.h"
#include <stddef.h>
#include <stdlib.h>

TaskList SCH_tasks_G;

void SCH_Init(void) {
	SCH_tasks_G.head = NULL;
	SCH_tasks_G.size = 0;
}

void SCH_Update(void) {
	if(SCH_tasks_G.head->task.Delay == 0) {
		SCH_tasks_G.head->task.RunMe = 1;
	}
	else {
		SCH_tasks_G.head->task.Delay--;
	}
}

unsigned char SCH_Add_Task(void (*pFunc)(), unsigned int DELAY, unsigned int PERIOD) {
	taskNode* node = (taskNode *) malloc(sizeof(taskNode));
	node->task.pTask = pFunc;
	node->task.Delay = DELAY;
	node->task.Period = PERIOD;
	node->task.RunMe = 0;
	node->pNext = NULL;

	uint8_t idx = 0;
	if (SCH_tasks_G.size == 0) {
		SCH_tasks_G.head = node;
	}
	else {
		taskNode* current = SCH_tasks_G.head;
		taskNode* previous = NULL;
		while(current != NULL && node->task.Delay > current->task.Delay) {
			node->task.Delay -= current->task.Delay;
			previous = current;
			current = current->pNext;
			idx++;
		}
		if(previous == NULL) {
			node->pNext = current;
			current->task.Delay -= node->task.Delay;
			SCH_tasks_G.head = node;
		}
		else {
			previous->pNext = node;
			node->pNext = current;

			if(current) {
				current->task.Delay -= node->task.Delay;
			}
		}
	}
	SCH_tasks_G.size++;
	return idx;
}

void SCH_Dispatch_Tasks(void) {
	if(SCH_tasks_G.head != NULL) {
		if (SCH_tasks_G.head->task.RunMe == 1) {
			(*SCH_tasks_G.head->task.pTask)();

			if (SCH_tasks_G.head->task.Period > 0) {
				SCH_Add_Task(SCH_tasks_G.head->task.pTask, SCH_tasks_G.head->task.Period, SCH_tasks_G.head->task.Period);
			}
			SCH_Delete_Task(0);
		}
	}
}

unsigned char SCH_Delete_Task(const tByte TASK_INDEX) {
	if (TASK_INDEX < 0 || TASK_INDEX >= SCH_tasks_G.size)
		return RETURN_ERROR;

	taskNode *temp = SCH_tasks_G.head;
	if (TASK_INDEX == 0) {
		SCH_tasks_G.head = temp->pNext;
		SCH_tasks_G.head->task.Delay += temp->task.Delay;
	} else {
		uint32_t Index = 0;
		taskNode *cur = SCH_tasks_G.head;

		while (Index < TASK_INDEX - 1) {
			cur = cur->pNext;
			Index++;
		}
		temp = cur->pNext;
		cur->pNext = temp->pNext;
		cur->pNext->task.Delay += temp->task.Delay;
	}
	free(temp);
	temp = NULL;
	SCH_tasks_G.size--;
	return RETURN_NORMAL;
}
