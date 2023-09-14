

#ifndef MCAL_MGPIO_MGPIO_INTERFACE_H_
#define MCAL_MGPIO_MGPIO_INTERFACE_H_

#include "../../LIB/STD_Types.h"
#include "../MRCC/MRCC_Interface.h"
#include "MGPIO_Private.h"
#include "MGPIO_Config.h"

#define PORTA	0
#define PORTB	1
#define PORTC	2

#define GPIO_LOW	0
#define GPIO_HIGH	1

/* Initialize the pin be sending the whole configuration in struct config */
void MGPIO_voidInit(u8 Copy_u8PortId, u8 Copy_u8PinNo, GPIO_Config_t* config);

/* Configure the pins */
void MGPIO_voidSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8Mode);
void MGPIO_voidSetPinOutputType(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8OutPutType);
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8OutputSpeed);
void MGPIO_voidSetPinInputPull(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8PullType);

/* Read and write pins */
u8 MGPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinNo);

void MGPIO_voidSetPinVal(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8PinVal);
void MGPIO_voidSetPinVal_fast(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8PinVal); /*BSRR*/

void MGPIO_voidTogglePin(u8 Copy_u8PortId, u8 Copy_u8PinNo);

/* Alternate Functions Configuration */
void MGPIO_voidSetAlternativeFunction(u8 Copy_u8PortId, u8 Copy_u8PinNo, EN_AlternateFunctions_t Copy_u8AltFun);

#endif /* MCAL_MGPIO_MGPIO_INTERFACE_H_ */
