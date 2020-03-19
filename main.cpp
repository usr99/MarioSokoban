#include "jeu.hpp"

int main()
{
	// Création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(408, 408), "Mario Sokoban !");
	
	// Affichage de l'écran de menu
	sf::Texture tx_fond;
	tx_fond.loadFromFile("./img/menu.jpg");
	sf::Sprite spr_fond(tx_fond);

	// Maintient le programme en fonctionnement
	while(window.isOpen())
	{
		// Détecte les évènements (non-bloquant)
		sf::Event event;
		window.pollEvent(event);

		switch(event.type)
		{
			case sf::Event::Closed: // Clic sur la croix rouge
				window.close();
				break;

			case sf::Event::KeyPressed: // Touche du clavier enfoncée
				if(event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1) // Touche "1"
				{
					sokoban(window, "1"); // Lance le jeu
				}
				else if(event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2) // Touche "2"
				{
					// EDITEUR
				}
				break;
		}

		// Actualise la fenêtre et ses éléments
		window.clear();
		window.draw(spr_fond);
		window.display();
	}

	return 0;
}
