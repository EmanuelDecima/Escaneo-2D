/**
 * @file    clock_config.h
 * @author  Enrique Emanuel Decima
 * @brief   Driver para la configuracion del reloj de STM32
 * @version 1.0
 * @date    2025
 *
 * @note    Este módulo encapsula la configuracion del reloj
 * 			para simplificar el codigo en el main.c
 */
#ifndef CLOCK_CONFIG_H
#define CLOCK_CONFIG_H

#include "stm32f4xx_hal.h"

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void);

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void);

#endif /* CLOCK_CONFIG_H_ */
