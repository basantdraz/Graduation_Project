
/*

*******************************************************                         ADC_Conf.h                         *********************************************************
    
*/

#ifndef _ADC_CONF_H_
#define _ADC_CONF_H_

/*
* Configure the voltage reference
* Range:
* ADC_VOLTAGE_REF_AVCC
* ADC_VOLTAGE_REF_AREF
* ADC_VOLTAGE_REF_2_56v
*/
#define ADC_VOLTAGE_REF_SELECTOR_msk    ADC_VOLTAGE_REF_AVCC


#define ADC_VOLTAGE_REF_mv              5000
#define ADC_MAX_NUMBER_OF_STEPS         1024

/*
* Configure the mode selector 
* Range:
* ADC-MODE_AUTO_TRIGGER
* ADC-MODE_SINGLE_CONVERSION 
*/
#define ADC_MODE_SELECTOR               ADC-MODE_AUTO_TRIGGER

/* Configure the ADC ADJUSTMENT 
* Range:
* ADC-RIGHT_ADJUSTMENT
* ADC-LEFT_ADJUSTMENT
*/
#define ADC_ADJUSTMENT_SELECTOR         ADC-RIGHT_ADJUSTMENT

/* Configure the ADC PRESCALER
* Range:
* ADC_PRESCALER_2_msk
* ADC_PRESCALER_4_msk
* ADC_PRESCALER_8_msk
* ADC_PRESCALER_16_msk
* ADC_PRESCALER_32_msk
* ADC_PRESCALER_64_msk
*ADC_PRESCALER_128_msk
*/
#define ADC_PRESCALER_SELECTOR_msk      ADC_PRESCALER_128_msk 

/* Configure the ADC TRIGGER SOURCE
* Range:
* ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk
* ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk       
* ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk        
* ADC_AUTO_TRIG_SRC_EXTI0_msk              
* ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk        
* ADC_AUTO_TRIG_SRC_TIMER0_OVF_msk         
* ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk       
* ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk        
* ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk   
*/    

#define ADC_AUTO_TRIG_SRC_SELECTOR     ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk






#endif