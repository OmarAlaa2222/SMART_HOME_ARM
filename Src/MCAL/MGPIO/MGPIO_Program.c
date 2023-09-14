
#include "MGPIO_Interface.h"

/* Initialize the pin be sending the whole configuration in struct config */
void MGPIO_voidInit(u8 Copy_u8PortId, u8 Copy_u8PinNo, GPIO_Config_t* config)
{
	volatile st_GPIO_RegDef_t *GPIOn;
		switch (Copy_u8PortId) {
		case PORTA:
			MRCC_voidEnableClock(GPIOA_EN);
			GPIOn = GPIOA;
			break;
		case PORTB:
			MRCC_voidEnableClock(GPIOB_EN);
			GPIOn = GPIOB;
			break;
		case PORTC:
			MRCC_voidEnableClock(GPIOC_EN);
			GPIOn = GPIOC;
			break;
		default:
			// error (will be edited later)
			break;
		}

		// Configure the mode
		GPIOn->MODER &= ~(0x3 << ((2 * Copy_u8PinNo)));
		GPIOn->MODER |= (config->mode << (2 * Copy_u8PinNo));

		// Configure GPIO_OUTPUTput type in case mode is output
		if (config->mode == GPIO_OUTPUT || config->mode == GPIO_ALT_FN) {
			GPIOn->OTYPER &= ~(1 << (Copy_u8PinNo));
			GPIOn->OTYPER |= (config->outType << Copy_u8PinNo);
		}

		// Configure speed
		GPIOn->OSPEEDR &= ~(0x3 << ((2 * Copy_u8PinNo)));
		GPIOn->OSPEEDR |= (config->speed << (2 * Copy_u8PinNo));

		// Configure pull up and pull down resistors in case mode is input or open drain output
		GPIOn->PUPDR &= ~(0x3 << ((2 * Copy_u8PinNo)));
		GPIOn->PUPDR |= (config->pupdState << (2 * Copy_u8PinNo));

		// Configure Alternate function
		if (config->mode == GPIO_ALT_FN) {
			if (Copy_u8PinNo < 8)
				GPIOn->AFRL |= (config->AltFuncMode << (4 * Copy_u8PinNo));
			else
				GPIOn->AFRH |= ((config->AltFuncMode) << (4 * (Copy_u8PinNo - 8)));
		}
}

/* Configure the pins */
void MGPIO_voidSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8Mode)
{
	switch(Copy_u8PortId)
	{
		case PORTA:
			GPIOA->MODER &= ~(0b11<<(2*Copy_u8PinNo));
			GPIOA->MODER |= (Copy_u8Mode<<(2*Copy_u8PinNo));
			break;
		case PORTB:
			GPIOB->MODER &= ~(0b11<<(2*Copy_u8PinNo));
			GPIOB->MODER |= (Copy_u8Mode<<(2*Copy_u8PinNo));
			break;
		case PORTC:
			GPIOC->MODER &= ~(0b11<<(2*Copy_u8PinNo));
			GPIOC->MODER |= (Copy_u8Mode<<(2*Copy_u8PinNo));
			break;
		default:
			// error
			break;
	}
}

void MGPIO_voidSetPinOutputType(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8OutPutType)
{
	switch(Copy_u8PortId)
	{
		case PORTA:
			GPIOA->OTYPER &= ~(1<<Copy_u8PinNo);
			GPIOA->OTYPER |= (Copy_u8OutPutType<<Copy_u8PinNo);
			break;
		case PORTB:
			GPIOB->OTYPER &= ~(1<<Copy_u8PinNo);
			GPIOB->OTYPER |= (Copy_u8OutPutType<<Copy_u8PinNo);
			break;
		case PORTC:
			GPIOB->OTYPER &= ~(1<<Copy_u8PinNo);
			GPIOB->OTYPER |= (Copy_u8OutPutType<<Copy_u8PinNo);
			break;
		default:
			// error
			break;
	}
}

void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8OutputSpeed)
{
	switch(Copy_u8PortId)
	{
		case PORTA:
			GPIOA->OSPEEDR &= ~(0b11<<(2*Copy_u8PinNo));
			GPIOA->OSPEEDR |= (Copy_u8OutputSpeed<<(2*Copy_u8PinNo));
			break;
		case PORTB:
			GPIOB->OSPEEDR &= ~(0b11<<(2*Copy_u8PinNo));
			GPIOB->OSPEEDR |= (Copy_u8OutputSpeed<<(2*Copy_u8PinNo));
			break;
		case PORTC:
			GPIOC->OSPEEDR &= ~(0b11<<(2*Copy_u8PinNo));
			GPIOC->OSPEEDR |= (Copy_u8OutputSpeed<<(2*Copy_u8PinNo));
			break;
		default:
			// error
			break;
	}
}

