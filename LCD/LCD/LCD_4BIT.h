#ifndef LCD_4BIT_H
#define LCD_4BIT_H
//header files
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
void lcd(char s[],int line_no);
void lcd(int a);
void lcd(char s[]);
void lcd(char s[],int line_no);
void lcd(float b);
void lcd(float b,int d);
void lcd(double b,int d);
void clc();

#endif