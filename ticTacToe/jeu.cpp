#include "jeu.h"

Jeu::Jeu(std::string etat) {
    _etat = etat;
    _nombre = 9;
}

void Jeu::reset() {
  _etat = "_________";
  _nombre = 9;
}

bool Jeu::coup_licite(int coup) {
  return !(_etat[coup] == 'x' || _etat[coup] == 'o');
}
  
void Jeu::joue(int coup, bool joueur) {
  if (joueur)
  {
    _etat[coup] = 'x';
  }
  else
  {
    _etat[coup] = 'o';
  }
  _nombre--;
}

int Jeu::nb_coups() {
  return _nombre;
}

int Jeu::winner() {
  if (_etat[0] == _etat[1] && _etat[0] == _etat[2] && _etat[0] != '_')          { switch(_etat[0]) { case('x') : return 1; case('o') : return 2;} }
  else if (_etat[3] == _etat[4] && _etat[3] == _etat[5] && _etat[3] != '_')     { switch(_etat[3]) { case('x') : return 1; case('o') : return 2;} }
  else if (_etat[6] == _etat[7] && _etat[6] == _etat[8] && _etat[6] != '_')     { switch(_etat[6]) { case('x') : return 1; case('o') : return 2;} }
  else if (_etat[0] == _etat[3] && _etat[0] == _etat[6] && _etat[0] != '_')     { switch(_etat[0]) { case('x') : return 1; case('o') : return 2;} }
  else if (_etat[1] == _etat[4] && _etat[1] == _etat[7] && _etat[1] != '_')     { switch(_etat[1]) { case('x') : return 1; case('o') : return 2;} }
  else if (_etat[2] == _etat[5] && _etat[2] == _etat[8] && _etat[2] != '_')     { switch(_etat[2]) { case('x') : return 1; case('o') : return 2;} }
  else if (_etat[0] == _etat[4] && _etat[0] == _etat[8] && _etat[0] != '_')     { switch(_etat[0]) { case('x') : return 1; case('o') : return 2;} }
  else if (_etat[2] == _etat[4] && _etat[2] == _etat[6] && _etat[2] != '_')     { switch(_etat[2]) { case('x') : return 1; case('o') : return 2;} }
  else if (_nombre == 0) return 0;

  return -1;
}

bool Jeu::fini()
{
  switch (winner())
  {
    case 0 :
      return true;
    case 2 :
      return true;
    case 1 :
      return true;
    default :
      return false;
  }
}

std::string Jeu::etat() {
  return _etat;
}

void Jeu::display() const
{
  for (int i(0); i<3; ++i)
  {
    for (int j(0); j<3; ++j)
    {
      if (_etat[j+3*i] != 2 && _etat[j+3*i] != 5 && _etat[j+3*i] != 8)
        std::cout << _etat[j+3*i] << "|";
      else
        std::cout << _etat[j+3*i];
    }
    std::cout << std::endl;
  }
}