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
#define hour1_Pin GPIO_PIN_1
#define hour1_GPIO_Port GPIOA
#define hour2_Pin GPIO_PIN_2
#define hour2_GPIO_Port GPIOA
#define hour3_Pin GPIO_PIN_3
#define hour3_GPIO_Port GPIOA
#define hour4_Pin GPIO_PIN_4
#define hour4_GPIO_Port GPIOA
#define hour5_Pin GPIO_PIN_5
#define hour5_GPIO_Port GPIOA
#define hour6_Pin GPIO_PIN_6
#define hour6_GPIO_Port GPIOA
#define hour7_Pin GPIO_PIN_7
#define hour7_GPIO_Port GPIOA
#define hour8_Pin GPIO_PIN_8
#define hour8_GPIO_Port GPIOA
#define hour9_Pin GPIO_PIN_9
#define hour9_GPIO_Port GPIOA
#define hour10_Pin GPIO_PIN_10
#define hour10_GPIO_Port GPIOA
#define hour11_Pin GPIO_PIN_11
#define hour11_GPIO_Port GPIOA
#define hour12_Pin GPIO_PIN_12
#define hour12_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
