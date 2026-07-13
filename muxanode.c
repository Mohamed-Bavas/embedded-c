#include <reg51.h>

sbit c1 = P1^0;      // Tens digit control
sbit c2 = P1^1;      // Units digit control

unsigned char num[] =
{
   0xC0,
	0xF9,
	0xA4,
	0xB0,
	0x99,
	0x92,
	0x82,
	0xF8,
	0x80,
	0x90
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
            c1 = 1;
            c2 = 0;
            delay();

            // Display Units Digit
            P2 = num[i%10];
            c1 = 0;
            c2 = 1;
            delay();
        }
    }
}