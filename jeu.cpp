#include "jeu.hpp"

void sokoban(sf::RenderWindow & window, std::string sMap)
{
	Mario joueur;
	Tilemap map(sMap, joueur);

	while(window.isOpen())
	{
		sf::Event event;
		window.pollEvent(event);
		
		if(event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			joueur.deplace(window, event.key.code, map);
		}
	}
}
