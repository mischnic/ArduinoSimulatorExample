#include "Sketch.h"
#include "SoftwareSerial.h"

int count = 0;

void getState(Data *d, int id){
	if(id & DATA_PIN){
		if((id & DATA_MASK) == 1){
			strcpy(d->desc, "BLINKY");
		}
	} else if(id & DATA_INFO){
		int i = 0;
		if((id & DATA_MASK) == i++){
			strcpy(d->desc, "VCC");
			d->vtype = Data::afloat;
			d->f = 5.0f;
		} else if((id & DATA_MASK) == i++){
			strcpy(d->desc, "counter");
			d->vtype = Data::aint;
			d->i = count;
		} else if((id & DATA_MASK) == i++){
			strcpy(d->desc, "counterEven");
			d->vtype = Data::abool;
			d->b = count%2 == 0;
		} else if((id & DATA_MASK) == i++){
			strcpy(d->desc, "counterDec");
			d->vtype = Data::afloat;
			d->f = count/10.0f;
		} else if((id & DATA_MASK) == i++){
			d->vtype = Data::aMotor;
			// MotorState::NONE ::LEFT ::RIGHT
			d->ms.dir = MotorState::Dirs(count%3);
			// MotorState::RED ::GREEN ::WHITE
			d->ms.state =  MotorState::States((count/3)%3);
		}
	}
}

SoftwareSerial Serial(6, 7);

void setup() {
	Serial.begin(9600);
	Serial.println("Setup called");
	pinMode(1, OUTPUT);
}

void loop() {
	Serial.println("Loop");
	digitalWrite(1, HIGH);
	delay(500);
	digitalWrite(1, LOW);
	delay(500);
	count++;
}