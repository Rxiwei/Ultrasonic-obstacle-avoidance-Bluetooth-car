#include "adc0832.h"

sbit CS = P1^7;//片选使能，低电平有效
sbit CLK= P1^4;//芯片时钟输入
sbit DIO = P1^5;//数据输入DI与输出DO
unsigned char Get_AD_Result(bit channel)
{
	uchar i,dat0=0,dat1=0;
	CS=0;			//片选信号置低，启动AD转换芯片
	CLK=0;			//时钟置低平
	
	DIO=1;  		//开始信号为高电平
	Delay_2us();
	CLK=1;			//产生一个正脉冲,在时钟上升沿，输入开始信号（DI=1）
	Delay_2us();
  CLK=0;			//第1个时钟下降沿
	DIO=1;
	Delay_2us();
	
	CLK=1;		    // 第2个下降沿输入DI=1，表示双通道单极性输入
	Delay_2us();		
	CLK=0;	
	DIO=channel;         // 第3个下降沿,设置DI，选择通道;
	Delay_2us();
	CLK=1;
	Delay_2us();	
	
	CLK=0;
	DIO=1;          //第四个下降沿之前，DI置高，准备接收数 
	Delay_2us();	
	for(i=0;i<8;i++)                 //第4~11共8个下降沿读数据（MSB->LSB）
	{
		CLK=1;
		Delay_2us();
		CLK=0;
		Delay_2us();
		dat0=dat0<<1|DIO;
	}
	for(i=0;i<8;i++)                 //第11~18共8个下降沿读数据（LSB->MSB）
	{
		dat1=dat1|((uchar)(DIO)<<i);
		CLK=1;
		Delay_2us();
		CLK=0;
		Delay_2us();
	} 
	CS=1;				  
	return (dat0==dat1)?dat0:0;	    //判断dat0与dat1是否相等
}

/*
LCD_Init();
LCD_Post(0,0); 

while(1)
{
	adc = Get_AD_Result(0);//读取adc值
	voltage = adc * 500.0 / 255;//将adc值换算成电压
	LED_buffer2[10] = voltage / 100 + '0';		//取电压个位
	LED_buffer2[11] = '.';//小数点
	LED_buffer2[12] = voltage / 10 % 10 + '0';	//取电压十分位
	LED_buffer2[13] = voltage % 10 + '0';	//取电压百分位		
	LCD_Dis_Str(0, 0, &LED_buffer1[0]);	//显示字符串
	LCD_Dis_Str(0, 1, &LED_buffer2[0]);	
}
*/

