#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#include "Accueil.h"
#include "Game.h"

enum class SceneType {
	Accueil,
	Jeu,
	Pause
};


class SceneManager {
public:
    void Initialize(RenderWindow& window);
    void Update(RenderWindow& window);
    void Render(RenderWindow& window);
    void ChangeScene(SceneType newScene);
private:
    SceneType currentScene = SceneType::Accueil;
    Accueil accueil;
    Game game;
    //Pause pause;
};

