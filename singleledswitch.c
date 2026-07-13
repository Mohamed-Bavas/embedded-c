#include <reg51.h>

sbit sw  = P2^1;
sbit led = P3^1;

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 200; i++)
    {
        for(j = 0; j < 1000; j++);
    }
}

void main(void)
{
    while(1)
    {
        if(sw == 0)      
        {
            led = 1;     
        }
        else             
        {
            led = 0;    
        }

        delay();
    }
}