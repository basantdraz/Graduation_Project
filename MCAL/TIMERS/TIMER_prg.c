/*
 * TIMER_prg.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Karim
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_int.h"
#include "TIMERS_prv.h"
#include "TIMER0_cfg.h"
#include "TIMER1_cfg.h"
#include "TIMER2_cfg.h"


static void (*GS_fpTIM0_OVF_Callback)(void);
static void (*GS_fpTIM0_CTC_Callback)(void);
static void (*GS_fpTIM2_OVF_Callback)(void);
static void (*GS_fpTIM2_CTC_Callback)(void);
static void (*GS_fpTIM1_OVF_Callback)(void);
static void (*GS_fpTIM1_CTC_A_Callback)(void);
static void (*GS_fpTIM1_CTC_B_Callback)(void);
static void (*GS_fpTIM1_ICU_Callback)(void);


/*static void (*G_fpTIMERS_Callback[TIMERS_INTERRUPTS])(void)={G_fpTIM0_OVF_Callback,G_fpTIM0_CTC_Callback,\
											   	   	   	       G_fpTIM2_OVF_Callback,G_fpTIM2_CTC_Callback,\
											                   G_fpTIM1_OVF_Callback,G_fpTIM1_CTC_A_Callback,\
											                   G_fpTIM1_CTC_B_Callback};
*/
u32 G_u32IntervalCountTIM0;
u32 G_u32IntervalCountTIM1A;
u32 G_u32IntervalCountTIM1B;
u32 G_u32IntervalCountTIM2;




