



#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "MSYSTICK_private.h"
#include "MSYSTICK_interface.h"
#include "MSYSTICK_config.h"





void ( * MSTK_CallBack ) ( void );

/*void SysTick_Handler(void){

	MSTK_CallBack();

}

*/


void MSTK_voidInit( void ){

	// Enable Systick Interrupt  -  Clock = AHB / 8 - Stop Systic
	MSTK->CTRL = 0x00000002;
}



void MSTK_voidStart( u32 Copy_PreloadValue ){

	// AHB = EXT = 8MHZ & CLOCK OF MSTK = AHB / 8 = 8MHZ / 8 = 1MHZ = 1 Micro For Each Count
	//Load Reload Value
	MSTK->LOAD = Copy_PreloadValue - 1;
	//Clear Val Register
	MSTK->VAL  = 0 ;
	//Enable Systick
	SET_BIT( MSTK->CTRL , 0 );

}


void MSTK_voidINTStatus( u8 Copy_u8Status ){

	MSTK->CTRL &= ~( 1 << 1 );
	MSTK->CTRL |=  ( Copy_u8Status << 1 );

}



u8 MSTK_u8ReadFlag( void ){

	return ( GET_BIT( MSTK->CTRL , 16 ) );

}



void MSTK_voidSetCallBack( void (*ptr)(void) ){

	MSTK_CallBack = ptr;
}


void MSTK_voidDelayMs(u32 Copy_u32Delay)
{

	MSTK_voidInit();
	/* Disable INT */
	MSTK_voidINTStatus( MSTK_INT_DIS );
	MSTK_voidStart( Copy_u32Delay * 1000 );
	/* Wiat Flag Polling */
	while( MSTK_u8ReadFlag() == 0 );



}
