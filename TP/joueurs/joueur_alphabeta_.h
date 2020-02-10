#pragma once


#include "joueur.h"


class Joueur_AlphaBeta_ : public Joueur
{
public:
	Joueur_AlphaBeta_(std::string nom, bool joueur);
	char nom_abbrege() const override;

	void recherche_coup(Jeu, int & coup, int tour) override;

	int alphabeta(Jeu jeu, bool E, int a, int b, int const& tour);

	void displayMainVar() const;

	int mainVar[50];
	int maxDepth, currentDepth, depth;
};
