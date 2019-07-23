#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include<string.h>
#include<math.h>

//port definations
#define RS 4
#define E 5
#define DB4 0
#define DB5 1
#define DB6 2
#define DB7 3
#define mdelay 2

void config_lcd();
void cmd(char DATA);
void cmd_config(char DATA);
void lcd(char s[]);
void lcd(char s[],int line_no);
void lcd(int a);
void lcd(float b);
void lcd(float b,int d);
void lcd(double b,int d);
void clc();

int main(){
	config_lcd();
	while(1){clc();
				lcd(11);		
			_delay_ms(1000);
			clc();
			lcd(("jayvik");
			_delay_ms(1000);
	}
}
void config_lcd(){
	_delay_ms(15);
	DDRB=0x0F;
	DDRA=0x30;
	PORTB=0x00;
	PORTA=0x00;
	cmd_config(0x02);
	cmd_config(0x28);
	cmd_config(0x0E);
	cmd_config(0x06);
	cmd_config(0x01);
	cmd_config(0x80);
	
}

void cmd_config(char DATA){
	
	PORTB |=(DATA>>4);
	PORTA &= ~(1<<RS);
	PORTA |= (1<<E);
	_delay_ms(mdelay);
	PORTA &= ~(1<<E);
	
	PORTB |= DATA;
	PORTA &= ~(1<<RS);
	PORTA |= (1<<E);
	_delay_ms(mdelay);
	PORTA &= ~(1<<E);
	
}

void cmd(char DATA){
	
	PORTB |= (DATA>>4) ;
	PORTA |= (1<<RS);
	PORTA |= (1<<E);
	_delay_ms(mdelay);
	PORTA &= ~(1<<E);
	
	PORTB |=(DATA);
	PORTA |=(1<<RS);
	PORTA |= (1<<E);
	_delay_ms(mdelay);
	PORTA &= ~(1<<E);
	
}
void clc(){
	cmd_config(0x01);
}


void lcd(int n){
	if(n<0){
		n=-n;
		cmd('-');
	}
	if (n==0){
		cmd('0');
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


void lcd(char s[],int line_no){
	if(line_no==2)
	cmd_config(0xC0);
	for(int i=0;s[i]!='\0';i++){
		cmd(s[i]);
	}
}

void lcd(float n,int d){
	
	lcd((int)n);
	n-=(int)n;
	n=n*pow(10,d);
	cmd(46);
	lcd((int)n);
	
}

void lcd(double n,int d){
	
	lcd((int)n);
	n-=(int)n;
	n=n*pow(10,d)+1;
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
