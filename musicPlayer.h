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
const short int NeverGonnaGiveYouUp[] = { //114
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
  /*
  REST,4, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_D5,8, NOTE_E5,8, NOTE_CS5,-8,
  NOTE_B4,16, NOTE_A4,2, REST,4, 
  
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,4, NOTE_A4,8, //7
  NOTE_A5,8, REST,8, NOTE_A5,8, NOTE_E5,-4, REST,4, 
  NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,8, REST,8,
  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, REST,4,
   
  NOTE_D5,2, NOTE_E5,8, NOTE_FS5,8, NOTE_D5,8, //13
  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, NOTE_A4,4,
  REST,2, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8,
  REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,-8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //18
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,8, NOTE_A4,8, NOTE_A4,8, 
  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  //23
  NOTE_E5,4, NOTE_D5,2, REST,4,
  REST,8, NOTE_B4,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,4, REST,8,
  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
  REST,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_D5,8,
  
  REST,8, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //29
  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
  NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4, REST,8,
  REST,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,4, NOTE_E5,-4, 
  NOTE_D5,2, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, 
  NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_A4,8, NOTE_A4,4,

  REST,-4, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //35
  REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 

   NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //40
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  
  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
   
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //45
  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  
  NOTE_E5,4, NOTE_D5,2, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //45
  
  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 

  NOTE_E5,4, NOTE_D5,2, REST,4
  */
};

const short int TakeOnMe[] = { //140
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
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  /*
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  */
};

const short int MyLittlePony[] = {
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
  
  /*
  // Fourth phrase
  NOTE_C5, 8, NOTE_C5, 8, NOTE_C5, 4, NOTE_C5, 4, // "Big adventures"
  NOTE_G5, 8, NOTE_A5, 4, NOTE_G5, -4, // "Tons of funs"
  NOTE_C5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_D5, 4, NOTE_D5, 4, // "A beautiful heart"
  NOTE_D5, 4, NOTE_D5, 8, NOTE_E5, 4, NOTE_D5, -2, // "Faithful and strong"
  

  // Fifth phrase
  NOTE_C5, 8, NOTE_D5, 4, NOTE_E5, 4, NOTE_C5, 8, // "Sharing kindness"
  NOTE_C5, 8, NOTE_C5, 8, NOTE_G5, 8, NOTE_A5, 4, NOTE_G5, -4, // "It's an easy feat"
  
  
  // Sixth phrase
  NOTE_C5, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4, NOTE_E5, 4, NOTE_A5, 4, NOTE_G5, 8, NOTE_G5, 4, // "And magic makes it all complete"
  NOTE_E5, 8, NOTE_F5, 4, NOTE_C5, 2, NOTE_B4, 8, NOTE_C5, 4, NOTE_D5, 4, NOTE_C5, -2, // "You have My Little Pony"
  
  // Seventh phrase
  NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 4, NOTE_C5, 8, NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 4, NOTE_C5, 4, NOTE_E5, 2,  // "Do you know you are my very best"
  NOTE_C5, 2, NOTE_B4, 2, NOTE_C5, 2, NOTE_D5, 2, NOTE_C5, 1,// "friends"
  */
};

/*///////////////////////////////////////////////
  DRIVERS
*////////////////////////////////////////////////

bool isPlayingMusic = false; // Vanguard to make sure we don't overlap

// Passing the array into the music player function
// Notes are actually x2, but because we increment +2, it's halved.
// arg1 = music array, arg2 = notes * 2, args3 = song tempo
void playMusic(int melody[], unsigned short int notes, unsigned short int tempo)
{
  isPlayingMusic = true; // Locking the program to only play one song at a time

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;

  int divider = 0, noteDuration = 0;

  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    //delay(noteDuration);
    myDelay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }

  isPlayingMusic = false;
}

// Selecting which array to run
void selectMusic(byte index) // LED pin default to 11
{
  if (!isPlayingMusic) // If currently is not playing music
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
}
