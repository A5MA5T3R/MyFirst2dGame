#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#include "Player.h"
#include "InputHandler.h"
#include "ResourceManager.h"


class Scene
{
public:
		
	Scene() = default;

	virtual void Initialize(RenderWindow& window) = 0;

	virtual void Update(RenderWindow& window) = 0;

	virtual void Render(RenderWindow& window) = 0;

	void Run();


private:
	
};

