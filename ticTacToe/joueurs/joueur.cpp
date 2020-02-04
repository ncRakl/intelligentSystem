#include "joueur.h"

Joueur::Joueur(std::string nom, bool joueur)
    :_nom(nom),_joueur(joueur)
{}

std::string Joueur::nom() const
{
    return _nom;
}

bool Joueur::joueur() const
{
    return _joueur;
}

void Joueur::setJoueur(bool joueur)
{
    _joueur = joueur;
}
