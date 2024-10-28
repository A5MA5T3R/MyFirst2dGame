#include "main.h"

#pragma region Variables globales
RenderWindow window;

Input input;

Texture wiseTexture;
Sprite wiseSprite;

enum Directions { Down, Right, Up, Left, Down_Atk, Right_Atk, Up_Atk, Left_Atk };

Vector2i wiseAnim(0, Down);
Clock wiseAnimClock;

bool wiseIdle = true;
bool wiseAtk = false;

RectangleShape cube(Vector2f(SPRITE_SIZE, SPRITE_SIZE));

FloatRect cubeHitbox;

FloatRect wiseHitbox;

int levelLoaded1[450];
int levelLoaded2[450];

int levelLoadedCol1[450];
int levelLoadedCol2[450];

RectangleShape rects[450];
RectangleShape rects2[450];

bool showDebugMap = false;

#pragma endregion

int main()
{
	window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), GAME_NAME, Style::Default);
	window.setVerticalSyncEnabled(true);

	if (!wiseTexture.loadFromFile("res/Sprite/first-sprite/hero_sheet.png"))
		cout << "Error charging texture" << endl;

	wiseSprite.setTexture(wiseTexture);
	wiseSprite.setTextureRect(IntRect(wiseAnim.x * SPRITE_SIZE, wiseAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));


	ifstream ifs("res/maps/map1.txt");
	string content(istreambuf_iterator<char>(ifs), (istreambuf_iterator<char>()));
	auto exploded = explode(content, ' ');

	for (int i = 0; i < 450; i++)
		levelLoaded1[i] = stoi(exploded[i]);

	ifstream ifs_col("res/maps/map1_col.txt");
	string content_col(istreambuf_iterator<char>(ifs_col), (istreambuf_iterator<char>()));
	auto exploded_col = explode(content_col, ' ');

	for (int i = 0; i < 450; i++)
		levelLoadedCol1[i] = stoi(exploded_col[i]);

	ifstream ifs2("res/maps/map2.txt");
	string content2(istreambuf_iterator<char>(ifs2), (istreambuf_iterator<char>()));
	auto exploded2 = explode(content2, ' ');

	for (int i = 0; i < 450; i++)
		levelLoaded2[i] = stoi(exploded2[i]);

	ifstream ifs_col2("res/maps/map2_col.txt");
	string content_col2(istreambuf_iterator<char>(ifs_col2), (istreambuf_iterator<char>()));
	auto exploded_col2 = explode(content_col2, ' ');

	for (int i = 0; i < 450; i++)
		levelLoadedCol2[i] = stoi(exploded_col2[i]);



	Map map1;

	Map map2;

	if (!map1.load("res/maps/tileset.png", Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded1, COL_COUNT, ROW_COUNT))
		return -1;

	if (!map2.load("res/maps/tileset.png", Vector2u(SPRITE_SIZE, SPRITE_SIZE), levelLoaded2, COL_COUNT, ROW_COUNT))
		return -1;



	cube.setFillColor(Color(255,0,0,100));
	cube.setPosition(SPRITE_SIZE*3, 0);

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			input.InputHandler(event, window);
		}
		//moveCube(cube);

		window.clear(Color::Black);

		window.draw(map1);

		checkButton(map2);
		animPlayer();

		window.draw(wiseSprite);

		checkMapCol(rects, levelLoaded1);
		checkMapCol(rects2, levelLoaded2);

		window.draw(cube);

		window.display();
		
	}

	return 0;
}

