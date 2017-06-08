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
	Serial.println(digitalRead(pin_food));
}
void FishFeeder::setup(uint8_t servo_pin,uint8_t food_pin) {
	servo.attach(servo_pin);
	position = 13;
	pin_servo = servo_pin;
	pin_food = food_pin;
	servo.write(position);

}


FishFeeder::~FishFeeder()
{
}
