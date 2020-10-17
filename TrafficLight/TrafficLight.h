class TrafficLight {
  
  const int TIMER_GREEN = 5000;
  const int TIMER_YELLOW = 2000;
  const int TIMER_RED = 5000;
  const int TIMER_RED_YELLOW = 3000;
  
  int _greenLED;
  int _yellowLED;
  int _redLED;
  
  enum State{
    GREEN,
    YELLOW,
    RED,
    RED_YELLOW
  };
  
  State _currentState = GREEN;
  State _targetState = GREEN;
  
  int timerStart;
  int timerTarget;
  
  public:
    TrafficLight(int greenLED, int yellowLED, int redLED) {
      _greenLED = greenLED;
      _yellowLED = yellowLED;
      _redLED = redLED;
    pinMode(_greenLED,OUTPUT);
    pinMode(_yellowLED,OUTPUT);
    pinMode(_redLED,OUTPUT);
  }
  private:
    void goToGreen(){
      switch(_currentState){
        case RED:
          _currentState = RED_YELLOW;
          startTimer(TIMER_RED_YELLOW);
          break;
        case RED_YELLOW:
          red_yellow();
          if(isTimerReady()){
          _currentState = GREEN;
          }
          break;
        case GREEN:
          green();
          break;
        case YELLOW:
          red();
          break;
      }  
    }
    void goToRed() {
      
    }
    
    void green(){
      digitalWrite(_greenLED,HIGH);
      digitalWrite(_yellowLED,LOW);
      digitalWrite(_redLED,LOW);
    }
    void yellow(){
      digitalWrite(_greenLED,LOW);
      digitalWrite(_yellowLED,HIGH);
      digitalWrite(_redLED,LOW);
    }
    void red(){
      digitalWrite(_greenLED,LOW);
      digitalWrite(_yellowLED,LOW);
      digitalWrite(_redLED,HIGH);
    }
    void red_yellow(){
      digitalWrite(_greenLED,LOW);
      digitalWrite(_yellowLED,HIGH);
      digitalWrite(_redLED,HIGH);
    }
    
    void startTimer(int msec) {
      timerStart = millis();
      timerTarget = msec;
    }
    
    bool isTimerReady() {
      if ((millis()-timerStart)>timerTarget) {
        return true;
      }
      else {
        return false;
      }
    }
};
