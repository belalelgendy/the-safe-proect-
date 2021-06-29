/*
 * LCD.h
 *
 *  Created on: 29 Oct 2019
 *      Author: Belal_Elgendy
 */



#ifndef LCD_H_
#define LCD_H_

#include"Main_Library.h"

/*--------------------------LCD CONFIGURATION-----------------------------------*/
#define LCD_PORT_DATA             	      PORTC
#define LCD_ENABLE_PIN         			  PORTA0           //PORTD_PIN0
#define LCD_Read_Write_PIN     			  PORTA1           //PORTD_PIN1
#define LCD_Data_Command_PIN     		  PORTA2           //PORTD_PIN2
#define LCD_BITMODE                         8

/*------------------------------LCD Commands------------------------------------*/
#define Clear_DISPLAY                      0X01
#define CURSOR_FIRSTLINE                   0X80
#define CURSOR_SECONDLINE                  0XC0
#define ENTRY_MODE                         0X06
#define CURSOR_FIRSTLINE                   0X80
#define DISPLAY_OFF_CURSOR_OFF             0X08
#define DISPLAY_ON_CURSOR_ON               0X0E
#define DISPLAY_ON_CURSOR_BLINKING         0X0F
#define SHIFT_LIFT_DISPLAY                 0X18
#define EIGHT_BIT_TWO_LINE                 0X38
#define Four_BIT_TWO_LINE                  0X28

/*-------------------------------FUNCTION--------------------------------------*/
void void_LCD_INIT(void);
void voidClear_LCD();
void voidENABLE_TRANSMIT(void);
void u8SEND_COMMAND(u8 command);
void u8SEND_DATA(u8 data);
void u8SEND_STRING(u8* str);
void LCD_String_xy (u8 row, u8 pos, u8 *str);
void u8Diplay_NUMBER(u32 num);
void u8Diplay_NUMBER_XY(u8 row, u8 pos,u32 num);
void void_writeCustom_char();
/*------------------------------------------------------------------------------*/
#endif /* LCD_H_ */
