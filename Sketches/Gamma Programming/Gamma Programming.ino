USBFS usbDevice;
USBManager USB(usbDevice, 0xf055, 0x2601, "Majenko Technologies", "Project Gamma (Programming)");
CDCACM uSerial;

#pragma option isa = mips32
#pragma option optimize = size
#pragma option usb = z_custom
#pragma option warnings = off

#pragma board gamma-usb

void setup() {
	USB.addDevice(uSerial);
	USB.begin();
	Serial.begin(115200);
	pinMode(PIN_RTS, OUTPUT); // RTS
	pinMode(PIN_DTR, OUTPUT); // DTR
	digitalWrite(PIN_RTS, LOW);
	digitalWrite(PIN_DTR, LOW);
	// Bypass the pullup control since we are in input mode.
	pinMode(PIN_PGC, INPUT_PULLUP);
	pinMode(PIN_PGD, INPUT_PULLUP);
	LATAbits.LATA0 = 0; // PGC LOW
	LATAbits.LATA1 = 0; // PGD LOW
}

void loop() {
	static bool dtr = uSerial.getDTR();
	static uint32_t dtrPulseTimestamp = 0;
	static uint32_t baud = uSerial.getBaud();
	static int mode = 0; // Passthrough
	
	uint32_t b = uSerial.getBaud();

	if (b != baud) {
		if (b == 300) {
			baud = b;
			mode = 1;
			pinMode(PIN_PGD, INPUT_PULLUP);
			pinMode(PIN_PGC, OUTPUT);
			digitalWrite(PIN_DTR, HIGH);
		} else {
			pinMode(PIN_PGC, INPUT);
			pinMode(PIN_PGD, INPUT);
			digitalWrite(PIN_DTR, LOW);
			mode = 0;
			baud = b;
			Serial.end();
			Serial.begin(baud);
		}
	}

	if (mode == 0) {
		while (uSerial.available()) {
			Serial.write(uSerial.read());
		}
	
		while (Serial.available()) {
			uSerial.write(Serial.read());
		}

		digitalWrite(PIN_RTS, uSerial.getRTS());
		bool d = uSerial.getDTR();
	
		if (d != dtr) {
			dtr = d;
	
			if (dtr) {
				Serial.begin(uSerial.getBaud());
				digitalWrite(PIN_DTR, HIGH);
				delay(1);
				digitalWrite(PIN_DTR, LOW);
			} else {
				Serial.end();
			}
		}
	} else if (mode == 1) {
		if (uSerial.available()) {
			handleuSerialProgramming(uSerial.read());
		}
	}


}

int clock1(int D) {
	pinMode(PIN_PGD, D ? INPUT_PULLUP : OUTPUT);
	delayMicroseconds(1);
	pinMode(PIN_PGC, INPUT_PULLUP);
	delayMicroseconds(1);
	pinMode(PIN_PGC, OUTPUT);
	delayMicroseconds(1);
	return PORTAbits.RA1; // Return the data value
}

int clock4(int TDI, int TMS) {
	pinMode(PIN_PGD, TDI ? INPUT_PULLUP : OUTPUT);
	delayMicroseconds(1);
	pinMode(PIN_PGC, INPUT_PULLUP);
	delayMicroseconds(1);
	pinMode(PIN_PGC, OUTPUT);
	delayMicroseconds(1);

	pinMode(PIN_PGD, TMS ? INPUT_PULLUP : OUTPUT);
	delayMicroseconds(1);
	pinMode(PIN_PGC, INPUT_PULLUP);
	delayMicroseconds(1);
	pinMode(PIN_PGC, OUTPUT);
	delayMicroseconds(1);

	pinMode(PIN_PGD, INPUT_PULLUP);
	delayMicroseconds(1);
	pinMode(PIN_PGC, INPUT_PULLUP);
	delayMicroseconds(1);
	pinMode(PIN_PGC, OUTPUT);
	delayMicroseconds(1);

	int B = PORTAbits.RA1;

	pinMode(PIN_PGC, INPUT_PULLUP);
	delayMicroseconds(1);
	pinMode(PIN_PGC, OUTPUT);
	
	return B;
}

