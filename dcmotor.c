#include <reg51.h>
sbit IN1=P2^0;
sbit IN2=P2^1;
sbit EN1=P2^2;
sbit EN2=P2^3;
sbit IN3=P2^4;
sbit IN4=P2^5;
void forward();
void reverse();
void main(){
	EN1=1;
	EN2=1;
	while(1){
		forward();
		reverse();
	}
}
void forward(){
	IN1=1;
	IN2=0;
}
void reverse(){
	IN3=0;
	IN4=1;
}