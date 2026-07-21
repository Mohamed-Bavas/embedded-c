#include <reg51.h>
void delay()
	{
	TMOD=0x00;
	TH0=0xE3;
	TL0=0x07;
	TR0=1;
	while(TF0==0);
		TR0=0;
		TF0=0;
	
}
void main()
	{
		unsigned int i;
		while(1){
			for( i=0;i<1000;i++){
				delay();
			}
			P2 = ~P2;
		}
	}