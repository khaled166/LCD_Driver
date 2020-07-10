/*
 * DIO.c
 *
 * Created: 7/9/2020 6:13:51 AM
 *  Author: Khaledseif166
 */ 



#include "DIO.h"

//DIO DRIVER PROTOTYPES

//1-PORTS&PINS DIRECTION prototype
void DIO_SetportDirection(uint8 port,uint8 Dir){
	switch(port){
		case DIO_PORTA:      //For readability text replacement by 0 as defined in header file DIO.h
		DDRA=Dir;
		break;
		
		case DIO_PORTB:      //For readability text replacement by 0 as defined in header file DIO.h
		DDRB=Dir;
		break;
		
		case DIO_PORTC:      //For readability text replacement by 0 as defined in header file DIO.h
		DDRC=Dir;
		break;
		
		case DIO_PORTD:      //For readability text replacement by 0 as defined in header file DIO.h
		DDRD=Dir;
		break;
		
		default:
		break;
	}
}
void DIO_SetpinDirection(uint8 port,uint8 pin,uint8 Dir){
	switch(Dir){
		case DIO_OUTPUT:
		switch(port){
			case DIO_PORTA:
			SET_BIT(DDRA,pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB,pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC,pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		case DIO_INPUT:
		switch(port){
			case DIO_PORTA:
			CLR_BIT(DDRA,pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB,pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC,pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

//2-Write PORTS|PINS Prototype
void DIO_Writeport(uint8 port,uint8 val){
	switch(port){
		case DIO_PORTA:
		PORTA=val;
		break;
		case DIO_PORTB:
		PORTB=val;
		break;
		case DIO_PORTC:
		PORTC=val;
		break;
		case DIO_PORTD:
		PORTD=val;
		break;
		default:
		break;
	}
}
void DIO_Writepin(uint8 port,uint8 pin,uint8 val){
	switch(val){
		case DIO_PIN_HIGH:
		switch(port){
			case DIO_PORTA:
			SET_BIT(PORTA,pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB,pin);
			case DIO_PORTC:
			SET_BIT(PORTC,pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		case DIO_PIN_LOW:
		switch(port){
			case DIO_PORTA:
			CLR_BIT(PORTA,pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB,pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC,pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

//3-Read PORTS|PINS Prototype
void DIO_Readport(uint8 port,uint8 *val){
	switch(port){
		case DIO_PORTA:
		*val=PINA;
		break;
		case DIO_PORTB:
		*val=PINB;
		break;
		case DIO_PORTC:
		*val=PINC;
		break;
		case DIO_PORTD:
		*val=PIND;
		break;
		default:
		break;
	}
}
void DIO_Readpin(uint8 port,uint8 pin,uint8 *val){
	switch(port){
		case DIO_PORTA:
		*val=GET_BIT(PINA,pin);
		break;
		case DIO_PORTB:
		*val=GET_BIT(PINB,pin);
		break;
		case DIO_PORTC:
		*val=GET_BIT(PINC,pin);
		break;
		case DIO_PORTD:
		*val=GET_BIT(PIND,pin);
		break;
		default:
		break;
	}
}

//4-Toggle pin prototype
void DIO_TogglePin(uint8 port,uint8  pin){
	switch(port){
		case DIO_PORTA:
		Toggle_BIT(PORTA,pin);
		break;
		case DIO_PORTB:
		Toggle_BIT(PORTB,pin);
		break;
		case DIO_PORTC:
		Toggle_BIT(PORTC,pin);
		break;
		case DIO_PORTD:
		Toggle_BIT(PORTD,pin);
		break;
	}
}
