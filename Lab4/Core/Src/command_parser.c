/*
 * command_parser.c
 *
 *  Created on: Nov 27, 2023
 *      Author: MY GEAR
 */


#include "global.h"

enum CommandStatus {
    IDLING,
    RECEIVING
};

enum CommandStatus parser_state = IDLING;

void command_parser_fsm() {
    switch (parser_state) {
        case IDLING:
            if (temp == '!') {
                parser_state = RECEIVING;
            }
            clear_buffer();
            break;
        case RECEIVING:
            if(temp == '!'){
                clear_buffer();
            }
            if (temp == '#') {
                parser_state = IDLING;
                memcpy(command_data, buffer, MAX_BUFFER_SIZE);
                char str[3];
                HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"),1000);
            }
            break;
        default:
            break;
    }
}
