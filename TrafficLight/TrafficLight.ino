/*
 * Project: TrafficLight
 * Decription: Example of Objects
 * Author: Brian Rashap
 * Date: 09-OCT-2020
 */

#include "TrafficLight.h"
#include "Button.h"

const int pinGreen = 5;
const int pinYellow = 6;
const int pinRed = 7;
const int pinButton = 23;

TrafficLight trafficlight(pinGreen,pinYellow,pinRed);
Button button(pinButton);
 
void setup() {

}

void loop() {

}
