/*
 * uart_communication.c
 *
 *  Created on: Nov 27, 2023
 *      Author: MY GEAR
 */


#include "global.h"

enum CommunicationStatus {
	WAIT_START,
	EXEC_REQ,
	WAIT_END
};

enum CommunicationStatus communication_state = WAIT_START;

void clear_buffer(){
	memset(buffer, 0, MAX_BUFFER_SIZE);
	index_buffer = 0;
}

void uart_communiation_fsm() {
	switch (communication_state) {
		case WAIT_START:
			if (strcmp((char *)command_data, "RST#") == 0) {
				communication_state = EXEC_REQ;
				uint32_t ADC_value = 0;
				HAL_ADC_Start(&hadc1);
				ADC_value =  HAL_ADC_GetValue(&hadc1);
				sprintf((char *)res_syntax, "!ADC=%d# \r",ADC_value);
			}
			break;
		case EXEC_REQ:
			HAL_UART_Transmit(&huart2, res_syntax, sizeof(res_syntax), 1000);
			communication_state = WAIT_END;
			setTimer1(3000);
			break;
		case WAIT_END:
			if (strcmp((char *)command_data, "OK#") == 0) {
				communication_state = WAIT_START;
				memset(command_data, 0, MAX_BUFFER_SIZE);
			}
			if (timer1_flag == 1) {
				communication_state = EXEC_REQ;
			}
			break;
		default:
			break;
	}
}
