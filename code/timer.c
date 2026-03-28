#include "timer.h"
//定时器
void Timer1Init(void)   //10毫秒@20.000MHz
{
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0xdc;		  //设置定时初值
	TH1 = 0x00;	    //设置定时初值
	TF1 = 0;		    //清除TF1溢出标志
	TR1 = 1;		    //定时器T1开始计时
	ET1 = 1;        //允许定时器T1中断
}



