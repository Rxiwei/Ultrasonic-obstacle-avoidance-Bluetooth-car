#ifndef __FLOW_LIGHT_H__
#define __FLOW_LIGHT_H__

#include <intrins.h>
#include <reg51.h>
#include "delay.h"
sbit G1=P1^6;
sbit G2=P1^7;

sbit row1 = P1^0;
sbit row2 = P1^1;
sbit row3 = P1^2;

sbit col1 = P1^3;
sbit col2 = P1^4;
sbit col3 = P1^5;
extern char shuzi[];

void flow_light();
void Seg_1(unsigned int k);
void Seg_2();
unsigned char Button_0();
#endif
