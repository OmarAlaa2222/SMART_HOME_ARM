/*
 * delay.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Lenovo
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
void	_delay_ms(u32 ticks)
{
	u32 i;
	for( i = 0; i < (ticks * 500) ; i++)
	{
		asm("NOP");
	}
}
