#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>
#define	_BOARD_NAME_	"Project Gamma (Programming)"

#define	NUM_DIGITAL_PINS	6
#define	NUM_ANALOG_PINS		0
#define NUM_OC_PINS			0
#define	NUM_IC_PINS			0
#define	NUM_TCK_PINS		0
#define	NUM_INT_PINS		0

#define	NUM_SERIAL_PORTS	1       
#define	NUM_SPI_PORTS		0
#define	NUM_I2C_PORTS		0       

#define NUM_DSPI_PORTS		0
#define NUM_DTWI_PORTS		0       

#define	NUM_LED				2
#define NUM_BTN				0
#define	NUM_SWT				0
#define NUM_SERVO			0

#define	PIN_LED1	        4
#define PIN_LED2            5

#define	PIN_LED_RX          4
#define PIN_LED_TX          5

#define PIN_OC1	          255
#define	PIN_OC2	          255
#define	PIN_OC3	          255
#define	PIN_OC4	          255
#define	PIN_OC5	          255

#define PIN_IC1	          255
#define PIN_IC2	          255
#define PIN_IC3	          255
#define PIN_IC4	          255
#define	PIN_IC5	          255

#define	PIN_TCK1          255
#define	PIN_TCK2          255
#define	PIN_TCK3          255
#define	PIN_TCK4          255
#define	PIN_TCK5          255

#define	PIN_INT0          255
#define	PIN_INT1          255
#define PIN_INT2          255
#define	PIN_INT3          255
#define	PIN_INT4          255

#if !defined(OPT_BOARD_DATA)

extern const uint32_t	port_to_tris_PGM[];
extern const uint8_t	digital_pin_to_port_PGM[];
extern const uint16_t	digital_pin_to_bit_mask_PGM[];
extern const uint16_t	digital_pin_to_timer_PGM[];
extern const uint8_t	digital_pin_to_pps_out_PGM[];
extern const uint8_t	digital_pin_to_pps_in_PGM[];
extern const uint8_t 	digital_pin_to_analog_PGM[];
extern const uint8_t	analog_pin_to_channel_PGM[];

extern const uint8_t	output_compare_to_digital_pin_PGM[];
extern const uint8_t	external_int_to_digital_pin_PGM[];

#endif

#if defined(OPT_BOARD_INTERNAL)

#define	OPT_BOARD_INIT			1	//board needs special init code
#define	OPT_BOARD_DIGITAL_IO	0	//board does not extend digital i/o functions
#define	OPT_BOARD_ANALOG_READ	0	//board does not extend analogRead
#define	OPT_BOARD_ANALOG_WRITE	0	//board does not extend analogWrite

#define       _SER0_BASE           _UART2_BASE_ADDRESS
#define       _SER0_IRQ            _UART2_ERR_IRQ
#define       _SER0_VECTOR         _UART_2_VECTOR
#define       _SER0_IPL_ISR        _UART2_IPL_ISR
#define       _SER0_IPL            _UART2_IPL_IPC
#define       _SER0_SPL            _UART2_SPL_IPC
#define       _SER0_TX_OUT         PPS_OUT_U2TX 
#define       _SER0_TX_PIN         1
#define       _SER0_RX_IN          PPS_IN_U2RX
#define       _SER0_RX_PIN         0

#endif	// OPT_BOARD_INTERNAL
#endif	// BOARD_DEFS_H
