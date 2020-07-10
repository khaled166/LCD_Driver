/*
 * LCD.h
 *
 * Created: 7/9/2020 2:27:59 AM
 *  Author: Khaledseif166
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_CONFIG.h"
#include <util/delay.h>


void LCD_Init(void);
void LCD_WriteCommand(uint8 cmd);
void LCD_Writechar(uint8 DATA );
void LCD_WriteString(uint8 *str);
void LCD_GOTO(uint8 row,uint8 col);
void LCD_Clear(void);

void LCD_Write_Integer(int32 Data);   //Assignment;





#endif /* LCD_H_ */