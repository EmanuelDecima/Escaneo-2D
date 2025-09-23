/*
 * Button_Handler.h
 *
 *  Created on: Sep 3, 2025
 *      Author: Estudiante
 */

#ifndef API_INC_BUTTON_HANDLER_H_
#define API_INC_BUTTON_HANDLER_H_

#include "main.h"
#include <stdbool.h>
#include "delay.h"

typedef enum {
	BUTTON_UP ,
	BUTTON_FALLING ,
	BUTTON_DOWN ,
	BUTTON_RISING
} ButtonState_t;

void debounceFSM_Init(GPIO_TypeDef* Port, uint16_t Pin, uint16_t id);
void Pressing_Signal(uint16_t id);
void Pressed_Signal(uint16_t id);
bool Read_Button_Response(uint16_t id);
ButtonState_t Read_State(uint16_t id);

#endif /* API_INC_BUTTON_HANDLER_H_ */
