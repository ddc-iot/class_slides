/*
 * Project MP3player
 * Description: Argon-based code for DFPlayer Mini Player
 *              Note: DFRobotDFPlayer.cpp modified to work on Argon
 * Author: Brian Rashap
 * Date: 14-APR-2022
 */

#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
const int playTime = 10000;
const int numberTracks = 7;
bool status;
int i,timer;
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  delay(2000);
  
  Serial.printf("DFRobot DFPlayer Mini Demo \nInitializing DFPlayer ... (May take 3~5 seconds)\n");

  status = myDFPlayer.begin(Serial1,false);
  Serial.printf("Status = %i\n",status);
  
  if (!status) {
    Serial.printf("Unable to begin:\n");
    Serial.printf("1.Please recheck the connection!\n");
    Serial.printf("2.Please insert the SD card!\n");
    while(true);
  }
  Serial.printf("DFPlayer Mini online.\n");
  
  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
  i=0;
  timer = -playTime;
}

void loop() {
  if (millis() - timer > playTime) {
    timer = millis();
    i++;
    if(i>numberTracks) {
      i=1;
    }
    Serial.printf("Play Next - Track %i\n",i);
    myDFPlayer.play(i);  //Play next mp3 every 3 second.
  }
  
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.printf("Time Out!\n");
      break;
    case WrongStack:
      Serial.printf("Stack Wrong!\n");
      break;
    case DFPlayerCardInserted:
      Serial.printf("Card Inserted!\n");
      break;
    case DFPlayerCardRemoved:
      Serial.printf("Card Removed!\n");
      break;
    case DFPlayerCardOnline:
      Serial.printf("Card Online!\n");
      break;
    case DFPlayerPlayFinished:
      Serial.printf("Number: %i Play Finished\n",value);
      break;
    case DFPlayerError:
      Serial.printf("DFPlayerError: ");
      switch (value) {
        case Busy:
          Serial.printf("Card not found\n");
          break;
        case Sleeping:
          Serial.printf("Sleeping\n");
          break;
        case SerialWrongStack:
          Serial.printf("Get Wrong Stack\n");
          break;
        case CheckSumNotMatch:
          Serial.printf("Check Sum Not Match\n");
          break;
        case FileIndexOut:
          Serial.printf("File Index Out of Bound\n");
          break;
        case FileMismatch:
          Serial.printf("Cannot Find File\n");
          break;
        case Advertise:
          Serial.printf("In Advertise\n");
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}