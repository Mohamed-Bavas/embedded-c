#include <reg51.h>

void delay()
{
    unsigned int i;
    for(i = 0; i < 7000; i++)
    {
        // Empty loop for delay
    }
}

void main()
{
    while(1)
    {
        P0 = 0x00;    // Turn ON all LEDs (assuming active LOW)
        delay();

        P0 = 0xFF;    // Turn OFF all LEDs
        delay();
    }
}