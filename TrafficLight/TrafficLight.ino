/*
 * Project: TrafficLight
 * Decription: Example of Objects
 * Author: Brian Rashap
 * Date: 09-OCT-2020
 */

#include "TrafficLight.h"
#include "Button.h"
#include "Timer.h"

const int pinGreen = 5;
const int pinYellow = 6;
const int pinRed = 7;
const int pinButton = 23;

const int TIMER_STOP = 10000; // stay on RED for 10 seconds

TrafficLight trafficlight(pinGreen,pinYellow,pinRed);
Button button(pinButton);
Timer timer;
 
void setup() {
  
}

void loop() {
  if (button.isPressed()) {
    trafficlight.stop();
    timer.startTimer(TIMER_STOP);
  }
  else {
    if (timer.isTimerReady()) {
      trafficlight.go();
    }
  }

  trafficlight.looplight();
}
