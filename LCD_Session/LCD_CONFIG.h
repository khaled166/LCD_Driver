/*
 * LCD_CONFIG.h
 *
 * Created: 7/9/2020 2:16:44 AM
 *  Author: Khaledseif166
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "DIO.h"



#define LCD_MODE     4

#define LCD_8BIT_CMND_PORT     DIO_PORTB
#define LCD_8BIT_DATA_PORT     DIO_PORTA


#define LCD_4BIT_CMND_PORT     DIO_PORTB
#define LCD_4BIT_DATA_PORT     DIO_PORTA


#define LCD_RS_PIN              DIO_PIN1
#define LCD_RW_PIN              DIO_PIN2
#define LCD_E_PIN               DIO_PIN3


#define LCD_DATA0_PIN           DIO_PIN0  
#define LCD_DATA1_PIN           DIO_PIN1
#define LCD_DATA2_PIN           DIO_PIN2
#define LCD_DATA3_PIN           DIO_PIN3
#define LCD_DATA4_PIN           DIO_PIN4
#define LCD_DATA5_PIN           DIO_PIN5
#define LCD_DATA6_PIN           DIO_PIN6
#define LCD_DATA7_PIN           DIO_PIN7






#endif /* LCD_CONFIG_H_ */