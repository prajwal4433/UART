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
Init_softUART();
	IODIR0 |=1<<7;
	while(1)
	{
	   softUART_TxByte('A');
		delay_ms(100);
	}

}

void Init_softUART(void)
{
	IODIR0|=(1<<TXD_PIN);
}
	
void softUART_TxByte(u8 sByte)
{
  u32 i;
	IOCLR0=1<<TXD_PIN;
	delay_us(104);
	for(i=0;i<8;i++)
	{
	IOPIN0=(IOPIN0&~(1<<TXD_PIN))|(((rByte>>i)&1)<<TXD_PIN);
		delay_us(104);
	}
	IOSET0=1<<TXD_PIN;
	delay_us(104);
}
