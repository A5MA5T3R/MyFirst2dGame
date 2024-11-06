#pragma	once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>


using namespace std;
using namespace sf;

#include "player.h"
#include "inputhandler.h"
#include "Entity.h"
#include "Game.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "Accueil.h"


const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
ContextSettings settings;
RenderWindow window;


int main();

void reorganizeSpriteSheet(const std::string& inputPath, const std::string& outputPath, int spriteWidth, int spriteHeight, int spritesPerRow, int totalSprites);

