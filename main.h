#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

const char* GAME_NAME = "Wisethug";

void ImputHandler(Event event, RenderWindow& window);

void loadFont(Font& font);

void setText(Text& txt, Font& font, String texte, unsigned int charSize, Color color, Uint32 style);

void keypressedImput(RenderWindow& window, Event& event);
