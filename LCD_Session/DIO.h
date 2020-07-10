/*
 * DIO.h
 *
 * Created: 7/9/2020 6:12:47 AM
 *  Author: Khaledseif166
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"



//defining all Digital ports at ATMEGA32 (AVR) Micro_controller.

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

//defining all Digital pins at ATMEGA32 (AVR) Micro_controller

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

//defining the pin direction if it OUTPUT OR INPUT

#define DIO_OUTPUT  1
#define DIO_INPUT   0

#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_INPUT  0x00

//defining the pin if it high(+5V) OR low(+0V)

#define DIO_PIN_HIGH   1
#define DIO_PIN_LOW    0

#define DIO_PORT_HIGH  0xFF
#define DIO_PORT_LOW   0x00



//DIO DRIVER PROTOTYPES

//1-PORTS&PINS DIRECTION prototype
void DIO_SetportDirection(uint8 port,uint8 Dir);
void DIO_SetpinDirection(uint8 port,uint8 pin,uint8 Dir);

//2-Write PORTS|PINS Prototype
void DIO_Writeport(uint8 port,uint8 val);
void DIO_Writepin(uint8 port,uint8 pin,uint8 val);

//3-Read PORTS|PINS Prototype
void DIO_Readport(uint8 port,uint8 *val);
void DIO_Readpin(uint8 port,uint8 pin,uint8 *val);

//4-Toggle pin prototype
void DIO_TogglePin(uint8 port,uint8  pin);





#endif /* DIO_H_ */