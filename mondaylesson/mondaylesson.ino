/*
 * Project: Class Discussion
 * Description: Q&A for end of week 1
 * Author: Brian
 * Date: Today
 */

int buttonPin = 23;
int buttonState;
int lastState;
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
  
      for (flashes = 0; flashes < counter; flashes++) {
        digitalWrite(ledPin,HIGH);
        delay(1000);
        digitalWrite(ledPin,LOW);
        delay(1000);
      }
    }
  }

delay(10);
}
