

#ifndef MCAL_MGPIO_MGPIO_PRIVATE_H_
#define MCAL_MGPIO_MGPIO_PRIVATE_H_

#include "../../LIB/STD_Types.h"

#define GPIOA_BASE_ADDR					0x40020000U
#define GPIOB_BASE_ADDR					0x40020400U
#define GPIOC_BASE_ADDR					0x40020800U
#define GPIOD_BASE_ADDR					0x40020C00U
#define GPIOE_BASE_ADDR					0x40021000U
#define GPIOH_BASE_ADDR					0x40021C00U

typedef struct{
	u32 MODER;		// GPIO port mode register
	u32 OTYPER;		// GPIO port output type register
	u32 OSPEEDR;	// GPIO port output speed register
	u32 PUPDR;		// GPIO port pull-up/pull-down register
	u32 IDR;		// GPIO port input data register
	u32 ODR;		// GPIO port output data register
	u32 BSRR;		// GPIO port bit set/reset register
	u32 LCKR;		// GPIO port configuration lock register
	u32 AFRL;		// GPIO alternate function low register
	u32 AFRH;		// GPIO alternate function high register
}st_GPIO_RegDef_t;

#define GPIOA		((volatile st_GPIO_RegDef_t *)GPIOA_BASE_ADDR)
#define GPIOB		((volatile st_GPIO_RegDef_t *)GPIOB_BASE_ADDR)
#define GPIOC		((volatile st_GPIO_RegDef_t *)GPIOC_BASE_ADDR)
#define GPIOD		((volatile st_GPIO_RegDef_t *)GPIOD_BASE_ADDR)
#define GPIOE		((volatile st_GPIO_RegDef_t *)GPIOE_BASE_ADDR)
#define GPIOH		((volatile st_GPIO_RegDef_t *)GPIOH_BASE_ADDR)

#define GPIO_PIN0  0
#define GPIO_PIN1  1
#define GPIO_PIN2  2
#define GPIO_PIN3  3
#define GPIO_PIN4  4
#define GPIO_PIN5  5
#define GPIO_PIN6  6
#define GPIO_PIN7  7
#define GPIO_PIN8  8
#define GPIO_PIN9  9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15

#endif /* MCAL_MGPIO_MGPIO_PRIVATE_H_ */
