
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H


#include "stm32f4xx_hal.h"
#include "main.h"
void I2C_start_metering (uint8_t sensor_addres);
void I2C_get_data (uint8_t sensor_addres, uint8_t *buf, uint8_t size);
#endif /* __STM32F4xx_IT_H */


