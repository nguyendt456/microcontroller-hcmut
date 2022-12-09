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
#define Button1_Pin GPIO_PIN_13
#define Button1_GPIO_Port GPIOC
#define _a_Pin GPIO_PIN_1
#define _a_GPIO_Port GPIOA
#define _b_Pin GPIO_PIN_2
#define _b_GPIO_Port GPIOA
#define _c_Pin GPIO_PIN_3
#define _c_GPIO_Port GPIOA
#define _d_Pin GPIO_PIN_4
#define _d_GPIO_Port GPIOA
#define _e_Pin GPIO_PIN_5
#define _e_GPIO_Port GPIOA
#define _f_Pin GPIO_PIN_6
#define _f_GPIO_Port GPIOA
#define _g_Pin GPIO_PIN_7
#define _g_GPIO_Port GPIOA
#define BUT1_Pin GPIO_PIN_0
#define BUT1_GPIO_Port GPIOB
#define BUT2_Pin GPIO_PIN_1
#define BUT2_GPIO_Port GPIOB
#define BUT3_Pin GPIO_PIN_10
#define BUT3_GPIO_Port GPIOB
#define RED1_Pin GPIO_PIN_8
#define RED1_GPIO_Port GPIOA
#define GREEN1_Pin GPIO_PIN_9
#define GREEN1_GPIO_Port GPIOA
#define YELLOW1_Pin GPIO_PIN_10
#define YELLOW1_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_11
#define RED2_GPIO_Port GPIOA
#define GREEN2_Pin GPIO_PIN_12
#define GREEN2_GPIO_Port GPIOA
#define YELLOW2_Pin GPIO_PIN_13
#define YELLOW2_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_3
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_4
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_5
#define EN2_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_6
#define EN3_GPIO_Port GPIOB
#define EN4_Pin GPIO_PIN_7
#define EN4_GPIO_Port GPIOB
#define EN5_Pin GPIO_PIN_8
#define EN5_GPIO_Port GPIOB
#define EN6_Pin GPIO_PIN_9
#define EN6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
