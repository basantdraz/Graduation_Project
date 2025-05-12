
/*
 * EXTI_reg.h
 *
 * Created: 16/11/2023 12:01:45 ص
 *  Author: pc
 */ 

#ifndef EXTI_REG_H_
#define EXTI_REG_H_

#define SREG_Reg           (*(volatile u8*) 0x5F)
#define MCUCR_Reg          (*(volatile u8*) 0x55)
#define MCUCSR_Reg         (*(volatile u8*) 0x54)
#define GICR_Reg           (*(volatile u8*) 0x5B)
#define GIFR_Reg           (*(volatile u8*) 0x5A)

#endif