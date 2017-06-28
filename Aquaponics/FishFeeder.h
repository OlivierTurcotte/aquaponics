#pragma once

#include <Servo.h>
#include <Arduino.h>

class FishFeeder
{
public:
	FishFeeder();
	void feed();
	void setup(uint8_t servo_pin,uint8_t food_pin);
	bool hasFood();
	~FishFeeder();
protected:
	uint8_t position;
	uint8_t pin_servo;
	uint8_t pin_food;
	bool	food_remaining;
	Servo	servo;
};

