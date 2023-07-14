#include <REGX52.H>
#include "wire_dq.h"

#define DS18B20_SKIP_ROM							0xCC
#define DS18B20_CONVERT_T							0x44
#define DS18B20_READ_SCRATCHPAD						0xBE
void DS18B20_ConvertT(void)
{
	WireDQ_Init();
	WireDQ_SendByte(DS18B20_SKIP_ROM);
	WireDQ_SendByte(DS18B20_CONVERT_T); 
}

float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;
	float temp;
	int T;
	WireDQ_Init();
	WireDQ_SendByte(DS18B20_SKIP_ROM);
	WireDQ_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=WireDQ_ReceiveByte();
	TMSB=WireDQ_ReceiveByte();
	T=(TMSB<<8)|TLSB;
	temp=T/16.0;
	return temp;
} 



	