void handleuSerialProgramming(int I) {
	static int PrAcc = 1;
	char ch;
	
	if (((I >= 'i') && (I <= 'x')) || ((I >= 'I') && (I <= 'X'))) {
		// 4-bit encoding of TDI, TMS = 0
		int J = tolower(I) - 'i';
		int B = 0;

		if (clock4(J & 1, 0)) {
			B |= 1;
		}

		if (clock4(J & 2, 0)) {
			B |= 2;
		}

		if (clock4(J & 4, 0)) {
			B |= 4;
		}

		if (clock4(J & 8, 0)) {
			B |= 8;
		}

		ch = 'I' + B;

		if (isupper(I)) {
			uSerial.print(ch);
		}
	} else
		switch (char(I)) {
// 'd','e','f','g': write TDI and TMS, no read back
			case 'd':                                 // TDI = 0, TMS = 0, read_flag = 0
				clock4(0, 0);
				break;

			case 'e':                                 // TDI = 0, TMS = 1, read_flag = 0
				clock4(0, 1);
				break;

			case 'f':                                 // TDI = 1, TMS = 0, read_flag = 0
				clock4(1, 0);
				break;

			case 'g':                                 // TDI = 1, TMS = 1, read_flag = 0
				clock4(1, 1);
				break;

			case 'a':                                 // TDI = 0, TMS = 1-0-0, read_flag = 0
				clock4(0, 1);                           // (data header)
				clock4(0, 0);
				clock4(0, 0);
				break;

			case 'z':                                 // TDI = 0, TMS = 1-0, read_flag = 0
				clock4(0, 1);                           // (data footer)
				clock4(0, 0);
				break;

// 'D','E','F','G', '+': write TDI and TMS, read back TDO

			case 'D':                                 // TDI = 0, TMS = 0, read_flag = 1
				ch = '0' + clock4(0, 0);
				uSerial.print(ch);
				break;

			case 'E':                                 // TDI = 0, TMS = 1, read_flag = 1
				ch = '0' + clock4(0, 1);
				uSerial.print(ch);
				break;

			case 'F':                                 // TDI = 1, TMS = 0, read_flag = 1
				ch = '0' + clock4(1, 0);
				uSerial.print(ch);
				break;

			case 'G':                                 // TDI = 1, TMS = 1, read_flag = 1
				ch = '0' + clock4(1, 1);
				uSerial.print(ch);
				break;

			case 'A':                                 // TDI = 0, TMS = 1-0-0, read_flag = 1
				clock4(0, 1);
				clock4(0, 0);
				ch = '0' + clock4(0, 0);
				uSerial.print(ch);
				break;

			case '+':                                 // TDI = 0, TMS = 0, accumulate PrAcc
				if (!clock4(0, 0)) {
					PrAcc = 0;    // remember if any error ('0')
				}

				break;

// '>', '.', '=': handshake and formatting commands, placed here for possible speed

			case '>':                                 // request a sync response of '<'
				uSerial.print('<');
				break;

			case '=':                                 // retrieve value of PrAcc
				uSerial.print(PrAcc ? '1' : '0');
				PrAcc = 1;                              // reset to default
				break;

			case '.':                                 // no operation, used for formatting
				break;

// '0','1': used to clock out "MCHP" signature for uSerial entry

			case '0':                                 // clock out a 0 bit on PGD pin
				clock1(0);                              // PGD = 0
				break;

			case '1':                                 // clock out a 1 bit on PGD pin
				clock1(1);                              // PGD = 1
				break;

			case '-':                                 // clock in single PGD bit
				ch = '0' + clock1(1);
				uSerial.print(ch);
				break;

// the remaining commands have no great speed requirements, therefore can use
// the slower arduino library routines for pinMode, digitalWrite, analogRead

// '2','3': pulse MCLR high, clock out signature, set MCLR high

			case '2':                                 // set MCLR low
				digitalWrite(PIN_DTR, HIGH);
				break;

			case '3':                                 // set MCLR high
				digitalWrite(PIN_DTR, LOW);
				break;

// '4','5': control power supply to target - something we can't do.

			case '4':                                 // turn power to target OFF
				break;

			case '5':                                 // turn power to target ON
				break;

// HV programming commands, for older device families that require Vpp - not needed here

			case '6':                                 // turn OFF Vpp, hold in reset
				break;

			case '7':                                 // release reset, turn ON Vpp
				break;

// miscellaneous other commands

			case '8':                                 // insert 10mS delay
				delay(10);
				break;

			case '@':                                 // output analog values
				long Vusb;
				Vusb = 3.3;
				uSerial.println(3.3);
				uSerial.println(3.3);
				uSerial.println(3.3);
				uSerial.println(3.3);
				uSerial.println(3.3);
				uSerial.println(3.3);
				uSerial.print((char)0x00);               // null terminated
				break;

			case '?':                                 // return ID string, "ascii uSerial v1X"
				uSerial.print("ascii ICSP v1E");
				break;

			default:
				break;
		}	// end of switch
}
