#include <avr/io.h>

#define F_CPU 16000000UL
#define BLINK_DELAY_MS 5000

#include <util/delay.h>

int main (void)
{
  // PB5 untuk output
  DDRB |= 0B100000; // PORTB5

  while(1) {
    // Idupin LED
    PORTB |= 0B100000; // PORTB5
    _delay_ms(BLINK_DELAY_MS);

    // matiin LED
    PORTB &= ~ 0B100000; // PORTB5
    _delay_ms(BLINK_DELAY_MS);
  }
}
