#include "main.h"

#include <set>


RenderWindow window;

Input input;

Texture wiseTexture;
Sprite wiseSprite;

enum Directions { Down, Right, Up, Left, Down_Atk, Right_Atk, Up_Atk, Left_Atk };

Vector2i wiseAnim(0, Down);
Clock wiseAnimClock;

bool wiseIdle = true;
bool wiseAtk = false;

   
int main()
{
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT,32), GAME_NAME, Style::Default);
    window.setVerticalSyncEnabled(true);

    if (!wiseTexture.loadFromFile("res/Sprite/first-sprite/hero_sheet.png"))
        cout << "Error charging texture" << endl ;

    wiseSprite.setTexture(wiseTexture);

	while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        checkButton();
        animPlayer();

        window.clear(Color::Black);

        window.draw(wiseSprite);

        window.display();

    }
    
    return 0;
}

void checkButton()
{
    
        if (input.GetButton().left == true)
        {
            if(wiseAtk)
            {
                wiseAnim.y = Left_Atk;

            } else
            {
                wiseAnim.y = Left;
            }
            wiseSprite.move(-WALK_SPEED, 0);
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
            wiseSprite.move(WALK_SPEED, 0);
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
            wiseSprite.move(0, -WALK_SPEED);
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
            wiseSprite.move(0, WALK_SPEED);
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


}

void animPlayer()
{
    wiseSprite.setTextureRect(IntRect(wiseAnim.x * SPRITE_SIZE, wiseAnim.y * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
    wiseSprite.setScale(4, 4);

    if (wiseAnimClock.getElapsedTime().asSeconds() > 0.1f)
    {
        if (wiseAnim.x * SPRITE_SIZE >= wiseTexture.getSize().x - SPRITE_SIZE)
        {
            wiseAnim.x = 0;

            if(wiseAtk)
            {
                wiseAtk = false;
                wiseAnim.y -= 4;
            }
        }

        else
        {
            if (!wiseIdle || wiseAtk)
            {
                wiseAnim.x++;
            }
        }

        wiseAnimClock.restart();

    }


}


