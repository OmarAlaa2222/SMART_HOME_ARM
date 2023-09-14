#include "LIB/BIT_Math.h"
#include "LIB/STD_TYPES.h"
#include "LIB/delay.h"

#include "MCAL/MRCC/MRCC_Interface.h"
#include "MCAL/MGPIO/MGPIO_Interface.h"
#include "MCAL/MSTK/MSYSTICK_Interface.h"
#include "MCAL/MUSART/MUSART_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KPD/KPD_Interface.h"

static u8 PASSKEY[3]={'1','2','3'};
void main (void){
	MRCC_init();
	MRCC_voidEnableClock(SYSCFG_EN);
	MRCC_voidEnableClock(GPIOA_EN);
	MRCC_voidEnableClock(GPIOB_EN);
	MRCC_voidEnableClock(USART1_EN);


	MGPIO_voidSetPinMode(PORTA,GPIO_PIN0,GPIO_OUTPUT);    // GREEN LED
	MGPIO_voidSetPinMode(PORTA,GPIO_PIN1,GPIO_OUTPUT);    // DOOR
	MGPIO_voidSetPinMode(PORTA,GPIO_PIN2,GPIO_OUTPUT);     // BUZZER
	MGPIO_voidSetPinMode(PORTA,GPIO_PIN3,GPIO_OUTPUT);     // RED LED
	MGPIO_voidSetPinMode(PORTA,GPIO_PIN4,GPIO_OUTPUT);

	MGPIO_voidSetPinMode(PORTA,GPIO_PIN9,GPIO_ALT_FN);
	MGPIO_voidSetPinMode(PORTA,GPIO_PIN10,GPIO_ALT_FN);

	MGPIO_voidSetAlternativeFunction(PORTA,GPIO_PIN9,GPIO_AF7);  // TX
	MGPIO_voidSetAlternativeFunction(PORTA,GPIO_PIN10,GPIO_AF7); // RX

	MUSART_voidInit();
	MUSART_voidSendString("WELCOME");
	MUSART_voidSendString("ENTER THE PASSWORD:");


	u8 RecievedData=0;
	u8 i=0;
	u8 Password[3];
	u8 Local_u8Flag=0;
	while (1){
         RecievedData=MUSART_u8ReadData();

         for (i=0;i<3;i++){
        	 Password[i]=RecievedData;
         }

         /************************  PASSWORD CHECK       ******************/

         if ((Password[0]== PASSKEY[0] ) && (Password[1]== PASSKEY[1] ) && (Password[2]== PASSKEY[2]) ){

        	 MUSART_voidSendString("Password Correct");
        	 MUSART_voidSendString("WELCOME");


        	 /************* IF PASS CORRECT OPEN THE DOOR AND GREEN LED ON ****/
        	 MGPIO_voidSetPinVal(PORTA,GPIO_PIN0,GPIO_HIGH);
        	 MGPIO_voidSetPinVal(PORTA,GPIO_PIN1,GPIO_HIGH);
        	 _delay_ms(3000);
        	 MGPIO_voidSetPinVal(PORTA,GPIO_PIN0,GPIO_LOW);
        	 MGPIO_voidSetPinVal(PORTA,GPIO_PIN1,GPIO_LOW);


         }

         else {
        	 MUSART_voidSendString("Password Wrong");
        	 Local_u8Flag++;
        	 if (Local_u8Flag<2){
             MUSART_voidSendString("Try Again");
        	 }
        	 else if ( Local_u8Flag == 2) {
        		 MUSART_voidSendString("Last Try");
        	 }

        	 MUSART_voidSendString("Password:");
         }


         /************** NO MORE TRIALS *******************/
         /**************** BUZZER ALERTED && RED LED ON ************/

         if (Local_u8Flag == 3){
        	 MUSART_voidSendString("BUZZER ALERTED");
        	 MGPIO_voidSetPinVal(PORTA,GPIO_PIN2,GPIO_HIGH);
        	 MGPIO_voidSetPinVal(PORTA,GPIO_PIN3,GPIO_HIGH);


         }








}
}

