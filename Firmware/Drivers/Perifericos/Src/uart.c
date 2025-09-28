/**
 * @file    uart.c
 * @brief   Implementación del driver UART
 */

#include "uart.h"

#define HANDSHAKE_SEND_CHAR  'o'
#define HANDSHAKE_REPLY_CHAR 'k'

UART_Status_t UART_Init(UART_HandleTypeDef *huart)
{
    if (HAL_UART_Init(huart) == HAL_OK) {
        return UART_OK;
    }
    return UART_ERROR;
}

UART_Status_t UART_Send(UART_HandleTypeDef *huart, const uint8_t *data, size_t size, UART_Mode_t mode)
{
    HAL_StatusTypeDef status;

    switch (mode) {
        case UART_MODE_POLLING:
            status = HAL_UART_Transmit(huart, (uint8_t*)data, (uint16_t)size, HAL_MAX_DELAY);
            break;

        case UART_MODE_IT:
            status = HAL_UART_Transmit_IT(huart, (uint8_t*)data, (uint16_t)size);
            break;

        case UART_MODE_DMA:
            status = HAL_UART_Transmit_DMA(huart, (uint8_t*)data, (uint16_t)size);
            break;

        default:
            return UART_ERROR;
    }

    return (status == HAL_OK) ? UART_OK : UART_ERROR;
}

UART_Status_t UART_Receive(UART_HandleTypeDef *huart, uint8_t *data, size_t size, UART_Mode_t mode)
{
    HAL_StatusTypeDef status;

    switch (mode) {
        case UART_MODE_POLLING:
            status = HAL_UART_Receive(huart, data, (uint16_t)size, HAL_MAX_DELAY);
            break;

        case UART_MODE_IT:
            status = HAL_UART_Receive_IT(huart, data, (uint16_t)size);
            break;

        case UART_MODE_DMA:
            status = HAL_UART_Receive_DMA(huart, data, (uint16_t)size);
            break;

        default:
            return UART_ERROR;
    }

    return (status == HAL_OK) ? UART_OK : UART_ERROR;
}

UART_Status_t UART_SendString(UART_HandleTypeDef *huart, const char *str)
{
    size_t len = 0U;

    if (str == NULL) {
        return UART_ERROR;
    }

    while (str[len] != '\0') {
        len++;
    }

    return UART_Send(huart, (const uint8_t*)str, len, UART_MODE_POLLING);
}



uint32_t UART_ReadNumber(UART_HandleTypeDef *huart, uint32_t Timeout)
{
    uint8_t rxChar;
    char buffer[16];
    uint8_t index = 0;

    while (1) {
        if (HAL_UART_Receive(huart, &rxChar, 1, Timeout) != HAL_OK) {
            return UINT32_MAX;
        }
        if (rxChar == '\r') {
            continue;
        }
        if (rxChar == '\n') {
            buffer[index] = '\0';
            break;
        }
        if (!isdigit(rxChar)) {
            return UINT32_MAX;
        }
        if (index < sizeof(buffer) - 1) {
            buffer[index++] = (char)rxChar;
        } else {
            return UINT32_MAX;
        }
    }
    return (uint32_t)strtoul(buffer, NULL, 10);
}

void UART_SendNumber(UART_HandleTypeDef *huart, uint32_t data)
{
    char str[12];
    sprintf(str, "%lu", data);
    HAL_UART_Transmit(huart, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
    HAL_UART_Transmit(huart, (uint8_t*)"\r\n", 2, HAL_MAX_DELAY);
}

HAL_StatusTypeDef UART_Handshake(UART_HandleTypeDef *huart, uint32_t Timeout){
    uint8_t txChar = HANDSHAKE_SEND_CHAR;
    uint8_t rxChar = 0;

    // Enviar carácter
    if (HAL_UART_Transmit(huart, &txChar, 1, Timeout) != HAL_OK) {
        return HAL_ERROR;  // Error al transmitir
    }

    // Esperar respuesta
    if (HAL_UART_Receive(huart, &rxChar, 1, Timeout) != HAL_OK) {
        return HAL_TIMEOUT;  // No se recibió nada
    }

    // Verificar si la respuesta es la esperada
    if (rxChar == HANDSHAKE_REPLY_CHAR) {
        return HAL_OK;  // Handshake exitoso
    } else {
        return HAL_ERROR;  // Carácter inesperado
    }
}
