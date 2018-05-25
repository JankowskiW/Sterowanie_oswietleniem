#include <avr\io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define UART_BAUD 4800
#define __UBRR ((F_CPU+UART_BAUD*8UL) / (16UL*UART_BAUD)-1)
//zmienne dot. odbioru danych
volatile unsigned char odb_x;       //odebrana liczba X
volatile unsigned char odb_flaga = 0;//flaga informujaca o odebraniu liczby


void USART_Init()
{

	 #define BAUD 9600        //9600bps standardowa predkosc transmisji modulu HC-05
	 #include <util/setbaud.h> //linkowanie tego pliku musi byc po zdefiniowaniu BAUD

	 //ustaw obliczone przez makro wartoœci
	 UBRRH = UBRRH_VALUE;
	 UBRRL = UBRRL_VALUE;
	 #if USE_2X
	   UCSRA |=  (1<<U2X);
	 #else
	   UCSRA &= ~(1<<U2X);
	 #endif

	 UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
	 UCSRB = (1<<TXEN) | (1<<RXEN) | (1<<RXCIE);
}

//--------------------------------------------------------------


ISR(USART_RXC_vect)
{
 //przerwanie generowane po odebraniu bajtu
 odb_x = UDR;   //zapamietaj odebrana liczbe
 odb_flaga = 1; //ustaw flage odbioru liczby dla main()
}


//--------------------------------------------------------------


int main(void)
{
	USART_Init(); //inicjuj modul USART (RS-232)
	sei();           //wlacz przerwania globalne

	DDRC |= (1<<PC5);
	PORTC |= (1<<PC5);
	while(1)
	{
		if(odb_flaga)
		{
			odb_flaga = 0; //zgas flage
			if(odb_x == '1')
			{
				PORTC = (1<<PC5);
			}else
			{
				PORTC = (0<<PC5);
			}
		}
	}
}
