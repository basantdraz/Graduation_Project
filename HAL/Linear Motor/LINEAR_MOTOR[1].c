
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_REG.h"
#include "../MCAL/DIO/DIO_TYPE.h"
#include "../MCAL/DIO/DIO.h"
#include "LINEAR_MOTOR_cfg[1].h"
#include "LNEAR_MOTOR_Int[1].h"

void LINEAR_MOTOR_Init(){
DIO_SetPinDirection (LINEAR_MOTOR_PORT,LINEAR_MOTOR_PIN0,Output);
DIO_SetPinDirection (LINEAR_MOTOR_PORT,LINEAR_MOTOR_PIN1,Output);

}
void LINEAR_MOTOR_Extend(){
DIO_SetPintValue (LINEAR_MOTOR_PORT,LINEAR_MOTOR_PIN0,high);
DIO_SetPintValue (LINEAR_MOTOR_PORT,LINEAR_MOTOR_PIN0,low);
}
void LINEAR_MOTOR_Retract(){
DIO_SetPintValue (LINEAR_MOTOR_PORT,LINEAR_MOTOR_PIN0,low);
DIO_SetPintValue (LINEAR_MOTOR_PORT,LINEAR_MOTOR_PIN0,low);
}




