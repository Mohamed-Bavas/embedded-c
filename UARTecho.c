#include <reg51.h>

void UART_init()
{
    TMOD = 0x20;      // Timer1 Mode2
    TH1  = 0xFD;      // 9600 baud
    SCON = 0x50;      // UART Mode1, Receiver Enable
    TR1  = 1;         // Start Timer1
}

void sendchar(char ch)
{
    SBUF = ch;
    while(TI == 0);
    TI = 0;
}

char receivechar()
{
    while(RI == 0);
    RI = 0;
    return SBUF;
}

void main()
{
    char ch;

    UART_init();

    while(1)
    {
        ch = receivechar(); // Receive one character
        P2 = ch;            // Display ASCII on Port 2
        sendchar(ch);       // Echo back
    }
}