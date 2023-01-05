/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#define BUT1_Pin GPIO_PIN_5
#define BUT1_GPIO_Port GPIOA
#define BUT2_Pin GPIO_PIN_6
#define BUT2_GPIO_Port GPIOA
#define BUT3_Pin GPIO_PIN_7
#define BUT3_GPIO_Port GPIOA
#define RED1_Pin GPIO_PIN_3
#define RED1_GPIO_Port GPIOB
#define GREEN1_Pin GPIO_PIN_4
#define GREEN1_GPIO_Port GPIOB
#define YELLOW1_Pin GPIO_PIN_5
#define YELLOW1_GPIO_Port GPIOB
#define RED2_Pin GPIO_PIN_6
#define RED2_GPIO_Port GPIOB
#define GREEN2_Pin GPIO_PIN_7
#define GREEN2_GPIO_Port GPIOB
#define YELLOW2_Pin GPIO_PIN_8
#define YELLOW2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
