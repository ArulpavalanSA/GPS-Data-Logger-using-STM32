#include "gps.h"
#include "string.h"
#include "stdio.h"
#include "usart.h"

void GPS_Init(void) {
    memset(gpsBuffer, 0, GPS_BUFFER_SIZE);
    HAL_UART_Receive_DMA(&huart1, gpsBuffer, GPS_BUFFER_SIZE);  // Start DMA Reception
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart == &huart1) {
        GPS_ProcessData(gpsBuffer, GPS_BUFFER_SIZE);
        memset(gpsBuffer, 0, GPS_BUFFER_SIZE);
        HAL_UART_Receive_DMA(&huart1, gpsBuffer, GPS_BUFFER_SIZE);  // Restart DMA Reception
    }
}


void GPS_ProcessData(uint8_t *data, uint16_t size) {
    char debugMessage[GPS_BUFFER_SIZE + 20];
    snprintf(debugMessage, sizeof(debugMessage), "GPS Data: %s\r\n", data);
    USART2_SendString(debugMessage);
    HAL_UART_Transmit(&huart2, (uint8_t *)"Received: ", 10, HAL_MAX_DELAY);
        HAL_UART_Transmit(&huart2, data, size, HAL_MAX_DELAY);
        HAL_UART_Transmit(&huart2, (uint8_t *)"\r\n", 2, HAL_MAX_DELAY);
}