void MTIMERS_vInit(void)
{
	/**
	 * Mode: Normal Overflow
	 * Interrupt: Enable Overflow interrupt
	 * Prescaller: No Clock
	 */
	/* 1-Wave Generation Mode*/
#if TIMER0_ENABLE==ENABLE
 #if TIMER0_MODE==TIMER_OVF
	CLEARBIT(TCCR0,WGM00);
	CLEARBIT(TCCR0,WGM01);
	/*OVF Interrupt Enable/Disable */
   #if TIMER0_OVF_INTERRUPT_ENABLE==DISABLE
	CLEARBIT(TIMSK, TOIE0);
   #elif TTIMER0_OVF_INTERRUPT_ENABLE==ENABLE
	SETBIT(TIMSK, TOIE0);
   #endif

 #elif TIMER0_MODE==TIMER_PHASECORRECT
	SETBIT(TCCR0,WGM00);
	CLEARBIT(TCCR0,WGM01);

 #elif TIMER0_MODE==TIMER_CTC
	CLEARBIT(TCCR0,WGM00);
	SETBIT(TCCR0,WGM01);
	/*CTC Interrupt Enable/Disable */
   #if TIMER0_CTC_INTERRUPT_ENABLE==DISABLE
	CLEARBIT(TIMSK, OCIE0);
   #elif TIMER0_CTC_INTERRUPT_ENABLE==ENABLE
	SETBIT(TIMSK, OCIE0);
   #endif
 #elif TIMER0_MODE==TIMER_FASTPWM
	SETBIT(TCCR0,WGM00);
	SETBIT(TCCR0,WGM01);
 #else
 #error "Please select a valid Timer Mode"
 #endif
	/*Compare match mode */
#if TIMER0_COMPARE_MATCH_OP_MODE==NORMAL_MODE
	CLEARBIT(TCCR0,COM00);
	CLEARBIT(TCCR0,COM01);
#elif TIMER0_COMPARE_MATCH_OP_MODE==TOGGLE_OC0
	SETBIT(TCCR0,COM00);
	CLEARBIT(TCCR0,COM01);
#elif TIMER0_COMPARE_MATCH_OP_MODE==CLEAR_OC0
	CLEARBIT(TCCR0,COM00);
	SETBIT(TCCR0,COM01);
#elif TIMER0_COMPARE_MATCH_OP_MODE==SET_OC0
	SETBIT(TCCR0,COM00);
	SETBIT(TCCR0,COM01);
#else
#error "Please select a valid Compare Match Output Mode"
#endif
#endif

#if TIMER2_ENABLE==ENABLE
 #if TIMER2_MODE==TIMER_OVF
	CLEARBIT(TCCR2,WGM20);
	CLEARBIT(TCCR2,WGM21);
	/*OVF Interrupt Enable/Disable */
   #if TIMER2_OVF_INTERRUPT_ENABLE==DISABLE
	CLEARBIT(TIMSK, TOIE2);
   #elif TTIMER2_OVF_INTERRUPT_ENABLE==ENABLE
	SETBIT(TIMSK, TOIE2);
   #endif

 #elif TIMER2_MODE==TIMER_PHASECORRECT
	SETBIT(TCCR2,WGM20);
	CLEARBIT(TCCR2,WGM21);

 #elif TIMER2_MODE==TIMER_CTC
	CLEARBIT(TCCR2,WGM20);
	SETBIT(TCCR2,WGM21);
	/*CTC Interrupt Enable/Disable */
   #if TIMER2_CTC_INTERRUPT_ENABLE==DISABLE
	CLEARBIT(TIMSK, OCIE2);
   #elif TIMER2_CTC_INTERRUPT_ENABLE==ENABLE
	SETBIT(TIMSK, OCIE2);
   #endif
 #elif TIMER2_MODE==TIMER_FASTPWM
	SETBIT(TCCR2,WGM20);
	SETBIT(TCCR2,WGM21);
 #else
 #error "Please select a valid Timer Mode"
 #endif
	/* Compare Match Mode */
#if TIMER2_COMPARE_MATCH_OP_MODE==NORMAL_MODE
		CLEARBIT(TCCR2,COM20);
		CLEARBIT(TCCR2,COM21);
#elif TIMER2_COMPARE_MATCH_OP_MODE==TOGGLE_OC2
		SETBIT(TCCR2,COM20);
		CLEARBIT(TCCR2,COM21);
#elif TIMER2_COMPARE_MATCH_OP_MODEE==CLEAR_OC2
		CLEARBIT(TCCR2,COM20);
		SETBIT(TCCR2,COM21);
#elif TIMER2_COMPARE_MATCH_OP_MODE==SET_OC2
		SETBIT(TCCR2,COM20);
		SETBIT(TCCR2,COM21);
#else
#error "Please select a valid Compare Match Output Mode"
#endif
#endif



		/* 1-Wave Generation Mode*/
#if TIMER1_ENABLE==ENABLE
 #if TIMER1_MODE==TIMER_OVF
		CLEARBIT(TCCR1A,WGM10);
		CLEARBIT(TCCR1A,WGM11);
		CLEARBIT(TCCR1B,WGM12);
		CLEARBIT(TCCR1B,WGM13);
		/*OVF Interrupt Enable/Disable */
	  #if TIMER1_OVF_INTERRUPT_ENABLE==DISABLE
		CLEARBIT(TIMSK, TOIE1);
	  #elif TTIMER1_OVF_INTERRUPT_ENABLE==ENABLE
		SETBIT(TIMSK, TOIE1);
	  #endif
 #elif TIMER1_MODE==TIMER1_PHASECORRECT_8_BITS
		SETBIT(TCCR1A,WGM10);
		CLEARBIT(TCCR1A,WGM11);
		CLEARBIT(TCCR1B,WGM12);
		CLEARBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_PHASECORRECT_9_BITS
		CLEARBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		CLEARBIT(TCCR1B,WGM12);
		CLEARBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_PHASECORRECT_10_BITS
		SETBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		CLEARBIT(TCCR1B,WGM12);
		CLEARBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_CTC_OCR1A
		CLEARBIT(TCCR1A,WGM10);
		CLEARBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		CLEARBIT(TCCR1B,WGM13);
      #if TIMER1_CTC_OCR1A_INTERRUPT_ENABLE==DISABLE
		CLEARBIT(TIMSK, OCIE1A);
	  #elif TTIMER1_OVF_INTERRUPT_ENABLE==ENABLE
		SETBIT(TIMSK, OCIE1A);
	  #endif
 #elif TIMER1_MODE==TIMER1_FASTPWM_8_BITS
		SETBIT(TCCR1A,WGM10);
		CLEARBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		CLEARBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_FASTPWM_9_BITS
		CLEARBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		CLEARBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_FASTPWM_10_BITS
		SETBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		CLEARBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_PHASE_FREQ_CORRECT_ICR1
		CLEARBIT(TCCR1A,WGM10);
		CLEARBIT(TCCR1A,WGM11);
		CLEARBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_PHASE_FREQ_CORRECT_OCR1A
		SETBIT(TCCR1A,WGM10);
		CLEARBIT(TCCR1A,WGM11);
		CLEARBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_PHASECORRECT_ICR1
		CLEARBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		CLEARBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_PHASECORRECT_OCR1A
		SETBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		CLEARBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_CTC_ICR1
		CLEARBIT(TCCR1A,WGM10);
		CLEARBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
     #if TIMER1_CTC_INTERRUPT_ENABLE==DISABLE
		CLEARBIT(TIMSK, OCIE1A);
		CLEARBIT(TIMSK, OCIE1B);
	 #elif TIMER1_CTC_INTERRUPT_ENABLE==ENABLE
		SETBIT(TIMSK, OCIE1A);
		SETBIT(TIMSK, OCIE1B);
	  #endif
 #elif TIMER1_MODE==TIMER1_FASTPWM_ICR1
		CLEARBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
 #elif TIMER1_MODE==TIMER1_FASTPWM_OCR1A
		SETBIT(TCCR1A,WGM10);
		SETBIT(TCCR1A,WGM11);
		SETBIT(TCCR1B,WGM12);
		SETBIT(TCCR1B,WGM13);
 #else
 #error "Please select a valid Timer Mode"
 #endif
		/*Compare match mode channel A */
 #if TIMER1A_COMPARE_MATCH_OP_MODE==NORMAL_MODE_OC1A
		CLEARBIT(TCCR1A,COM1A0);
		CLEARBIT(TCCR1A,COM1A1);
 #elif TIMER1A_COMPARE_MATCH_OP_MODE==INVERTING_OC1A
		SETBIT(TCCR1A,COM1A0);
		SETBIT(TCCR1A,COM1A1);
 #elif TIMER1A_COMPARE_MATCH_OP_MODE==TOGGLE_OC1A
		SETBIT(TCCR1A,COM1A0);
		CLEARBIT(TCCR1A,COM1A1);
 #elif TIMER1A_COMPARE_MATCH_OP_MODE==NON_INVERTING_OC1A
		CLEARBIT(TCCR1A,COM1A0);
		SETBIT(TCCR1A,COM1A1);
 #else
 #error "Please select a valid Compare Match Output Mode"
 #endif
		/*Compare match mode channel B */
 #if TIMER1B_COMPARE_MATCH_OP_MODE==NORMAL_MODE_OC1B
		CLEARBIT(TCCR1A,COM1B0);
		CLEARBIT(TCCR1A,COM1B1);

 #elif TIMER1B_COMPARE_MATCH_OP_MODE==TOGGLE_OC1B
	   SETBIT(TCCR1A,COM1B0);
 	   CLEARBIT(TCCR1A,COM1B1);
 #elif TIMER1B_COMPARE_MATCH_OP_MODE==NON_INVERTING_OC1B
 	   CLEARBIT(TCCR1A,COM1B0);
	   SETBIT(TCCR1A,COM1B1);
 #elif TIMER1B_COMPARE_MATCH_OP_MODE==INVERTING_OC1B
   	   SETBIT(TCCR1A,COM1B0);
       SETBIT(TCCR1A,COM1B1);
 #else
 #error "Please select a valid Compare Match Output Mode"
 #endif
#endif

}

