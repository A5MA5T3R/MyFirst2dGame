#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class InputHandler
{
private:

public:

	InputHandler() = default;

	static bool IsKeyPressed(Keyboard::Key key);
	static bool IsKeyReleased(Keyboard::Key key);

};
