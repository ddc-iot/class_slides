/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "c:/Users/IoT_Instructor/Documents/IoT/class_slides/ParticleCode/I2C_Scan/src/I2C_Scan.ino"
/*
 * Project I2C_Scan
 * Description: Scan I2C bus and return found addresses
 * Author: Brian Rashap
 * Date: 13-Jan-2020
 */

#include "Particle.h"

void setup();
void loop();
#line 10 "c:/Users/IoT_Instructor/Documents/IoT/class_slides/ParticleCode/I2C_Scan/src/I2C_Scan.ino"
byte status; 
byte address;
int nDevices;
unsigned long delayTime=2000;

void setup() {
	Wire.begin();
	Serial.begin(9600);
	while(!Serial);    // time to get serial running
	Serial.println("\nI2C Scanner");
}


void loop() {
	Serial.printf("Starting Scan: \n-------------- \n");
	nDevices = 0;
	for(address = 1; address < 127; address++ ) {
		Wire.beginTransmission(address);
		status = Wire.endTransmission();
		if (status == 0) {
			Serial.printf("I2C device found at address 0x%02x \n",address);
			nDevices++;
		} else if (status == 4) {
			Serial.printf("Unknown error at address 0x%02x \n",address);
		}
	}
	if (nDevices == 0) {
		Serial.printf("No I2C devices found\n");
	}
	Serial.printf("-------------- \nScan Complete!\n");
	delay(delayTime);           // wait 5 seconds for next scan
}