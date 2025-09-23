/**
 * @file    delay.h
 * @author  Enrique Emanuel Decima
 * @brief   Librería de delay no bloqueante usando SysTick
 * @version 1.0
 * @date    2025
 *
 * @note    Basada en HAL_GetTick(). Útil para multitarea cooperativa.
 * @license MIT
 */

#ifndef DELAY_H_
#define DELAY_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

/* Tipos definidos -----------------------------------------------------------*/

/**
 * @brief Estructura de control de un delay no bloqueante
 */
typedef struct {
    uint32_t startTime;   /**< Tick de inicio */
    uint32_t duration;    /**< Duración configurada (ms) */
    bool running;         /**< Estado interno (delay activo o no) */
} delay_t;

/* Funciones públicas --------------------------------------------------------*/

/**
 * @brief  Inicializa un delay
 * @param  delay: Puntero a la estructura de delay
 * @param  duration: Tiempo en ms
 * @retval None
 */
void Delay_Init(delay_t *delay, uint32_t duration);

/**
 * @brief  Lee el estado del delay
 * @param  delay: Puntero a la estructura de delay
 * @retval true si ya transcurrió el tiempo, false en caso contrario
 */
bool Delay_Read(delay_t *delay);

/**
 * @brief  Modifica la duración de un delay en tiempo de ejecución
 * @param  delay: Puntero a la estructura de delay
 * @param  duration: Nueva duración en ms
 * @retval None
 */
void Delay_Write(delay_t *delay, uint32_t duration);

#endif /* DELAY_H_ */
