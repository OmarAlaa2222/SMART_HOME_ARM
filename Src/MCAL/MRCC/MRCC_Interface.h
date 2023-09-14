

#ifndef MCAL_MRCC_MRCC_INTERFACE_H_
#define MCAL_MRCC_MRCC_INTERFACE_H_

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "MRCC_Private.h"
#include "MRCC_Config.h"

void MRCC_init(void);

void MRCC_voidEnableClock(EN_peripheral_t per);
void MRCC_voidDisableClock(EN_peripheral_t per);

#endif /* MCAL_MRCC_MRCC_INTERFACE_H_ */
