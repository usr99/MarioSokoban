#include "mario.hpp"
#include "tilemap.hpp"

Mario::Mario() : sf::Sprite()
{
	this->_txMario.loadFromFile("./img/mario_bas.gif");
	this->setTexture(this->_txMario);
}

void Mario::deplace(sf::RenderWindow & window, int key, Tilemap & map)
{
	int i, j;
	this->getTileMario(i, j);

	switch(key)
	{
		case sf::Keyboard::Up:
			i--;
			break;

		case sf::Keyboard::Down:
			i++;
			break;

		case sf::Keyboard::Left:
			j--;
			break;

		case sf::Keyboard::Right:
			j++;
			break;
	}

	if(!map.isCollision(i, j))
	{
		this->setPosition(j*34, i*34);
		map.afficheMap(window, *this);
	}
}

void Mario::getTileMario(int & i, int & j)
{
	j = this->getPosition().x / 34;
	i = this->getPosition().y / 34;
}
