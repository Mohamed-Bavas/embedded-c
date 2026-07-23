#include <reg51.h>
void UART_init(){
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
}
void UART_char(char ch){
	
	SBUF=ch;
	while(TI==0);
	TI=0;
}
void UART_str(char *str){
	
	while(*str){
		UART_char(*str);
		str++;
	}
}void main(){
	UART_init();
	while(1){
		UART_str("HELLO\r\n");
	}
}