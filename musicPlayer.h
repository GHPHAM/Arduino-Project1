// musicPlayer.h
// Huy Pham - 9/20/2024
// Adapted from https://github.com/robsoncouto/arduino-songs

// Unfortunately I have to truncate a lot of these musics since they will not fit the ram
// I tried fitting it on the onboard memeory, but they will break

/*///////////////////////////////////////////////
  MUSICS
*////////////////////////////////////////////////

// notes of the melody followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
const int NeverGonnaGiveYouUp[] = { //114
  /* 
  Never Gonna Give you Up
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
  */
  // Never Gonna Give You Up - Rick Astley
  // Score available at https://musescore.com/chlorondria_5/never-gonna-give-you-up_alto-sax
  // Arranged by Chlorondria

  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //1
  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //repeat from 1
  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
};

const int TakeOnMe[] = { //140
  /* 
  Take on me
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
  */
  // Take on me, by A-ha
  // Score available at https://musescore.com/user/27103612/scores/4834399
  // Arranged by Edward Truong

  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
};

const int MyLittlePony[] = {
  // Original piece arranged by Huy Pham
  
  // Allegretto (First phrase)
  NOTE_E5, 8, NOTE_G5, 8, NOTE_E5, 8, NOTE_D5, 4, NOTE_G5, -4, // "My little po-ny"
  NOTE_C5, 8, NOTE_D5, 8, NOTE_C5, 8, NOTE_B4, 4, NOTE_G4, -4, // "My little po-ny"
  NOTE_A4, 4, NOTE_B4, 4, NOTE_C5, 4, NOTE_D5, 4,//"ah ah ah ah"
  
  // Lively (Second phrase)
  NOTE_C5, 2, NOTE_B4, 8, NOTE_C5, 4, NOTE_D5, 4, NOTE_C5, 2, // "My little po-ny"
  REST, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4, NOTE_C5, 4, //"I used to wonder"
  NOTE_D5, 4, NOTE_C5, 8, NOTE_E5, 4, NOTE_D5, 4, NOTE_C5, 4, // "What friendship could be"
  
  // Third phrase
  NOTE_C5, 2, NOTE_B4, 8, NOTE_C5, 4, NOTE_D5, 4, NOTE_C5, 2, // "My little po-ny"
  NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_G5, 4, NOTE_G5, 4, // "Until you all shared"
  NOTE_E5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_E5, 4, NOTE_D5, 2, // "its magic with me"

};

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
