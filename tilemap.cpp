#include "tilemap.hpp"
#include "mario.hpp"

Tilemap::Tilemap(std::string sMap, Mario & mario)
{
	// Chargement des textures du niveau
	this->_txMap['#'].loadFromFile("./img/mur.jpg");
	this->_txMap['X'].loadFromFile("./img/caisse.jpg");
	this->_txMap['O'].loadFromFile("./img/objectif.jpg");
	this->_txMap['Y'].loadFromFile("./img/caisse_ok.jpg");

	// Ajoute 12 lignes vides à la matrice (ligne = std::vector<sf::Sprite>)
	// Indispensable à la création des 12 colonnes (colonne = sf::Sprite)
	for (int i = 0 ; i < 12 ; i++)
	{
		this->_sprMap.emplace_back();
	}
	
	// Ouvre le fichier correspondant au niveau
	std::ifstream fichier("./levels/" + sMap + ".txt");	

	// Fichier ouvert
	if(fichier)
	{
		char carac = 0;
		int i = 0, j = 0;
		
		// Parcourt les lignes de la matrice du niveau
		while(i < 12)
		{
			fichier.get(carac);	// Récupère un élément du niveau dans le fichier
			
			// Si le caractère lu représente Mario
			if(carac == '8')
			{
				mario.setPosition(j*34, i*34); // Place Mario
			}

			// Si le caractère lu n'est pas un retour à la ligne
			// Evite l'ajout d'une sprite à la matrice ne correspondant à aucun élément du niveau
			if(carac != '\n')
			{
				sf::Sprite spr(this->_txMap[carac]);	// Crée la sprite avec la texture associé à l'élément
				spr.setPosition(j*34, i*34);			// Positionne la sprite (dimensions de 34*34)
	
				this->_sprMap[i].push_back(spr);		// Ajoute la sprite à la matrice

				j++; // Passe à la colonne suivante de la matrice

				// Si les 12 colonnes ont été créées
				// Passe à la ligne suivante
				if(j > 11)
				{
					j = 0;
					i++;
				}
			}
		}
	}
	// Echec de l'ouverture   
	else {std::cerr << "Impossible de charger les données du niveau" << std::endl;}
}

void Tilemap::afficheMap(sf::RenderWindow & window, Mario & mario)
{
	int xMario, yMario;
	mario.getTileMario(yMario, xMario);

	// Crée un fond gris clair
	sf::Color clr(180, 180, 180);
	window.clear(clr);

	// Parcourt la matrice du niveau
	for(int i = 0 ; i < 12 ; i++)
	{
		for(int j = 0 ; j < 12 ; j++)
		{
			// Si la case est celle de Mario
			if(j == xMario && i == yMario)
			{
				window.draw(mario); // Dessine Mario
			}
			else
			{
				window.draw(this->_sprMap[i][j]); // Dessine la sprite de la tilemap dans la fenêtre
			}
		}
	}

	window.display(); // Actualise l'affichage de la fenêtre
}

bool Tilemap::isCollision(int i, int j)
{
	if(this->_sprMap[i][j].getTexture() == &(this->_txMap.at('#')))
	{
		return true;
	}
	else
	{
		return false;
	}
}
