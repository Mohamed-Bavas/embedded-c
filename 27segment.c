#include <reg51.h>
unsigned char num[]={
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
void delay(){
	unsigned int i,j;
	for(i=0;i<200;i++){
		for(j=0;j<1000;j++);
}
	}
void main(){
	int i;
	while(1){
		for(i=0;i<=99;i++){
			P2=num[i/10];
			P3=num[i%10];
			delay();
		}
}
	}
