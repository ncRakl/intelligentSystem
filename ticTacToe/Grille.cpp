#include "Grille.h"

#include <iostream>

Grille::Grille()
{
	for (int i(0); i<3; ++i)
	{
		for (int j(0); j<3; ++j)
		{
			grille[i][j] = '_';
		}
	}
}

void Grille::display() const
{
	for (int i(0); i<3; ++i)
	{
		for (int j(0); j<3; ++j)
		{
			if (grille[i][j] == '_' && i == 2)
				std::cout << " ";
			else
				std::cout << grille[i][j];
			if (j != 2)
				std::cout << "|";
			else
				std::cout << std::endl;
		}
	}
	std::cout << std::endl;

}

void Grille::start()
{
	int cpt(0), line, column;
	do {
		system("cls");
		++cpt;
		display();
		std::cout << "Tour du Joueur " << numeroJoueur << " : " << std::endl;
		do {
			std::cout << "Choisissez la ligne de la case : ";
			std::cin >> line;
			std::cout << "Choisissez la colonne de la case : ";
			std::cin >> column;
		} while (!isValidCoord(grille, line, column));

		if (joueur == 1)
			grille[line-1][column-1] = 'x';
		else
			grille[line-1][column-1] = 'o';

		joueur = joueur % 2 + 1;
	} while (!isWon() && cpt != 9);
}