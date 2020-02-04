#pragma once

#include <mutex>
#include <iostream>
#include "../jeu.h"

/*****************************************************************************************************
 *      Toutes les classes implantant les divers joueurs doivent hériter de cette classe             *
 *      et donc contenir ces methodes                                                                *
 *****************************************************************************************************/

/**
 * @brief The Joueur class
 * classe mère des joueurs
 * chaque joueur doit implémenter la méthode jouer
 */
class Joueur
{
    std::string _nom;   //nom du joueur
    bool _joueur;       //joueur 1 : true , joueur 2 : false



public:

    Joueur(std::string nom, bool joueur);

    virtual void recherche_coup(Jeu, int & coup, bool joueur) =0;

    std::string nom() const;

    bool joueur() const;

    void setJoueur(bool joueur);

    virtual char nom_abbrege() const =0;

};
