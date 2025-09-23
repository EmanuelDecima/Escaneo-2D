/**
 * @file    mef.h
 * @author  Enrique Emanuel Decima
 * @brief   Maquina de estados finita que controla el flujo de la aplicacion
 * @version 1.0
 * @date    2025
 *
 */

#ifndef PERIFERICOS_INC_MEF_H_
#define PERIFERICOS_INC_MEF_H_

#include "main.h"
#include <stdio.h>
#include <string.h>

#include "clock_config.h"
#include "delay.h"
#include "gpio.h"
#include "i2c.h"

#include "ssd1306_oled.h"
#include "fonts.h"
#include "motorpap.h"

#include "menu.h"

void MEF_Init();
void MEF_Update(int8_t btn_pressed);


#endif /* PERIFERICOS_INC_MEF_H_ */
