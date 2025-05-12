


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_REG.h"
#include "../MCAL/DIO/DIO_TYPE.h"
#include "../MCAL/DIO/DIO.h"
#include "SEEDING_cfg.h"
#include "SEEDING_Int.h"


void SEEDING_MOTOR1_Init(){
DIO_SetPinDirection (SEEDING_MOTOR1_PORT ,  SEEDING_MOTOR1_PIN0 , Output);
DIO_SetPinDirection (SEEDING_MOTOR1_PORT ,  SEEDING_MOTOR1_PIN1 , Output );                
}
void SEEDING_MOTOR2_Init(){
	DIO_SetPinDirection (SEEDING_MOTOR2_PORT ,  SEEDING_MOTOR2_PIN2 , Output);
	DIO_SetPinDirection (SEEDING_MOTOR2_PORT ,  SEEDING_MOTOR2_PIN3 , Output );
}

  
	  void SEEDING_MOTOR1_Open(){
		  DIO_SetPintValue (SEEDING_MOTOR1_PORT ,  SEEDING_MOTOR1_PIN0 ,high );
		  DIO_SetPintValue (SEEDING_MOTOR1_PORT ,  SEEDING_MOTOR1_PIN1 ,low );
	  }
	   void SEEDING_MOTOR2_Open(){
		   DIO_SetPintValue (SEEDING_MOTOR2_PORT ,  SEEDING_MOTOR2_PIN2 ,high );
		   DIO_SetPintValue (SEEDING_MOTOR2_PORT ,  SEEDING_MOTOR2_PIN3 ,low );
	   }
	    
  
	 
	void SEEDING_MOTOR1_Turn_off(){
		DIO_SetPintValue (SEEDING_MOTOR1_PORT ,  SEEDING_MOTOR1_PIN0 ,low );
		DIO_SetPintValue (SEEDING_MOTOR1_PORT ,  SEEDING_MOTOR1_PIN1 ,low );
	}
	void SEEDING_MOTOR2_Turn_off(){
		DIO_SetPintValue (SEEDING_MOTOR2_PORT ,  SEEDING_MOTOR2_PIN2 ,low );
		DIO_SetPintValue (SEEDING_MOTOR2_PORT ,  SEEDING_MOTOR2_PIN3 ,low );
	}  
 

