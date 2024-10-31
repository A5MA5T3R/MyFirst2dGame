#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#include "entity.h"
#include "ResourceManager.h"


using namespace sf;

class Player : public Entity
{
private:

	Sprite sprite;
	float posX, posY;
	string texturePath;
	Vector2f Scale;

public:
	Player(const string& path, float x = 0.0f, float y = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f));

	void Initialize();

	Vector2f getSpritePosition() const;
	void setSpritePosition(float x, float y);

	Vector2f getSpriteScale() const;
	void setSpriteScale(Vector2f scale_vec);

	void setSpriteTexture();

	void Update();

	void Draw(RenderWindow& window) const;
};
