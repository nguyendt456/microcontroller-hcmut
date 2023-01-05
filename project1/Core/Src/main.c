/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
#include "button.h"
#include "math.h"
#include "global.h"
#include "led.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


int keyEvent_0 = -1;
int keyEvent_1 = -1;
int keyEvent_2 = -1;

int keyEvent_3 = -1;
int time_duration = 0;
int first_red_duration = 7;
int first_yellow_duration = 2;
int first_green_duration = 5;
int second_red_duration = 7;
int second_yellow_duration = 2;
int second_green_duration = 5;
int first_traffic_state = 0;
int second_traffic_state = 1;

void fsm_simple_buttons_run() {
	keyEvent_0 = keyEvent_1;
	keyEvent_1 = keyEvent_2;
	keyEvent_2 = getButtonEvent();
	if(keyEvent_0 == keyEvent_1 && keyEvent_1 == keyEvent_2) {
		if(keyEvent_3 != keyEvent_2) {
			keyEvent_3 = keyEvent_2;
			if(mode == 2) {
				if(keyEvent_2 == 2) {
					first_red_duration = time_duration;
					second_red_duration = time_duration;
					first_traffic_state = 0;
					second_traffic_state = 1;
					clearAllTrafficLight();
				}
				if(keyEvent_2 == 1) {
					time_duration += 1;
					if (time_duration > 99) time_duration = 0;
				}
			}
			if(mode == 3) {
				if(keyEvent_2 == 2) {
					first_yellow_duration = time_duration;
					second_yellow_duration = time_duration;
					first_traffic_state = 0;
					second_traffic_state = 1;
					clearAllTrafficLight();
				}
				if(keyEvent_2 == 1) {
					time_duration += 1;
					if (time_duration > 99) time_duration = 0;
				}
			}
			if(mode == 4) {
				if(keyEvent_2 == 2) {
					first_green_duration = time_duration;
					second_green_duration = time_duration;
					first_traffic_state = 0;
					second_traffic_state = 1;
				}
				if(keyEvent_2 == 1) {
					time_duration += 1;
					if (time_duration > 99) time_duration = 0;
				}
			}
			if(keyEvent_2 == 0) {
				clearAllTrafficLight();
				mode += 1;
				setTimer3(0);
				if (mode > 4) mode = 1;
				if (mode == 1) {
					setTimer2(first_red_duration*100);
					setTimer3(second_green_duration*100);
					HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
					HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
				}
				time_duration = 0;

			}
		}
	}
}
void setFirstTrafficLight(int state) {
	switch (state) {
		case RED_STATE:
		  setTimer2(first_green_duration*100);
		  setTraffic(1, 0, 1, 0);
		  //Write to green
		  first_traffic_state = GREEN_STATE;
		  break;
		case GREEN_STATE:
		  setTimer2(first_yellow_duration*100);
		  setTraffic(1, 0, 0, 1);
		  //Write to yellow
		  first_traffic_state = YELLOW_STATE;
		  break;
		case YELLOW_STATE:
		  setTraffic(1, 1, 0, 0);
		  setTimer2(first_red_duration*100);
		  //Write to red
		  first_traffic_state = RED_STATE;
		  break;
		default:
		  break;
	}
}
void setSecondTrafficLight(int state) {
	switch (state) {
		case RED_STATE:
		  setTimer3(second_green_duration*100);
		  setTraffic(2, 0, 1, 0);
		  //Write to green
		  second_traffic_state = GREEN_STATE;
		  break;
		case GREEN_STATE:
		  setTimer3(second_yellow_duration*100);
		  setTraffic(2, 0, 0, 1);
		  //Write to yellow
		  second_traffic_state = YELLOW_STATE;
		  break;
		case YELLOW_STATE:
		  setTimer3(second_red_duration*100);
		  setTraffic(2, 1, 0, 0);
		  //Write to red
		  second_traffic_state = RED_STATE;
		  break;
		default:
		  break;
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(& htim2);
  setTimer1(100);
  setTimer4(1);
  setTimer5(50);
  setTimer2(first_red_duration*100);
  setTimer3(second_green_duration*100);
  HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
  HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(timer5_flag == 1 && mode != MODE_1_MANUAL) {
	  		  setTimer5(50);
	  		  switch (mode) {
	  		  case MODE_2_RED:
	  			  blink_red();
	  			  break;
	  		  case MODE_3_YELLOW:
	  			  blink_yellow();
	  			  break;
	  		  case MODE_4_GREEN:
	  			  blink_green();
	  			  break;
	  		  }
	  	  }
	  	  if(timer4_flag == 1) {
	  		  setTimer4(1);
	  		  fsm_simple_buttons_run();
	  	  }
	  	  if(timer2_flag == 1 && mode == MODE_1_MANUAL) {
	  		  setFirstTrafficLight(first_traffic_state);
	  	  }
	  	  if(timer3_flag == 1 && mode == MODE_1_MANUAL) {
	  		  setSecondTrafficLight(second_traffic_state);
	  	  }
	  	  if(timer1_flag == 1) {
	  		  HAL_UART_Transmit(&huart2, (void*)str, sprintf(str , "\r\n!Time=%d", (int) (timer3_counter / 100)), 1000);
	  	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RED1_Pin|GREEN1_Pin|YELLOW1_Pin|RED2_Pin
                          |GREEN2_Pin|YELLOW2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BUT1_Pin BUT2_Pin BUT3_Pin */
  GPIO_InitStruct.Pin = BUT1_Pin|BUT2_Pin|BUT3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : RED1_Pin GREEN1_Pin YELLOW1_Pin RED2_Pin
                           GREEN2_Pin YELLOW2_Pin */
  GPIO_InitStruct.Pin = RED1_Pin|GREEN1_Pin|YELLOW1_Pin|RED2_Pin
                          |GREEN2_Pin|YELLOW2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timerRun();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
