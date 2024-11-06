#pragma once
#include "Scene.h"


class Game : public Scene
{

public:
	Game();

	virtual void Initialize(RenderWindow& window);
	virtual void Update(RenderWindow& window);
	virtual void Render(RenderWindow& window);

	void Draw(RenderWindow& window) const;

private:
	Clock clock;
	float deltaTime;

	Player1 player1;
	Player2 player2;
};