#include <reg51.h>
void delay(){
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x18;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
	}
void delay1s(){
	unsigned int i;
	for(i=0;i<1000;i++){
		delay();
	}
}
void main(){
	while(1){
	P2=0x09;
	P3=0x24;
		delay1s();
	P2=0x12;
	P3=0x24;
		delay1s();
	P2=0x24;
	P3=0x09;
		delay1s();
	P2=0x24;
	P3=0x12;
		delay1s();
}
}