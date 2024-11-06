#include "main.h"

Game game;
Accueil accueil;
int start = 0;

int main()
{
    //reorganizeSpriteSheet("res/Sprite/second-sprite/warrior.png", "res/Sprite/second-sprite/warrior2.png",191.66, 192, 6, 24);
    //this_thread::sleep_for(chrono::seconds(10));

    settings.antialiasingLevel = 8;
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Game", Style::Default, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);


	game.Initialize(window);
	accueil.Initialize(window);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        game.Update(window);
        accueil.Update(window);



        if (start == 0) {
            if (accueil.handleTextClick(window, accueil.get_text()) == true)
            {
                game.Render(window);
				start = 1;
			}
			else 
				accueil.Render(window);
        }

		if (start == 1) {
			game.Render(window);
		}
        

    }


    return 0;
}


void reorganizeSpriteSheet(const std::string& inputPath, const std::string& outputPath, int spriteWidth, int spriteHeight, int spritesPerRow, int totalSprites) {
    sf::Image originalImage;
    if (!originalImage.loadFromFile(inputPath)) {
        std::cerr << "Erreur: impossible de charger l'image " << inputPath << std::endl;
        return;
    }

    int newColumns = spritesPerRow;
    int newRows = (totalSprites + spritesPerRow - 1) / spritesPerRow;
	cout << newRows << endl;

    sf::Image newImage;
    newImage.create(newColumns * spriteWidth, newRows * spriteHeight, sf::Color::Transparent); 

    for (int index = 0; index < totalSprites; ++index) {
        int srcRow = index / (originalImage.getSize().x / spriteWidth);
        int srcCol = index % (originalImage.getSize().x / spriteWidth);

        //int destRow = index / spritesPerRow;
        int destRow;
        if (srcRow < newRows / 2) {
            destRow = srcRow + newRows / 2; // décaler les premières lignes vers la seconde moitié
        }
        else {
            destRow = srcRow - newRows / 2; // décaler les dernières lignes vers la première moitié
        }
        int destCol = index % spritesPerRow;

        sf::IntRect srcRect(srcCol * spriteWidth, srcRow * spriteHeight, spriteWidth, spriteHeight);

        for (int y = 0; y < spriteHeight; ++y) {
            for (int x = 0; x < spriteWidth; ++x) {
                sf::Color pixelColor = originalImage.getPixel(srcRect.left + x, srcRect.top + y);
                newImage.setPixel(destCol * spriteWidth + x, destRow * spriteHeight + y, pixelColor);
            }
        }
    }

    if (!newImage.saveToFile(outputPath)) {
        std::cerr << "Erreur: impossible de sauvegarder l'image " << outputPath << std::endl;
    }
    else {
        std::cout << "Nouvelle fiche de sprite sauvegardée avec succès dans " << outputPath << std::endl;
    }
}