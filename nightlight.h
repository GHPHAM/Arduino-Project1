//Automatic Nightlight
const int WLED=10; //Red LED on pin 9 (PWM)
const int LIGHT=0; //Lght Sensor on analog pin 0
const int MIN_LIGHT=0; //Minimum expected light value
const int MAX_LIGHT=100; //Maximum Expected Light value
const int SWITCH=8; //switch is connected to pin 8
int val = 0; //variable to hold the analog reading
void lightSetup()
{
pinMode(SWITCH, INPUT);
pinMode(WLED, OUTPUT); //Set LED pin as output
//Serial.begin(9600);
}
void lightLoop()
{
  if (digitalRead(SWITCH) == LOW) digitalWrite(LIGHT,LOW); //allows for the photosensor to be powered on or off
  else
  {
    val = analogRead(LIGHT); //Read the light sensor
    val = map(val, MIN_LIGHT, MAX_LIGHT, 0, 255);//Map the light reading
    val = constrain(val, 255, 0); //Constrain light value
    analogWrite(WLED, val); //Control the LED
    //Serial.println(val);
    //delay(100);
  }
  if (digitalRead(WLED) == HIGH) digitalWrite(WLED, LOW); //troubleshoots the issue of the light staying on while you turned the switch off
}


