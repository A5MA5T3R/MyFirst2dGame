#include "InputHandler.h"

bool InputHandler::IsKeyPressed(Keyboard::Key key) 
{
	return Keyboard::isKeyPressed(key);
}

bool InputHandler::IsKeyReleased(Keyboard::Key key) 
{
	return !(Keyboard::isKeyPressed(key));
}

