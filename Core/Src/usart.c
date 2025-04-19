/*
 * usart.c
 *
 *  Created on: Mar 14, 2025
 *      Author: ARULPAVALAN S A
 */


#include "usart.h"

void USART2_SendString(char *str) {
    HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}
