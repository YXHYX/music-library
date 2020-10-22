#include "Music.h"

//empty constructor
Music::Music()
{

}

Music::Music(int buzzerPin, int musicNotes [], int musicDurations [], int tempo, int notesLength)
	: 	_buzzerPin(buzzerPin),
	_musicNotes(musicNotes), _musicDurations(musicDurations),
	tempo(tempo), _notesLength(notesLength)
{
	this->_currentNote = 0;
	this->_currentDuration = 0;
	if(!this->tempo)
		this->tempo = BPM;

	this->pause = false;
}

Music::~Music()
{
	delete this->_musicNotes;
	delete this->_musicDurations;
}

/*		Functions   	*/

//Initializers
void Music::init(int buzzerPin, int musicNotes[], int musicDurations[], int tempo, int notesLength)
{
	this->_buzzerPin = buzzerPin;

	this->tempo = tempo;
	this->_notesLength = notesLength;
	if(!this->tempo)
		this->tempo = BPM;

	this->_musicNotes = musicNotes;
	this->_musicDurations = musicDurations;

	this->pause = false;
}

//Functions
void Music::play()
{
    //reset if it exceeds the notes limit
    if(this->_currentNote >= this->_notesLength - 1)
        this->reset();

    //play the notes
	for(int i = this->_currentNote; i < this->_notesLength; i++)
	{
		this->_currentDuration = this->tempo / this->_musicDurations[this->_currentNote];

		tone(this->_buzzerPin, this->_musicNotes[this->_currentNote], this->_currentDuration);

		int pauseBetweenNotes = this->_currentDuration * 1.45;

        //pause between notes
		delay(pauseBetweenNotes);

		this->_currentNote = i;
	}
}

void Music::resume()
{
    this->pause = false;
}

void Music::reset()
{
	this->_currentNote = 0;
}

void Music::stop()
{
    this->pause = true;
}
