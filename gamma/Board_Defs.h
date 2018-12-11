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

#define _BOARD_NAME_ "Project Gamma"

#define NUM_DIGITAL_PINS     45
#define NUM_ANALOG_PINS      10
#define NUM_OC_PINS          9
#define NUM_IC_PINS          0
#define NUM_TCK_PINS         0
#define NUM_INT_PINS         5

#define NUM_DIGITAL_PINS_EXTENDED NUM_DIGITAL_PINS
#define NUM_ANALOG_PINS_EXTENDED NUM_ANALOG_PINS

#define NUM_SERIAL_PORTS     2
#define NUM_SPI_PORTS        1
#define NUM_DSPI_PORTS       3
#define NUM_I2C_PORTS        1
#define NUM_DTWI_PORTS       2

#define NUM_LED              0
#define NUM_BTN              0
#define NUM_SWT              0
#define NUM_SERVO            0



#define PIN_INT0             5
#define PIN_INT1             2
#define PIN_INT2             4
#define PIN_INT3             3
#define PIN_INT4             18

#define PIN_BACKLIGHT             29
#define PIN_TEAR             30
#define PIN_UP             35
#define PIN_BSIG             28
#define PIN_DOWN             36
#define PIN_BM1             33
#define PIN_RESET             31
#define PIN_BM2             34
#define PIN_RIGHT             38
#define PIN_LEFT             37
#define PIN_SD_CS             39
#define PIN_BM0             32

static const uint8_t A0     = 14;
static const uint8_t A1     = 15;
static const uint8_t A2     = 16;
static const uint8_t A3     = 17;
static const uint8_t A5     = 19;
static const uint8_t A6     = 20;
static const uint8_t A7     = 35;
static const uint8_t A8     = 36;
static const uint8_t A10     = 37;
static const uint8_t A11     = 38;

static const uint8_t MOSI   = 23;
static const uint8_t MISO   = 24;
static const uint8_t SCK    = 25;

static const uint8_t PIN_DSPI0_MOSI   = 23;
static const uint8_t PIN_DSPI0_MISO   = 24;
static const uint8_t PIN_DSPI0_SCK    = 25;

static const uint8_t PIN_DSPI1_SS     = 10;
static const uint8_t PIN_DSPI1_MOSI   = 11;
static const uint8_t PIN_DSPI1_MISO   = 12;
static const uint8_t PIN_DSPI1_SCK    = 13;

static const uint8_t PIN_DSPI2_MOSI   = 40;
static const uint8_t PIN_DSPI2_MISO   = 41;
static const uint8_t PIN_DSPI2_SCK    = 42;

#if defined(OPT_BOARD_INTERNAL)
#define OPT_BOARD_INIT          0   //board needs no special init code
#define OPT_BOARD_DIGITAL_IO    0   //board does not extend digital i/o functions
#define OPT_BOARD_ANALOG_READ   0   //board does not extend analogRead
#define OPT_BOARD_ANALOG_WRITE  0   //board does not extend analogWrite

#define _SER0_BASE            _UART2_BASE_ADDRESS
#define _SER0_IRQ             _UART2_FAULT_VECTOR
#define _SER0_VECTOR          _UART2_FAULT_VECTOR
#define _SER0_IPL_ISR         IPL1SRS
#define _SER0_IPL             2
#define _SER0_SPL             0
#define _SER0_TX_OUT          PPS_OUT_U2TX
#define _SER0_TX_PIN          27
#define _SER0_RX_IN           PPS_IN_U2RX
#define _SER0_RX_PIN          26

#define _SER1_BASE            _UART4_BASE_ADDRESS
#define _SER1_IRQ             _UART4_FAULT_VECTOR
#define _SER1_VECTOR          _UART4_FAULT_VECTOR
#define _SER1_IPL_ISR         IPL1SRS
#define _SER1_IPL             2
#define _SER1_SPL             0
#define _SER1_TX_OUT          PPS_OUT_U4TX
#define _SER1_TX_PIN          1
#define _SER1_RX_IN           PPS_IN_U4RX
#define _SER1_RX_PIN          0

