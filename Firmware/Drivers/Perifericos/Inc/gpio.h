/**
 * @file    gpio.h
 * @author  Enrique Emanuel Decima
 * @brief   Driver GPIO para STM32 - Abstracción sobre HAL
 * @version 1.0
 * @date    2025
 *
 * @note    Este módulo encapsula funciones de HAL para simplificar
 *          y uniformar el uso de pines digitales.
 */

#ifndef GPIO_H_
#define GPIO_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"   /* Ajustar según tu familia de MCU */
#include <stdint.h>

/* Tipos definidos -----------------------------------------------------------*/

/**
 * @brief  Estados posibles de un pin digital
 */
typedef enum {
    GPIO_STATE_LOW = 0U,
    GPIO_STATE_HIGH
} GPIO_State_t;

/**
 * @brief  Modos de funcionamiento de un pin
 */
typedef enum {
	GPIO_MODE_INPUT_NOPULL = 0U,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_INPUT_PULLUP,
    GPIO_MODE_INPUT_PULLDOWN
} GPIO_Mode_t;

/* Funciones públicas --------------------------------------------------------*/

/**
 * @brief  Habilita un puerto GPIO con su respectivo Reloj
 * @param  port: Puerto GPIO (ej. GPIOA, GPIOB, etc.)
 * @retval None
 */
void GPIO_EnableCLK(GPIO_TypeDef *port);

/**
 * @brief  Inicializa un pin GPIO
 * @param  port: Puerto GPIO (ej. GPIOA, GPIOB, etc.)
 * @param  pin:  Pin GPIO (ej. GPIO_PIN_5)
 * @param  mode: Modo de configuración (entrada, salida, pull-up, etc.)
 * @retval None
 */
void GPIO_InitPin(GPIO_TypeDef *port, uint16_t pin, GPIO_Mode_t mode);

/**
 * @brief  Escribe un estado en un pin
 * @param  port: Puerto GPIO
 * @param  pin:  Pin GPIO
 * @param  state: HIGH o LOW
 * @retval None
 */
void GPIO_WritePin(GPIO_TypeDef *port, uint16_t pin, GPIO_State_t state);

/**
 * @brief  Lee el estado de un pin
 * @param  port: Puerto GPIO
 * @param  pin:  Pin GPIO
 * @retval GPIO_STATE_HIGH o GPIO_STATE_LOW
 */
GPIO_State_t GPIO_ReadPin(GPIO_TypeDef *port, uint16_t pin);

/**
 * @brief  Alterna el estado de un pin
 * @param  port: Puerto GPIO
 * @param  pin:  Pin GPIO
 * @retval None
 */
void GPIO_TogglePin(GPIO_TypeDef *port, uint16_t pin);

#endif /* GPIO_H_ */

