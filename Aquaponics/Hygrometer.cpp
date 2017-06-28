#include "Hygrometer.h"



Hygrometer::Hygrometer()
{
}


Hygrometer::~Hygrometer()
{
}

void Hygrometer::setup(uint8_t sensor_pin) 
{
	pinMode(sensor_pin, INPUT);
	pin = sensor_pin;

}

void Hygrometer::setMoisture(uint16_t moisture_value) {
	moisture_top = moisture_value;
}

bool Hygrometer::isMoist() {
	
	uint16_t value[10] = {};

	//Value getters
	for (int i = 0; i < 9; i++) {
		value[i] = analogRead(pin);
		Serial.println(value[i]);
		delay(500);
	}
	//Average part
	uint16_t average = 0;
	for (int i = 0; i < 9; i++) {
		average += value[i];
	}
	average = average / 10;
	Serial.println(average);
	if (average < moisture_top) {
		return true;
	}
	else return false;
}
