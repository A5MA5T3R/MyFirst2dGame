#include <set>

#include "game.h"

Game::Game():
player1("res/Sprite/first-sprite/hero_sheet.png",0.0f, 0.0f, Vector2f(0.5f,0.5f)),
player2("res/Sprite/first-sprite/hero_sheet.png", 0.0f, 800.0f, Vector2f(3.0f,3.0f))

{

}

void Game::WindowInitialize()
{
	settings.antialiasingLevel = 8;
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Game", Style::Default, settings);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
}

void Game::Initialize()
{
	player1.Initialize();
	player2.Initialize();

}

void Game::Run()
{

	WindowInitialize();
	Initialize();

	player1.setSpritePosition(player1.getSpritePosition().x + 500, player1.getSpritePosition().y);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		
		Update();


		Render();
	}
}

void Game::Update()
{


	player1.Update();
	player2.Update();
}

void Game::Draw()
{
	player1.Draw(window);
	player2.Draw(window);
}

void Game::Render()
{
	window.clear(Color::Black);
	Draw();
	window.display();

}