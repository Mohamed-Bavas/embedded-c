#include <reg51.h>

sbit c1 = P1^0;      // Tens digit control
sbit c2 = P1^1;      // Units digit control

unsigned char num[] =
{
    0x3F,
    0x06,
    0x5B,
    0x4F,
    0x66,
    0x6D,
    0x7D,
    0x07,
    0x7F,
    0x6F
};

unsigned char i;
//unsigned char tens, units;

void delay()
{
    unsigned int i, j;

    for(i = 0; i < 200; i++)
    {
        for(j = 0; j < 100; j++);
    }
}

void main()
{
    while(1)
    {
        for(i = 0; i <= 99; i++)
        {
           // tens = i / 10;
            // units = i % 10;

            // Display Tens Digit
            P2 = num[i/10];
            c1 = 0;
            c2 = 1;
            delay();

            // Display Units Digit
            P2 = num[i%10];
            c1 = 1;
            c2 = 0;
            delay();
        }
    }
}