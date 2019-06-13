#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>
#define _USB

#ifndef _TIMER_1_IRQ
#define _TIMER_1_IRQ _TIMER_1_VECTOR
#endif


#undef digitalPinToAnalog
#define digitalPinToAnalog(P) (((P) < NUM_ANALOG_PINS) ? (P) : (digital_pin_to_analog_PGM[P]))

#undef analogInPinToChannel
#define analogInPinToChannel(P) (analog_pin_to_channel_PGM[P])

#if !defined(OPT_BOARD_DATA)

extern const uint32_t   port_to_tris_PGM[];
extern const uint8_t    digital_pin_to_port_PGM[];
extern const uint16_t   digital_pin_to_bit_mask_PGM[];
extern const uint16_t   digital_pin_to_timer_PGM[];

extern const uint8_t    output_compare_to_digital_pin_PGM[];
extern const uint8_t    external_int_to_digital_pin_PGM[];

extern const uint8_t    analog_pin_to_channel_PGM[];
extern const uint8_t    digital_pin_to_analog_PGM[];

extern const uint8_t    digital_pin_to_pps_out_PGM[];
extern const uint8_t    digital_pin_to_pps_in_PGM[];

#endif

#define _BOARD_NAME_ "Project Gamma (USB)"

#define NUM_DIGITAL_PINS     11
#define NUM_ANALOG_PINS      0
#define NUM_OC_PINS          0
#define NUM_IC_PINS          0
#define NUM_TCK_PINS         0
#define NUM_INT_PINS         0

#define NUM_DIGITAL_PINS_EXTENDED NUM_DIGITAL_PINS
#define NUM_ANALOG_PINS_EXTENDED NUM_ANALOG_PINS

#define NUM_SERIAL_PORTS     1
#define NUM_SPI_PORTS        0
#define NUM_DSPI_PORTS       0
#define NUM_I2C_PORTS        0
#define NUM_DTWI_PORTS       0

#define NUM_LED              2
#define NUM_BTN              0
#define NUM_SWT              0
#define NUM_SERVO            0


#define PIN_LED1             4
#define PIN_LED2             5


#define PIN_TX             1
#define PIN_PGD             7
#define PIN_RX             0
#define PIN_ICSP_PGC             9
#define PIN_LED_TX             5
#define PIN_DTR             3
#define PIN_BOOT             10
#define PIN_PGC             6
#define PIN_ICSP_PGD             8
#define PIN_LED_RX             4
#define PIN_RTS             2



#if defined(OPT_BOARD_INTERNAL)
#define OPT_BOARD_INIT          0   //board needs no special init code
#define OPT_BOARD_DIGITAL_IO    0   //board does not extend digital i/o functions
#define OPT_BOARD_ANALOG_READ   0   //board does not extend analogRead
#define OPT_BOARD_ANALOG_WRITE  0   //board does not extend analogWrite

#define _SER0_BASE            _UART2_BASE_ADDRESS
#define _SER0_IRQ             _UART2_ERR_IRQ
#define _SER0_VECTOR          _UART_2_VECTOR
#define _SER0_IPL_ISR         IPL1SRS
#define _SER0_IPL             2
#define _SER0_SPL             0
#define _SER0_TX_OUT          PPS_OUT_U2TX
#define _SER0_TX_PIN          1
#define _SER0_RX_IN           PPS_IN_U2RX
#define _SER0_RX_PIN          0

#define _PORTA
#define _PORTB

#define _JTAG 0

#endif  // OPT_BOARD_INTERNAL

#endif  // BOARD_DEFS_H

