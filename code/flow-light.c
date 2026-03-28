#include "flow-light.h"
uint i;
uint key;
//流水灯代码
void flow_light(){
	while(1)
	{
		P0=0xfe;
		//四个灯循环亮起
		for(i=4;i>0;i--){
			delay(500);
			P0=_crol_(P0,1);
		}
	}
}

//两位数码管代码
void Seg_2(){
	//使用时，需先将P0、P1口预处理
	G1=1;
	G2=0;
	while(1){
		P0=shuzi[i];
		i++;
		delay(500);
		if(i>15) i=0;
	}
}
//指定显示数字
void Seg_1(unsigned char k){
	//使用时，需先将P0、P1口预处理
	G1=1;
	G2=0;
	P0=shuzi[k];
	delay(500);
}

//矩阵键盘的代码
unsigned char Button_0(){
	unsigned char key_value = 0xff; // 默认无按键按下
	P0=key_value;
	// 第一行
	row1 = 0; delay(5);
	if (col1 == 0) key_value = 1;
	if (col2 == 0) key_value = 2;
	if (col3 == 0) key_value = 3;
	row1 = 1;
	
	// 第二行
	row2 = 0; delay(5);
	if (col1 == 0) key_value = 4;
	if (col2 == 0) key_value = 5;
	if (col3 == 0) key_value = 6;
	row2 = 1;
	
	// 第三行
	row3 = 0; delay(5);
	if (col1 == 0) key_value = 7;
	if (col2 == 0) key_value = 8;
	if (col3 == 0) key_value = 9;
	row3 = 1;
	
	return key_value;
}