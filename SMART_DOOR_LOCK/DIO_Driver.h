/*
 * DIO_Driver.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#include "Datatype.h"

#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

void DIO_SetPinDirection( u8 port_number, u8 pin_number, u8 direction);
void DIO_SetPinValue( u8 port_number, u8 pin_number, u8 value);
   u8  DIO_GetPinValue( u8 port_number, u8 pin_number);

void DIO_SetPortDirection( u8 port_number,  u8 direction);
void DIO_SetPortValue( u8 port_number, u8 value);
   u8  DIO_GetPortValue( u8 port_number);

void DIO_SetPinsDirection( u8 pin_number, u8 direction);
void DIO_SetPinsValue( u8 pin_number, u8 value);
   u8  DIO_GetPinsValue( u8 pin_number);


void DIO_EnablePullupResistance(u8 pin_number);



#endif /* DIO_DRIVER_H_ */
