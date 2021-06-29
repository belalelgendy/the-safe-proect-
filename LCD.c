/*
 * LCD.c
 *
 *  Created on: 29 Oct 2019
 *      Author: HP
 */


#include"LCD.h"



u8 arr_charater[]={0x00, 0x00, 0x00, 0x01, 0x01, 0x1F, 0x00, 0x04, //Char0
		0x00, 0x00, 0x01, 0x09, 0x05, 0x02, 0x04, 0x08, //Char1
		0x00, 0x00, 0x01, 0x01, 0x05, 0x05, 0x07, 0x00, //Char2
		0x00, 0x00, 0x1F, 0x05, 0x07, 0x00, 0x00, 0x00, //Char3
		0x08, 0x04, 0x02, 0x1F, 0x00, 0x00, 0x00, 0x00, //Char4
		0x00, 0x00, 0x1F, 0x0A, 0x0E, 0x00, 0x00, 0x00, //Char5
		0x08, 0x04, 0x02, 0x1F, 0x00, 0x00, 0x00, 0x00, //Char6
		0x06, 0x02, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00};


void voidClear_LCD()
{

	u8SEND_COMMAND(Clear_DISPLAY);
	u8SEND_COMMAND (0x0C);

}
/*------------------------------------------------*/
void void_LCD_INIT(void)
{
	#if (LCD_BITMODE ==8)
		{
			void_write_channel(LCD_Read_Write_PIN,high);      // R/W_OUTPUT
			void_write_channel(LCD_Data_Command_PIN,high);    // RS_OUTPUT
			void_write_channel(LCD_ENABLE_PIN,high);    // RS_OUTPUT
			u8SEND_COMMAND (EIGHT_BIT_TWO_LINE );   /* Initialize 16X2 LCD in 8bit mode */
		}
	#elif(LCD_BITMODE ==4)
		{
			LCD_Direction_PINS=0xff;               // LCD_DATA_PINS OUTPUT
			u8SEND_COMMAND (Four_BIT_TWO_LINE);   /* Initialize 16X2 LCD in 8bit mode */
		}
	#endif
	/*-----------------------------------------------------------------------*/
	_delay_ms(20);
	voidClear_LCD();/* LCD power up time to get things ready, it should always >15ms */
	u8SEND_COMMAND (DISPLAY_ON_CURSOR_ON);								/* Display ON, Cursor OFF command */
	u8SEND_COMMAND (ENTRY_MODE);								/* Auto Increment cursor */
}
/*---------------------------------------------------*/
void voidENABLE_TRANSMIT(void)
{
	void_write_channel(LCD_ENABLE_PIN,high);
	_delay_us(1);
	void_write_channel(LCD_ENABLE_PIN,low);
	_delay_ms(3);
}
/*---------------------------------------------------*/
void u8SEND_COMMAND(u8 command)
{
	#if (LCD_BITMODE ==8)
		{
			void_write_channel(LCD_Read_Write_PIN,low);      // R/W_OUTPUT
			void_write_channel(LCD_Data_Command_PIN,low);    // RS_OUTPUT
			void_write_Port(LCD_PORT_DATA, command);
			voidENABLE_TRANSMIT();                                 // ENABLE TRANSMITT
		}
	#elif(LCD_BITMODE ==4)
		{
			LCD_PORT_DATA=(LCD_PORT_DATA &0x0F) | (command & 0xf0);
			Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
			Clear_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);     // SEND_COMMAND
			voidENABLE_TRANSMIT();                                 // ENABLE TRANSMITT
			_delay_us(20);
			LCD_PORT_DATA=((LCD_PORT_DATA & 0xF0) | (command<<4));
			Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
			Clear_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);     // SEND_COMMAND
			voidENABLE_TRANSMIT();
		}
	#endif

}
/*---------------------------------------------------*/
void u8SEND_DATA(u8 data)
{
	#if (LCD_BITMODE ==8)
		{
			void_write_channel(LCD_Read_Write_PIN,low);      // R/W_OUTPUT
			void_write_channel(LCD_Data_Command_PIN,high);    // RS_OUTPUT
			 void_write_Port(LCD_PORT_DATA, data);
		     voidENABLE_TRANSMIT();                                 // ENABLE TRANSMITT
		}
	#elif(LCD_BITMODE ==4)
		{
			LCD_PORT_DATA=(LCD_PORT_DATA & 0x0F) | (data & 0xf0);
			Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
			Set_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);       // SEND_DATA
			voidENABLE_TRANSMIT();
			_delay_us(200);
			LCD_PORT_DATA=((LCD_PORT_DATA &0xF0) | ((data<<4)));
			Clear_BIT(LCD_CONTROL_value,LCD_Read_Write_PIN);       // WRITE_MODE
			Set_BIT(LCD_CONTROL_value,LCD_Data_Command_PIN);       // SEND_DATA
			voidENABLE_TRANSMIT();
		}
	#endif
}
/*---------------------------------------------------*/
void u8SEND_STRING(u8* str)
{
	while (*str != '\0')
	{
		u8SEND_DATA(*str);
		str++;
	}
}
/*----------------------------------------------------------*/
void LCD_String_xy (u8 row, u8 pos, u8 *str)	/* Send string to LCD function */
{
	if (row == 1)
		u8SEND_COMMAND((pos & 0x0F)|0x80);				/* Command of first row and required position<16 */
	else if (row == 2)
		u8SEND_COMMAND((pos & 0x0F)|0xC0);				/* Command of Second row and required position<16 */
	else if (row == 3)
		u8SEND_COMMAND((pos & 0x0F)|0x90);				/* Command of Third row and required position<16 */
	else if (row == 4)
		u8SEND_COMMAND((pos & 0x0F)|0xD0);				/* Command of Fourth row and required position<16 */
	u8SEND_STRING(str);								/* Call LCD string function */
}
/*-------------------------------------------------------*/

void u8Diplay_NUMBER(u32 num)
{
	/*u8 arr[5];
	u8 i;
	for (i=1;i<5;i++)
	{
		arr[i]=num%10;
		num=num/10;
     }

		for (i=4;i>0;i--)
		{
			u8SEND_DATA(arr[i]+'0');
      	}*/
	char str[100];
	itoa(num,str,10);
	u8SEND_STRING(str);

}
/*********************************************************-*/
void u8Diplay_NUMBER_XY(u8 row, u8 pos,u32 num)
{
	u8 str[10];
	itoa(num,str,10);
	LCD_String_xy(row,pos,str);
}
/*------------------------------------------------------------------*/
void void_writeCustom_char()
{
u8 i;
	u8SEND_COMMAND(0x48);   // Set CGRAM Address
	u8SEND_COMMAND(0x00);   // Set CGRAM Address
	  for (i = 0; i <= 63 ; i++)
		  u8SEND_DATA(arr_charater[i]);

}
