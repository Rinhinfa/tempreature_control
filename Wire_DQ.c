#include <regx52.h>


sbit Wire_DQ = P3^7;

unsigned char WireDQ_Init(void)		//初始化
{
	unsigned char i;
	unsigned char ackbit;
	Wire_DQ=1;
	Wire_DQ=0;
	i=247;while(--i);      //delay 500us
	Wire_DQ=1;
	i=32;while(--i);       //delay 70us
	ackbit=Wire_DQ;
	i=247;while(--i);      //delay 500us
	return ackbit;
}


void WireDQ_SendBit(unsigned char Bit)   //时序：发送一位
{
	unsigned char i;
	Wire_DQ=0;
	i=4;while(--i);     //delay 10us
	Wire_DQ=Bit;
	i=24;while(--i);    //dalay 50us
	Wire_DQ=1;
}


unsigned char WireDQ_ReceiveBit(void)		//时序：接受一位
{
	unsigned char i;
	unsigned char Bit;
	Wire_DQ=0;
	i=2;while(--i);     //delay 5us
	Wire_DQ=1;
	i=2;while(--i);		//delay 5us
	Bit=Wire_DQ;
	i=24;while(--i);  	//delay 50us
	return Bit;
}

void WireDQ_SendByte(unsigned char Byte)		//发送一个字节
{
	
	unsigned char i;
	for(i=0;i<8;i++)
	{
		WireDQ_SendBit(Byte&0x01<<i);
	}
}

unsigned char WireDQ_ReceiveByte(void)		//接受一个字节
{
	unsigned char i;
	unsigned char Byte=0x00;
	for(i=0;i<8;i++)
	{
		if(WireDQ_ReceiveBit())
		{
			Byte|=(0x01<<i);
		}
	}
	return Byte;
}



	