/*
 * keypad.h
 *
 *  Created on: 25 Dec 2020
 *      Author: HP
 */

#include "Main_Library.h"



#define PORT_KEYPAD    PORTD

#define N_COL   4
#define N_ROW   4

extern u8 array_config[];

void keypad_InitKeyPad(void);
u8 keypad_GetPressedKey(void);


