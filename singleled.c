#include <reg51.h>
 sbit led=P2^1;

void delay()
{
    unsigned int i,j;
    for(i = 0; i <200; i++)
    {
			for(j=0;j<1000;j++);
        // Empty loop for delay
    }
}

void main()
{   
   
    while(1)
    {
        led=0;    // Turn ON all LEDs (assuming active LOW)
        delay();
			led=1;
			delay();
        
    }
}