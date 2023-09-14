/*
 * LCD_Program.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Lenovo
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/delay.h"


#include "../../MCAL/MRCC/MRCC_Interface.h"
#include "../../MCAL/MGPIO/MGPIO_Interface.h"
#include "../../MCAL/MSTK/MSYSTICK_Interface.h"

#include "LCD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"




//init
void LCD_init(){
//rs=0 and rw=0 and latch ale hwa send 8 bits w b3den en high ,dlay 2ms, b3dha en low ,2ms

	MGPIO_voidSetPinMode(lcd_DATAPORT,0,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(lcd_DATAPORT,1,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(lcd_DATAPORT,2,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(lcd_DATAPORT,3,GPIO_OUTPUT);

	MGPIO_voidSetPinMode(lcd_CONTROLPORT,lcd_EPIN,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(lcd_CONTROLPORT,lcd_RSPIN,GPIO_OUTPUT);


	_delay_ms(50);

		LCD_SendCommand(0x02);
		LCD_SendCommand(0x28);
		LCD_SendCommand(0x0c);
		LCD_SendCommand(0x01);
		LCD_SendCommand(0x06);
		LCD_SendCommand(0x80);
}

//char
  void LCD_sendChar(u8 Data){


	       /* Set RS to high */
	  MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_RSPIN,1);

	  MGPIO_voidSetPinVal(lcd_DATAPORT,0,GET_BIT(Data,4));
	  MGPIO_voidSetPinVal(lcd_DATAPORT,1,GET_BIT(Data,5));
	  MGPIO_voidSetPinVal(lcd_DATAPORT,2,GET_BIT(Data,6));
	  MGPIO_voidSetPinVal(lcd_DATAPORT,3,GET_BIT(Data,7));

		    //latch
	  MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_EPIN,1);
			_delay_ms(2);
			MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_EPIN,0);
			_delay_ms(2);


			MGPIO_voidSetPinVal(lcd_DATAPORT,0,GET_BIT(Data,0));
			MGPIO_voidSetPinVal(lcd_DATAPORT,1,GET_BIT(Data,1));
			MGPIO_voidSetPinVal(lcd_DATAPORT,2,GET_BIT(Data,2));
			MGPIO_voidSetPinVal(lcd_DATAPORT,3,GET_BIT(Data,3));

		    //latch
			MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_EPIN, 1);
		   _delay_ms(2);
		   MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_EPIN, 0);
			_delay_ms(2);

}

//send command
void LCD_SendCommand(u8 command){
	MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_RSPIN,0);
	_delay_ms(20);

	MGPIO_voidSetPinVal(lcd_DATAPORT,0,GET_BIT(command,4));
	MGPIO_voidSetPinVal(lcd_DATAPORT,1,GET_BIT(command,5));
	MGPIO_voidSetPinVal(lcd_DATAPORT,2,GET_BIT(command,6));
	MGPIO_voidSetPinVal(lcd_DATAPORT,3,GET_BIT(command,7));

    //latch
	MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_EPIN,1);
	_delay_ms(2);
	MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_EPIN,0);
	_delay_ms(2);

	MGPIO_voidSetPinVal(lcd_DATAPORT,0,GET_BIT(command,0));
	MGPIO_voidSetPinVal(lcd_DATAPORT,1,GET_BIT(command,1));
	MGPIO_voidSetPinVal(lcd_DATAPORT,2,GET_BIT(command,2));
	MGPIO_voidSetPinVal(lcd_DATAPORT,3,GET_BIT(command,3));


    //latch
	MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_EPIN,1);
	_delay_ms(2);
	MGPIO_voidSetPinVal(lcd_CONTROLPORT,lcd_EPIN,0);
	_delay_ms(2);

}

void LCD_SendString (u8 *str){
	u8 i;


	for(i=0;i>str[i];i++){
		LCD_sendChar(str[i]);
	}

}

void GoToXY(u8 x,u8 y){
	u8 address;
	if(y<2 && x<16){
		address=y*0x40+x;
		address=SET_BIT(address,7);
		LCD_SendCommand(address);

	}
}

void LCD_voidWriteNumber(s32 num)
{
	s8 j,i=0;
	u8 str[16];
	if(num==0)
	{
		LCD_sendChar('0');
	}
	else if(num<0)
	{
		LCD_sendChar('-');
		num=num*-1;
	}
	while(num)
	{
		str[i]=num%10+'0';
		num=num/10;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
		LCD_sendChar(str[j]);
	}
}
