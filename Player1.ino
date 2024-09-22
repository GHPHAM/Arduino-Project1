#include "pitches.h"
#define REST      0

// change this to whichever pin you want to use
const byte buzzer = 9;


unsigned int previousMillis = 0;
void myDelay(unsigned int ms) {
  unsigned int start = millis();  // Get the current time in milliseconds
  while (millis() - start < ms) {
    // You can do something else here if needed while waiting
  }
}


// musicPlayer.h
// Huy Pham - 9/20/2024
#include "musicPlayer.h"

bool PrevlastButton = LOW;
bool PrevcurrentButton = LOW;
bool NextlastButton = LOW;
bool NextcurrentButton = LOW;

const byte PrevButton = 2;
const byte NextButton = 3;

//bool PowerSwitchState = LOW;
//const byte PowerSwitch = 4;

const byte GLED = 10; // Red light

byte index = 0; // Currently at 0 (no song is playing)
const byte maxIndex = 3; // Set up max index to fit the number of musics we have (currently 3)



void setup() {
  Serial.begin(9600); //Start Serial Communication

  pinMode(PrevButton, INPUT);
  pinMode(NextButton, INPUT);

  PrevlastButton = digitalRead(PrevButton);
  NextlastButton = digitalRead(NextButton);
  //bool PowerSwitchState = digitalRead(PowerSwitch);

  //pinMode(GLED, OUTPUT);
}

byte prevIndex = 0;



bool debounce(bool last, byte BUTTON)
{
  bool current = digitalRead(BUTTON); //Read the button state
  if (last != current) //if it's different...
  {
    delay(5); //wait 5ms
    current = digitalRead(BUTTON); //read it again
  }
  return current; //return the current value
}

void loop() {
  PrevcurrentButton = debounce(PrevlastButton, PrevButton);
  //PrevcurrentButton = digitalRead(PrevButton);
  if (PrevcurrentButton == HIGH && PrevlastButton == LOW) // Going back
  {
    if (index <= 1) // If index is at the start, then...
      index = maxIndex; // roll back to the last song
    else
      --index;
  }
  PrevlastButton = PrevcurrentButton;

  
  NextcurrentButton = debounce(NextlastButton, NextButton);
  //NextcurrentButton = digitalRead(NextButton);
  if (NextcurrentButton == HIGH && NextlastButton == LOW) // Going forward
  {
    if (index >= maxIndex) // If index is at max, then...
      index = 1; // roll back to 1
    else
      ++index;
  }
  NextlastButton = NextcurrentButton;

  // Debugger
  if (prevIndex != index)
  {
    prevIndex = index;
    Serial.print(F("Index: "));
    Serial.println(index);
    selectMusic(index);
  }
}
