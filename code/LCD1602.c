#include "LCD1602.h"
#define uint unsigned int
#define uchar unsigned char
 
void LCD_Delay()		//LCD1602延时函数
{
	unsigned char i, j;
 
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}
	
void LCD_WriteCommand(unsigned char Command)  //LCD写命令函数
{
	LCD_E=0;
	LCD_RS=0;
	P0=Command;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;
	LCD_Delay();
}
 
void LCD_WriteData(unsigned char Data)  //LCD写数据函数
{
	LCD_E=0;
	LCD_RS=1;
	P0=Data;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;
	LCD_Delay();
}
//LCD初始化函数 
void LCD_Init(void){
	//LCD_RW=0;
	LCD_E=0;
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
}

void LCD_Post(int X,int Y){			
	LCD_WriteCommand(0x80+X*(0x40)+Y);
}

void LCD_Dis_Str(uchar x, uchar y, uchar *str)
{
	if(y) x |= 0x40;
	x |= 0x80;
	LCD_WriteCommand(x);
	while(*str != '\0')
	{
		LCD_WriteData(*str++);
	}
}

void Delay_2us(void)  //延时2us
{
	_nop_();
	_nop_();
}