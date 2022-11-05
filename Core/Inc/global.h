/*
 * global.h
 *
 *  Created on: Oct 28, 2022
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "button.h"
#include "Software_Timer.h"

#define AUTO			1
#define MAN_INC			2
#define MAN_DEC			3
#define MAN_RESET		4

extern int status; 		// Khai bao lai trong global.c
extern int counter;


#endif /* INC_GLOBAL_H_ */
