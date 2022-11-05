/*
 * button.c
 *
 *  Created on: Oct 28, 2022
 *      Author: ASUS
 */

#include "button.h"


//----------------------------------BEGIN BUTTON1-------------------------------------

int button1_flag = 0;
//KeyReg trong qua trinh rung
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

//KeyReg cua qua trinh on dinh truoc day
int KeyReg3 = NORMAL_STATE;


//Thoi gian cua nhan de'
int TimerforKeyPRESS1 = 300;



int isButton1Pressed(){
	if (button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	else return 0;
}
//
void getKeyInput1(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);


	if (KeyReg0 == KeyReg1 && KeyReg1 == KeyReg2){

		if (KeyReg2 != KeyReg3){					//Nhan doi trang thai
			KeyReg3 = KeyReg2;
			if (KeyReg2 == PRESSED_STATE){			//Neu dang nhan
				button1_flag = 1;
			}
			else{									//Luc truoc thi nhan, bay gio dang tha ra
				button1_flag = 0;
				TimerforKeyPRESS1 = 300;				//khi release thi RESET nhan de ve 3 giay (100 = 1giay)
													//neu nhan lai trong 1 giay thi tinh la nhan de
			}

		}
		else{										//Nhan de
			if(KeyReg2 == PRESSED_STATE){			// Neu dang nhan de
				TimerforKeyPRESS1--;
				if (TimerforKeyPRESS1 == 0){			// Nhan de thanh cong
					TimerforKeyPRESS1 = 100;			// Moi 1 giay nhan de thi RETURN button_flag 1 lan
					button1_flag = 1;
				}
			}
		}


	}

}
///-------------------------------END BUTTON 1-----------------------



///////------------------------BEGIN BUTTON2-------------------------------
int button2_flag = 0;


//KeyReg trong qua trinh rung
int KeyReg02 = NORMAL_STATE;
int KeyReg12 = NORMAL_STATE;
int KeyReg22 = NORMAL_STATE;

//KeyReg cua qua trinh on dinh truoc day
int KeyReg32 = NORMAL_STATE;


//Thoi gian cua nhan de'
int TimerforKeyPRESS2 = 300;



int isButton2Pressed(){
	if (button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	else return 0;
}
//
void getKeyInput2(){
	KeyReg02 = KeyReg12;
	KeyReg12 = KeyReg22;
	KeyReg22 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);


	if (KeyReg02 == KeyReg12 && KeyReg12 == KeyReg22){

		if (KeyReg22 != KeyReg32){					//Nhan doi trang thai
			KeyReg32 = KeyReg22;
			if (KeyReg22 == PRESSED_STATE){			//Neu dang nhan
				button2_flag = 1;
			}
			else{									//Luc truoc thi nhan, bay gio dang tha ra
				button2_flag = 0;
				TimerforKeyPRESS2 = 300;				//khi release thi RESET nhan de 1 giay
													//neu nhan lai trong 1 giay thi tinh la nhan de
			}

		}
		else{										//Nhan de
			if(KeyReg22 == PRESSED_STATE){			// Neu dang nhan de
				TimerforKeyPRESS2--;
				if (TimerforKeyPRESS2 == 0){			// Nhan de thanh cong
					TimerforKeyPRESS2 = 100;			// Moi 50ms nhan de thi RETURN button_flag 1 lan
					button2_flag = 1;
				}
			}
		}


	}

}

//---------------------------END BUTTON 2---------------------------------------




///////////////////-----------BEGIN BUTTON 3-------------------------------------------------


int button3_flag = 0;

//KeyReg trong qua trinh rung
int KeyReg03 = NORMAL_STATE;
int KeyReg13 = NORMAL_STATE;
int KeyReg23 = NORMAL_STATE;

//KeyReg cua qua trinh on dinh truoc day
int KeyReg33 = NORMAL_STATE;


//Thoi gian cua nhan de'
int TimerforKeyPRESS3 = 300;



int isButton3Pressed(){
	if (button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	else return 0;
}
//
void getKeyInput3(){
	KeyReg03 = KeyReg13;
	KeyReg13 = KeyReg23;
	KeyReg23 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);


	if (KeyReg03 == KeyReg13 && KeyReg13 == KeyReg23){

		if (KeyReg23 != KeyReg33){					//Nhan doi trang thai
			KeyReg33 = KeyReg23;
			if (KeyReg23 == PRESSED_STATE){			//Neu dang nhan
				button3_flag = 1;
			}
			else{									//Luc truoc thi nhan, bay gio dang tha ra
				button3_flag = 0;
				TimerforKeyPRESS3 = 300;				//khi release thi RESET nhan de 3 giay
													//neu nhan lai trong 1 giay thi tinh la nhan de
			}

		}
		else{										//Nhan de
			if(KeyReg33 == PRESSED_STATE){			// Neu dang nhan de
				TimerforKeyPRESS3--;
				if (TimerforKeyPRESS3 == 0){			// Nhan de thanh cong
					TimerforKeyPRESS3 = 100;			// Moi 1 giay nhan de thi RETURN button_flag 1 lan
					button3_flag = 1;
				}
			}
		}


	}

}

//------------------------------END BUTTON 3--------------------------------------










