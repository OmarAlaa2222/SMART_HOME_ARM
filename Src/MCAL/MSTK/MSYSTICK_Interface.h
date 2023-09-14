

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#define MSTK_INT_EN   1
#define MSTK_INT_DIS  0




void MSTK_voidInit( void );

void MSTK_voidStart( u32 Copy_PreloadValue );

void MSTK_voidINTStatus( u8 Copy_u8Status );

u8 MSTK_u8ReadFlag( void );

void MSTK_voidSetCallBack( void (*ptr)(void) );
void SysTick_Handler(void);

void MSTK_voidDelayMs(u32 Copy_u32Delay);

#endif /* SYSTICK_INTERFACE_H_ */
