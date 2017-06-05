/*
Name:		Aquaponics.ino
Created:	04/06/2017 16:44:23
Author:	Olivier Turcotte
*/

#include <Servo.h>
#include <PS2Keyboard.h>

// DIGITAL PINS 
#define pin_kbrd_clock		(3)
#define pin_kbrd_data		(4)
#define pin_relay_pump		(5)
#define pin_relay_temp		(6)
#define pin_relay_valve		(7)
#define pin_led_pwm			(9)
#define pin_ff_servo		(11)
// ANALOG PINS 
#define pin_light_sensor	(14)
#define pin_hygrometer		(15)
#define pin_temp_soil		(16)
#define pin_temp_water		(17)
#define pin_i2c_data		(18)
#define pin_i2c_clock		(19)



char kbrd_input = ' ';
int pos = 0;

PS2Keyboard keyboard;
Servo fishFeeder;

void setup() {
	delay(1000);
	keyboard.begin(pin_kbrd_data, pin_kbrd_clock);
	fishFeeder.attach(pin_ff_servo);
	Serial.begin(9600);
	Serial.println("Keyboard Test:");
	
}

void loop() {
	keyboardRoutine(); 
	if (kbrd_input == 'f') {
		kbrd_input = ' ';
		feedFish();
		
	}

}

void keyboardRoutine() {
	if (keyboard.available()) {
		kbrd_input = keyboard.read();

		Serial.println(kbrd_input);
	}

}

void feedFish() {
	for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
										  // in steps of 1 degree
		fishFeeder.write(pos);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
		fishFeeder.write(pos);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
	}
}