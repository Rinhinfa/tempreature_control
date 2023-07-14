#include <regx52.h>
#include  "delay.h"
#include  "ds18b20.h"
#include  "timer.h"
#include  "lcd1602.h"
#include  "tb6612.h"

sbit STBY=P1^0;
sbit PWMA=P1^1;
sbit PWMB=P1^2;
sbit AIN1=P1^3;
sbit AIN2=P1^4;
sbit BIN1=P1^5;
sbit BIN2=P1^6;


float temp;   //ȫ�ֿɵ��õļ�ʱ�¶�
int temp_target=45;		//Ŀ���¶�
void main()
{   
	DS18B20_ConvertT();	
	Delay(1000);       
	LCD_Init();    //��ʼ��LCD
	LCD_ShowString(1,1,"TEMP:");
	LCD_ShowChar(1,7,'+');
	LCD_ShowString(2,1,"Target:+");
	LCD_ShowNum(2,9,temp_target,2);
	LCD_ShowString(2,11,"C");
	LCD_ShowString(1,16,"C");
	TB6612_Init();		//��ʼ���������оƬ
	
	
	
	while(1)
	{
		DS18B20_ConvertT(); 
		temp=DS18B20_ReadT();
		LCD_ShowChar(1,11,'.');
		LCD_ShowNum(1,8,temp,3);
		LCD_ShowNum(1,12,(unsigned long)(temp*10000)%10000,4);
			if(temp_target-temp>0.2)			//���Ͻӽ�Ŀ���¶ȣ���ʼ����,����ͣ
			{
				Gate1_Start();
				Gate2_Stop();				
			}
			else if(temp_target-temp<-0.3)	//���½ӽ�Ŀ���¶ȣ�ֹͣ���ȣ����ȿ�
			{
				Gate1_Stop();
				Gate2_Start();
			}
			else
			{	
				Gate1_Stop();
				Gate2_Stop();
			}
	}
}



unsigned char counter0,counter1;		//����������
unsigned char percent0=35;   	 //ռ�ձ�65%
unsigned char percent1=80;    	 //ռ�ձ�20%



void Timer0_routine() interrupt 1  //��ʱ�����PWMA�ź� @1kHz		
{
	
	TL0=0x9C;		//PWM@1kHz
	TH0=0xFF;
	counter0++;
	counter0%=100;
	if(counter0<percent0)
	{	
		PWMA=1;
	}
	else
	{
		PWMA=0;
	}
}


void Timer1_routine() interrupt 2  //��ʱ�����PWMB�ź� @100kHz		
{
	
	TL1=0xF5;		//PWM@100kHz
	TH1=0xFF;
	counter1++;
	counter1%=100;
	if(counter1<percent1)
	{	
		PWMB=1;
	}
	else
	{
		PWMB=0;
	}
}


		
	
		