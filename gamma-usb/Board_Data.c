#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t port_to_tris_PGM[] = {
    NOT_A_PORT,                //index value 0 is not used

#if defined(_PORTA)
    (uint32_t)&TRISA,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTB)
    (uint32_t)&TRISB,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTC)
    (uint32_t)&TRISC,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTD)
    (uint32_t)&TRISD,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTE)
    (uint32_t)&TRISE,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTF)
    (uint32_t)&TRISF,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTG)
    (uint32_t)&TRISG,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTH)
    (uint32_t)&TRISH,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTJ)
    (uint32_t)&TRISJ,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTK)
    (uint32_t)&TRISK,
#else
    NOT_A_PORT,
#endif
    
    NOT_A_PORT,
};  


const uint8_t digital_pin_to_port_PGM[] = {
    _IOPORT_PB,    // 0: RB8
    _IOPORT_PB,    // 1: RB9
    _IOPORT_PB,    // 2: RB7
    _IOPORT_PB,    // 3: RB5
    _IOPORT_PB,    // 4: RB4
    _IOPORT_PA,    // 5: RA4
    _IOPORT_PB,    // 6: RB0
    _IOPORT_PB,    // 7: RB1
};

const uint16_t digital_pin_to_bit_mask_PGM[] = {
    _BV(8),   // 0: RB8
    _BV(9),   // 1: RB9
    _BV(7),   // 2: RB7
    _BV(5),   // 3: RB5
    _BV(4),   // 4: RB4
    _BV(4),   // 5: RA4
    _BV(0),   // 6: RB0
    _BV(1),   // 7: RB1
};

const uint16_t digital_pin_to_timer_PGM[] = {
    NOT_ON_TIMER,   // 0: RB8
    NOT_ON_TIMER,   // 1: RB9
    NOT_ON_TIMER,   // 2: RB7
    NOT_ON_TIMER,   // 3: RB5
    NOT_ON_TIMER,   // 4: RB4
    NOT_ON_TIMER,   // 5: RA4
    NOT_ON_TIMER,   // 6: RB0
    NOT_ON_TIMER,   // 7: RB1
};

const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN,   // 0: RB8
    NOT_ANALOG_PIN,   // 1: RB9
    NOT_ANALOG_PIN,   // 2: RB7
    NOT_ANALOG_PIN,   // 3: RB5
    NOT_ANALOG_PIN,   // 4: RB4
    NOT_ANALOG_PIN,   // 5: RA4
    NOT_ANALOG_PIN,   // 6: RB0
    NOT_ANALOG_PIN,   // 7: RB1
};

const uint8_t analog_pin_to_channel_PGM[] = {
    NOT_ANALOG_PIN,
};

const  uint8_t digital_pin_to_pps_out_PGM[] = {
    _PPS_OUT(_PPS_RPB8R),
    _PPS_OUT(_PPS_RPB9R),
    _PPS_OUT(_PPS_RPB7R),
    _PPS_OUT(_PPS_RPB5R),
    _PPS_OUT(_PPS_RPB4R),
    _PPS_OUT(_PPS_RPA4R),
    _PPS_OUT(_PPS_RPB0R),
    _PPS_OUT(_PPS_RPB1R),
};

const  uint8_t digital_pin_to_pps_in_PGM[] = {
    _PPS_IN(_PPS_RPB8),
    _PPS_IN(_PPS_RPB9),
    _PPS_IN(_PPS_RPB7),
    _PPS_IN(_PPS_RPB5),
    _PPS_IN(_PPS_RPB4),
    _PPS_IN(_PPS_RPA4),
    _PPS_IN(_PPS_RPB0),
    _PPS_IN(_PPS_RPB1),
};

const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
};

const uint8_t external_int_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
};

#if    (OPT_BOARD_INIT != 0)

void _board_init(void) {

}

#endif
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_pinMode(uint8_t pin, uint8_t mode) {

    return 0;

}

#endif
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_getPinMode(uint8_t pin, uint8_t * mode) {

    return 0;

}

#endif
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalWrite(uint8_t pin, uint8_t val) {

    return 0;

}

#endif
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalRead(uint8_t pin, uint8_t * val) {

    return 0;

}

#endif
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogRead(uint8_t pin, int * val) {

    return 0;

}

#endif
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogReference(uint8_t mode) {

    return 0;

}

#endif
#if (OPT_BOARD_ANALOG_WRITE != 0)

int    _board_analogWrite(uint8_t pin, int val) {

    return 0;

}

#endif
#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif    // BOARD_DATA_C

