#ifndef TILEMAP_HPP
#define TILEMAP_HP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

class Tilemap
{
	public:

		Tilemap(int nMap);
		void afficheMap(sf::RenderWindow & window);

	private:

		std::vector<std::vector<sf::Sprite>> 	_sprMap; 
		std::map<char, sf::Texture> 			_txMap;
};

#endif
