#include "Buzzer.h"

sbit Buzzer=P1^6;

void Buzzer_time(unsigned int ms){
	unsigned int i;
	for(i=0;i<ms*2;i++){
		Buzzer=!Buzzer;
		delay(0.1*ms);
	}
}