/*
Name:		Aquaponics.ino
Created:	04/06/2017 16:44:23
Author:	Olivier Turcotte
*/

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

PS2Keyboard keyboard;

void setup() {
	delay(1000);
	keyboard.begin(pin_kbrd_data, pin_kbrd_clock);
	Serial.begin(9600);
	Serial.println("Keyboard Test:");
}

void loop() {
	keyboardRoutine();
}

void keyboardRoutine() {
	if (keyboard.available()) {
		kbrd_input = keyboard.read();

		Serial.println(kbrd_input);
	}

}