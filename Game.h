#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#include "Player.h"

class Game
{

public:
	Game();
	void Run();
	void WindowInitialize();
	void Initialize();



private:
	const int WINDOW_WIDTH = 1920;
	const int WINDOW_HEIGHT = 1080;
	ContextSettings settings;
	RenderWindow window;

	Player player1;
	Player player2;

	void Update();
	void Draw();
	void Render();

};