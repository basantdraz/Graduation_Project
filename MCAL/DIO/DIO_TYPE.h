
/*
 * DIO_TYPE.h
 *
 * Created: 08/11/2023 08:20:13 م
 *  Author: pc
 */ 
#ifndef project_MCAL_DIO_DIO_TYPE_H_
#define project_MCAL_DIO_DIO_TYPE_H_
typedef enum 
{
	Input,
	Output
	
	}DIO_direction;
typedef enum 
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
	
	}DIO_port_ID;
	
typedef enum
{
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7
	
	}DIO_PIN_ID;
	
	
	
#endif