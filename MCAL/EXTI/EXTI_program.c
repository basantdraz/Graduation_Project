
/*
 * EXTI_program.c
 *
 * Created: 16/11/2023 12:03:50 ص
 *  Author: pc
 */ 
#include "EXTI_interface.h"
void (*CallBackPtr)(void) = NULL ;
void EXTI_Initialization (void)
{
	CLEARBIT (MCUCR_Reg,0);
	CLEARBIT (MCUCR_Reg,1);
	CLEARBIT (MCUCR_Reg,2);
	CLEARBIT (MCUCR_Reg,3);
	CLEARBIT (MCUCR_Reg,6);
	
	#if EXTI0_MODE == EXTI_Low_Level
	 MCUCR_Reg |= EXTI_Low_Level ;
	#elif EXTI0_MODE == EXTI_Any_Logical_Change
	 MCUCR_Reg |= EXTI_Any_Logical_Change;
	#elif EXTI0_MODE == EXTI_Falling_Edge
	 MCUCR_Reg |= EXTI_Falling_Edge;
	#elif EXTI0_MODE == EXTI_Rising_Edge
	 MCUCR_Reg |= EXTI_Rising_Edge;
     #endif
	 
	 
	#if EXTI1_MODE == EXTI_Low_Level
	MCUCR_Reg |= (EXTI_Low_Level<<2) ;
	#elif EXTI1_MODE == EXTI_Any_Logical_Change
	MCUCR_Reg |= (EXTI_Any_Logical_Change<<2);
	#elif EXTI1_MODE == EXTI_Falling_Edge
	MCUCR_Reg |= (EXTI_Falling_Edge<<2);
	#elif EXTI1_MODE == EXTI_Rising_Edge
	MCUCR_Reg |= (EXTI_Rising_Edge<<2);
	#endif
	 
	 
	 #if EXTI2_MODE == EXTI_INT2_Falling_Edge
	 MCUCR_Reg |= EXTI_INT2_Falling_Edge;
	 #elif EXTI2_MODE == EXTI_INT2_Rising_Edge
	 MCUCR_Reg |= EXTI_INT2_Rising_Edge;
	 #endif
	 
	 #if EXTI_INT0_INIT_STATE == EXTI_Disable_State
	 CLEARBIT(GICR_Reg,6);
	 #elif EXTI_INT0_INIT_STATE == EXTI_Enable_State
	 SETBIT(GICR_Reg,6);
	 #endif

	 #if EXTI_INT1_INIT_STATE == EXTI_Disable_State
	 CLEARBIT(GICR_Reg,7);
	 #elif EXTI_INT1_INIT_STATE == EXTI_Enable_State
	 SETBIT(GICR_Reg,7);
	 #endif

	 #if EXTI_INT2_INIT_STATE == EXTI_Disable_State
	 CLEARBIT(GICR_Reg,5);
	 #elif EXTI_INT2_INIT_STATE == EXTI_Enable_State
	 MCUCSR_Reg |=  EXTI_INT2_Rising_Edge;
	 SETBIT(GICR_Reg,5);
	 #endif
	 SETBIT(GIFR_Reg,5);
	 SETBIT(GIFR_Reg,6);
	 SETBIT(GIFR_Reg,7);
 
	
	
}

void EXTI_EnableGlobalInterrupt (void)
{
	SETBIT (SREG_Reg,7);
}
void EXTI_DisableGlobalInterrupt (void)
{
	CLEARBIT (SREG_Reg,7);
}
void EXTI_EnableInt0 (void)
{
	SETBIT (GICR_Reg,6);
}

void EXTI_DisableInt0 (void)
{
	CLEARBIT (GICR_Reg,6);
}

void EXTI_SetCallback (void (*CopyFuncPtr) (void) )
{
	CallBackPtr = CopyFuncPtr;
}

void __vector_1(void) __attribute__((signal, used));
void __vector_1(void)
{
	if(CallBackPtr != NULL){
		CallBackPtr();
	}
}
