
#include "MRCC_Interface.h"

void MRCC_init(void)
{
	/* Choosing System Clock */
#if (SYS_CLK == RCC_HSI)
	/* Enable HSI */
	RCC->CR |= (1<<RCC_BIT_HSI_ON);
	/* Wait until HSI is ready */
	while(!((RCC->CR) & (1<<1)));
	/* Set HSI as system clock */
	RCC->CFGR &= ~(11<<0);
	RCC->CFGR |= (RCC_HSI<<0);
	/* Wait until it is used */
	while( ((RCC->CFGR & (11<<2))>>2) != RCC_HSI);

#elif (SYS_CLK == RCC_HSE)
	RCC->CR |= (1<<RCC_BIT_HSE_ON);
	while(!((RCC->CR) & (1<<17)));
	RCC->CFGR &= ~(11<<0);
	RCC->CFGR |= (RCC_HSE<<0);
	while( ((RCC->CFGR & (11<<2))>>2) != RCC_HSE);

#elif (SYS_CLK == RCC_PLL)
	RCC->CR |= (1<<RCC_BIT_PLL_ON);
	while(!((RCC->CR) & (1<<25)));
	RCC->CFGR &= ~(11<<0);
	RCC->CFGR |= (RCC_PLL<<0);
	while( ((RCC->CFGR & (11<<2))>>2) != RCC_PLL);

#endif

	/* Clock Security system */
#if (RCC_CSS_ENABLE == ENABLE)
	RCC->CR |= (1<<19);
#else
	RCC->CR &= ~(1<<19);
#endif

	/* AHB Prescaler */
	RCC->CFGR &= ~(1111<<4);
	switch(AHB_PRESCALER)
	{
	case 1:
		RCC->CFGR |= (0000<<4);
		break;
	case 2:
		RCC->CFGR |= (1000<<4);
		break;
	case 4:
		RCC->CFGR |= (1001<<4);
		break;
	case 8:
		RCC->CFGR |= (1010<<4);
		break;
	case 16:
		RCC->CFGR |= (1011<<4);
		break;
	case 64:
		RCC->CFGR |= (1100<<4);
		break;
	case 128:
		RCC->CFGR |= (1101<<4);
		break;
	case 256:
		RCC->CFGR |= (1110<<4);
		break;
	case 512:
		RCC->CFGR |= (1111<<4);
		break;
	default:
		// error
		break;
	}

	/* APB1 Prescaler */
	RCC->CFGR &= ~(111<<10);
	switch(APB1_PRESCALER)
	{
	case 1:
		RCC->CFGR |= (000<<10);
		break;
	case 2:
		RCC->CFGR |= (100<<10);
		break;
	case 4:
		RCC->CFGR |= (101<<10);
		break;
	case 8:
		RCC->CFGR |= (110<<10);
		break;
	case 16:
		RCC->CFGR |= (111<<10);
		break;
	default:
		//error
		break;
	}

	/* APB2 Prescaler */
	RCC->CFGR &= ~(111<<13);
	switch(APB2_PRESCALER)
	{
	case 1:
		RCC->CFGR |= (000<<13);
		break;
	case 2:
		RCC->CFGR |= (100<<13);
		break;
	case 4:
		RCC->CFGR |= (101<<13);
		break;
	case 8:
		RCC->CFGR |= (110<<13);
		break;
	case 16:
		RCC->CFGR |= (111<<13);
		break;
	default:
		//error
		break;
	}

}

