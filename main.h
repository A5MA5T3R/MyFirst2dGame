#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <set>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <utility>
#include <stdlib.h>

#include "map.h"
#include "input.h"



using namespace sf;
using namespace std;

const char* GAME_NAME = "Wisethug";
const int WIN_HEIGHT = 576;
const int WIN_WIDTH = 800;
const int SPRITE_SIZE = 32;
const int WALK_SPEED = 1;
const int ROW_COUNT = 18;
const int COL_COUNT = 25;


void animPlayer();
void checkButton(Map map);
int simpleCheckCollisions();
void moveCube(RectangleShape& cube);
vector<string> explode(string const& content, char delim);
void checkMapCol(RectangleShape rects[], int levelLoadedCol[]);



