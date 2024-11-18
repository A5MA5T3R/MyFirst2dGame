#include "Pause.h"

void Pause::Initialize(RenderWindow& window)
{
	auto font = ResourceManager::loadFont("font_halloween", "res/fonts/font_halloween.ttf");
	set_text(titre, *font, "Pause", 150, Color::Red, Text::Bold);
	set_text(resume, *font, "Resume", 75, Color::White, Text::Bold);
	set_text(leave, *font, "Leave", 75, Color::White, Text::Bold);
	center_text(window, titre);
	center_text(window, resume);
	center_text(window, leave);
	titre.setPosition(titre.getPosition().x, titre.getPosition().y - 300);
	resume.setPosition(resume.getPosition().x, resume.getPosition().y - 50);
	leave.setPosition(leave.getPosition().x, leave.getPosition().y + 100);
}

void Pause::Update(RenderWindow& window)
{
	handleTextClick(window, leave);
}

void Pause::Render(RenderWindow& window)
{
	window.clear(Color::Black);
	Draw(window);
	window.display();
}

void Pause::Draw(RenderWindow& window)
{
	window.draw(titre);
	window.draw(resume);
	window.draw(leave);
}

void Pause::set_text(Text& txt, Font& font, String texte, unsigned int charSize, Color color, Uint32 style) {
	txt.setFont(font);
	txt.setString(texte);
	txt.setCharacterSize(charSize);
	txt.setFillColor(color);
	txt.setStyle(style);
}

void Pause::center_text(RenderWindow& window, Text& txt)
{
	auto textRect = txt.getLocalBounds();
	auto windowsize = window.getSize();
	txt.setPosition((windowsize.x - textRect.width) / 2 - textRect.left, (windowsize.y - textRect.height) / 2.0f - textRect.top);

}

bool Pause::handleTextClick(RenderWindow& window, Text& text) {
	if (Mouse::isButtonPressed(Mouse::Left)) {
		Vector2i mousePos = Mouse::getPosition(window);
		FloatRect textBounds = text.getGlobalBounds();

		return textBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	}
	return  false;
}

Text& Pause::get_text(String texte)
{
	if (texte == "Resume")
		return resume;
	if (texte == "Leave")
		return leave;
	throw std::invalid_argument("Invalid text argument");
}