void checkButton(Map map)
{
	int wisePosX = round(wiseSprite.getPosition().x / SPRITE_SIZE);
	int wisePosY = round(wiseSprite.getPosition().y / SPRITE_SIZE);
	if (showDebugMap)
	{
		cout << levelLoaded1[(wisePosX + wisePosY * 25)] << endl;
		cout << wisePosX << " , " << wisePosY << endl;
	}

	if (input.GetButton().left == true)
	{
		if (wiseAtk)
		{
			wiseAnim.y = Left_Atk;

		}
		else
		{
			wiseAnim.y = Left;
		}

		wisePosX = round((wiseSprite.getPosition().x - (WALK_SPEED * 3)) / SPRITE_SIZE);
		if (levelLoadedCol1[(wisePosX + wisePosY * 25)] == 0 && wisePosX > -1)
		{
			wiseSprite.move(-WALK_SPEED, 0);
		}

		wiseIdle = false;
	}

	else if (input.GetButton().right == true)
	{
		if (wiseAtk)
		{
			wiseAnim.y = Right_Atk;

		}
		else
		{
			wiseAnim.y = Right;
		}

		wisePosX = round((wiseSprite.getPosition().x + (WALK_SPEED * 3)) / SPRITE_SIZE);
		if (levelLoadedCol1[(wisePosX + wisePosY * 25)] == 0 && wisePosX < 25)
		{
			wiseSprite.move(WALK_SPEED, 0);
		}
		wiseIdle = false;
	}

	else if (input.GetButton().up == true)
	{
		if (wiseAtk)
		{
			wiseAnim.y = Up_Atk;

		}
		else
		{
			wiseAnim.y = Up;
		}

		wisePosY = round((wiseSprite.getPosition().y - (WALK_SPEED * 3)) / SPRITE_SIZE);
		int wisePosX = round(wiseSprite.getPosition().x / SPRITE_SIZE);

		if (wisePosX >= 3 && wisePosX <= 4 && wisePosY <= -1)
		{
			cout << wisePosY << endl;
			window.draw(map);
		}
		if (levelLoadedCol1[(wisePosX + wisePosY * 25)] == 0 && wisePosY > -1)
		{

			wiseSprite.move(0, -WALK_SPEED);
		}
		wiseIdle = false;
	}

	else if (input.GetButton().down == true)
	{
		if (wiseAtk)
		{
			wiseAnim.y = Down_Atk;

		}
		else
		{
			wiseAnim.y = Down;
		}

		wisePosY = round((wiseSprite.getPosition().y + (WALK_SPEED * 3)) / SPRITE_SIZE);
		if (levelLoadedCol1[(wisePosX + wisePosY * 25)] == 0 && wisePosY < 18)
		{
			wiseSprite.move(0, WALK_SPEED);
		}
		wiseIdle = false;
	}

	else
	{
		wiseIdle = true;
	}

	if (input.GetButton().attack == true && !wiseAtk)
	{
		wiseAtk = true;
		wiseAnim.x = 0;
		wiseAnim.y += 4;
	}


	if (input.GetButton().escape == true)
	{
		window.close();
	}

	showDebugMap = input.GetButton().space;
}

void animPlayer()
{
	wiseSprite.setTextureRect(IntRect(wiseAnim.x * SPRITE_SIZE, wiseAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
	if (wiseAnimClock.getElapsedTime().asSeconds() > 0.1f)
	{
		if (wiseAnim.x * SPRITE_SIZE >= wiseTexture.getSize().x - SPRITE_SIZE)
		{
			wiseAnim.x = 0;
			if (wiseAtk)
			{
				wiseAtk = false;
				wiseAnim.y -= 4;
			}
		}
		else
		{
			if (!wiseIdle || wiseAtk)
				wiseAnim.x++;
		}
		wiseAnimClock.restart();
	}
}

int simpleCheckCollisions()
{
	cubeHitbox = cube.getGlobalBounds();

	wiseHitbox = wiseSprite.getGlobalBounds();

	if (wiseHitbox.intersects(cubeHitbox))
		return 1;

	return 0;
}

void moveCube(RectangleShape& cube)
{
	if (simpleCheckCollisions())
	{
		cout << "ok" << endl;
		cube.setPosition(rand() % (500 + 1), rand() % (500 + 1));
		

	}
}


vector<string> explode(string const& content, char delim)
{
	vector<string> result;
	istringstream icontent(content);

	for (string token; getline(icontent, token, delim);)
	{
		result.push_back(move(token));
	}

	return result;
}


void checkMapCol(RectangleShape rects1[], int levelLoadedCol[])
{
	for (unsigned int j = 0; j < 18; j++)
	{
		for (unsigned int i = 0; i < 25; i++)
		{
			if (levelLoadedCol[(i + j * 25)] == 1)
			{
				Vector2f pos = Vector2f(i * SPRITE_SIZE, j * SPRITE_SIZE);
				rects1[(i + j * 25)].setPosition(pos);
				rects1[(i + j * 25)].setSize(Vector2f(SPRITE_SIZE, SPRITE_SIZE));
				rects1[(i + j * 25)].setFillColor(Color(255, 0, 0, 100));
				if (showDebugMap)
				{
					window.draw(rects1[(i + j * 25)]);
					wiseHitbox = wiseSprite.getGlobalBounds();
					RectangleShape wiseSquareHitbox;
					wiseSquareHitbox.setPosition(wiseHitbox.left, wiseHitbox.top);
					wiseSquareHitbox.setSize(Vector2f(wiseHitbox.width, wiseHitbox.height));
					wiseSquareHitbox.setFillColor(Color(255, 0, 0, 100));
					window.draw(wiseSquareHitbox);

				}

			}
		}
	}
}