void MRCC_voidEnableClock(EN_peripheral_t per)
{
	switch(per)
	{
	/* AHB1 */
	case GPIOA_EN:
		RCC->AHB1ENR |= (1<<0);
		break;
	case GPIOB_EN:
		RCC->AHB1ENR |= (1<<1);
		break;
	case GPIOC_EN:
		RCC->AHB1ENR |= (1<<2);
		break;
	case GPIOD_EN:
		RCC->AHB1ENR |= (1<<3);
		break;
	case GPIOE_EN:
		RCC->AHB1ENR |= (1<<4);
		break;
	case GPIOH_EN:
		RCC->AHB1ENR |= (1<<7);
		break;
	case CRC_EN:
		RCC->AHB1ENR |= (1<<12);
		break;
	case DMA1_EN:
		RCC->AHB1ENR |= (1<<21);
		break;
	case DMA2_EN:
		RCC->AHB1ENR |= (1<<22);
		break;
	/* AHB2 */
	case OTGFS_EN:
		RCC->AHB2ENR |= (1<<7);
		break;
	/* APB1 */
	case TIM2_EN:
		RCC->APB1ENR |= (1<<0);
		break;
	case TIM3_EN:
		RCC->APB1ENR |= (1<<1);
		break;
	case TIM4_EN:
		RCC->APB1ENR |= (1<<2);
		break;
	case TIM5_EN:
		RCC->APB1ENR |= (1<<3);
		break;
	case WWDG_EN:
		RCC->APB1ENR |= (1<<11);
		break;
	case SPI2_EN:
		RCC->APB1ENR |= (1<<14);
		break;
	case SPI3_EN:
		RCC->APB1ENR |= (1<<15);
		break;
	case USART2_EN:
		RCC->APB1ENR |= (1<<17);
		break;
	case I2C1_EN:
		RCC->APB1ENR |= (1<<21);
		break;
	case I2C2_EN:
		RCC->APB1ENR |= (1<<22);
		break;
	case I2C3_EN:
		RCC->APB1ENR |= (1<<23);
		break;
	case PWR_EN:
		RCC->APB1ENR |= (1<<28);
		break;
	/* APB2 */
	case TIM1_EN:
		RCC->APB2ENR |= (1<<0);
		break;
	case USART1_EN:
		RCC->APB2ENR |= (1<<4);
		break;
	case USART6_EN:
		RCC->APB2ENR |= (1<<5);
		break;
	case ADC1_EN:
		RCC->APB2ENR |= (1<<8);
		break;
	case SDIO_EN:
		RCC->APB2ENR |= (1<<11);
		break;
	case SPI1_EN:
		RCC->APB2ENR |= (1<<12);
		break;
	case SPI4_EN:
		RCC->APB2ENR |= (1<<13);
		break;
	case SYSCFG_EN:
		RCC->APB2ENR |= (1<<14);
		break;
	case TIM9_EN:
		RCC->APB2ENR |= (1<<16);
		break;
	case TIM10_EN:
		RCC->APB2ENR |= (1<<17);
		break;
	case TIM11_EN:
		RCC->APB2ENR |= (1<<18);
		break;
	default:
		break;
	}
}

void MRCC_voidDisableClock(EN_peripheral_t per)
{
	switch(per)
	{
	/* AHB1 */
	case GPIOA_EN:
		RCC->AHB1ENR &= ~(1<<0);
		break;
	case GPIOB_EN:
		RCC->AHB1ENR &= ~(1<<1);
		break;
	case GPIOC_EN:
		RCC->AHB1ENR &= ~(1<<2);
		break;
	case GPIOD_EN:
		RCC->AHB1ENR &= ~(1<<3);
		break;
	case GPIOE_EN:
		RCC->AHB1ENR &= ~(1<<4);
		break;
	case GPIOH_EN:
		RCC->AHB1ENR &= ~(1<<7);
		break;
	case CRC_EN:
		RCC->AHB1ENR &= ~(1<<12);
		break;
	case DMA1_EN:
		RCC->AHB1ENR &= ~(1<<21);
		break;
	case DMA2_EN:
		RCC->AHB1ENR &= ~(1<<22);
		break;
	/* AHB2 */
	case OTGFS_EN:
		RCC->AHB2ENR &= ~(1<<7);
		break;
	/* APB1 */
	case TIM2_EN:
		RCC->APB1ENR &= ~(1<<0);
		break;
	case TIM3_EN:
		RCC->APB1ENR &= ~(1<<1);
		break;
	case TIM4_EN:
		RCC->APB1ENR &= ~(1<<2);
		break;
	case TIM5_EN:
		RCC->APB1ENR &= ~(1<<3);
		break;
	case WWDG_EN:
		RCC->APB1ENR &= ~(1<<11);
		break;
	case SPI2_EN:
		RCC->APB1ENR &= ~(1<<14);
		break;
	case SPI3_EN:
		RCC->APB1ENR &= ~(1<<15);
		break;
	case USART2_EN:
		RCC->APB1ENR &= ~(1<<17);
		break;
	case I2C1_EN:
		RCC->APB1ENR &= ~(1<<21);
		break;
	case I2C2_EN:
		RCC->APB1ENR &= ~(1<<22);
		break;
	case I2C3_EN:
		RCC->APB1ENR &= ~(1<<23);
		break;
	case PWR_EN:
		RCC->APB1ENR &= ~(1<<28);
		break;
	/* APB2 */
	case TIM1_EN:
		RCC->APB2ENR &= ~(1<<0);
		break;
	case USART1_EN:
		RCC->APB2ENR &= ~(1<<4);
		break;
	case USART6_EN:
		RCC->APB2ENR &= ~(1<<5);
		break;
	case ADC1_EN:
		RCC->APB2ENR &= ~(1<<8);
		break;
	case SDIO_EN:
		RCC->APB2ENR &= ~(1<<11);
		break;
	case SPI1_EN:
		RCC->APB2ENR &= ~(1<<12);
		break;
	case SPI4_EN:
		RCC->APB2ENR &= ~(1<<13);
		break;
	case SYSCFG_EN:
		RCC->APB2ENR &= ~(1<<14);
		break;
	case TIM9_EN:
		RCC->APB2ENR &= ~(1<<16);
		break;
	case TIM10_EN:
		RCC->APB2ENR &= ~(1<<17);
		break;
	case TIM11_EN:
		RCC->APB2ENR &= ~(1<<18);
		break;
	default:
		break;
	}
}
