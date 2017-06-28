/*
Name:		Aquaponics.ino
Created:	04/06/2017 16:44:23
Author:	Olivier Turcotte
*/


#include <Servo.h>
#include <PS2Keyboard.h>
#include "FishFeeder.h"
#include "Hygrometer.h"


// DIGITAL PINS 
#define pin_kbrd_clock		(3)
#define pin_kbrd_data		(4)
#define pin_relay_pump		(5)
#define pin_relay_temp		(6)
#define pin_relay_valve		(7)
#define pin_lcd_power		(8)
#define pin_led_pwm			(9)
#define pin_ir_sensor		(10)
#define pin_ff_servo		(11)
// ANALOG PINS 
#define pin_light_sensor	(14)
#define pin_hygrometer		(15)
#define pin_temp_soil		(16)
#define pin_temp_water		(17)
#define pin_i2c_data		(18)
#define pin_i2c_clock		(19)

Hygrometer moisture;
PS2Keyboard keyboard;
//FishFeeder	feeder;
bool lcdInit = false;

void setup() {
	delay(500);
	keyboard.begin(pin_kbrd_data, pin_kbrd_clock);
	
	Serial.begin(9600);
	Serial.println("Keyboard input:");

	moisture.setup(pin_hygrometer);

}

void loop() {
	if (keyboard.available()) {
		switch (keyboard.read())
		{
		case 'h':
			Serial.println(moisture.isMoist());
			break;
		}
	}
}





