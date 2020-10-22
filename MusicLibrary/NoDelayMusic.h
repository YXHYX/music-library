#ifndef NODELAYMUSIC_H
#define NODELAYMUSIC_H

#include "Music.h"

class NoDelayMusic
: public Music
{
public:
    NoDelayMusic();
    NoDelayMusic(int buzzerPin, int musicNotes [], int musicDurations [], int tempo, int notesLength);
    virtual ~NoDelayMusic();

    void play(); //start playing the music
	void resume(); //resume where it was paused
	void reset(); //reset the music to start from the begining
	void stop(); //pause the music


private:
    //for no delay
    long _currentMillis;
    long _previosMillis;

    bool _playNote;

    void playNote();
};

#endif
