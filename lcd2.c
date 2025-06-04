#include<lpc21xx.h>
#include"types2.h"
#include"delay2.h"
//#include"lc_defines2.h"
#define LCD_DATA 8
#define RW 16
#define RS 17
#define EN 18



void cmdlcd(u8 cmd)
{

}
void initlcd(void)
{
  IODIR0 |=0XFF<<LCD_DATA|1<<RW|1<<RS|1<<EN;
	delay_ms(15);
	cmdlcd(0x30);
	delay_ms(2);
	delay_us(100);
	cmdlcd(0x30);
	delay_us(100);
	cmdlcd(0x30);
	cmdlcd(0x38);
	cmdlcd(0x0f);
	cmdlcd(0x01);
	cmdlcd(0x06);
}

