
/*

*******************************************************                         ADC_INTERFACE.h                         *********************************************************
    
*/

#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ADC_Conf.h"
#include "ADC_REGS.h"
#include "ADC_TYPES.h"


typedef enum 
{ 
ADC_Channel_0,
ADC_Channel_1,
ADC_Channel_2,
ADC_Channel_3,
ADC_Channel_4,
ADC_Channel_5,
ADC_Channel_6,
ADC_Channel_7
} ADC_Channel_types;


void ADC_Initialize(void);

void ADC_StartConversion(ADC_Channel_types ADC_Channel);

u16 ADC_GetResult(void);

#endif














