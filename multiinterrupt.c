#include <reg51.h>

sbit led1 = P2^0;
sbit led2 = P2^1;
sbit led3 = P2^2;
sbit M1   = P2^3;
sbit M2   = P2^4;

unsigned int count = 0;

void delay()
{
    unsigned int i, j;

    for(i = 0; i < 200; i++)
        for(j = 0; j < 1000; j++);
}

void main()
{
    P2 = 0x00;
    P3 = 0x0C;          
    TMOD = 0x01;       

    TH0 = 0xFC;         
    TL0 = 0x67;

    IE=0x8F;           

    IT0 = 1;            
    IT1 = 1;            

    IP=0x04;            

    TR0 = 1;            

    while(1)
    {
        led1 = ~led1;
        delay();
    }
}
void ISR_Timer0(void) interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x67;

    count++;

    if(count >= 1000)
    {
        led2 = ~led2;
        count = 0;
    }
}
void ISR_X0(void) interrupt 0
{
    led3 =1;
	  delay();
	led3=0;
}
void ISR_X1(void) interrupt 2
{
    M1 = 1;
    M2 = 0;

    delay();        

    M1 = 0;
    M2 = 0;
}