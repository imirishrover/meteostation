
#include "AT_init.h"

extern uint8_t buf_usart[40];


extern UART_HandleTypeDef huart3;


void AT_AP_mode_init(void){
	uint8_t msg[10] = "init";
	uint8_t msg1[15] = "wait please";
	uint8_t msg2[15] = "init complete";
	
	//HAL_UART_Receive_IT(&huart3, (uint8_t*)buf_usart,40);
	
	HAL_Delay(500);
	AT_check_status();
	HAL_UART_Transmit(&huart3, AT.AT, sizeof(AT.AT),100);
	AT_check_status();
	HAL_UART_Transmit(&huart3, AT.AT, sizeof(AT.AT),100);
	AT_check_status();
	
	HAL_UART_Transmit(&huart3, AT.wifi_set_connection_AT, sizeof(AT.wifi_set_connection_AT),100);
	AT_check_status();
	HAL_UART_Transmit(&huart3, AT.wifi_create_own_AT, sizeof(AT.wifi_create_own_AT), 100);
	AT_check_status();
	HAL_UART_Transmit(&huart3, AT.AT, sizeof(AT.reset),100);
	HAL_Delay(3000);
	HAL_UART_Transmit(&huart3, AT.AT, sizeof(AT.AT),100);
	AT_check_status();
		//HAL_UART_Transmit(&huart3, msg2, 13,100);
	
	

}
	

void AT_check_status(void){
	uint8_t ref[1] = {"O"};
	uint8_t p[4] = "done";
	HAL_UART_Receive(&huart3, (uint8_t*)buf_usart,40, 2000);
	
	if(buf_usart[0] == ref[0]){
			//HAL_UART_Transmit(&huart3, p, 4, 100);
			buf_usart[0] = 0;
		buf_usart[1] = 0;
		buf_usart[2] = 0;
		buf_usart[3] = 0;
		buf_usart[4] = 0;
		buf_usart[5] = 0;
		buf_usart[6] = 0;
		buf_usart[7] = 0;
		buf_usart[8] = 0;
		buf_usart[9] = 0;
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
	}
}	