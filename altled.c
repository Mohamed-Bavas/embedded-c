#include <reg51.h>

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
        P1 =0xAA;    // Turn ON all LEDs (assuming active LOW)
        delay();

        P1 =0x55;    // Turn OFF all LEDs
        delay();
    }
}