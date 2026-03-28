#include "booth.h"
#include "motor.h"
//蓝牙初始化
void booth_int(void){
  SCON = 0x50; 	// SCON: 模式1, 8-bit UART, 使能接收 
	TMOD |= 0x20;
	TH1=0xfd; 		//波特率9600 初值
	TL1=0xfd;
	TR1= 1;
	EA = 1;	    //开总中断
	ES= 1; 		//打开串口中断
	IP=00010000;
}
//接收蓝牙信号
void BluetoothControl(void)	 
{
	unsigned char receive_data;
	
  EA = 0;
	
  if(RI == 1) { 		
		
		receive_data = SBUF;
	
		if(receive_data == '1'){
			run();
		}
		else if(receive_data == '2'){
			back();
		}
		else if(receive_data == '3'){
			left();
		}
		else if(receive_data == '4'){
			right(); 
		}
		else if(receive_data == '0'){
			stop();
		}	
	}
	EA = 1;
}