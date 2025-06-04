#include<lpc21xx.h>
#include"types.h"
#include"delay.h"

#define TXD_PIN 0
#define RXD_PIN 1
#define BAUD9600 104
void Init_softUART(void);
void softUART_TxByte(u8);
u8 softUART_RxByte(void);
u8 rByte;

main()
{
		PINSEL0=0x00000001|0x00000004;
Init_softUART();
	IODIR0 |=1<<7;

	while(1)
	{
	   rByte=softUART_RxByte();
		if(rByte=='A')
			IOPIN0^=1<<7;
	
	}

}

void Init_softUART(void)
{
	IODIR0|=(1<<TXD_PIN);
}
	
u8 softUART_RxByte(void)
{
  u32 i;
	//u8 rByte;
	while(((IOPIN0>>RXD_PIN)&1)==1);
	IOCLR0=1<<TXD_PIN;
	delay_us(104);

	for(i=0;i<8;i++)
	{
	delay_us(104);
	rByte=(rByte&~(1<<i))|(((IOPIN0>>RXD_PIN)&1)<<i);
	}
			delay_us(104);
	
	    while(((IOPIN0>>RXD_PIN)&1)!=1);
	return rByte;
}
