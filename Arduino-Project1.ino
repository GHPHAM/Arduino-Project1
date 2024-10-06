/*////////////////////////////////////////////////
Project one: Music Player
The music player allows you to select from a range of pre-installed tunes.
More information and source code: https://github.com/GHPHAM/Arduino-Project1/

*/////////////////////////////////////////////////

// System integration by Huy Pham
// Put your name here if you integrated something yourself.

//#include <cmath>
#include "pitches.h"
#define REST      0

// change this to whichever pin you want to use
const byte buzzer = 9;
const byte PrevButton = 2;
const byte NextButton = 3;
const byte RLED = 7; // Red light

// pitchLED.h
// Van Lai Sy - 9/25/2024
#include "pitchLED.h"

// music.h
// musicPlayer.h
// Huy Pham - 9/20/2024
#include "music.h"
#include "musicPlayer.h"

// nightLight.h
// Adrian Miranda - 10/2/2024
//#include "nightLight.h"
#include "nightlight.h"


// INITIALIZING GLOBAL VARIABLES
bool PrevlastButton = LOW;
bool PrevcurrentButton = LOW;
bool NextlastButton = LOW;
bool NextcurrentButton = LOW;

byte index = 0; // Currently at 0 (no song is playing)
byte prevIndex = 0;
const byte maxIndex = 3; // Set up max index to fit the number of musics we have (currently 3)



void setup() {
  
  Serial.begin(9600); //Start Serial Communication

  pinMode(PrevButton, INPUT);
  pinMode(NextButton, INPUT);

  PrevlastButton = digitalRead(PrevButton);
  NextlastButton = digitalRead(NextButton);
}



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
  lightLoop();

  isChangingMusic = false;
  
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
    isChangingMusic = true;
    prevIndex = index;
    Serial.print(F("Index: "));
    Serial.println(index);
    selectMusic(index);
  }

  // Continue
  if (isPlayingMusic) {
    selectMusic(index);
  }
}
