#include <Music.h>

Music music;

//Notes
int melody[] = {
    C4, C3, C4, B3, B6, B3, B6, A2, C3, C4, B3, B6, B3, B6, A2, C3, C4, B3, B6, B3, B6, A2, C3, C4, B3, B6, B3, B6, A2, C3, C4, B3, B6, B3, B6, A2
};

//Notes durations
int noteDurations[] = {
    16, 16, 16, 4, 4, 4, 4, 8, 16, 16, 4, 4, 4, 4, 8, 16, 16, 4, 4, 4, 4, 8, 16, 16, 4, 4, 4, 4, 8, 16, 16, 4, 4, 4, 4, 8
};

//Melody's length
int melodylen = sizeof(melody) / sizeof(melody[0]);

int buzzerPin = 6;

void setup() {
    //Initialize the music
    music.init(buzzerPin, melody, noteDurations, 1200, melodylen);
}

void loop() {
    music.play();
}
