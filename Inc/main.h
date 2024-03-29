/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWMOfRight_Pin GPIO_PIN_3
#define PWMOfRight_GPIO_Port GPIOA
#define A_Left_Pin GPIO_PIN_6
#define A_Left_GPIO_Port GPIOA
#define B_Left_Pin GPIO_PIN_7
#define B_Left_GPIO_Port GPIOA
#define DirOfRight_Pin GPIO_PIN_14
#define DirOfRight_GPIO_Port GPIOB
#define DirOfLeft_Pin GPIO_PIN_15
#define DirOfLeft_GPIO_Port GPIOB
#define brake_Pin GPIO_PIN_8
#define brake_GPIO_Port GPIOA
#define PWMOfLeft_Pin GPIO_PIN_11
#define PWMOfLeft_GPIO_Port GPIOA
#define A_Right_Pin GPIO_PIN_6
#define A_Right_GPIO_Port GPIOB
#define B_Right_Pin GPIO_PIN_7
#define B_Right_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
