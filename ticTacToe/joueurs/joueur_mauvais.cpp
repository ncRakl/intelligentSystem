#include "joueur_mauvais.h"


joueur_mauvais::joueur_mauvais(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char joueur_mauvais::nom_abbrege() const
{
    return 'B';
}


void joueur_mauvais::recherche_coup(Jeu jeu, int &coup, bool joueur)
{
	int l = jeu.etat().length();
	for (int i(0); i<l; ++i)
	{
		if (jeu.etat()[i] == '_')
		{
			coup = i;
		}
	}
}

