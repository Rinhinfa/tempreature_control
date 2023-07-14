#include <REGX52.H>
#include <timer.h>


sbit STBY=P1^0;
sbit PWMA=P1^1;
sbit PWMB=P1^2;
sbit AIN1=P1^3;
sbit AIN2=P1^4;
sbit BIN1=P1^5;
sbit BIN2=P1^6;

void TB6612_Init()            //驱动芯片待机，开始输出PWM信号
{
	STBY=1;
	PWMA=1;
	PWMB=1;
	AIN1=0;
	AIN2=0;
	BIN1=0;
	BIN2=0;
	Timer0_Init;
	Timer1_Init();  			
}

void Gate1_Start()
{
	STBY=1;
	AIN1=0;
	AIN2=1;
}

void Gate2_Start()
{
	STBY=1;
	BIN1=0;
	BIN2=1;
}

void Gate1_Stop()
{
	STBY=1;
	AIN1=0;
	AIN2=0;
}


void Gate2_Stop()
{
	STBY=1;
	BIN1=0;
	BIN2=0;
}

	
	
	
	
	
	
	
	
