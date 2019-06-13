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
}

void loop() {
	
	static bool dtr = uSerial.getDTR();
	static uint32_t dtrPulseTimestamp = 0;
	static uint32_t baud = uSerial.getBaud();
	
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

	uint32_t b = uSerial.getBaud();
	if (b != baud) {
		baud = b;
		Serial.end();
		Serial.begin(baud);
	}
	
}
