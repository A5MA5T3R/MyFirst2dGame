#include "input.h"


Input::Input()
{
	button.attack = button.down = button.right = button.left = button.down = button.up = 0;
}

Input::Button Input::GetButton(void) const
{
	return button;
}


void Input::InputHandler(Event event, RenderWindow& window)
{
	if (event.type == Event::Closed)
	{
		window.close();
	}


	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = true;
			break;

		case Keyboard::Space:
			button.space = true;
			break;

		case Keyboard::Z:
			button.up = true;
			break;

		case Keyboard::Q:
			button.left = true;
			break;

		case Keyboard::S:
			button.down = true;
			break;

		case Keyboard::D:
			button.right = true;
			break;

		default:
			break;
		}
	}

	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = false;
			break;

		case Keyboard::Space:
			button.space = false;
			break;

		case Keyboard::Z:
			button.up = false;
			break;

		case Keyboard::Q:
			button.left = false;
			break;

		case Keyboard::S:
			button.down = false;
			break;

		case Keyboard::D:
			button.right = false;
			break;

		default:
			break;
		}
	}

	if (event.type == Event::MouseButtonPressed) {

		if (event.mouseButton.button == Mouse::Left)
		{
			button.attack = true;
		}
	}

	if (event.type == Event::MouseButtonReleased) {

		if (event.mouseButton.button == Mouse::Left)
		{
			button.attack = false;
		}
	}


}

