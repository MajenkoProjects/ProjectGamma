#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

#if defined(OPT_BOARD_DATA)

const uint32_t	port_to_tris_PGM[] = {
	NOT_A_PORT,
	(uint32_t)&TRISA,
	(uint32_t)&TRISB,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
};

const uint8_t	digital_pin_to_port_PGM[] = {
    _IOPORT_PB, _IOPORT_PB, _IOPORT_PB, _IOPORT_PB, _IOPORT_PB, _IOPORT_PA
};

const uint16_t	digital_pin_to_bit_mask_PGM[] = {
    _BV(8), _BV(9), _BV(7), _BV(5), _BV(4), _BV(4)
};

const uint16_t	digital_pin_to_timer_PGM[] = {
    NOT_ON_TIMER, NOT_ON_TIMER, NOT_ON_TIMER, NOT_ON_TIMER, NOT_ON_TIMER, NOT_ON_TIMER
};

const uint8_t digital_pin_to_pps_out_PGM[] = {
    _PPS_OUT(_PPS_RPB8R), _PPS_OUT(_PPS_RPB9R), _PPS_OUT(_PPS_RPB7R), 
    _PPS_OUT(_PPS_RPB5R), _PPS_OUT(_PPS_RPB4R), _PPS_OUT(_PPS_RPA4R)
};

const uint8_t digital_pin_to_pps_in_PGM[] = {
    _PPS_IN(_PPS_RPB8), _PPS_IN(_PPS_RPB9), _PPS_IN(_PPS_RPB7), 
    _PPS_IN(_PPS_RPB5), _PPS_IN(_PPS_RPB4), _PPS_IN(_PPS_RPA4)
};

const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN, NOT_ANALOG_PIN, NOT_ANALOG_PIN,
    NOT_ANALOG_PIN, NOT_ANALOG_PIN, NOT_ANALOG_PIN
};

const uint8_t output_compare_to_digital_pin_PGM[] = {
    0,
	PIN_OC1,	        // A0, B3, B4, B15, B7  ; B15   RPB15R  = 5  	
	PIN_OC2,	        // A1, B5, B1, B11, B8  ; B8    RPB8R   = 5
	PIN_OC3,	        // A3, B14, B0, B10, B9 ; B9    RPB9R   = 5
	PIN_OC4,	        // A2, B6, A4, B13, B2  ; B2    RPB2R   = 5
	PIN_OC5,	        // A2, B6, A4, B13, B2	; B13   RPB13R  = 6
};

const uint8_t external_int_to_digital_pin_PGM[] = {
	NOT_PPS_PIN,		// INT0 is not mappable;    RB7
	PIN_INT1,			// A3, B14, B0, B10, B9;    B9  INT1R = RPB9 = 4
	PIN_INT2,			// A2, B6, A4, B13, B2;     B2  INT2R = RPB2 = 4
	PIN_INT3,			// A1, B5, B1, B11, B8;     B8  INT3R = RPB8 = 4
	PIN_INT4			// A0, B3, B4, B15, B7;     B4  INT4R = RPB4 = 2
};

#if	(OPT_BOARD_INIT != 0)

void _board_init(void) {

	//	Turn Secondary oscillator off as GPIO is needed
	OSCCONCLR	=	_OSCCON_SOSCEN_MASK;
	
}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif	// BOARD_DATA_C

/************************************************************************/
