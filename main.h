#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"

using namespace sf;
using namespace std;

const char* GAME_NAME = "Wisethug";
const int WIN_HEIGHT = 576;
const int WIN_WIDTH = 800;
const int SPRITE_SIZE = 32;
const int WALK_SPEED = 3.5;
void animPlayer();
void checkButton();
