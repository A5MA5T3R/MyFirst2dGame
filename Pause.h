#pragma once
#include "Scene.h"

class Pause : public Scene
{

public:
	Pause() = default;
	virtual void Initialize(RenderWindow& window) override;
	virtual void Update(RenderWindow& window) override;
	virtual void Render(RenderWindow& window) override;

	Text& get_text(String texte);
	bool handleTextClick(RenderWindow& window, Text& text);
	void center_text(RenderWindow& window, Text& txt);
	void set_text(Text& txt, Font& font, String texte, unsigned int charSize, Color color, Uint32 style);
	void Draw(RenderWindow& window);

private:
	Text titre;
	Text resume;
	Text leave;
};
