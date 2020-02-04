#pragma once


#include "joueur.h"


class joueur_humain : public Joueur
{
public:
  joueur_humain(std::string nom, bool joueur);
  char nom_abbrege() const override;

  void recherche_coup(Jeu, int & coup, bool joueur) override;
};
