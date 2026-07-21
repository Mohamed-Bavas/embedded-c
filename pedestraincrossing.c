#include <reg51.h>
sbit p_red=P1^0;
sbit p_green=P1^1;
sbit v_red=P1^2;
sbit v_green=P1^3;
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
void delay(){
	TMOD=0X01;
	TH0=0XFC;
	TL0=0X18;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
}
void delays(int d){
	int i;
	for(i=0;i<d;i++){
		delay();
	}
}
void countdown(int c){
	int i;
	for(i=c;i>=0;i--){
		P2=num[i/10];
		P3=num[i%10];
		delays(1000);
	}
}
void main(){
	while(1){
		p_red=1;
		p_green=0;
		v_red=0;
		v_green=1;
		P2=0x00;
		P3=0x00;
		delays(15000);
		p_red=0;
		p_green=1;
		v_red=1;
		v_green=0;
		countdown(15);
	}
}
		