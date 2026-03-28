#include "uart.h"
#include "flow-light.h"
#include "adc0832.h"
#include "LCD1602.h"
#define uchar unsigned char
#define uint unsigned int
uchar code Zifu[]="0123456789";

uchar adc = 0;
uint voltage = 0;

char shuzi[]={0xc0,0xf9,0xa4,0xb0,
							0x99,0x92,0x82,0xf8,
							0x80,0x90,0x88,0x83,
							0xc6,0xa1,0x86,0x8e};
int value[4];
uchar LED_buffer1[16] = {" Voltage"};//电压显示
uchar LED_buffer2[16] = {" Now:     V "};

void main()
{
	LCD_Init();
	LCD_Post(0,0); 
	
	while(1)
	{
		//读取adc值
		adc = Get_AD_Result(0);
		//将adc值换算成电压
		voltage = adc * 500.0 / 255;
		//取电压个位
		LED_buffer2[5] = voltage / 100 + '0';
		//小数点
		LED_buffer2[6] = '.';
		//取电压十分位
		LED_buffer2[7] = voltage / 10 % 10 + '0';
		//取电压百分位
		LED_buffer2[8] = voltage % 10 + '0';
		//显示字符串
		LCD_Dis_Str(0, 0, &LED_buffer1[0]);	
		LCD_Dis_Str(0, 1, &LED_buffer2[0]);	
	}
}
