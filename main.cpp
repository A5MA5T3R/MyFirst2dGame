#include "main.h"


bool displayText = false;

Font font; 
Text clicText;

int main()
{
    RenderWindow window;
    window.create(VideoMode::getDesktopMode(), GAME_NAME, Style::Fullscreen);
    window.setVerticalSyncEnabled(true);

    loadFont(font);
    Text txt;
    setText(txt, font,"Ntm césar", 50, Color::Red, Text::Bold | Text::Underlined);

    Text escText;
    setText(escText, font, "JE REGARDE PAS", 150, Color::Yellow, Text::Bold);
    
    Text spaceText;
    setText(spaceText, font, "JEN AI MARRE", 500, Color::Blue, Text::Bold);

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            ImputHandler(event, window);
        }

        window.clear(Color::Black);


        if (Keyboard::isKeyPressed(Keyboard::Z))
        {
            setText(txt, font, "Z", 500, Color::Blue, Text::Bold);
            window.draw(txt);
        }
        if (Keyboard::isKeyPressed(Keyboard::Q))
        {
            setText(txt, font, "Q", 500, Color::Blue, Text::Bold);
            window.draw(txt);
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            setText(txt, font, "S", 500, Color::Blue, Text::Bold);
            window.draw(txt);
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            setText(txt, font, "D", 500, Color::Blue, Text::Bold);
            window.draw(txt);
        }


        if (Mouse::isButtonPressed(Mouse::Left))
        {
            setText(clicText, font, "Gauche", 500, Color::Blue, Text::Bold);
            window.draw(clicText);
        }
        if (Mouse::isButtonPressed(Mouse::Right))
        {
            setText(clicText, font, "Droite", 500, Color::Blue, Text::Bold);
            window.draw(clicText);
        }
        if (Mouse::isButtonPressed(Mouse::Middle))
        {
            setText(clicText, font, "Middle", 500, Color::Blue, Text::Bold);
            window.draw(clicText);
        }


        if (displayText) window.draw(escText);

        if (Keyboard::isKeyPressed(Keyboard::Space)) 
        {
            window.draw(spaceText);
        }

        window.display();
    }
    
    return 0;
}


void ImputHandler(Event event, RenderWindow& window) 
{

    if (event.type == Event::Closed) window.close();

    if (event.type == Event::KeyPressed) keypressedImput(window ,event);

}

void loadFont(Font &font) 
{
    if (!font.loadFromFile("res/font_halloween.ttf")) cout << "can't load font" << endl;
    
}

void setText(Text& txt, Font& font, String texte, unsigned int charSize, Color color, Uint32 style)
{
    txt.setFont(font);
    txt.setString(texte);
    txt.setCharacterSize(charSize);
    txt.setFillColor(color);
    txt.setStyle(style);
}

void keypressedImput(RenderWindow& window, Event& event)
{
    if (event.key.code == Keyboard::Escape)
    {
        displayText = true;
    }
}




