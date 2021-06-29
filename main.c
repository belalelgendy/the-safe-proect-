/*
 * main.c
 *
 *  Created on: 30 Dec 2020
 *      Author: HP
 */


#include "Main_Library.h"

u32 sorted_num(u8 arr[],u8 offset)
{
	u8 i=0,num=0;
	for (i=0;i<offset;i++)
	{
		num=num*10+arr[i];
	}
	return num;
}
void Rest_arr(u8 arr[],u8 offset)
{
	u8 i=0;
	for (i=0;i<offset;i++)
	{
		arr[i]=0;
	}

}

u8 array_equal(u8 *arr1,u8 *arr2)
{
	u8 i,flag=1;
	for (i=0;i<4;i++)
	{
		if (arr1[i] != arr2[i])
		{
			flag=0;
		}
	}
	return flag;
}

int main()
{
	/*
 20---Clear Screen    10--- (/)   11--(*)        12---- (-)    13---(+)    14---(=)
	 *
	 */

	u8 key=0,i,j;
	u8 passward[4]={0},confirm_passward[4]={0};

	while (1)
	{
		voidClear_LCD();
		LCD_String_xy(1,1,"Press_ON");
		LCD_String_xy(2,5,"TO start");
		while (keypad_GetPressedKey()!=20);
		voidClear_LCD();
		LCD_String_xy(1,1,"Enter_pass:");
		for (i=0;i<4;i++)
		{
			passward[i]=keypad_GetPressedKey();
			u8Diplay_NUMBER_XY(1,12,passward[i]);
		}
		LCD_String_xy(2,1,"Conf_pass:");
		for (i=0;i<4;i++)
		{
			confirm_passward[j]=keypad_GetPressedKey();
			u8Diplay_NUMBER_XY(2,11,passward[j]);
		}
		if (array_equal(passward,confirm_passward)==0)
		{
			voidClear_LCD();
			u8SEND_STRING("INVALID PASS");
		}
	}
	 }
