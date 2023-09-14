/*
 * LCD_Interface.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Lenovo
 */

#ifndef SRC_HAL_LCD_LCD_INTERFACE_H_
#define SRC_HAL_LCD_LCD_INTERFACE_H_

void	_delay_ms(u32 ticks);


//init
void LCD_init();

//char
void LCD_sendChar(u8 Data);

//send command
void LCD_SendCommand(u8 command);

//Send String
void LCD_SendString (u8 *str);

void GoToXY(u8 x,u8 y);

void LCD_voidWriteNumber(s32 num);

#endif /* SRC_HAL_LCD_LCD_INTERFACE_H_ */
