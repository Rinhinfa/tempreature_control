#include <REGX52.H>


void Timer1_Init(void)		//10΢��@12.000MHz
{
	TMOD=0x11;		//���ö�ʱ��ģʽ
	TL1 = 0xF6;		//���ö�ʱ��ֵ
	TH1 = 0xFF;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF1��־
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	ET1=1;
	PT1=0;
	EA=1;


}
void Timer0_Init(void)		//1����@12.000MHz
{
	TMOD=0x11;		//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0=1;
	PT0=0;
	EA=1;
}