void MTIMERS_vSetPreLoadVal(u8 A_u8TimerId, u16 A_u16PreLoadVal)
{
	switch(A_u8TimerId)
	{
		case TIMER0:TCNT0=A_u16PreLoadVal;
					break;
		case TIMER1:TCNT1=A_u16PreLoadVal ;
					break;
		case TIMER2:TCNT2=A_u16PreLoadVal;
					break;
	}
}

void MTIMERS_vSetCompareValue(u8 A_u8TimerId,u16 A_u16CompareVal)
{
	switch(A_u8TimerId)
	{
	case TIMER0 :OCR0=A_u16CompareVal;
				     break;
	case TIMER2 :OCR2=A_u16CompareVal;
					 break;
	}


}

void MTIMERS_vSetCompareValueTIM1(u8 A_u8Channel, u16 A_u16CompareVal)
{
#if TIMER1_MODE==TIMER1_FASTPWM_ICR1 || TIMER1_MODE==TIMER1_PHASECORRECT_ICR1 ||\
	TIMER1_MODE==TIMER1_PHASE_FREQ_CORRECT_ICR1||TIMER1_MODE==TIMER1_CTC_ICR1
			ICR1=TOP;
			switch(A_u8Channel)
				{
				case CHANNEL_A:OCR1A=A_u16CompareVal;
									break;
				case CHANNEL_B:OCR1B=A_u16CompareVal;
									break;
				}
#elif TIMER1_MODE==TIMER1_FASTPWM_OCR1A || TIMER1_MODE==TIMER1_PHASECORRECT_OCR1A  || \
	  TIMER1_MODE==TIMER1_PHASE_FREQ_CORRECT_OCR1A || TIMER1_MODE==TIMER1_CTC_OCR1A
			OCR1A=TOP;
			OCR1B=A_u16CompareVal;
#endif

}

