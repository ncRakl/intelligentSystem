#pragma once


#include <thread>
// #include <experimental/random>
#include "joueur.h"


class Joueur_Brutal_ : public Joueur
{
private:

public:
  Joueur_Brutal_(std::string nom, bool joueur);

  char nom_abbrege() const override;
  
  void recherche_coup(Jeu, int & coup, int tour) override;

};
