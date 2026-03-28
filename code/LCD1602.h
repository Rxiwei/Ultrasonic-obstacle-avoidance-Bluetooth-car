#ifndef __LCD1602_H_
#define __LCD1602_H_
#include<reg51.h>
#include<intrins.h> 
#include "delay.h" 

sbit LCD_RS = P1^2;
//sbit LCD_RW = P1^1;
sbit LCD_E  = P1^3;	 

void LCD_Delay();
void LCD_WriteData(unsigned char Data);
void LCD_Init(void);
void LCD_WriteCommand(unsigned char Command);
void LCD_Dis_Str(uchar x, uchar y, uchar *str);
void Delay_2us(void);
void LCD_Post(int X,int Y);
#endif