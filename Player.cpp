#include "Player.h"

Player::Player(const string& name, const string& path, float x, float y, Vector2f scale)
	: Entity(name, path, x, y, scale), speed(300.0f), heroClock(), AnimX(0), AnimY(0), SpriteSize(32), health(100), check_one_atk(0)
{
	direction.Down = direction.Left = direction.Right = direction.Up = false;
	direction.case_Idle = true;
	direction.Attack = false;
}

Player1::Player1(const string& name, const string& path, float x, float y, Vector2f scale)
	: Player(name, path, x, y, scale)
{
}

Player2::Player2(const string& name, const string& path, float x, float y, Vector2f scale)
	: Player(name, path, x, y, scale)
{
}

void Player::Initialize()
{
	setSpriteTexture();
	sprite.setTextureRect(IntRect(AnimX, AnimY, SpriteSize, SpriteSize));
	setSpritePosition(posX, posY);
	setSpriteScale(Scale);
}

void Player::Animation()
{
	sprite.setTextureRect(IntRect(AnimX * SpriteSize, AnimY * SpriteSize, SpriteSize, SpriteSize));
	if (heroClock.getElapsedTime().asSeconds() > 0.1f)
	{
		if (AnimX * SpriteSize >= getSpriteSize().x - SpriteSize)
		{
			AnimX = 0;
			if (direction.Attack)
			{
				direction.Attack = false;
				AnimY -= 4;
			}
		}
		else
		{
			if (!direction.case_Idle || direction.Attack)
				AnimX++;
		}
		heroClock.restart();
	}

}

void Player::move(float deltaTime, Direction direction) {
	Vector2f movement(0.0f, 0.0f);


	if (direction.Up) {
		if (direction.Attack)
		{
			AnimY = 6;
		}
		else {
			AnimY = 2;
		}
		if(can_move("Up"))
		{
			movement.y = -speed * deltaTime;
		}
	}

	if (direction.Down) {
		if (direction.Attack)
		{
			AnimY = 4;
		}
		else {
			AnimY = 0;
		}
		if (can_move("Down"))
		{
			movement.y = speed * deltaTime;
		}
	}


	if (direction.Left) {
		if (direction.Attack)
		{
			AnimY = 7;
		}
		else {
			AnimY = 3;
		}
		if (can_move("Left"))
		{
			movement.x = -speed * deltaTime;
		}
	}

	if (direction.Right) {
		if (direction.Attack)
		{
			AnimY = 5;
		}
		else {
			AnimY = 1;
		}
		if (can_move("Right")) 
		{
			movement.x = speed * deltaTime;
		}
	}

	sprite.move(movement);

}

bool Player::can_move(const string& d)
{
	int temp_posX = round(sprite.getPosition().x / SpriteSize);
	int temp_PosY = round(sprite.getPosition().y / SpriteSize);

	if (d == "Up")
	{
		temp_PosY = round(sprite.getPosition().y);
		if (temp_PosY - 1 <= 0)
		{
			return false;
		}
	}

	if (d == "Down")
	{
		temp_PosY = round(sprite.getPosition().y);
		if (temp_PosY + 1 >= 840)
		{
			return false;
		}
	}

	if (d == "Left")
	{
		temp_posX = round(sprite.getPosition().x);
		if (temp_posX - 1 <= 0)
		{
			return false;
		}
	}

	if (d == "Right")
	{
		temp_posX = round(sprite.getPosition().x);
		if (temp_posX + 1 >= 1780)
		{
			return false;
		}
	}

	return true;
}

int Player::get_health() const
{
	return health;
}

void Player::set_health(int h)
{
	health = h;
}

void Player::is_dead() const
{
	if (health <= 0)
	{
		cout << sprite_name << " is dead" << endl;
	}
}

void Player1::deal_damage(Player& player2)
{
	if (check_one_atk == 0)
	{
		if (sprite.getGlobalBounds().intersects(player2.getSprite().getGlobalBounds()) && direction.Attack)
		{
			player2.set_health(player2.get_health() - 10);
			cout << player2.get_health() << endl;
			check_one_atk = 1;
		}
	}
	if (check_one_atk == 1 && !direction.Attack)
	{
		check_one_atk = 0;
	}
}

void Player2::deal_damage(Player& player1)
{
	if (check_one_atk == 0)
	{
		if (sprite.getGlobalBounds().intersects(player1.getSprite().getGlobalBounds()) && direction.Attack)
		{
			player1.set_health(player1.get_health() - 10);
			cout << player1.get_health() << endl;
			check_one_atk = 1;
		}
	}
	if (check_one_atk == 1 && !direction.Attack)
	{
		check_one_atk = 0;
	}
}

void Player1::Update(float deltaTime)
{
	set_direction();
	move(deltaTime, direction);
	Animation();
	is_dead();
}

void Player2::Update(float deltaTime)
{
	set_direction();
	move(deltaTime, direction);
	Animation();
	is_dead();
}

void Player1::set_direction() {

	direction.Up = direction.Down = direction.Left = direction.Right = false;
	direction.case_Idle = true;

	if (Keyboard::isKeyPressed(Keyboard::Z)) {
		direction.Up = true;
		direction.case_Idle = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		direction.Down = true;
		direction.case_Idle = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		direction.Left = true;
		direction.case_Idle = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		direction.Right = true;
		direction.case_Idle = false;
	}
	if (Mouse::isButtonPressed(Mouse::Left) && !direction.Attack) {
		direction.Attack = true;
		AnimX = 0;
		AnimY += 4;
	}

}

void Player2::set_direction() {

	direction.Up = direction.Down = direction.Left = direction.Right = false;
	direction.case_Idle = true;

	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		direction.Up = true;
		direction.case_Idle = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		direction.Down = true;
		direction.case_Idle = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		direction.Left = true;
		direction.case_Idle = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		direction.Right = true;
		direction.case_Idle = false;
	}
	if (Mouse::isButtonPressed(Mouse::Right) && !direction.Attack) {
		direction.Attack = true;
		AnimX = 0;
		AnimY += 4;
	}
}





