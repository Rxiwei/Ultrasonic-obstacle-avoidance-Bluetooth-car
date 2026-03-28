#include <delay.h>
void delay(uint i)
{
	uchar t;
	while(i--)
	{
		for(t=0;t<120;t++);
	}
}
