/*////////////////////////////////////////////////
pitch.h
Van Lai Sy - 10/2/2024

activates the LED based on the level of the Pitch
if LED is less than or equal 140, the LED will slightly turn the LED off
if LED is less or equal to 0, then the lights shuts off
if not, LED is HIGH 
*////////////////////////////////////////////////
void PitchLED(int pitch, int LED) {
  //Serial.println(pitch);
  unsigned int ledBrightness = map(pitch,0,1024,0,255); //8192 ;  
  //Serial.println(ledBrightness);
  if (ledBrightness <= 100)
  {
    digitalWrite(LED, 0);
  }
  else if(ledBrightness <= 130 && ledBrightness > 100)
  {
    digitalWrite(LED, 128);
  }
  else
  {
    digitalWrite(LED, 255);
  }
  //brightness value to the LED
  //digitalWrite(LED, ledBrightness);
  Serial.println(ledBrightness);
}

// set LED back to 0;
void restartLED(int LED)
{
    digitalWrite(LED, 0);
}