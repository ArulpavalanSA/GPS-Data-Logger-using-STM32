#ifndef GPS_H
#define GPS_H

#include "stm32f4xx_hal.h"

#define GPS_BUFFER_SIZE 128

extern uint8_t gpsBuffer[GPS_BUFFER_SIZE];

void GPS_Init(void);
void GPS_ProcessData(uint8_t *data, uint16_t size);

#endif
