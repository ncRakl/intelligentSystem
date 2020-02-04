#include "joueur_humain.h"
#include <limits>

joueur_humain::joueur_humain(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}

char joueur_humain::nom_abbrege() const
{
    return 'H';
}

void joueur_humain::recherche_coup(Jeu jeu, int &coup, bool joueur)
{
	int choix;
	std::cout << "Choisissez une case où placer votre choix (1-9) : ";
	std::cin >> choix;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("clear");
	coup = choix-1;
}