/**
 * @file    i2c.h
 * @author  Emanuel
 * @brief   Driver I2C para STM32 - Abstracción sobre HAL
 * @version 1.0
 * @date    2025
 */

#ifndef I2C_H_
#define I2C_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stddef.h>

#define I2C_STANDARD_MODE 100000
#define I2C_FAST_MODE 400000

/* Tipos definidos -----------------------------------------------------------*/

/**
 * @brief Estado de retorno de funciones I2C
 */
typedef enum {
    I2C_OK = 0U,
    I2C_ERROR
} I2C_Status_t;


/* Funciones públicas --------------------------------------------------------*/

/**
 * @brief  Inicializa el periférico I2C
 * @param  hi2c: handler generado por CubeMX (ej. &hi2c1)
 * @retval I2C_OK o I2C_ERROR
 */
I2C_Status_t I2C_Init(I2C_TypeDef* Descriptor,uint32_t clock_speed, I2C_HandleTypeDef *hi2c);

/**
 * @brief  Escribe datos en un dispositivo I2C
 * @param  hi2c: handler
 * @param  devAddr: dirección del dispositivo (7 bits)
 * @param  data: puntero a buffer de datos
 * @param  size: cantidad de bytes a enviar
 * @retval I2C_OK o I2C_ERROR
 */
I2C_Status_t I2C_Write(I2C_HandleTypeDef *hi2c, uint16_t devAddr,
                       const uint8_t *data, size_t size);

/**
 * @brief  Lee datos desde un dispositivo I2C
 * @param  hi2c: handler
 * @param  devAddr: dirección del dispositivo (7 bits)
 * @param  data: puntero a buffer destino
 * @param  size: cantidad de bytes a leer
 * @retval I2C_OK o I2C_ERROR
 */
I2C_Status_t I2C_Read(I2C_HandleTypeDef *hi2c, uint16_t devAddr,
                      uint8_t *data, size_t size);

/**
 * @brief  Escribe en un registro específico de un dispositivo I2C
 * @param  hi2c: handler
 * @param  devAddr: dirección del dispositivo (7 bits)
 * @param  regAddr: dirección del registro
 * @param  data: puntero a buffer de datos
 * @param  size: cantidad de bytes
 * @retval I2C_OK o I2C_ERROR
 */
I2C_Status_t I2C_WriteReg(I2C_HandleTypeDef *hi2c, uint16_t devAddr,
                          uint8_t regAddr, const uint8_t *data, size_t size);

/**
 * @brief  Lee desde un registro específico de un dispositivo I2C
 * @param  hi2c: handler
 * @param  devAddr: dirección del dispositivo (7 bits)
 * @param  regAddr: dirección del registro
 * @param  data: puntero a buffer destino
 * @param  size: cantidad de bytes
 * @retval I2C_OK o I2C_ERROR
 */
I2C_Status_t I2C_ReadReg(I2C_HandleTypeDef *hi2c, uint16_t devAddr,
                         uint8_t regAddr, uint8_t *data, size_t size);

#endif /* I2C_H_ */

