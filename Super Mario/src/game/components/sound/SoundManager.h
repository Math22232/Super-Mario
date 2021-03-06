#pragma once
#include "..\observer\Observer.h"
#include "SDL_mixer.h"
#include <iostream>

class SoundManager: public Observer
{
public:
	SoundManager();
	~SoundManager();


public:
	bool Init();
	void Update();
	void onNotification(Event& event) override;

private:
	Mix_Chunk* m_SoundFiles[EVENT_SIZE];
	Mix_Music* m_MusicFiles[EVENT_SIZE];
	bool LoadFile(std::string& path, Event& event);
	bool LoadMusFile(std::string& path, Event& event);
	bool PlayMus(std::string path, Event& event);
	bool PlayWAV(std::string path, Event& event);
	
};

