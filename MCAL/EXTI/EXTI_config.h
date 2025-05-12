
/*
 * EXTI_config.h
 *
 * Created: 16/11/2023 12:03:06 ص
 *  Author: pc
 */ 
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*configure the external interrupt 0 mode 
* Range:
* EXTI_Low_Level
* EXTI_Any_Logical_Change
* EXTI_Falling_Edge
* EXTI_Rising_Edge
*/
#define EXTI0_MODE      EXTI_Low_Level 

/*configure the external interrupt 1 mode
* Range:
* EXTI_Low_Level
* EXTI_Any_Logical_Change
* EXTI_Falling_Edge
* EXTI_Rising_Edge
*/

#define EXTI1_MODE      EXTI-Falling_Edge
 
/*configure the external interrupt 2 mode
* Range:
* EXTI_INT2_Falling_Edge
* EXTI_INT2_Rising_Edge
*/
#define EXTI2_MODE    EXTI_INT2_Falling_Edge  


/* Configure the external interrupt initial state
* Range:
* EXTI_Disable_State
* EXTI_Enable_State
*/

#define EXTI_INT0_INIT_STATE           EXTI_Disable_State
#define EXTI_INT1_INIT_STATE           EXTI_Disable_State
#define EXTI_INT2_INIT_STATE           EXTI_Disable_State


#endif