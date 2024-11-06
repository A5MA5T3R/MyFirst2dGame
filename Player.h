#pragma once
#include "entity.h"

struct  Direction { bool Down, Right, Up, Left, case_Idle, Attack; };


class Player : public Entity
{
protected:
	float speed;
	Clock heroClock;
	Direction direction;
	int AnimX, AnimY;
	unsigned int SpriteSize;
	Texture* spriteTexture;
	int health;
	int check_one_atk;

public:

	Player(const string& name, const string& path = "", float x = 0.0f, float y = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f));

	void move(float deltaTime, Direction direction);

	void Animation();

	virtual void Initialize() override;

	void is_dead() const;

	int get_health() const;

	void set_health(int h);

	bool can_move(const string& d);

};


class Player1 : public Player
{
private:

public:
	Player1(const string& name, const string& path = "", float x = 0.0f, float y = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f));

	void Update(float deltaTime);

	void set_direction();

	void deal_damage(Player& player2);

	

};

class Player2 : public Player
{
private:

public:
	Player2(const string& name, const string& path = "", float x = 0.0f, float y = 0.0f, Vector2f scale = Vector2f(1.0f, 1.0f));

	void Update(float deltaTime);

	void set_direction();

	void deal_damage(Player& player1);

};

