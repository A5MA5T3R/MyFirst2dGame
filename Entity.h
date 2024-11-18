#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using namespace sf;

#include "ResourceManager.h"


class Entity
{
protected:

	Sprite sprite;
	float posX, posY;
	string texturePath;
	Vector2f Scale;
    string sprite_name;

public:

    Entity(const string& name, const string& path = "", float x = 0.0f, float y = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f));

    Vector2f getSpritePosition() const;
    void setSpritePosition(float x, float y);

    Vector2f getSpriteScale() const;
    void setSpriteScale(Vector2f scale_vec);

	Sprite getSprite() const;
    void setSpriteTexture();
    Texture getSpriteTexture();
	Vector2u getSpriteSize();

    virtual void Initialize();
    virtual void Update();
    virtual void Draw(RenderWindow& window) const = 0;
	
};
