#include "Arduino.h"
#include "Sketch.h"


int count = 0;


void getState(Data *d, int id){
	if(id & DATA_PIN){
		if((id & DATA_MASK) == 1){
			strcpy(d->desc, "BLINKY");
		}
	} else if(id & DATA_INFO){
		if((id & DATA_MASK) == 0){
			// strcpy(d->desc, "VCC");
			d->vtype = Data::afloat;
			d->f = 5.0f;
		} else if((id & DATA_MASK) == 1){
			strcpy(d->desc, "counter");
			d->vtype = Data::aint;
			d->i = count;
		} else if((id & DATA_MASK) == 2){
			strcpy(d->desc, "counterEven");
			d->vtype = Data::abool;
			d->i = count%2 == 0;
		} else if((id & DATA_MASK) == 3){
			strcpy(d->desc, "cDec");
			d->vtype = Data::afloat;
			d->f = count/10.0f;
		}  else if((id & DATA_MASK) == 4){
			strcpy(d->desc, "MOTOR");
			d->vtype = Data::aint;
			int dir = count%3; // 0:none, 1:counterclockwise, 2:clockwise
			int state = (count/3)%3; // 0:white, 1:red, 2:green
			d->i = (dir << 4) | (state);
		}
	}
}



void setup() {
	pinMode(1, OUTPUT);
}


void loop() {
	digitalWrite(1, HIGH);
	delay(1000);
	digitalWrite(1, LOW);
	delay(1000);
	count++;
}