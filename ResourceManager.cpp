#include "ResourceManager.h"

map<string, shared_ptr<Texture>> ResourceManager::textures;

shared_ptr<Texture> ResourceManager::getTexture(const string& name)
{
	auto texture = textures.find(name);
	if (texture != textures.end()) {
		return texture->second;
	}
	else {
		return nullptr;
	}
}

shared_ptr<Texture> ResourceManager::loadTexture(const string& name, const string& path)
{
	auto texture = getTexture(name);
	if (texture != nullptr) {
		return texture;
	}	

	else {

		texture = make_shared<Texture>();

		if (!texture->loadFromFile(path)) {
			cout << "Failed to load texture: " << path << endl;
			return nullptr;
		}
		textures[name] = texture;
		return texture;
	}
}

map<string, shared_ptr<Font>> ResourceManager::fonts;

shared_ptr<Font> ResourceManager::getFont(const string& name)
{
	auto font = fonts.find(name);
	if (font != fonts.end()) {
		return font->second;
	}
	else {
		cout << "Failed to get font: " << name << endl;
		return nullptr;
	}
}

shared_ptr<Font> ResourceManager::loadFont(const string& name, const string& path)
{
	auto font = getFont(name);
	if (font != nullptr) {
		return font;
	}
	else {
		font = make_shared<Font>();
		if (!font->loadFromFile(path)) {
			cout << "Failed to load font: " << path << endl;
			return nullptr;
		}
		fonts[name] = font;
		return font;
	}
}

map<string, shared_ptr<SoundBuffer>> ResourceManager::soundBuffers;

shared_ptr<SoundBuffer> ResourceManager::getSoundBuffer(const string& name)
{
	auto soundBuffer = soundBuffers.find(name);
	if (soundBuffer != soundBuffers.end()) {
		return soundBuffer->second;
	}
	else {
		cout << "Failed to get sound buffer: " << name << endl;
		return nullptr;
	}
}

shared_ptr<SoundBuffer> ResourceManager::loadSoundBuffer(const string& name, const string& path)
{
	auto soundBuffer = getSoundBuffer(name);
	if (soundBuffer != nullptr) {
		return soundBuffer;
	}
	else {
		soundBuffer = make_shared<SoundBuffer>();
		if (!soundBuffer->loadFromFile(path)) {
			cout << "Failed to load sound buffer: " << path << endl;
			return nullptr;
		}
		soundBuffers[name] = soundBuffer;
		return soundBuffer;
	}
}

map<string, shared_ptr<Music>> ResourceManager::musics;

shared_ptr<Music> ResourceManager::getMusic(const string& name)
{
	auto m = musics.find(name);
	if (m != musics.end()) {
		return m->second;
	}
	else {
		cout << "Failed to get music: " << name << endl;
		return nullptr;
	}
}

shared_ptr<Music> ResourceManager::loadMusic(const string& name, const string& path)
{
	auto music = getMusic(name);
	if (music != nullptr) {
		return music;
	}
	else {
		music = make_shared<Music>();
		if (!music->openFromFile(path)) {
			cout << "Failed to load music: " << path << endl;
			return nullptr;
		}
		musics[name] = music;
		return music;
	}
}






