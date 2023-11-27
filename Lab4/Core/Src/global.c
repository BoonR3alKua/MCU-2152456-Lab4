/*
 * global.c
 *
 *  Created on: Nov 27, 2023
 *      Author: MY GEAR
 */

#include "global.h"

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t command_data[MAX_BUFFER_SIZE];
uint8_t res_syntax[MAX_BUFFER_SIZE];
