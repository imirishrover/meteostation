
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H
#include "main.h"
#include "stm32f4xx_hal.h"

void AT_AP_mode_init(void);
void AT_check_status(void);

typedef struct {
	uint8_t AT[10];
	uint8_t check_version[10];
	uint8_t check_baudrate_pool[50];
	uint8_t set_baudrate_115200[30];
	uint8_t wifi_set_connection_STA[15];
	uint8_t wifi_set_connection_AT[19];
	uint8_t wifi_set_connection_BOTH[15];
	uint8_t check_wifi_spots[10];
	uint8_t wifi_connect[40];
	uint8_t check_ip[10];
	uint8_t wifi_disconnect[10];
	uint8_t wifi_create_own_AT[39];
	uint8_t reset[8];
	
}commands;




commands AT = { 
				.AT = "AT\r\n",
				.check_version = "AT+GMR",
				.check_baudrate_pool = "AT+CIOBAUD=?",
				.set_baudrate_115200 = "AT+CIOBAUD=115200",
				.wifi_set_connection_STA = "AT+CWMODE=1",
				.wifi_set_connection_AT = "AT+CWMODE_DEF=2\r\n",
				.wifi_set_connection_BOTH = "AT+CWMODE=3",
				.check_wifi_spots = "AT+CWLAP",
				.wifi_connect = "AT+CWJAP=\"Test\",\"password\"",
				.check_ip = "AT+CIFSR",
				.wifi_disconnect = "AT+CWQAP",
				.wifi_create_own_AT = "AT+CWSAP_DEF=\"toch9\",\"7654321399\",5,3",
				.reset = "AT+RST\n\r"
				
				
			
};


char *array[20] = {"AT", "AT+GMR"};

#endif /* __STM32F4xx_IT_H */


