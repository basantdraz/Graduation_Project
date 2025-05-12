
/*
 * DIO.c
 *
 * Created: 08/11/2023 08:15:49 م
 *  Author: pc
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "DIO_REG.h"
#include "DIO_TYPE.h"

#include "DIO.h"
void DIO_SetPortDirection (DIO_port_ID PORT_ID , DIO_direction direction)
{
	if (Output == direction)
	{
		switch (PORT_ID)
		{
			case PORTA: DDRA_Reg = 0xFF ; break;
			case PORTB: DDRB_Reg = 0xFF ; break;
			case PORTC: DDRC_Reg = 0xFF ; break;
			case PORTD: DDRD_Reg = 0xFF ; break;
		}
	}
	else if (Input == direction)
	{
		switch (PORT_ID)
		{
			case PORTA: DDRA_Reg = 0x00 ; break;
			case PORTB: DDRB_Reg = 0x00 ; break;
			case PORTC: DDRC_Reg = 0x00 ; break;
			case PORTD: DDRD_Reg = 0x00 ; break;
		}
	}
}

void DIO_SetPortValue (DIO_port_ID PORT_ID , unsigned char value)
{
	switch (PORT_ID)
	{
		case PORTA: PORTA_Reg = value ; break;
		case PORTB: PORTB_Reg = value ; break;
		case PORTC: PORTC_Reg = value ; break;
		case PORTD: PORTD_Reg = value ; break;
	}
}

void DIO_SetPinDirection (DIO_port_ID PORT_ID , DIO_PIN_ID PIN_ID , DIO_direction direction)
{
	if (PORT_ID<= PORTD && PIN_ID<= pin7)
	{
		if (Output== direction)
		{
			switch(PORT_ID)
			{
				case PORTA: SETBIT(DDRA_Reg , PIN_ID) ; break;
				case PORTB: SETBIT(DDRB_Reg , PIN_ID) ; break;
				case PORTC: SETBIT(DDRC_Reg , PIN_ID) ; break;
				case PORTD: SETBIT(DDRD_Reg , PIN_ID) ; break;
			}
		}
			else if (Input == direction)
			{
				switch(PORT_ID)
				{
					case PORTA: CLEARBIT(DDRA_Reg , PIN_ID) ; break;
					case PORTB: CLEARBIT(DDRB_Reg , PIN_ID) ; break;
					case PORTC: CLEARBIT(DDRC_Reg , PIN_ID) ; break;
					case PORTD: CLEARBIT(DDRD_Reg , PIN_ID) ; break;
				}
			}
		}
	}

void DIO_SetPintValue (DIO_port_ID PORT_ID , DIO_PIN_ID PIN_ID , STD_value value )
{

if (PORT_ID<=PORTD && PIN_ID<= pin7)
{
	if (value== high)
	{
		switch (PORT_ID)
		{
			case PORTA: SETBIT (PORTA_Reg, PIN_ID) ; break;
			case PORTB: SETBIT (PORTB_Reg, PIN_ID) ; break;
			case PORTC: SETBIT (PORTC_Reg, PIN_ID) ; break;
			case PORTD: SETBIT (PORTD_Reg, PIN_ID) ; break;
		}
		
	} 
	else if ( value == low)
	switch (PORT_ID)
	{
		case PORTA: CLEARBIT (PORTA_Reg, PIN_ID) ; break;
		case PORTB: CLEARBIT (PORTB_Reg, PIN_ID) ; break;
		case PORTC: CLEARBIT (PORTC_Reg, PIN_ID) ; break;
		case PORTD: CLEARBIT (PORTD_Reg, PIN_ID) ; break;
	}
	}
}

STD_value DIO_GetPinValue (DIO_port_ID PORT_ID , DIO_PIN_ID PIN_ID )
{
	STD_value PinValue;
	if (PORT_ID<=PORTD && PIN_ID<= pin7)
	{
		switch (PORT_ID)
		{
			case PORTA: PinValue=GETBIT (PINA_Reg, PIN_ID) ; break;
			case PORTB: PinValue=GETBIT (PINA_Reg, PIN_ID) ; break;
			case PORTC: PinValue=GETBIT (PINC_Reg, PIN_ID) ; break;
			case PORTD: PinValue=GETBIT (PIND_Reg, PIN_ID) ; break;
		}
	}
	return PinValue;
}