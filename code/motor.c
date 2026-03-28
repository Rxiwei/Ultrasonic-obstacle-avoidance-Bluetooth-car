#include "motor.h"

//前进
void run(){
	Left_moto_go;
	Right_moto_go;
}
//后退
void back(){
	Left_moto_back;
	Right_moto_back;
}
//停车
void stop(){
	Left_moto_Stop;
	Right_moto_Stop;
}
//左转
void left(){
	Left_moto_back;
	Right_moto_go;
}
//右转
void right(){
	Left_moto_go;
	Right_moto_back;
}