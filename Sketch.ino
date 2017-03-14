/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/
#include "Arduino.h"
#include "Sketch.h"


int count = 0;


void getState(Data *d, int id){
	if(id & DATA_INFO){
		if((id & DATA_MASK) == 0){
			// strcpy(d->desc, "VCC");
			d->value = (int) (5.0f * 1000.0f);
		} else if((id & DATA_MASK) == 1){
			strcpy(d->desc, "counter");
			d->value = count;
		} else {
			strcpy(d->desc, "!!END");
		}
		// count
	}

	if(id & DATA_PIN){
		if((id & DATA_MASK) == 1){
			strcpy(d->desc, "BLINKY");
		}
	}
}




// the setup function runs once when you press reset or power the board
void setup() {
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
	digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(1000);                       // wait for a second
	digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
	delay(1000);                       // wait for a second
	count++;
}