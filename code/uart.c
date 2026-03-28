#include "uart.h"
#include "reg51.h"
#include "motor.h"
void UartConfiguration()  
{
    TMOD=0x20;      //设置计数器1的工作方式2
    TH1=0xfd;	    //设置计数器1的初值，决定波特率
    TL1=0xfd;		//设置计数器1的初值，决定波特率
    PCON=0x00;      // 波特率倍增0x00不加倍	 0x80加倍
    SCON=0x50;		//设置工作方式1 开启接受允许
    EA=1;		    //开启总中断
    ES=1;			//开启串口接受中断
    TR1=1;			//计数器1开始运行
}

