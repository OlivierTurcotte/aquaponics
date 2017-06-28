#include "FishFeeder.h"


FishFeeder::FishFeeder()
{	
}

void FishFeeder::feed()
{
	for (; position <= 170; position += 2) { 										   // in steps of 1 degree
		servo.write(position);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
	}
	for (position = 170; position >= 13; position -= 2) { 
		servo.write(position);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
	}
	digitalWrite(pin_servo, HIGH);
	food_remaining = digitalRead(pin_food);
	digitalWrite(pin_servo, LOW);
	switch (food_remaining) {
	case true:
		Serial.println("food");
		break;
	case false:
		Serial.println("no food");
	}
	
}
void FishFeeder::setup(uint8_t servo_pin,uint8_t food_pin) {
	servo.attach(servo_pin);
	position = 13;
	pin_servo = servo_pin;
	pin_food = food_pin;
	pinMode(pin_food, INPUT);
	servo.write(position);

	digitalWrite(pin_servo, HIGH);
	food_remaining = digitalRead(pin_food);
	digitalWrite(pin_servo, LOW);

	
}

bool FishFeeder::hasFood() {
	return food_remaining;
}


FishFeeder::~FishFeeder()
{
}
