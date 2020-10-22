#include "NoDelayMusic.h"

NoDelayMusic::NoDelayMusic()
{

}

NoDelayMusic::NoDelayMusic(int buzzerPin, int musicNotes [], int musicDurations [], int tempo, int notesLength)
    :   Music(buzzerPin, musicNotes, musicDurations, tempo, notesLength)
{
    this->pause = false;
    this->_playNote = true;
}

NoDelayMusic::~NoDelayMusic()
{

}

void NoDelayMusic::play()
{
    //music is paused
    if(pause)
        return;

    //get elapsed time
    this->_currentMillis = millis();
    int elapsedTime = this->_currentMillis - this->_previosMillis;

    //get the duration of the current note
    this->_currentDuration = this->tempo / this->_musicDurations[this->_currentNote];
    int pauseBetweenNotes = this->_currentDuration * 1.45;

    //play the note
    if(elapsedTime < pauseBetweenNotes)
    {
        playNote();
    }
    else
    {
        this->_previosMillis = _currentMillis;
        this->_playNote = true;
    }
}

void NoDelayMusic::stop()
{
    this->pause = true;
}

void NoDelayMusic::resume()
{
    this->pause = false;
}

void NoDelayMusic::reset()
{
    this->pause = false;
    this->_currentNote = 0;
}

void NoDelayMusic::playNote()
{
    if(this->_playNote)
    {
        this->_currentNote++;

        if(this->_currentNote >= this->_notesLength)
            this->_currentNote = 0;

        tone(this->_buzzerPin, this->_musicNotes[this->_currentNote], this->_currentDuration);
        this->_playNote = false;
    }
}
