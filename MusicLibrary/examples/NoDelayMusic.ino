/*
    Control music through the Serial monitor window
*/
//include the library
#include <NoDelayMusic.h>

//Create a music object
NoDelayMusic music;

int melody[] = {
    C4, C3, C4, B3, B6, B3, B6, A2, C3, C4, B3, B6, B3, B6, A2, C3, C4, B3, B6, B3, B6, A2, C3, C4, B3, B6, B3, B6, A2, C3, C4, B3, B6, B3, B6, A2
};

int noteDurations[] = {
    16, 16, 16, 4, 4, 4, 4, 8, 16, 16, 4, 4, 4, 4, 8, 16, 16, 4, 4, 4, 4, 8, 16, 16, 4, 4, 4, 4, 8, 16, 16, 4, 4, 4, 4, 8
};

//Melody length
int melodylen = sizeof(melody) / sizeof(melody[0]);

int buzzerPin = 6;
char incomingData = 0;

void setup() {
    //For Serial monitor
    Serial.begin(9600);
    //Initialize the music with the tempo of 1200
    music.init(buzzerPin, melody, noteDurations, 1200, melodylen);
}

void loop() {
    if (Serial.available() > 0) {    // input entered
        incomingData = Serial.read();       // get the input

        switch(incomingData) { // check the input
            case 'p':
                Serial.println("Music resumed");
                music.resume(); // resume the music
                break;

            case 's':
                Serial.println("Music stopped");
                music.stop(); // pause the music
                break;

            case 'r':
                Serial.println("Music restart");
                music.reset(); // reset the music to startover
                break;
        }
    }

    music.play();
}