void MTIMERS_vSetInterval_OVF_Asynch(u8 A_u8TimerId,u16 A_u16IntervalCounts, void (*A_fptr)(void))
{

	switch(A_u8TimerId)
		{
		case TIMER0 :GS_fpTIM0_OVF_Callback=A_fptr;
		             G_u32IntervalCountTIM0=A_u16IntervalCounts;
					     break;
		case TIMER1 :GS_fpTIM1_OVF_Callback=A_fptr;
					 G_u32IntervalCountTIM1A=A_u16IntervalCounts;
						 break;
		case TIMER2 :GS_fpTIM2_OVF_Callback=A_fptr;
					 G_u32IntervalCountTIM2=A_u16IntervalCounts;
						 break;
		}
	//G_fpTIM0_Callback[TIM_CB_OVF]=A_fptr;
	MTIMERS_vStartTimer(A_u8TimerId);
}

void MTIMERS_vSetInterval_CTC_Asynch(u8 A_u8TimerId,u16 A_u16IntervalCounts,
									 u16 A_u16CompareValue,
									 void (*A_fptr)(void))
{

	switch(A_u8TimerId)
		{
			case TIMER0 :GS_fpTIM0_CTC_Callback=A_fptr;
						 G_u32IntervalCountTIM0=A_u16IntervalCounts;
						     break;
			case TIMER2 :GS_fpTIM2_CTC_Callback=A_fptr;
			             G_u32IntervalCountTIM2=A_u16IntervalCounts;
							 break;
		}
	//G_fpTIM0_Callback[TIM_CB_CTC]=A_fptr;
	MTIMERS_vSetCompareValue(A_u8TimerId,A_u16CompareValue);
	MTIMERS_vStartTimer(A_u8TimerId);
}
void MTIMERS_vSetInterval_TIM1_CTC_Asynch(u8 A_u8Channel,u16 A_u16IntervalCounts,
		                             	  u16 A_u16CompareValueChannel,
										  void (*A_fptr)(void))
{
	switch(A_u8Channel)
	{
	case CHANNEL_A:GS_fpTIM1_CTC_A_Callback=A_fptr;
	 	 	 	   G_u32IntervalCountTIM1A=A_u16IntervalCounts;
						break;
	case CHANNEL_B:GS_fpTIM1_CTC_B_Callback=A_fptr;
                   G_u32IntervalCountTIM1B=A_u16IntervalCounts;
						break;
	}
	MTIMERS_vSetCompareValueTIM1(A_u8Channel, A_u16CompareValueChannel);
	MTIMERS_vStartTimer(TIMER1);
}


