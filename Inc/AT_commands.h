
#ifndef __AT_COMMANDS_H
#define __AT_COMMANDS_H


#include "stm32f4xx_hal.h"
#include "main.h"



typedef struct{
	char *AT[10];
	char *check_version[10];
	char *check_baudrate_pool[50];
	char *set_baudrate_115200[30];
	char *wifi_set_connection_STA[15];
	char *wifi_set_connection_AT[15];
	char *wifi_set_connection_BOTH[15];
	char *check_wifi_spots[10];
	char *wifi_connect[40];
	char *check_ip[10];
	char *wifi_disconnect[10];
	char *wifi_create_own_AT[50];
	char *reset[10];
} ESP8266_old;


struct commands{
	uint8_t AT[2], check_version[10],check_baudrate_pool[50], set_baudrate_115200[30], wifi_set_connection_STA[15], 
	wifi_set_connection_AT[15], wifi_set_connection_BOTH[15], check_wifi_spots[10], wifi_connect[40], check_ip[10],
	wifi_disconnect[10], wifi_create_own_AT[50], reset[10];
	
};




void AT_command_send(uint8_t *command[]);
#endif /* __AT_COMMANDS_H*/


