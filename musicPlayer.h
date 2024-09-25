/*////////////////////////////////////////////////
musicPlayer.h
Huy Pham - 9/20/2024
Adapted from https://github.com/robsoncouto/arduino-songs

The driver for the music player. 
  Non-blocking delay for smoother user experience.
*////////////////////////////////////////////////

/*///////////////////////////////////////////////
  DRIVERS
*////////////////////////////////////////////////

bool isPlayingMusic = false; // Vanguard to make sure we don't overlap
bool isChangingMusic = false;
unsigned long noteStartMillis = 0;
int currentNote = 0;
int noteDuration = 0;

// Passing the array into the music player function
// Notes are actually x2, but because we increment +2, it's halved.
// arg1 = music array, arg2 = notes * 2, args3 = song tempo

void playNextNote(int melody[], unsigned int notes, unsigned int tempo) {
  // this calculates the duration of a whole note in ms
  unsigned int wholenote = (60000 * 4) / tempo;

  // calculates the duration of each note
  int divider = melody[currentNote + 1];
  if (divider > 0) {
    // regular note
    noteDuration = (wholenote) / divider;
  } else if (divider < 0) {
    // dotted note
    noteDuration = (wholenote) / abs(divider);
    noteDuration *= 1.5;
  }

  // Play the note
  tone(buzzer, melody[currentNote], noteDuration * 0.9);

  // Start timer for this note
  noteStartMillis = millis();
  currentNote += 2; // Move to the next note in the array
}

void playMusic(int melody[], unsigned int notes, unsigned int tempo)
{
  if (!isPlayingMusic || isChangingMusic) {
    currentNote = 0;
    isPlayingMusic = true;
    playNextNote(melody, notes, tempo);
  }

  if (currentNote >= notes) {
    // Music finished
    isPlayingMusic = false;
    noTone(buzzer);
    return;
  }

  // If it's time for the next note
  if (millis() - noteStartMillis >= noteDuration) {
    noTone(buzzer);  // Stop the current note
    playNextNote(melody, notes, tempo);
  }
}

// Selecting which array to run
void selectMusic(byte index) // LED pin default to 11
{
    switch(index)
    {
      case 0: // Nothing's playing
      break;

      case 1: // Never gonna give you up
      playMusic(NeverGonnaGiveYouUp, sizeof(NeverGonnaGiveYouUp) / sizeof(NeverGonnaGiveYouUp[0]), 114);
      break;

      case 2:
      playMusic(TakeOnMe, sizeof(TakeOnMe) / sizeof(TakeOnMe[0]), 140);
      break;

      case 3:
      playMusic(MyLittlePony, sizeof(MyLittlePony) / sizeof(MyLittlePony[0]), 140);
      break;
      
      // ADD MORE SONGS HERE
    }
}
