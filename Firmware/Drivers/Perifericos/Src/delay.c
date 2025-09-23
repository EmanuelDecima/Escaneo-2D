/**
 * @file    delay.c
 * @brief   Implementación de delay no bloqueante con SysTick
 */

#include "delay.h"

/* Funciones públicas --------------------------------------------------------*/

void Delay_Init(delay_t *delay, uint32_t duration)
{
    delay->duration = duration;
    delay->running = false;
}

bool Delay_Read(delay_t *delay)
{
    if (delay->running) {
        if ((HAL_GetTick() - delay->startTime) >= delay->duration) {
            delay->running = false;
            return true;
        } else {
            return false;
        }
    } else {
        delay->startTime = HAL_GetTick();
        delay->running = true;
        return false;
    }
}

void Delay_Write(delay_t *delay, uint32_t duration)
{
    delay->duration = duration;
}
