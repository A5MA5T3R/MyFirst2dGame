#include "main.h"

#include <set>


RenderWindow window;


Input input;

Font font; 
Text txt, positionX, positionY;
float posX = 20, posY = 20;
char temp[256];
CircleShape circle1(20);


   
int main()
{

    ContextSettings options;
    options.antialiasingLevel = 8;
    window.create(VideoMode::getDesktopMode(), GAME_NAME, Style::Fullscreen, options);
    window.setVerticalSyncEnabled(true);
    Vector2u windowSize = window.getSize();
    float maxX = windowSize.x;
    float maxY = windowSize.y;

    circle1.setFillColor(Color::White);
    circle1.setOrigin(20, 20);
    


    loadFont(font);
    setText(txt, font,"Ntm césar", 50, Color::Red, Text::Bold | Text::Underlined);

	while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
            txt.setString("");
        }

        checkButton(maxX, maxY);


        window.clear(Color::Black);

		window.draw(txt);
		window.draw(positionX);
		window.draw(positionY);
        window.draw(circle1);

        window.display();

    }
    
    return 0;
}

void loadFont(Font &font) 
{
    if (!font.loadFromFile("res/fonts/font_halloween.ttf")) cout << "can't load font" << endl;
    
}

void setText(Text& txt, Font& font, String texte, unsigned int charSize, Color color, Uint32 style)
{
    txt.setFont(font);
    txt.setString(texte);
    txt.setCharacterSize(charSize);
    txt.setFillColor(color);
    txt.setStyle(style);
}

void checkButton(float maxX, float maxY)
{
    if(input.GetButton().left == true)
    {
        cout << "avant1 : " << posX << endl;
        posX -= 10;
        cout << "apres1 : " << posX << endl;

        if (posX < 0)
            posX = 0;
        if (posX >= maxX)
            posX = maxX;
        //sprintf_s(temp, "%d", posX);
        //setText(positionX, font, temp, 300, Color::Blue, Text::Bold);
    }

    if(input.GetButton().right == true)
    {
        cout << "avant2 : " << posX << endl;
        posX += 10;
        cout << "apres2 : " << posX << endl;

        if (posX < 0)
            posX = 0;
        if (posX >= maxX)
            posX = maxX;
        //sprintf_s(temp, "%d", posX);
        //setText(positionX, font, temp, 300, Color::Blue, Text::Bold);
    }

    if (input.GetButton().up == true)
    {
        posY -= 10;
        if (posY < 0)
            posY = 0;
        if (posY >= maxY)
            posY = maxY;
        //sprintf_s(temp, "%d", posY);
        //setText(positionY, font, temp, 500, Color::Yellow, Text::Bold);
    }

    if (input.GetButton().down == true)
    {
        posY += 10;
        if (posY < 0)
            posY = 0;
        if (posY >= maxY)
            posY = maxY;
        //sprintf_s(temp, "%d", posY);
        //setText(positionY, font, temp, 500, Color::Yellow, Text::Bold);
    }

    circle1.setPosition(posX, posY);


    if (input.GetButton().attack == true)
    {
        setText(txt, font, "Attack", 500, Color::White, Text::Bold);
    }

    if (input.GetButton().escape == true)
    {
        window.close();
    }


}



