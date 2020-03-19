#ifndef MARIO_HPP
#define MARIO_HPP

#include <SFML/Graphics.hpp>

class Tilemap;

class Mario : public sf::Sprite
{
	public : 

		Mario();
		void deplace(sf::RenderWindow & window, int key, Tilemap & map);
		void getTileMario(int & i, int & j);

	private : 

		sf::Texture _txMario;
};

#endif
