/*
 * KPD_Program.c
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

#include "KPD_Config.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"



	const u8 KPD_Au8Rows[ROW_NUMBER]={KPD_ROW0_PIN ,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	const u8 KPD_Au8Cols[COLUMN_NUMBER]={KPD_COLUMN0_PIN ,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	const u8 KPD_Au8Keys[ROW_NUMBER][COLUMN_NUMBER]= KPD_Arr_Value;

	void KPD_voidInit(void){

		GPIO_Config_t KPD_COLUMN0;
		KPD_COLUMN0.mode = GPIO_INPUT;
		KPD_COLUMN0.speed = GPIO_LOW_SPEED;
		KPD_COLUMN0.pupdState = GPIO_PULL_UP;
		MGPIO_voidInit(KPD_Port,KPD_COLUMN0_PIN,&KPD_COLUMN0);

		GPIO_Config_t KPD_COLUMN1;
		KPD_COLUMN1.mode = GPIO_INPUT;
		KPD_COLUMN1.speed = GPIO_LOW_SPEED;
		KPD_COLUMN1.pupdState = GPIO_PULL_UP;
		MGPIO_voidInit(KPD_Port,KPD_COLUMN1_PIN,&KPD_COLUMN1);

		GPIO_Config_t KPD_COLUMN2;
		KPD_COLUMN2.mode = GPIO_INPUT;
		KPD_COLUMN2.speed = GPIO_LOW_SPEED;
		KPD_COLUMN2.pupdState = GPIO_PULL_UP;
		MGPIO_voidInit(KPD_Port,KPD_COLUMN2_PIN,&KPD_COLUMN2);

		GPIO_Config_t KPD_COLUMN3;
		KPD_COLUMN3.mode = GPIO_INPUT;
		KPD_COLUMN3.speed = GPIO_LOW_SPEED;
		KPD_COLUMN3.pupdState = GPIO_PULL_UP;
		MGPIO_voidInit(KPD_Port,KPD_COLUMN3_PIN,&KPD_COLUMN3);

		GPIO_Config_t KPD_ROW0;
		KPD_ROW0.mode = GPIO_OUTPUT;
		KPD_ROW0.outType = GPIO_PUSH_PULL;
		KPD_ROW0.speed = GPIO_LOW_SPEED;
		KPD_ROW0.pupdState = GPIO_NO_PUPD;
		MGPIO_voidInit(KPD_Port,KPD_ROW0_PIN,&KPD_ROW0);

		GPIO_Config_t KPD_ROW1;
		KPD_ROW1.mode = GPIO_OUTPUT;
		KPD_ROW1.outType = GPIO_PUSH_PULL;
		KPD_ROW1.speed = GPIO_LOW_SPEED;
		KPD_ROW1.pupdState = GPIO_NO_PUPD;
		MGPIO_voidInit(KPD_Port,KPD_ROW1_PIN,&KPD_ROW1);

		GPIO_Config_t KPD_ROW2;
		KPD_ROW2.mode = GPIO_OUTPUT;
		KPD_ROW2.outType = GPIO_PUSH_PULL;
		KPD_ROW2.speed = GPIO_LOW_SPEED;
		KPD_ROW2.pupdState = GPIO_NO_PUPD;
		MGPIO_voidInit(KPD_Port,KPD_ROW2_PIN,&KPD_ROW2);

		GPIO_Config_t KPD_ROW3;
		KPD_ROW3.mode = GPIO_OUTPUT;
		KPD_ROW3.outType = GPIO_PUSH_PULL;
		KPD_ROW3.speed = GPIO_LOW_SPEED;
		KPD_ROW3.pupdState = GPIO_NO_PUPD;
		MGPIO_voidInit(KPD_Port,KPD_ROW3_PIN,&KPD_ROW3);

		MGPIO_voidSetPinVal(PORTA,0,1);
		MGPIO_voidSetPinVal(PORTA,1,1);
		MGPIO_voidSetPinVal(PORTA,2,1);
		MGPIO_voidSetPinVal(PORTA,3,1);
		MGPIO_voidSetPinVal(PORTA,4,1);
		MGPIO_voidSetPinVal(PORTA,5,1);
		MGPIO_voidSetPinVal(PORTA,6,1);
		MGPIO_voidSetPinVal(PORTA,7,1);






	}

	u8 KPD_u8GetPressedKey(void){

		u8 Local_u8RowsCounter , Local_u8ColsCounter , Local_u8Flag=0;

		for(Local_u8RowsCounter=0 ; Local_u8RowsCounter<ROW_NUMBER ; Local_u8RowsCounter++){

			MGPIO_voidSetPinVal(KPD_Port,KPD_Au8Rows[Local_u8RowsCounter],GPIO_LOW);

			for (Local_u8ColsCounter =0 ; Local_u8ColsCounter< COLUMN_NUMBER ; Local_u8ColsCounter++){




				if ( MGPIO_u8GetPinValue(KPD_Port,KPD_Au8Cols[Local_u8ColsCounter]) == GPIO_LOW){

					_delay_ms(20);

					while (MGPIO_u8GetPinValue(KPD_Port,KPD_Au8Cols[Local_u8ColsCounter]) == GPIO_LOW){
						Local_u8Flag=1;

					}
					break;

				}


			}
			MGPIO_voidSetPinVal(KPD_Port,KPD_Au8Rows[Local_u8RowsCounter],GPIO_HIGH);

			if (Local_u8Flag == 1){
				return KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColsCounter];
			}


		}

	}
