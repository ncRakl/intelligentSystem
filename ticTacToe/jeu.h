#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Jeu {
 private :
  std::string _etat;
  int _nombre;

 public :
  Jeu(std::string);
  void reset(); // Remet à la graine le jeu
  bool coup_licite(int); // Vérifie si le coup est licite
  void joue(int, bool); // Joue le coup (sans vérifier qu'il est licite)
  int nb_coups(); // Le nombre de coups possibles
  int winner(); // Vérifie si un état final a été atteint (dans ce cas le jeu prend fin)
  bool fini();

  std::string etat();

  void display() const;
};
