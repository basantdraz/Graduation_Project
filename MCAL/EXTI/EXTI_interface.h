
/*
 * EXTI_interface.h
 *
 * Created: 16/11/2023 12:03:23 ص
 *  Author: pc
 */ 
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "EXTI_config.h"
#include "EXTI_reg.h"
#include "EXTI_TYPES.h"

void EXTI_Initialization (void);
void EXTI_EnableInt0 (void);
void EXTI_DisableInt0 (void);
void EXTI_EnableGlobalInterrupt (void);
void EXTI_DisableGlobalInterrupt (void);
void EXTI_SetCallback (void (*CopyFuncPtr) (void) );


#endif