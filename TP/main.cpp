
#include <iostream>
#include <mutex>

#include "arbitre.h"

int main()
{
    //initialise la graine du générateur aléatoire
    std::srand(std::time(nullptr));

    // création de l'Arbitre (graine , joueur 1, joueur 2 , nombre de parties)
    Arbitre a (3333, player::A_, player::RAND,100);
    // commence le challenge
    a.challenge();
    return 0;
}
