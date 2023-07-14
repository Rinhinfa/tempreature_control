#ifndef __WIRE_DQ_H__
#define __WIRE_DQ_H__

void WireDQ_Init(void);
void WireDQ_SendBit(unsigned char Bit);
unsigned char WireDQ_ReceiveBit();
void WireDQ_SendByte(unsigned char Byte);
unsigned char WireDQ_ReceiveByte(void);


#endif