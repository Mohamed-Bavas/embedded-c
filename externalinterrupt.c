#include <reg51.h>
sbit main_led = P2^0;
sbit x0_led = P2^1;
sbit x1_led = P2^2;
void delay(){
	unsigned int i,j;
	for(i=0;i<200;i++)
	for(j=0;j<1000;j++);
}
void x0_ISR(void) interrupt 0{
	x0_led=1;
	delay();
	x0_led=0;
	delay();
}
void x1_ISR(void) interrupt 2{
	x1_led=1;
	delay();
	x1_led=0;
	delay();
}
void main(){
	main_led=0;
	x0_led=0;
	x1_led=0;
	TCON=0X05;
	IE=0X85;
	IP=0x01;
	while(1){
		main_led=1;
		delay();
		main_led=0;
		delay();
	}
}
