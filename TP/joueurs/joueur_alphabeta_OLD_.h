#pragma once


#include "joueur.h"


class Joueur_AlphaBeta_OLD_ : public Joueur
{
public:
	Joueur_AlphaBeta_OLD_(std::string nom, bool joueur);
	char nom_abbrege() const override;

	void recherche_coup(Jeu, int & coup, int tour) override;

	int alphabeta(Jeu jeu, bool E, int a, int b);

	int min(int, int);
	int max(int, int);
};
