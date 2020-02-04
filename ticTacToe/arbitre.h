#pragma once
#include <memory>
#include <iostream>
#include <chrono>
#include <thread>
#include <utility>
#include <functional>
#include <vector>
#include "jeu.h"
#include "joueurs/joueur.h"
#include "joueurs/joueur_alphabeta.h"
#include "joueurs/joueur_humain.h"
#include "joueurs/joueur_mauvais.h"

enum class player {A_, Man_, Bad_} ;

class Arbitre
{
private:
    std::shared_ptr<Joueur> _joueur1;
    std::shared_ptr<Joueur> _joueur2;

    Jeu _jeu;
    std::vector<int> _coups;

    int _nombre_parties;
    int _numero_partie;

    player _player1;
    player _player2;

public:
    /**
     * @brief Arbitre
     * @param graine du jeu mystère
     * @param player1
     * @param player2
     * @param nombre_parties
     */
    Arbitre(std::string etat, player player1 , player player2, int nombre_parties);


    void initialisation();
    /**
     * @brief challenge
     * @param nombre_parties
     * methode lançant un challenge avec un nombre de parties
     * affiche le nombre de parties gagnées pour chaque participant
     */
    void challenge();
    /**
     * @brief partie
     * @return le gagnant de la partie (joueur 1 : 1, joueur 2 : 0)
     * lance une partie,
     *
     */
    int partie();
};
