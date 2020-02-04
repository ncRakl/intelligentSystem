#pragma once


#include "joueur.h"


class joueur_alphabeta : public Joueur
{
public:
  joueur_alphabeta(std::string nom, bool joueur);
  char nom_abbrege() const override;

  void recherche_coup(Jeu, int & coup, bool joueur) override;
};
