/*
 * LCD_Private.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Lenovo
 */

#ifndef SRC_HAL_LCD_LCD_PRIVATE_H_
#define SRC_HAL_LCD_LCD_PRIVATE_H_

/*#define LCD_u8_FUNCTION_SET      0b00111000
#define LCD_u8_CLEAR_DISPLAY     0b00000001
#define LCD_u8_DISPLAY_CONTROL   0b00001100
#define LCD_u8_ENTRY_MODE        0b00000010

#define LCD_u8_POSITION          0b10000000
#define LCD_u8_CGRAM             0b11000000

*/

#define LCD_clr 		 	    0x01
#define LCD_Home		 	    0x02
#define LCD_EnteryMode 		    0x01
#define LCD_DispOn              0x0C
#define LCD_DispOff        	    0x08
#define LCD_SetFunction4bit     0x20
#define LCD_SetFunc             0x80




#define lcd_DATAPORT          PORTB
#define lcd_CONTROLPORT       PORTA
#define lcd_RSPIN     		  13
//#define lcd_RWPIN
#define lcd_EPIN      		  15


#endif /* SRC_HAL_LCD_LCD_PRIVATE_H_ */
