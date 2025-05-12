
/*

*******************************************************                         ADC.C                         *********************************************************
    
*/



#include "ADC_INTERFACE.h"


void ADC_Initialize(void)
{
	ADMUX_Reg &= ADC_VOLTAGE_REF_clr_msk;
	ADMUX_Reg |= ADC_VOLTAGE_REF_SELECTOR_msk;
	
	
	#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
	SETBIT (ADCSRA_Reg,5);
	SFIOR_Reg &= ADC_AUTO_TRIG_SRC_clr_msk;
	SFIOR_Reg |= ADC_AUTO_TRIG_SRC_SELECTOR;
	#elif ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION
	CLEARBIT (ADCSRA_Reg,5);
	#endif
	
	
	#if ADC_ADJUSTMENT_SELECTOR == ADC_RIGHT_ADJUSTMENT
	CLEARBIT (ADMUX_Reg, 5);
	#elif ADC_ADJUSTMENT_SELECTOR == ADC_LEFT_ADJUSTMENT
	SETBIT (ADMUX_Reg, 5);
	#endif
	
	SETBIT (ADCSRA_Reg,4);
	SETBIT (ADCSRA_Reg,7);
	
	
}

void ADC_StartConversion(ADC_Channel_types ADC_Channel)
{
	ADMUX_Reg &= ADC_Channel_SELECTOR_clr_msk;
	
	ADMUX_Reg |= ADC_Channel;
    SETBIT(ADCSRA_Reg,6);
	

	
}
u16 ADC_GetResult(void)
{
	
	while(GETBIT(ADCSRA_Reg,6))
	{
		
	}
	return ADCLH_Reg;
	

	
}







