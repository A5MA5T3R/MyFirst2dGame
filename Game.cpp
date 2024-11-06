#include <set>

#include "game.h"
#include "InputHandler.h"

Game::Game() :
	player1("Hero", "res/Sprite/first-sprite/hero_sheet.png", 0.0f, 0.0f, Vector2f(5.0f, 5.0f)),
	player2("Hero2", "res/Sprite/first-sprite/hero_sheet.png", 0.0f, 800.0f, Vector2f(5.0f, 5.0f))

{
	deltaTime = 0.0f;
}

void Game::Initialize(RenderWindow& window)
{
	player1.Initialize();
	player2.Initialize();
}

void Game::Update(RenderWindow& window)
{

	deltaTime = clock.restart().asSeconds();

	player1.Update(deltaTime);
	player2.Update(deltaTime);
	player1.deal_damage(player2);
	player2.deal_damage(player1);

}

void Game::Draw(RenderWindow& window) const
{
	player1.Draw(window);
	player2.Draw(window);
}

void Game::Render(RenderWindow& window)
{
	window.clear(Color::Black);
	Draw(window);
	window.display();

}