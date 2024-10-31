#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class ResourceManager
{
private:

	static map<string, shared_ptr<Texture>> textures;
	static map<string, shared_ptr<Font>> fonts;
	static map<string, shared_ptr<SoundBuffer>> soundBuffers;
	static map<string, shared_ptr<Music>> musics;
	
public:

	ResourceManager() = default;

	static shared_ptr<Texture> getTexture(const string& name);
	static shared_ptr<Texture> loadTexture(const string& name, const string& path);

	static shared_ptr<Font> getFont(const string& name);
	static shared_ptr<Font> loadFont(const string& name, const string& path);

	static shared_ptr<SoundBuffer> getSoundBuffer(const string& name);
	static shared_ptr<SoundBuffer> loadSoundBuffer(const string& name, const string& path);

	static shared_ptr<Music> getMusic(const string& name);
	static shared_ptr<Music> loadMusic(const string& name, const string& path);
};
