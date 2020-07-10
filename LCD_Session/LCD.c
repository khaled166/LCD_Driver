/*
 * LCD.c
 *
 * Created: 7/9/2020 2:28:58 AM
 *  Author: Khaledseif166
 */ 


#include "LCD.h"



void LCD_Init(void){
	
	#if  LCD_MODE==8
	//COMMAND_DIRECTION_8BIT_MODE
	DIO_SetpinDirection(LCD_8BIT_CMND_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_SetpinDirection(LCD_8BIT_CMND_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_SetpinDirection(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_OUTPUT);
	
		//DATA_DIRECTIION FOR 8BIT MODE
	DIO_SetportDirection(LCD_8BIT_DATA_PORT,DIO_OUTPUT);
	
	
	_delay_ms(100);	
	
	LCD_WriteCommand(0x38);     //COMMAND TO WORK AT 8-BIT MODE
	LCD_WriteCommand(0x0E);     //TOGGLE CURSOR  
	LCD_WriteCommand(0x01);     //CLEAR LCD SCREEN 
	_delay_ms(20);        
	LCD_WriteCommand(0x06);    //CURSOR AUTOMATICLLY POINT TO NEXT EMPTY ADDRESS(SHIFT CURSOR TO RIGHT)
		_delay_ms(5);

	
	#elif   LCD_MODE==4  
	//COMMAND_DIRECTION_4BIT_MODE
	DIO_SetpinDirection(LCD_4BIT_CMND_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_SetpinDirection(LCD_4BIT_CMND_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_SetpinDirection(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_OUTPUT);
	
	
	//DATA_DIRECTIION FOR 4BIT MODE
	DIO_SetpinDirection(LCD_4BIT_DATA_PORT,LCD_DATA4_PIN,DIO_OUTPUT);
	DIO_SetpinDirection(LCD_4BIT_DATA_PORT,LCD_DATA5_PIN,DIO_OUTPUT);
	DIO_SetpinDirection(LCD_4BIT_DATA_PORT,LCD_DATA6_PIN,DIO_OUTPUT);
	DIO_SetpinDirection(LCD_4BIT_DATA_PORT,LCD_DATA7_PIN,DIO_OUTPUT);

		_delay_ms(100);	
		
		/*(0x33,0x32,0x28 RESPICTIVLLY) WORK AT 4-BIT MODE*/
		LCD_WriteCommand(0x33);
		LCD_WriteCommand(0x32);
		LCD_WriteCommand(0x28);
		LCD_WriteCommand(0x0C);     //TOGGLE CURSOR
		LCD_WriteCommand(0x01);     //CLEAR LCD SCREEN
		_delay_ms(20);
		LCD_WriteCommand(0x06);    //CURSOR AUTOMATICLLY POINT TO NEXT EMPTY ADDRESS(SHIFT CURSOR TO RIGHT)
		LCD_WriteCommand(0x02);    //CURSOR RETURN HOME COMMAND
		
		_delay_ms(5);
		
	#endif	
}


void LCD_WriteCommand(uint8 cmd){
	
		#if  LCD_MODE==8
			
	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	DIO_Writeport(LCD_8BIT_DATA_PORT,cmd);
	
	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
    _delay_ms(1);	
 	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
    _delay_ms(5);

	#elif  LCD_MODE ==4
	
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);

    PORTA = (cmd & 0xF0) | (PORTA & 0x0F);

	
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
    PORTA = (cmd << 4) | (PORTA & 0x0F);
	
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	_delay_ms(5);

	
	#endif
}
void LCD_Writechar(uint8 DATA ){
	#if  LCD_MODE==8
	
	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	DIO_Writeport(LCD_8BIT_DATA_PORT,DATA);
	
	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_Writepin(LCD_8BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	_delay_ms(5);

	#elif  LCD_MODE ==4
	
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	PORTA=(DATA&0xF0);
	
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	PORTA=(DATA<<4);
	
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_Writepin(LCD_4BIT_CMND_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	_delay_ms(5);

	
	#endif
}
void LCD_WriteString(uint8 *str){
	uint8 i=0;
	while(str[i]!='\0'){
		LCD_Writechar(str[i]);
		i++;
	}
}
void LCD_GOTO(uint8 row,uint8 col){
	uint8 pos[2]={0X80,0Xc0};
		LCD_WriteCommand(pos[row]+col);
}
void LCD_Clear(void){
	LCD_WriteCommand(0x01);
}



/********************************************************************Assignment_Solution**********************************************************************************/

//Assignment;
void LCD_Write_Integer(int32 Data){

	int32 Buffer[4];     // 4-byte empty buffer    
	
	Buffer[0]= Data/100 + 0x48;       // hundreds digit
	Data=Data%100;
	
	Buffer[1]=Data/10 + 0x48;        // tens digit
	Data=Data%10;
	
	Buffer[2]=Data + 0x48;          // ones digit
	
	Buffer[3]=0;                    // null termination
	
	LCD_Writechar(Buffer[Data]);
}                                