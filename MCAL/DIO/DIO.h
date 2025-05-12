
/*
 * DIO.h
 *
 * Created: 08/11/2023 08:10:49 م
 *  Author: pc
 */ 
#ifndef project_MCAL_DIO_DIO_H_
#define project_MCAL_DIO_DIO_H_
void DIO_SetPortDirection (DIO_port_ID PORT_ID , DIO_direction direction);




void DIO_SetPortValue (DIO_port_ID PORT_ID , unsigned char value );



void DIO_SetPinDirection (DIO_port_ID PORT_ID , DIO_PIN_ID PIN_ID, DIO_direction direction);


void DIO_SetPintValue (DIO_port_ID PORT_ID , DIO_PIN_ID PIN_ID , STD_value value );


STD_value DIO_GetPinValue (DIO_port_ID PORT_ID , DIO_PIN_ID PIN_ID );


#endif
