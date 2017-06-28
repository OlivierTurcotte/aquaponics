#pragma once

#include <Arduino.h>

class Hygrometer
{
public:
	Hygrometer();
	void setup(uint8_t sensor_pin);
	void setMoisture(uint16_t moisture_value);
	bool isMoist();
	~Hygrometer();

protected:
	uint8_t pin;
	uint16_t moisture_top;
};

