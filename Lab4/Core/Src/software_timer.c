/*
 * software_timer.c
 *
 *  Created on: Nov 27, 2023
 *      Author: MY GEAR
 */


int timer1_counter = 0;
int timer1_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;

#define TICK 10;

void setTimer1(int duration){
	timer1_counter = duration/TICK;
	timer1_flag = 0;
}

void clearTimer1(){
	timer1_counter = 0;
	timer1_flag = 0;
}

void timerRun(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
}