void MGPIO_voidSetPinInputPull(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8PullType)
{
	switch(Copy_u8PortId)
	{
		case PORTA:
			GPIOA->PUPDR &= ~(0b11<<(2*Copy_u8PinNo));
			GPIOA->PUPDR |= (Copy_u8PullType<<(2*Copy_u8PinNo));
			break;
		case PORTB:
			GPIOB->PUPDR &= ~(0b11<<(2*Copy_u8PinNo));
			GPIOB->PUPDR |= (Copy_u8PullType<<(2*Copy_u8PinNo));
			break;
		case PORTC:
			GPIOC->PUPDR &= ~(0b11<<(2*Copy_u8PinNo));
			GPIOC->PUPDR |= (Copy_u8PullType<<(2*Copy_u8PinNo));
			break;
		default:
			// error
			break;
	}
}

/* Read and write pins */
u8 MGPIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinNo)
{
	u8 result = 0;
	switch(Copy_u8PortId)
	{
		case PORTA: result = (GPIOA->IDR&(1<<Copy_u8PinNo))>>Copy_u8PinNo; break;
		case PORTB: result = (GPIOB->IDR&(1<<Copy_u8PinNo))>>Copy_u8PinNo; break;
		case PORTC: result = (GPIOC->IDR&(1<<Copy_u8PinNo))>>Copy_u8PinNo; break;
		default: break; // error
	}
	return result;
}

void MGPIO_voidSetPinVal(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8PinVal)
{
	if(Copy_u8PinVal == 1){
		switch(Copy_u8PortId)
		{
			case PORTA: GPIOA->ODR |= (1<<Copy_u8PinNo); break;
			case PORTB: GPIOB->ODR |= (1<<Copy_u8PinNo); break;
			case PORTC: GPIOC->ODR |= (1<<Copy_u8PinNo); break;
			default: break; // error
		}
	}
	else{
		switch(Copy_u8PortId)
		{
			case PORTA: GPIOA->ODR &= ~(1<<Copy_u8PinNo); break;
			case PORTB: GPIOB->ODR &= ~(1<<Copy_u8PinNo); break;
			case PORTC: GPIOC->ODR &= ~(1<<Copy_u8PinNo); break;
			default: break; // error
		}
	}
}
void MGPIO_voidSetPinVal_fast(u8 Copy_u8PortId, u8 Copy_u8PinNo, u8 Copy_u8PinVal) /*BSRR*/
{
	if(Copy_u8PinVal == 1){
		switch(Copy_u8PortId)
		{
			case PORTA: GPIOA->BSRR = (1<<Copy_u8PinNo); break;
			case PORTB: GPIOB->BSRR = (1<<Copy_u8PinNo); break;
			case PORTC: GPIOC->BSRR = (1<<Copy_u8PinNo); break;
			default: break; // error
		}
	}
	else{
		Copy_u8PinVal += 8;
		switch(Copy_u8PortId)
		{
			case PORTA: GPIOA->BSRR = (1<<Copy_u8PinNo); break;
			case PORTB: GPIOB->BSRR = (1<<Copy_u8PinNo); break;
			case PORTC: GPIOC->BSRR = (1<<Copy_u8PinNo); break;
			default: break; // error
		}
	}
}

void MGPIO_voidTogglePin(u8 Copy_u8PortId, u8 Copy_u8PinNo)
{
	switch(Copy_u8PortId)
	{
		case PORTA:
			GPIOA->ODR ^= (1 << Copy_u8PinNo);
			break;
		case PORTB:
			GPIOB->ODR ^= (1 << Copy_u8PinNo);
			break;
		case PORTC:
			GPIOC->ODR ^= (1 << Copy_u8PinNo);
			break;
		default:
			// error
			break;
	}
}

/* Alternate Functions Configuration */
void MGPIO_voidSetAlternativeFunction(u8 Copy_u8PortId, u8 Copy_u8PinNo, EN_AlternateFunctions_t Copy_u8AltFun)
{
	if(Copy_u8PinNo < 8)
	{
		switch(Copy_u8PortId)
		{
			case PORTA: GPIOA->AFRL |= (Copy_u8AltFun << (4*Copy_u8PinNo));
			case PORTB: GPIOB->AFRL |= (Copy_u8AltFun << (4*Copy_u8PinNo));
			case PORTC: GPIOC->AFRL |= (Copy_u8AltFun << (4*Copy_u8PinNo));
		}
	}
	else
	{
		Copy_u8PinNo -= 8;
		switch(Copy_u8PortId)
		{
			case PORTA: GPIOA->AFRH |= (Copy_u8AltFun << (4*Copy_u8PinNo));
			case PORTB: GPIOB->AFRH |= (Copy_u8AltFun << (4*Copy_u8PinNo));
			case PORTC: GPIOC->AFRH |= (Copy_u8AltFun << (4*Copy_u8PinNo));
		}
	}
}
