/*
 * Project: Class Discussion
 * Description: Q&A for end of week 1
 * Author: Brian
 * Date: Today
 */

int buttonPin = 23;
int buttonState;
int lastState;
int ledDelay = 1000;
int ledPin = 4;
int counter;
int flashes;

void setup() 
  {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600); // Turn on Serial Monitor at speed 9600 bps 
  //while(!Serial);     // This is dangerous
  delay(100);           // instead let's just use a short delay
  Serial.println("Hello - I am getting started");
  
  counter = 0;
  buttonState = LOW;
  }

void loop() {
  // put your main code here, to run repeatedly:
  
  buttonState = digitalRead(buttonPin);
  /*Serial.print("The Button State is ");
  Serial.println(buttonState);*/

  if(buttonState != lastState) {
    lastState=buttonState;
    if(buttonState == LOW) {
      Serial.println("Button is NOT pressed!!!!");
      digitalWrite(ledPin,LOW);
    }
    else {
      Serial.println("Button is pressed"); 
      Serial.println("Glad it is Friday");
      counter++;
      Serial.print("The counter is equal to "); Serial.println(counter);
      digitalWrite(ledPin,HIGH);

      switch (counter) {
      case 1:    
        Serial.println("First Push");
        ledDelay = 1000;
        break;
      case 2:    
        Serial.println("Second Push");
        ledDelay = 750;
        break;
      case 3:    
        Serial.println("Third Push");
        ledDelay = 500;
        break;
      case 4:    
        Serial.println("Forth Push");
        ledDelay = 250;
        break;
      }

  
      for (flashes = 0; flashes < counter; flashes++) {
        digitalWrite(ledPin,HIGH);
        delay(ledDelay);
        digitalWrite(ledPin,LOW);
        delay(ledDelay);
      }
    }
  }

delay(10);
}
