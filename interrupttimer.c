#include <reg51.h>
sbit led=P1^0;
sbit m1=P2^0;
sbit m2=P2^1;
unsigned int count =0;
void delay(){
	unsigned int i,j;
	for(i=0;i<200;i++)
	for(j=0;j<10000;j++);
}
void main(){
	P3=0x04;
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x67;
	IT0=1;
	IE=0x83;
	IP=0x01;
	TR0=1;
	while(1);
}
void ISR_Timer0(void) interrupt 1
{
	TH0=0xFC;
	TL0=0x67;
	count++;
	if(count>=1000){
		led=~led;
		count=0;
}
	}
void ISR_Ex0(void) interrupt 0
{
	m1=1;
	m2=0;
	delay();
	m1=0;
	m2=0;
}