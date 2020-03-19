#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

class Mario;

class Tilemap
{
	public:

		Tilemap(std::string sMap, Mario & mario);
		void afficheMap(sf::RenderWindow & window, Mario & mario);
		bool isCollision(int i, int j);

	private:

		std::vector<std::vector<sf::Sprite>> 	_sprMap; 
		std::map<char, sf::Texture> 			_txMap;
};

#endif
