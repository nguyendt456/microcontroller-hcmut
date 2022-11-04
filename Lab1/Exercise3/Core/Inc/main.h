/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define a_1_Pin GPIO_PIN_1
#define a_1_GPIO_Port GPIOA
#define b_1_Pin GPIO_PIN_2
#define b_1_GPIO_Port GPIOA
#define c_1_Pin GPIO_PIN_3
#define c_1_GPIO_Port GPIOA
#define d_1_Pin GPIO_PIN_4
#define d_1_GPIO_Port GPIOA
#define e_1_Pin GPIO_PIN_5
#define e_1_GPIO_Port GPIOA
#define f_1_Pin GPIO_PIN_6
#define f_1_GPIO_Port GPIOA
#define g_1_Pin GPIO_PIN_7
#define g_1_GPIO_Port GPIOA
#define row1_red_Pin GPIO_PIN_0
#define row1_red_GPIO_Port GPIOB
#define row1_green_Pin GPIO_PIN_1
#define row1_green_GPIO_Port GPIOB
#define row1_yellow_Pin GPIO_PIN_2
#define row1_yellow_GPIO_Port GPIOB
#define a_2_Pin GPIO_PIN_8
#define a_2_GPIO_Port GPIOA
#define b_2_Pin GPIO_PIN_9
#define b_2_GPIO_Port GPIOA
#define c_2_Pin GPIO_PIN_10
#define c_2_GPIO_Port GPIOA
#define d_2_Pin GPIO_PIN_11
#define d_2_GPIO_Port GPIOA
#define e_2_Pin GPIO_PIN_12
#define e_2_GPIO_Port GPIOA
#define f_2_Pin GPIO_PIN_13
#define f_2_GPIO_Port GPIOA
#define g_2_Pin GPIO_PIN_14
#define g_2_GPIO_Port GPIOA
#define row2_red_Pin GPIO_PIN_4
#define row2_red_GPIO_Port GPIOB
#define row2_green_Pin GPIO_PIN_5
#define row2_green_GPIO_Port GPIOB
#define row2_yellow_Pin GPIO_PIN_6
#define row2_yellow_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
