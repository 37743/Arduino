#define __AVR_ATmega32U4__
#define __SFR_OFFSET 0
#include <avr/io.h>

.global LEDSetUP
.global LEDon
.global LEDoff
.global SPCLEDon
.global SPCLEDoff
.global NEWDelay

LEDSetUP:
    ldi r21, 0x0
    SEC
L:
    rol R21
    dec R24
    brne L
    
    in R23, DDRB
    or R23, R21
    out DDRB, R23
    mov r24, r23

    ret

LEDon:
    sbi PORTB, 4
    ret

SPCLEDon:
    sbi PORTB, 5
    ret

LEDoff:
    cbi PORTB, 4
    ret

SPCLEDoff:
    cbi PORTB, 5
    ret