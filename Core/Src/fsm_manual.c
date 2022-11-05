/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2022
 *      Author: ASUS
 */

#include "fsm_manual.h"
#include "7segment_led.h"


void fsm_simple_buttons_run(){

	switch(status){

	case AUTO:		//Tu dong dem lui

		if (timer3_flag == 1){
			setTimer3(1000);
			counter--;
			if (counter < 0) counter = 0;	//Dung lai khi bang 0
		}

		updateClockBuffer(counter);


		if (isButton2Pressed()){
			status = MAN_INC;
			counter = counter + 1;
			if (counter > 9) counter = 0;
			setTimer2(10000);				//setTimer cho time-out
		}
		if (isButton3Pressed()){
			status = MAN_DEC;
			counter = counter - 1;
			if (counter < 0) counter = 9;
			setTimer2(10000);				//setTimer cho time-out
		}
		if (isButton1Pressed()){
			status = MAN_RESET;
			counter = 0;
			setTimer2(10000);				//setTimer cho time-out
		}


		break;

	case MAN_INC:		//Trang thai nhan INC, tang counter

		if (isButton1Pressed()){
			status = MAN_RESET;
			setTimer2(10000);					//setTimer cho time-out
			counter = 0;
		}
		if (isButton2Pressed()){
			status = MAN_INC;
			setTimer2(10000);					//setTimer cho time-out
			counter = counter + 1;
			if (counter > 9) counter = 0;
		}
		if (isButton3Pressed()){
			status = MAN_DEC;
			setTimer2(10000);					//setTimer cho time-out
			counter = counter - 1;
			if (counter < 0) counter = 9;
		}

		updateClockBuffer(counter);

		if (timer2_flag == 1){					//Time-out quay ve AUTO dem nguoc
			setTimer3(1000);
			status = AUTO;
		}
		break;



	case MAN_DEC:		//Trang thai nhan DEC, giam counter

		if (isButton1Pressed()){
			status = MAN_RESET;
			setTimer2(10000);					////setTimer cho time-out
			counter = 0;
		}
		if (isButton2Pressed()){
			status = MAN_INC;
			setTimer2(10000);					//setTimer cho time-out
			counter = counter + 1;
			if (counter > 9) counter = 0;
		}
		if (isButton3Pressed()){
			status = MAN_DEC;
			setTimer2(10000);				//setTimer cho time-out
			counter = counter - 1;
			if (counter < 0) counter = 9;
		}

		updateClockBuffer(counter);

		if (timer2_flag == 1){		//Time-out quay ve AUTO dem nguoc
			setTimer3(1000);
			status = AUTO;
		}
		break;


	case MAN_RESET:				//trang thai reset counter = 0;

		if (isButton1Pressed()){
			status = MAN_RESET;
			setTimer2(10000);		//setTimer cho time-out
			counter = 0;
		}
		if (isButton2Pressed()){
			status = MAN_INC;
			setTimer2(10000);		//setTimer cho time-out
			counter = counter + 1;
			if (counter > 9) counter = 0;
		}
		if (isButton3Pressed()){
			status = MAN_DEC;
			setTimer2(10000);		//setTimer cho time-out
			counter = counter - 1;
			if (counter < 0) counter = 9;
		}

		updateClockBuffer(counter);

		//Time-out quay ve AUTO dem nguoc
		if (timer2_flag == 1){
			setTimer3(1000);
			status = AUTO;
		}
		break;

	default:
		break;
	}

}










