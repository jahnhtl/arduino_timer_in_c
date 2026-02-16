#include <Arduino.h>

void setup()
{
  // Pin PB5 als Ausgang konfigurieren
  DDRB = DDRB | (1 << PB5);

  // Timer2 konfigurieren mit Prescaler 1024
  TCCR2B = (1 << CS22) | (1 << CS21) |(1 << CS20);

}

void loop()
{
  static uint8_t overflows_anzahl = 0;

  // Check ob Overflow von Timer0 aufgetreten ist
  if(TIFR2 & (1 << TOV2))
  {
    overflows_anzahl++;
    TIFR2 = TIFR2 | (1 << TOV2);
  }

  if(overflows_anzahl >= 32)
  {
    PORTB = PORTB ^ (1 << PB5);
    overflows_anzahl = 0;
  }
}
