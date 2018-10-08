
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

bool swiching = false;

void opstelling(){
  DDRB = 0b0000001;
  PORTB |= (1<<1);
  PORTB |= (1<<0);
}

// Main function so program can run
int main(void){
    // Run code that only needs to be run once (setup)
    opstelling();

    // Same as Loop() in adruino. Infite loop while 1.
    while(1){

      if (bit_is_clear(PINB, PB1)){
        // PRESSED
        if (swiching == false){
          PORTB ^= (1<<0);
          _delay_ms(200);
        }
        swiching = true;
      }
      else {
        // NOT PRESSED
        if (swiching == true)
        {
          swiching = false;
        }
      }


    }// Return 0 cause main is int
    return 0;
}
