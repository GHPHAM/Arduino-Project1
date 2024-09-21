#include "pitches.h"
#define REST      0

// change this to whichever pin you want to use
int buzzer = 9;

// musicPlayer.h
// Huy Pham - 9/20/2024
#include "musicPlayer.h"

void setup() {
  Serial.begin(9600); //Start Serial Communication

  selectMusic(3);
}

void loop() {
  
}