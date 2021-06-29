/*
 * keypad.c
 *
 *  Created on: 25 Dec 2020
 *      Author: HP
 */

#include "keypad.h"
/*
 *   20---Clear Screen    10--- (/)   11--(*)        12---- (-)    13---(+)    14---(=)
 *
 */
static u8 array_number[4][4]={{7,4,1,20},{8,5,2,0},{9,6,3,14},{10,11,12,13}};


void keypad_InitKeyPad(void)
{
	void_write_Port(PORT_KEYPAD,0b11101111);
}

u8 keypad_GetPressedKey(void)
{
	u8 col,row;
	u8 button;

	//void_write_channel(array_config[row+4],~(1<<(row+4));
 while (1)
 {
	for (row=0;row<N_ROW;row++)
	{
		PORTD_high_low = ~(0b00010000 << row);
		for (col=0;col<N_COL;col++)
		{

		   if(GET_BIT(PORTD_ReadData,col)==0)
		   {
			   _delay_ms(40);
			   return  button=array_number[row][col];

		   }
		}
	}


 }

}






