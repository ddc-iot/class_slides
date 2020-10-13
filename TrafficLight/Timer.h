#ifndef _TIMER_H_
#define _TIMER_H_

class Timer {

  unsigned long timerStart = 0;
  unsigned long timerTarget = 0;

  public:
    void startTimer(long msec) {
      timerStart = millis();
      timerTarget = msec;
    }

    bool isTimerReady() {
      return (millis() - timerStart) > timerTarget;
    }  
};

#endif // _TIMER_H_
