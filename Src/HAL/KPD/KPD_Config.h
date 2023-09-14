/*
 * KPD_Config.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Lenovo
 */

#ifndef SRC_HAL_KPD_KPD_CONFIG_H_
#define SRC_HAL_KPD_KPD_CONFIG_H_

#define KPD_Port              PORTA
#define KPD_COLUMN0_PIN       GPIO_PIN0
#define KPD_COLUMN1_PIN       GPIO_PIN1
#define KPD_COLUMN2_PIN       GPIO_PIN2
#define KPD_COLUMN3_PIN       GPIO_PIN3

#define KPD_ROW0_PIN       GPIO_PIN4
#define KPD_ROW1_PIN       GPIO_PIN5
#define KPD_ROW2_PIN       GPIO_PIN6
#define KPD_ROW3_PIN       GPIO_PIN7


#define KPD_No_Key_Pressed  0xff


#define KPD_Arr_Value         {{'7','8','9','+'},   \
				  	           {'4','5','6','-'},   \
				  	           {'1','2','3','*'},   \
				  	           {'=','0','/','D'}}

#endif /* SRC_HAL_KPD_KPD_CONFIG_H_ */
