/*
 * DIO_REG.h
 *
 *  Created on: 11 Dec 2020
 *      Author: HP
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

#include "Main_Library.h"
//#include "basic_function.h"

/*-----------------PORT Direction---------------------*/
#define PORTA_in_out 	 	 *((volatile u8*)0x3A)
#define PORTB_in_out  	 	 *((volatile u8*)0x37)
#define PORTC_in_out  		 *((volatile u8*)0x34)
#define PORTD_in_out   		 *((volatile u8*)0x31)
/*----------------PORT_DATA------------------------*/
#define PORTA_high_low   	 *((volatile u8*)0x3B)
#define PORTB_high_low    	 *((volatile u8*)0x38)
#define PORTC_high_low  	 *((volatile u8*)0x35)
#define PORTD_high_low    	 *((volatile u8*)0x32)
/*-----------------PORT_Read------------------------------*/
#define PORTA_ReadData  	 *((volatile u8*)0x39)
#define PORTB_ReadData   	 *((volatile u8*)0x36)
#define PORTC_ReadData   	 *((volatile u8*)0x33)
#define PORTD_ReadData   	 *((volatile u8*)0x30)



/*
 * config=0 AS OUTPUT  config=1 AS INPUT   config=2 AS PULL_UP
 */






/*----------------*/

/*---------------------------------------------------------*/
/*
 *   from 0 to 7   PORTA     8 to 15  PORTB     16 TO 23 PORTC  24 TO 31 PORTD
 */
typedef enum{
	/*-----PORTA----*/
	PORTA0=0,PORTA1,PORTA2,PORTA3,PORTA4,PORTA5,PORTA6,PORTA7,
	/*------PORTB---*/
	PORTB0,PORTB1,PORTB2,PORTB3,PORTB4,PORTB5,PORTB6,PORTB7,
	/*----PORTC-----*/
	PORTC0,PORTC1,PORTC2,PORTC3,PORTC4,PORTC5,PORTC6,PORTC7,
	/*----PORTD-----*/
	PORTD0,PORTD1,PORTD2,PORTD3,PORTD4,PORTD5,PORTD6,PORTD7
}DIO_enum_channel;

typedef enum{
	PORTA=0,PORTB,PORTC,PORTD
}DIO_enum_Port;

typedef enum{
	OUTPUT=0,s,PULL_UP,INPUT_Floating
}Status;


typedef enum{input=0,output=1}DIO_Direct;
typedef enum {high=1 , low=0}DIO_PinValue;
typedef enum {high_port=0xff , low_port=0x00}DIO_PortValue;

typedef struct{
	Status config;
	DIO_enum_channel PIN;
}Config_PINS;

#define no_pins         20
extern Config_PINS arr[no_pins];
/// 0=output  1= input  2= pull_up


/*------------Function Declaration------------*/
 void void_initDIO(void);
 void void_write_channel(u8 channel, u8 value);
 u8 u8_Read_channel(u8 channel);
 void void_write_Port(u8 port, u8 value);
 u8 void_Read_Port(u8 port);

#endif /* DIO_REG_H_ */
