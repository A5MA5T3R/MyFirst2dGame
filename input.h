#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <fstream> //pour travailler avec des fichiers
#include <string> //pour travailler avec des chaines de caracteres
#include <vector>
#include <sstream> //pr travailler avec des buffers et des streams
#include <utility>

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


