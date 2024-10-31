#include "Player.h"

Player::Player(const string& path, float x, float y, Vector2f scale)
: posX(x), posY(y), texturePath(path), Scale(scale)

{

}


void Player::Initialize()
{
	setSpriteTexture();
	setSpritePosition(posX, posY);
	setSpriteScale(Scale);
}

Vector2f Player::getSpritePosition() const {
	return sprite.getPosition(); 
}

void Player::setSpritePosition(float x, float y)
{
	posX = x;
	posY = y;
	sprite.setPosition(posX, posY);
	
}

Vector2f Player::getSpriteScale() const {
	return sprite.getScale();
}

void Player::setSpriteScale(Vector2f scale_vec)
{
	Scale = scale_vec;
	sprite.setScale(Scale);
}

void Player::setSpriteTexture()
{
	auto texture = ResourceManager::loadTexture("player", texturePath);
	if (texture == nullptr) {
		cout << "Failed to load player texture" << endl;
		return;
	}
	else
	{
		sprite.setTexture(*texture);
	}
}

void Player::Update()
{
	setSpritePosition(posX, posY);
	setSpriteScale(Scale);
}

void Player::Draw(RenderWindow& window) const
{
	window.draw(sprite);
}




