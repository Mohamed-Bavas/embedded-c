#include <reg51.h>
void UART_init(){
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
}
char UART_receive(){
	
	while(RI==0){
		RI=0;
		return SBUF;
	}
}
void main(){
	char hdata;
	UART_init();
	while(1){
		
	 hdata=UART_receive();
		P2=hdata;
	}
}
		