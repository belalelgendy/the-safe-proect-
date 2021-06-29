/*
 * data_types.h
 *
 *  Created on: 28/10/2019
 *      Author: Belal_elgendy
 */
#ifndef BASIC_FUNCTION_H
#define BASIC_FUNCTION_H

#define Set_BIT(REG,BIT)             	 REG |=(1<<BIT)
#define Clear_BIT(REG,BIT)           	 REG &=~(1<<BIT)
#define Toggle_BIT(REG,BIT)          	 REG ^=(1<<BIT)
#define BIT_IS_SET(REG,BIT)            	 REG | (1<<BIT)
#define BIT_IS_Clear(REG,BIT)         	 REG & (~(1<<BIT))
#define ROT_RIGHT(REG,BIT,no_bits)       REG= ((REG>>BIT) | (REG<<(no_bits-BIT)))
#define ROT_LIFT(REG,BIT,no_bits)        REG= ((REG<<BIT) |(REG>>(no_bits-BIT)))
#define SET_PORT_HIGH(PORT)              (PORT|=0XFF)
#define SET_PORT_LOW(PORT)               (PORT&=0X00)
#define SET_Direction_OUTPUT(PORT)       PORT|=0XFF
#define SET_Direction_INPUT(PORT)        PORT&=0X00
#define GET_BIT(PORT,BIT)                ((PORT>>BIT) & 0X01)
#define Bit_Is_Set(REG,BIT) 			(REG & (1<<BIT))
#define Bit_Is_Clear(REG,BIT) 			(!(REG & (1<<BIT)))




#endif
