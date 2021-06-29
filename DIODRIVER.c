/*
 * DIODRIVER.C
 *
 *  Created on: 12 Dec 2020
 *      Author: HP
 */


#include "DIO_REG.h"

void void_initDIO(void)
{
	u8 i;
			for (i=0;i<no_pins;i++)
			{
				/*----------------OUTPUT------------------*/
				if (arr[i].config==OUTPUT)
				{
					 if (arr[i].PIN >=0 && arr[i].PIN<=7)
						 Set_BIT(PORTA_in_out ,arr[i].PIN);
					 else if (arr[i].PIN >=8 && arr[i].PIN<=15)
						 Set_BIT(PORTB_in_out ,arr[i].PIN-8);
					 else if (arr[i].PIN >=16 && arr[i].PIN<=23)
						 Set_BIT(PORTC_in_out ,arr[i].PIN-16);
					 else if (arr[i].PIN >=24 && arr[i].PIN<=31)
						 Set_BIT(PORTD_in_out ,arr[i].PIN-24);
				}
				/*----------------INPUT------------------*/
				else if (arr[i].config==INPUT_Floating)
				{
					 if (arr[i].PIN >=0 && arr[i].PIN<=7)
					 {
						 Clear_BIT(PORTA_in_out ,arr[i].PIN);
						 Clear_BIT(PORTA_high_low,arr[i].PIN);
					 }
					 else if (arr[i].PIN >=8 && arr[i].PIN<=15)
					 {
						 Clear_BIT(PORTB_in_out ,arr[i].PIN-8);
						 Clear_BIT(PORTB_high_low,arr[i].PIN-8);
					 }
					 else if (arr[i].PIN >=16 && arr[i].PIN<=23)
						 {
						 Clear_BIT(PORTC_in_out ,(arr[i].PIN-16));
						 Clear_BIT(PORTC_high_low,(arr[i].PIN-16));
						 }
					 else if (arr[i].PIN >=24 && (arr[i].PIN<=31))
						 {
						 Clear_BIT(PORTD_in_out ,(arr[i].PIN-24));
						 Clear_BIT(PORTD_high_low,(arr[i].PIN-24));
						 }
				}
				/*------------Pull_Up---------------*/
				else if (arr[i].config==PULL_UP)
				{
					 if (arr[i].PIN >=0 && arr[i].PIN<=7)
					 {
						 Clear_BIT(PORTA_in_out ,arr[i].PIN);
						 Set_BIT(PORTA_high_low,arr[i].PIN);
					 }
					 else if (arr[i].PIN >=8 && arr[i].PIN<=15)
					 {
						 Clear_BIT(PORTB_in_out ,arr[i].PIN-8);
						 Set_BIT(PORTB_high_low,arr[i].PIN-8);
					 }
					 else if (arr[i].PIN >=16 && arr[i].PIN<=23)
						 {
						 Clear_BIT(PORTC_in_out ,arr[i].PIN-16);
						 Set_BIT(PORTC_high_low,arr[i].PIN-16);
						 }
					 else if (arr[i].PIN >=24 && arr[i].PIN<=31)
						 {
						 Clear_BIT(PORTD_in_out ,arr[i].PIN-24);
						 Set_BIT(PORTD_high_low,arr[i].PIN-24);
						 }
				}

			}
}

/*----------------------------------------------------------*/
void void_write_channel(DIO_enum_channel channel,DIO_PinValue value)
{

     if (value==high)
        {
    	 /*-------------PORTA--------*/
    	  if (channel >=0 && channel<=7)
    	 	  Set_BIT(PORTA_high_low,channel);
    	  /*-------------PORTB--------*/
    	  else if (channel >=8 && channel<=15)
    		  Set_BIT(PORTB_high_low,channel-8);
    	  /*-------------PORTC--------*/
    	  else if (channel >=16 && channel<=23)
    		  Set_BIT(PORTC_high_low,channel-16);
    	  /*-------------PORTD--------*/
    	  else if (channel >=24 && channel<=31)
    		  Set_BIT(PORTD_high_low,channel-24);
        }

     else if (value==low)
     {
         {
       	 /*-------------PORTA--------*/
       	  if (channel >=0 && channel<=7)
       		Clear_BIT(PORTA_high_low,channel);
       	  /*-------------PORTB--------*/
       	  else if (channel >=8 && channel<=15)
       		Clear_BIT(PORTB_high_low,channel-8);
       	  /*-------------PORTC--------*/
       	  else if (channel >=16 && channel<=23)
       		Clear_BIT(PORTC_high_low,channel-16);
       	  /*-------------PORTD--------*/
       	  else if (channel >=24 && channel<=31)
       		Clear_BIT(PORTD_high_low,channel-24);
           }
     }

}

/*---------------------------------------------------*/
u8 u8_Read_channel(u8 channel)
{
	u8 data;
    	 /*-------------PORTA--------*/
    	  if (channel >=0 && channel<=7)
    		  data=GET_BIT(PORTA_ReadData,channel);
    	  /*-------------PORTB--------*/
    	  else if (channel >=8 && channel<=15)
    		  data=GET_BIT(PORTA_ReadData,channel-8);
    	  /*-------------PORTC--------*/
    	  else if (channel >=16 && channel<=23)
    		  data=GET_BIT(PORTA_ReadData,channel-16);
    	  /*-------------PORTD--------*/
    	  else if (channel >=24 && channel<=31)
    		  data=GET_BIT(PORTA_ReadData,channel-24);

    	  return data;
}

/*-----------------------------------------*/
void void_write_Port(u8 port, u8 value)
{
	    	 /*-------------PORTA--------*/
	    	  if (port ==PORTA)
	    	 	  PORTA_high_low=value;
	    	  /*-------------PORTB--------*/
	    	  else if (port ==PORTB)
	    		  PORTB_high_low=value;
	    	  /*-------------PORTC--------*/
	    	  else if (port ==PORTC)
	    		  PORTC_high_low=value;
	    	  /*-------------PORTD--------*/
	    	  else if (port ==PORTD)
	   		     PORTD_high_low=value;
}

/*----------------------------------------------*/
u8 void_Read_Port(u8 port)
{
	u8 data;
	    	 /*-------------PORTA--------*/
	    	  if (port ==  0)
	    		  data=PORTA_ReadData;
	    	  /*-------------PORTB--------*/
	    	  else if (port == 1)
	    		  data=PORTB_ReadData;
	    	  /*-------------PORTC--------*/
	    	  else if (port == 2)
	    		  data=PORTC_ReadData;
	    	  /*-------------PORTD--------*/
	    	  else if (port == 3)
	    		  data=PORTD_ReadData;
	   return data;
}























