#include <avr/io.h>
//function header biar data bisa dikirim
#define F_CPU 16000000UL
//enih ngasi tau mikro crystal oscillator kita frekuensinya berapa 
#include <util/delay.h>
//biar bisa make delay 

int main(void)
{
    DDRD |= 1 << PIND1;           //pin1 di portD sebagai OUTPUT
    DDRD &= ~(1 << PIND0);        //pin0  di portD sebagai INPUT
    PORTD |= 1 << PIND0;
    int UBBRValue = 25;           //setting baud rate yang dipake

    //taro bit awal baud rate kita (bits 8 to 11)
    UBRRH = (unsigned char) (UBBRValue >> 8);
    //sisanya taro di sokin
    UBRRL = (unsigned char) UBBRValue;

    //nyalain rx ama tx 
    UCSRB = (1 << RXEN) | (1 << TXEN);

    //Setting stop bit (2 bit) dan panjang data bit 8
    UCSRC = (1 << USBS) | (3 << UCSZ0);

    while (1)
    {
        if (bit_is_clear(PINC,0)) // pas button dipencet
        {
            while (! (UCSRA & (1 << UDRE)) );
            {
                UDR = 0b11110000;	
            }
            // Get that data f out of here (GTDFO)
            _delay_ms(220);
        }
    }
}
