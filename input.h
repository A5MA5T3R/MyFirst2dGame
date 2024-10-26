#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class Input
{
	struct Button { bool left, right, down, up, attack, escape; };

public:
	Input();
	void InputHandler(Event event, RenderWindow& window);

	Button GetButton(void) const;


private:
	Button button;
	
};



#endif


