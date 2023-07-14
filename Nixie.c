#include <regx52.h>
#include "delay.h"
unsigned char NixieTable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6D,0x7D,0x07,0x7F,0x6F};    //LED数字段码

void Nixie(unsigned char location,number)
{
	switch(location)                                                //LED位码
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;//1
		case 2:P2_4=1;P2_3=1;P2_2=0;break;//2
		case 3:P2_4=1;P2_3=0;P2_2=1;break;//3
		case 4:P2_4=1;P2_3=1;P2_2=0;break;//4
		case 5:P2_4=0;P2_3=1;P2_2=1;break;//5
		case 6:P2_4=0;P2_3=1;P2_2=0;break;//6
		case 7:P2_4=0;P2_3=0;P2_2=1;break;//7
		case 8:P2_4=0;P2_3=0;P2_2=0;break;//8
	}
	P0=NixieTable[number];
	Delay(1);
	P0=0x00;                        //LED消影
}