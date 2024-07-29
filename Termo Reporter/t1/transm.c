/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project :
Version :
Date    : 12/29/2019
Author  :  mehran tamjidi
Company :
Comments:


Chip type               : ATmega16A
Program type            : Application
AVR Core Clock frequency: 4.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16a.h>
#include <delay.h>
#include <stdio.h>
//_________________________________________
interrupt [ADC_INT] void adc_isr(){
unsigned int adc_data;
float   volt;
adc_data=ADCH;
volt=adc_data*2.56/255;
volt=volt*100;
if(volt>=10&& volt<40){ printf("@%2.2f#",volt); PORTB.3=0;}
else if(volt>40 && volt<55 ){ printf("@%2.2f#",volt);PORTB.3=1; }
else if( volt>55 && volt<60 ){ printf("A%2.2f#",volt) ;PORTB.3=1; }
else if( volt>60 && volt<90 ){ printf("D%2.2f#",volt) ;PORTB.3=1; }
else  {printf("@0%2.2f#",volt);   PORTB.3=0;}
delay_ms(250);
ADCSRA=0XCF;
}
//__________________________________________
void main(){
DDRD=0XFF;
PORTD=0X00;
DDRB=0XFF;
ADMUX=0b11100000;    //ADLAR=1   & INTERNAL BANDGAP
ADCSRA=0b10001011; //ADC INTERRUPT ENABLE &PRESCALER 8 --------011
ACSR=0b10000000; //analog comparator
SFIOR=0X00;   // not an special trigger source

//ADMUX=0XC0;
//ADCSRA=0X8F;
// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: Off
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud rate: 9600
UCSRA=0x00;
UCSRB=0x08;
UCSRC=0b10001110;
UBRRH=0x00;
UBRRL=0x19;
#asm("sei")
  PORTB.7=0;

puts("AT+C021") ;
PORTB.7=1;

ADCSRA=0XCF;
while(1){
 };
}