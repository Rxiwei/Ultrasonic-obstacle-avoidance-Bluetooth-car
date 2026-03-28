#ifndef __DHT11_H__
#define __DHT11_H__
#include <delay.h>
#include <reg51.h>

sbit Temp_data = P1^3; 

//初始化 
void DHT11_start();
//接收一个字节
unsigned char DHT11_rec_byte(); 
//接收温湿度数据
void DHT11_receive();
 
#endif
