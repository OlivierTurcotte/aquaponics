#pragma once

#include <Servo.h>
#include <Arduino.h>

class FishFeeder
{
public:
	FishFeeder();
	void feed();
	void setup(uint8_t servo_pin);
	~FishFeeder();
protected:
	uint8_t position;
	Servo	servo;
};

