#include <REGX52.H>


void Timer1_Init(void)		//10微秒@12.000MHz
{
	TMOD=0x11;		//设置定时器模式
	TL1 = 0xF6;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1=1;
	PT1=0;
	EA=1;


}
void Timer0_Init(void)		//1毫秒@12.000MHz
{
	TMOD=0x11;		//设置定时器模式
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	PT0=0;
	EA=1;
}

