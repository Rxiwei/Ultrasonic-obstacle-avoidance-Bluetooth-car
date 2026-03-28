#ifndef __MOTOR_H__
#define __MOTOR_H__
#include <reg51.h>
#include "delay.h"

//电机驱动引脚
sbit  M1=P2^1;
sbit  M2=P2^0;
sbit  M3=P2^2;
sbit  M4=P2^3;

#define Left_moto_go      {M1=1,M2=0;}  //左电机向前走
#define Left_moto_back    {M1=0,M2=1;} 	//左边电机向后转
#define Left_moto_Stop    {M1=0,M2=0;}         //左边电机停转                     
#define Right_moto_go     {M3=1,M4=0;}	//右边电机向前走
#define Right_moto_back   {M3=0,M4=1;}	//右边电机向后走
#define Right_moto_Stop   {M3=0,M4=0;}      	//右边电机停转  
	
void run();
void back();
void stop();
void left();
void right();
 
#endif

