/**
 * @file    i2c.c
 * @brief   Implementación del driver I2C
 */

#include "i2c.h"

/* Funciones públicas --------------------------------------------------------*/

I2C_Status_t I2C_Init(I2C_TypeDef* Descriptor,uint32_t clock_speed, I2C_HandleTypeDef *hi2c)
{
    hi2c->Instance = Descriptor;
    hi2c->Init.ClockSpeed = clock_speed;
    hi2c->Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c->Init.OwnAddress1 = 0;
    hi2c->Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c->Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c->Init.OwnAddress2 = 0;
    hi2c->Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c->Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    return (HAL_I2C_Init(hi2c) == HAL_OK) ? I2C_OK : I2C_ERROR;
}

I2C_Status_t I2C_Write(I2C_HandleTypeDef *hi2c, uint16_t devAddr, const uint8_t *data, size_t size)
{
    if (HAL_I2C_Master_Transmit(hi2c, devAddr, (uint8_t*)data, (uint16_t)size, HAL_MAX_DELAY) == HAL_OK) {
        return I2C_OK;
    }
    return I2C_ERROR;
}

I2C_Status_t I2C_Read(I2C_HandleTypeDef *hi2c, uint16_t devAddr, uint8_t *data, size_t size)
{
    if (HAL_I2C_Master_Receive(hi2c, devAddr, data, (uint16_t)size, HAL_MAX_DELAY) == HAL_OK) {
        return I2C_OK;
    }
    return I2C_ERROR;
}

I2C_Status_t I2C_WriteReg(I2C_HandleTypeDef *hi2c, uint16_t devAddr, uint8_t regAddr, const uint8_t *data, size_t size)
{
    if (HAL_I2C_Mem_Write(hi2c, devAddr, regAddr, I2C_MEMADD_SIZE_8BIT,
                          (uint8_t*)data, (uint16_t)size, HAL_MAX_DELAY) == HAL_OK) {
        return I2C_OK;
    }
    return I2C_ERROR;
}

I2C_Status_t I2C_ReadReg(I2C_HandleTypeDef *hi2c, uint16_t devAddr, uint8_t regAddr, uint8_t *data, size_t size)
{
    if (HAL_I2C_Mem_Read(hi2c, devAddr, regAddr, I2C_MEMADD_SIZE_8BIT,
                         data, (uint16_t)size, HAL_MAX_DELAY) == HAL_OK) {
        return I2C_OK;
    }
    return I2C_ERROR;
}
