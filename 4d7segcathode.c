#include <reg51.h>

unsigned char num[]={
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

void delay()
{
    unsigned int i,j;

    for(i=0;i<200;i++)
    {
        for(j=0;j<1000;j++);
    }
}

void main()
{
    unsigned int i;

    while(1)
    {   
        for(i=0;i<=9999;i++)
        { 
            P0 = num[(i/1000)%10];
            P1 = num[(i/100)%10];
            P2 = num[(i/10)%10];
            P3 = num[i%10];

            delay();
        }
    }
}