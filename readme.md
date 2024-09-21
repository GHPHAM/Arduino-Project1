Project 1 Source code
```
Music Player
The music player cycles between preinstalled songs (that we can straight up steal from the internet.)

Input
    Two buttons to go forward or backward in cycling
    A switch to enable/disable the music player
    A volume knob to control the volume of the player

Output
    Lights to display the pitches (imagine a musical light show)
    Light to display activity (optional, basically a static light to show that it's on)
    A speaker to play the sound
```

Software wise,
```
Music player function
accept an argument for the pin for the audio visual, also another argument for the music index
  Index will be read by a switch-case. Music are loaded depending on the switch index.
  Runs the audio visual function every time a pitch is played, with the pitch as argument
```

```
Audio visual function
Accept one argument for the pitch
  Do math to crunch the range of the pitch to 0 - 255
  Then simply feed that into the LED.
```

```
Main
Accept inputs to cycle forward or backward
  Have an incrementor for every forward and decrementor for backward like the LED lab
  Stores the current music index to pass to the music player function
```
Hardware wise,
```
volume can be controlled with analog
```

```
switch to turn the whole thing on/off can be simply just cutting off the power source.
```