void MTIMERS_vStartTimer(u8 A_u8TimerId)
{
	switch(A_u8TimerId)
	{
	case TIMER0 :TCCR0=(TCCR0 & CLR_CS_BITS)|(TIMER0_PRESCALER);
						 break;
	case TIMER1 :TCCR1B=(TCCR1B & CLR_CS_BITS)|(TIMER1_PRESCALER);
							 break;
	case TIMER2 :TCCR2=(TCCR2 & CLR_CS_BITS)|(TIMER2_PRESCALER);
						 break;
	}

}
void MTIMERS_vStopTimer(u8 A_u8TimerId)
{
	switch(A_u8TimerId)
		{
		case TIMER0 :TCCR0=(TCCR0 & CLR_CS_BITS);
							 break;
		case TIMER2 :TCCR2=(TCCR2 & CLR_CS_BITS);
							 break;
		}
}
u16 MTIMERS_u16GetElapsedTime(u8 A_u8TimerId)
{
	u16 L_u16ElapsedTime=0;
	switch(A_u8TimerId)
		{
		case TIMER0 :L_u16ElapsedTime=TCNT0;
							 break;
		case TIMER1 :L_u16ElapsedTime=TCNT1;
							 break;
		case TIMER2 :L_u16ElapsedTime=TCNT2;
							 break;
		}
	return L_u16ElapsedTime;

}
u16 MTIMERS_u16GetCapturedValue()
{
	return ICR1;
}
void MTIMERS_vSetIcuTrigger(ICU_Trigger_t A_xIcuTrigger )
{
	switch(A_xIcuTrigger )
	{
	case ICU_Falling: CLEARBIT(TCCR1B,ICES1);
					  break;
	case ICU_Raising: SETBIT(TCCR1B,ICES1);
					  break;
	}

}
void MTIMERS_vEnableIntterupts(u8 A_u8Interrupt_type)
{
	switch(A_u8Interrupt_type)
		{
		    case TIMER0_OVF :SETBIT(TIMSK,TOIE0);
						 break;
			case TIMER1_OVF :SETBIT(TIMSK,TOIE1);
						 break;
			case TIMER2_OVF:SETBIT(TIMSK,TOIE2);
						 break;
			case TIMER0_CTC:SETBIT(TIMSK,OCIE0);
						 break;
			case TIMER2_CTC:SETBIT(TIMSK,OCIE2);
					 	 break;
			case TIMER1_CTC_CHANNEL_A:SETBIT(TIMSK,OCIE1A);
					  	 break;
			case TIMER1_CTC_CHANNEL_B:SETBIT(TIMSK,OCIE1B);
						 break;
			case TIMER1_ICU:SETBIT(TIMSK,TICIE1);
						 break;
		}

}
void MTIMERS_DisableIntterupts(u8 A_u8Interrupt_type)
{
	switch(A_u8Interrupt_type)
		{
		    case TIMER0_OVF :CLEARBIT(TIMSK,TOIE0);
						 break;
			case TIMER1_OVF :CLEARBIT(TIMSK,TOIE1);
						 break;
			case TIMER2_OVF:CLEARBIT(TIMSK,TOIE2);
						 break;
			case TIMER0_CTC:CLEARBIT(TIMSK,OCIE0);
						 break;
			case TIMER2_CTC:CLEARBIT(TIMSK,OCIE2);
					 	 break;
			case TIMER1_CTC_CHANNEL_A:CLEARBIT(TIMSK,OCIE1A);
					  	 break;
			case TIMER1_CTC_CHANNEL_B:CLEARBIT(TIMSK,OCIE1B);
						 break;
			case TIMER1_ICU:CLEARBIT(TIMSK,TICIE1);
						 break;
		}
}
void MTIMERS_vSetCallback(u8 A_u8Interrupt_type,void (*A_fptr)(void))
{
	switch(A_u8Interrupt_type)
	{
	    case TIMER0_OVF :GS_fpTIM0_OVF_Callback=A_fptr;
					 break;
		case TIMER1_OVF :GS_fpTIM1_OVF_Callback=A_fptr;
					 break;
		case TIMER2_OVF:GS_fpTIM2_OVF_Callback=A_fptr;
					 break;
		case TIMER0_CTC:GS_fpTIM0_CTC_Callback=A_fptr;
					 break;
		case TIMER2_CTC:GS_fpTIM2_CTC_Callback=A_fptr;
				 	 break;
		case TIMER1_CTC_CHANNEL_A:GS_fpTIM1_CTC_A_Callback=A_fptr;
				  	 break;
		case TIMER1_CTC_CHANNEL_B:GS_fpTIM1_CTC_B_Callback=A_fptr;
					 break;
		case TIMER1_ICU:GS_fpTIM1_ICU_Callback=A_fptr;
					break;

	}

}
/*---------------ISR TIMER2 COMP---------------*/
void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	static u32 LS_u32Counter=0;

	LS_u32Counter++;
	if(LS_u32Counter==G_u32IntervalCountTIM2)
	{
		if (GS_fpTIM2_CTC_Callback != NULL)
			{
				GS_fpTIM2_CTC_Callback();
				LS_u32Counter=0;
			}
	}
}
/*---------------ISR TIMER2 OVF---------------*/
void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	static u32 LS_u32Counter=0;

	LS_u32Counter++;
	if(LS_u32Counter==G_u32IntervalCountTIM2)
	{
		if (GS_fpTIM2_OVF_Callback != NULL)
			{
				GS_fpTIM2_OVF_Callback();
				LS_u32Counter=0;
			}
	}
}
/*---------------ISR TIMER1 ICU---------------*/
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if (GS_fpTIM1_ICU_Callback != NULL)
		{
		    GS_fpTIM1_ICU_Callback();

		}
}
/*---------------ISR TIMER1 COMPA---------------*/
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	static u32 LS_u32Counter=0;

	LS_u32Counter++;
	if(LS_u32Counter==G_u32IntervalCountTIM1A)
	{
		if (GS_fpTIM1_CTC_A_Callback != NULL)
			{
				GS_fpTIM1_CTC_A_Callback();
				LS_u32Counter=0;
			}
	}

}
/*---------------ISR TIMER1 COMPB---------------*/
void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	static u32 LS_u32Counter=0;

	LS_u32Counter++;
	if(LS_u32Counter==G_u32IntervalCountTIM1B)
	{
		if (GS_fpTIM1_CTC_B_Callback != NULL)
			{
				GS_fpTIM1_CTC_B_Callback();
				LS_u32Counter=0;
			}
	}

}
/*---------------ISR TIMER1 OVF---------------*/
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	static u32 LS_u32Counter=0;

	LS_u32Counter++;
	if(LS_u32Counter==G_u32IntervalCountTIM1A)
	{
		if (GS_fpTIM1_OVF_Callback != NULL)
			{
				GS_fpTIM1_OVF_Callback();
				LS_u32Counter=0;
			}
	}
}
/*---------------ISR TIMER0 COMP---------------*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u32 LS_u32Counter=0;

	LS_u32Counter++;
	if(LS_u32Counter==G_u32IntervalCountTIM0)
	{
		if (GS_fpTIM0_CTC_Callback != NULL)
			{
				GS_fpTIM0_CTC_Callback();
				LS_u32Counter=0;
			}
	}

}
/*---------------ISR TIMER0 OVF---------------*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u32 LS_u32Counter=0;

	LS_u32Counter++;
	if(LS_u32Counter==G_u32IntervalCountTIM0)
	{
		if (GS_fpTIM0_OVF_Callback != NULL)
			{
				GS_fpTIM0_OVF_Callback();
				LS_u32Counter=0;
			}
	}
}
