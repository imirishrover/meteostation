#include "locator.h"
#include "main.h"
#define WRITE_THE_RANGE_COMMAND 81
#define DEVICE_ADDRESS 8


extern I2C_HandleTypeDef hi2c1;
uint8_t I2C_buffer[2] = {0, 0};

void I2C_start_metering (uint8_t sensor_addres)
{
	uint8_t command = WRITE_THE_RANGE_COMMAND;
	
	HAL_StatusTypeDef result = HAL_I2C_Master_Transmit(&hi2c1, sensor_addres, &command, 1, 10000);
	//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	
	if (result != HAL_OK)
	{
		
	}
}


void I2C_get_data (uint8_t sensor_addres, uint8_t *buf, uint8_t size)
{
	
	extern uint8_t I2C_buffer[];
	buf[0] = I2C_buffer[0];
	buf[1] = I2C_buffer[1];
	//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	HAL_StatusTypeDef result = HAL_I2C_Master_Receive(&hi2c1, sensor_addres, I2C_buffer, size, 10000);
	//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
	
	if (result != HAL_OK)
	{
		
	}
}