#define _DSPI0_BASE            _SPI4_BASE_ADDRESS
#define _DSPI0_ERR_IRQ         _SPI4_FAULT_VECTOR
#define _DSPI0_RX_IRQ          _SPI4_RX_VECTOR
#define _DSPI0_TX_IRQ          _SPI4_TX_VECTOR
#define _DSPI0_VECTOR          _SPI4_FAULT_VECTOR
#define _DSPI0_IPL_ISR         IPL3SRS
#define _DSPI0_IPL             3
#define _DSPI0_SPL             0
#define _DSPI0_MISO_IN         PPS_IN_SDI4
#define _DSPI0_MISO_PIN        24
#define _DSPI0_MOSI_OUT        PPS_OUT_SDO4
#define _DSPI0_MOSI_PIN        23

#define _DSPI1_BASE            _SPI3_BASE_ADDRESS
#define _DSPI1_ERR_IRQ         _SPI3_FAULT_VECTOR
#define _DSPI1_RX_IRQ          _SPI3_RX_VECTOR
#define _DSPI1_TX_IRQ          _SPI3_TX_VECTOR
#define _DSPI1_VECTOR          _SPI3_FAULT_VECTOR
#define _DSPI1_IPL_ISR         IPL3SRS
#define _DSPI1_IPL             3
#define _DSPI1_SPL             0
#define _DSPI1_MISO_IN         PPS_IN_SDI3
#define _DSPI1_MISO_PIN        12
#define _DSPI1_MOSI_OUT        PPS_OUT_SDO3
#define _DSPI1_MOSI_PIN        11

#define _DSPI2_BASE            _SPI5_BASE_ADDRESS
#define _DSPI2_ERR_IRQ         _SPI5_FAULT_VECTOR
#define _DSPI2_RX_IRQ          _SPI5_RX_VECTOR
#define _DSPI2_TX_IRQ          _SPI5_TX_VECTOR
#define _DSPI2_VECTOR          _SPI5_FAULT_VECTOR
#define _DSPI2_IPL_ISR         IPL3SRS
#define _DSPI2_IPL             3
#define _DSPI2_SPL             0
#define _DSPI2_MISO_IN         PPS_IN_SDI5
#define _DSPI2_MISO_PIN        41
#define _DSPI2_MOSI_OUT        PPS_OUT_SDO5
#define _DSPI2_MOSI_PIN        40

#define _DTWI0_BASE            _I2C1_BASE_ADDRESS
#define _DTWI0_BUS_IRQ         _I2C1_BUS_VECTOR
#define _DTWI0_VECTOR          _I2C1_BUS_VECTOR
#define _DTWI0_IPL_ISR         IPL3SRS
#define _DTWI0_IPL             3
#define _DTWI0_SPL             0
#define _DTWI0_SCL_PIN         22
#define _DTWI0_SDA_PIN         21

#define _DTWI1_BASE            _I2C5_BASE_ADDRESS
#define _DTWI1_BUS_IRQ         _I2C5_BUS_VECTOR
#define _DTWI1_VECTOR          _I2C5_BUS_VECTOR
#define _DTWI1_IPL_ISR         IPL3SRS
#define _DTWI1_IPL             3
#define _DTWI1_SPL             0
#define _DTWI1_SCL_PIN         44
#define _DTWI1_SDA_PIN         43

#define _PORTA
#define _PORTB
#define _PORTC
#define _PORTD
#define _PORTE
#define _PORTF
#define _PORTG

#define _JTAG 0

#endif  // OPT_BOARD_INTERNAL

#define ADCRANGE        4096ul              // analog read will return a max number of ADCRANGE-1
#define ADCTADFREQ      25000000ul          // How fast to run the TAD ADC clock
#define ADCTADSH        68ul                // How many TADs the Sample and Hold will charge

/* ------------------------------------------------------------ */
/*                  Defines for the On Board uSD                */
/* ------------------------------------------------------------ */

#define _uSD_SPI_CONFIG_

#define SD_CS_PIN PIN_DSPI0_SS

#define DefineSDSPI(spi) DSPI0 spi
#define DefineDSDVOL(vol, spi) DSDVOL vol(spi, 10)

#endif  // BOARD_DEFS_H

