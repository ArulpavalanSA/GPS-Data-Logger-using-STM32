#ifndef USART_H
#define USART_H

#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

void USART2_SendString(char *str);

#endif // USART_H
