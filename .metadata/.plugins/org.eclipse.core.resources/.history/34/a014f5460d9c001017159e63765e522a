/**
 * @file    uart.h
 * @author  Enrique Emanuel Decima
 * @brief   Driver UART para STM32 - Abstracción sobre HAL
 * @version 1.0
 * @date    2025
 */

#ifndef UART_H_
#define UART_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* Tipos definidos -----------------------------------------------------------*/

/**
 * @brief Estado de retorno de funciones UART
 */
typedef enum {
    UART_OK = 0U,
    UART_ERROR
} UART_Status_t;

/**
 * @brief Modo de recepción de UART
 */
typedef enum {
    UART_MODE_POLLING = 0U,
    UART_MODE_IT,
    UART_MODE_DMA
} UART_Mode_t;

/* Funciones públicas --------------------------------------------------------*/

/**
 * @brief  Inicializa un periférico UART
 * @param  huart: Handler generado por CubeMX (ej: &huart2)
 * @retval UART_OK si la inicialización fue exitosa
 */
UART_Status_t UART_Init(UART_HandleTypeDef *huart);

/**
 * @brief  Envía un buffer por UART
 * @param  huart: Handler
 * @param  data:  Puntero a buffer
 * @param  size:  Tamaño del buffer
 * @param  mode:  Polling / IT / DMA
 * @retval UART_OK o UART_ERROR
 */
UART_Status_t UART_Send(UART_HandleTypeDef *huart, const uint8_t *data, size_t size, UART_Mode_t mode);

/**
 * @brief  Recibe un buffer por UART
 * @param  huart: Handler
 * @param  data:  Puntero a buffer
 * @param  size:  Tamaño esperado
 * @param  mode:  Polling / IT / DMA
 * @retval UART_OK o UART_ERROR
 */
UART_Status_t UART_Receive(UART_HandleTypeDef *huart, uint8_t *data, size_t size, UART_Mode_t mode);

/**
 * @brief  Envía un string (null-terminated)
 * @param  huart: Handler
 * @param  str:   String a enviar
 * @retval UART_OK o UART_ERROR
 */
UART_Status_t UART_SendString(UART_HandleTypeDef *huart, const char *str);

/**
 * @brief  Lee un número entero desde UART (modo polling)
 * @param  huart: handler de UART
 * @retval Número recibido (uint32_t) o UINT32_MAX en caso de error
 */
uint32_t UART_ReadNumber(UART_HandleTypeDef *huart);

/**
 * @brief  Enviar un número entero a traves de UART (modo polling)
 * @param  huart: handler de UART
 * @param Número a enviar (uint32_t)
 * @retval None
 */
void UART_SendNumber(UART_HandleTypeDef *huart, uint32_t data);

HAL_StatusTypeDef UART_Handshake(UART_HandleTypeDef *huart, uint32_t Timeout);

#endif /* UART_H_ */

