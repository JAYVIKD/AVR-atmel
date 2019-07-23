#include "LCD_4BIT.h"


void config_lcd(){
	_delay_ms(15);
	DDRB=0xFF;
	PORTB=0x00;
	cmd_config(0x02);
	cmd_config(0x28);
	cmd_config(0x0E);
	cmd_config(0x06);
	cmd_config(0x01);
	cmd_config(0x80);
	
}

void cmd_config(char DATA){
	
	PORTB =(DATA>>4);
	PORTB &= ~(1<<RS);
	PORTB |= (1<<E);
	_delay_ms(mdelay);
	PORTB &= ~(1<<E);
	
	PORTB = DATA;
	PORTB &= ~(1<<RS);
	PORTB |= (1<<E);
	_delay_ms(mdelay);
	PORTB &= ~(1<<E);
	
}

void cmd(char DATA){
	
	PORTB = (DATA>>4) ;
	PORTB |= (1<<RS);
	PORTB |= (1<<E);
	_delay_ms(mdelay);
	PORTB &= ~(1<<E);
	
	PORTB =(DATA);
	PORTB |=(1<<RS);
	PORTB |= (1<<E);
	_delay_ms(mdelay);
	PORTB &= ~(1<<E);
	
}
void clc(){
	cmd_config(0x01);
}


void lcd(int n){
	if(n<0){
		n=-n;
		cmd('-');
	}
	char str[16];
	int rem,len=0,num;
	num=n;
	while(num!=0){
		len++;
		num/=10;
	}
	for(int i=0;i<len;i++){
		rem=n%10;
		n=n/10;
		str[len-(i+1)]=rem+'0';
	}
	str[len]='\0';
	lcd(str);

}

void lcd(long int n){
	long int remd,rev=0;
	int count=0;
	char s[16];
	while(n!=0){
		remd=n%10;
		n=n/10;
		rev=10*rev+remd;
		remd+=48;
		s[count++]=remd;
	}
	char srev[count];
	for(int i=0;i<count;i++){
		srev[i]=s[count-i-1];
	}
	lcd(srev,1);

}

void lcd(char s[]){
	for(int i=0;s[i]!='\0';i++){
		cmd(s[i]);
	}
}


void lcd(char s[],int line_no=1){
	if(line_no==2)
	cmd_config(0xC0);
	for(int i=0;s[i]!='\0';i++){
		cmd(s[i]);
	}
}

void lcd(float n,int d=3){
	
	lcd((int)n);
	n-=(int)n;
	n=n*pow(10,d);
	cmd(46);
	lcd((int)n);
	
}

void lcd(double n,int d=3){
	
	lcd((int)n);
	n-=(int)n;
	n=n*pow(10,d);
	cmd(46);
	lcd((int)n);
}

void lcd(float n){
	
	lcd((int)n);
	n-=(int)n;
	n=n*pow(10,3);
	cmd(46);
	lcd((int)n);
	
}
