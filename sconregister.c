#include <reg51.h>

void main()
{
    TMOD = 0x20;      // Timer1 Mode2 (8-bit auto reload)
    TH1  = 0xFD;      // 9600 baud for 11.0592MHz
    TL1  = 0xFD;
    TR1  = 1;         // Start Timer1

    SCON = 0x50;      // UART Mode1, REN=1

    TI = 1;           // Set TI initially

    SBUF = 'B';       // Send 'A'

    while(TI == 0);   // Wait until transmission complete
    TI = 0;
	
    while(1);
}