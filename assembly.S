#include <avr/io.h>

.global LED1213

LED1213:
    SBI DDRB, 4
    SBI DDRB, 5
    SBI PORTB, 4
    SBI PORTB, 5
    ret