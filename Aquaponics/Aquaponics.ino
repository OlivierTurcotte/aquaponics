/*
Name:		Aquaponics.ino
Created:	04/06/2017 16:44:23
Author:	Olivier Turcotte
*/

#include <Servo.h>
#include <PS2Keyboard.h>
#include "FishFeeder.h"

// DIGITAL PINS 
#define pin_kbrd_clock		(3)
#define pin_kbrd_data		(4)
#define pin_relay_pump		(5)
#define pin_relay_temp		(6)
#define pin_relay_valve		(7)
#define pin_lcd_power		(8)
#define pin_led_pwm			(9)
#define pin_ff_servo		(11)
// ANALOG PINS 
#define pin_light_sensor	(14)
#define pin_hygrometer		(15)
#define pin_temp_soil		(16)
#define pin_temp_water		(17)
#define pin_i2c_data		(18)
#define pin_i2c_clock		(19)


PS2Keyboard keyboard;
FishFeeder	feeder;
bool lcdInit = false;

void setup() {
	delay(500);
	//pinMode(pin_lcd_power,INPUT_PULLUP);
	keyboard.begin(pin_kbrd_data, pin_kbrd_clock);
	feeder.setup(pin_ff_servo);

	Serial.begin(9600);
	Serial.println("Keyboard input:");
	
}

void loop() {

	//LCD 
	/*switch (digitalRead(pin_lcd_power)) {
	case HIGH:
		lcdInit = false
		break;
	case LOW:
		if (lcdInit == false) {
			delay(100);
			//initialisation du lcd
			lcdInit = true;
		}
		break;
	}*/

	if (keyboard.available()){
		switch (keyboard.read()) {
			
		}
	}

}





