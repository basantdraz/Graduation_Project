
/*
 * BitMath.h
 *
 * Created: 12/11/2023 11:27:37 م
 *  Author: pc
 */ 
#ifndef project_MCAL_DIO_BitMath_H_
#define project_MCAL_DIO_BitMath_H_

#define SETBIT(PORT_ID , PIN_ID)              (PORT_ID |= (1<<PIN_ID))
#define CLEARBIT(PORT_ID, PIN_ID)             (PORT_ID &= ~(1<<PIN_ID))
#define TOGGLEBIT(PORT_ID, PIN_ID)            (PORT_ID ^= (1<<PIN_ID))
#define GETBIT(PORT_ID, PIN_ID)              (((PORT_ID)>> (PIN_ID)) & 0X01)
#endif