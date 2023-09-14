

#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_

#include "../../LIB/STD_Types.h"

#define RCC_BASE_ADDR	0x40023800

typedef struct{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved1[2];
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 reserved2[2];
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved3[2];
	u32 APB1ENR;
	u32 APB2ENR;
	u32 reserved4[2];
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 reserved5[2];
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 reserved6[2];
	u32 BDCR;
	u32 CSR;
	u32 reserved7[2];
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 reserved8;
	u32 DCKCFGR;
}st_RCC_RegDef_t;

#define RCC		((st_RCC_RegDef_t *)RCC_BASE_ADDR)

#define RCC_BIT_HSI_ON	0
#define RCC_BIT_HSE_ON	16
#define RCC_BIT_PLL_ON	24

#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

#define DISABLE	0
#define ENABLE	1

#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
