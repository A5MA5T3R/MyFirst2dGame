#include "Accueil.h"

void Accueil::Initialize(RenderWindow& window)
{
	auto font = ResourceManager::loadFont("font_halloween", "res/fonts/font_halloween.ttf");
	set_text(titre, *font, "Arena", 150, Color::Red, Text::Bold);
	set_text(solo, *font, "Solo", 75, Color::White, Text::Bold);
	set_text(multi, *font, "Multiplayer", 75, Color::White, Text::Bold);
	center_text(window, titre);
	center_text(window, solo);
	center_text(window, multi);
	titre.setPosition(titre.getPosition().x, titre.getPosition().y - 300);
	solo.setPosition(solo.getPosition().x, solo.getPosition().y - 50);
	multi.setPosition(multi.getPosition().x, multi.getPosition().y + 100);
}

void Accueil::Update(RenderWindow& window)
{
	handleTextClick(window, multi);
}

void Accueil::Render(RenderWindow& window)
{
	window.clear(Color::Black);
	Draw(window);
	window.display();
}

void Accueil::Draw(RenderWindow& window)
{
	window.draw(titre);
	window.draw(solo);
	window.draw(multi);
}

void Accueil::set_text(Text& txt, Font& font, String texte, unsigned int charSize, Color color, Uint32 style) {
	txt.setFont(font);          
	txt.setString(texte);        
	txt.setCharacterSize(charSize);  
	txt.setFillColor(color);    
	txt.setStyle(style);
}

void Accueil::center_text(RenderWindow& window, Text& txt)
{
	auto textRect = txt.getLocalBounds();
	auto windowsize = window.getSize();
	txt.setPosition((windowsize.x - textRect.width) / 2 - textRect.left, (windowsize.y - textRect.height) / 2.0f - textRect.top);

}

bool Accueil::handleTextClick(RenderWindow& window, Text& text) {
	if (Mouse::isButtonPressed(Mouse::Left)) {
		Vector2i mousePos = Mouse::getPosition(window); 
		FloatRect textBounds = text.getGlobalBounds();  

		return textBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	}
	return  false;
}

Text& Accueil::get_text()
{
	return multi;
}