#include "arbitre.h"

Arbitre::Arbitre(std::string etat, player player1, player player2, int nombre_parties)
  :
  _jeu(etat),
	_coups(nombre_parties, -1),
	_nombre_parties(nombre_parties),
	_numero_partie(1),
	_player1(player1),
	_player2(player2)
{}

void Arbitre::initialisation()
{
  	_joueur1=nullptr;
    _joueur2=nullptr;

    _jeu.reset();

    switch ((_numero_partie%2? _player1 : _player2)) {
    case player::A_:
      _joueur1 = std::make_shared<joueur_alphabeta> ("AlphaBeta",true);
        break;
    case player::Man_:
        _joueur1 = std::make_shared<joueur_humain> ("Humain",true);
        break;
    case player::Bad_:
        _joueur1 = std::make_shared<joueur_mauvais> ("Mauvais",true);
        break;
    default:
        break;
    }

    switch ((!(_numero_partie%2)? _player1 : _player2)) {
    case player::A_:
              _joueur2 = std::make_shared<joueur_alphabeta> ("AlphaBeta",false);
        break;
    case player::Man_:
        _joueur2 = std::make_shared<joueur_humain> ("Humain",false);
        break;
    case player::Bad_:
        _joueur2 = std::make_shared<joueur_mauvais> ("Mauvais",false);
        break;
    default:
        break;
    }

}

void Arbitre::challenge()
{
  initialisation(); // Au moins une fois pour que les objets de la ligne qui suit soient définis
    std::cout << "Le challenge de " << _nombre_parties << " parties "
              <<"entre " << _joueur1->nom() << " et " << _joueur2->nom()
             << " commence. " << std::endl;
    int victoire_joueur_1 = 0;
    int victoire_joueur_2 = 0;
    for(int i=0 ; i < _nombre_parties ; i++)
    {
        std::cout << "\n" << "Partie n°" << _numero_partie << " : \n";
        (partie()==1?
                    ((_numero_partie%2)?
                         victoire_joueur_1++
                       :
                         victoire_joueur_2++ )
                  :
                    (!(_numero_partie%2)?
                         victoire_joueur_1++
                       :
                         victoire_joueur_2++ ));
        std::this_thread::sleep_for (std::chrono::milliseconds(250)); // temps de latence entre deux parties
        _numero_partie++;
        initialisation();
    }
    std::cout << "FIN DU CHALLENGE\n\t"
              << _joueur1->nom()<< " gagne " << victoire_joueur_1
              << "\n\t"<< _joueur2->nom()<< " gagne " << victoire_joueur_2 << std::endl;
}

int Arbitre::partie()
{
	int tour = 0;
  _jeu.display();

	while(!_jeu.fini())
	{
		tour++;
		int coup = 0;

		do {
			if (tour%2)
			{
				_joueur1->recherche_coup(_jeu, coup, tour%2);
			}
			else
			{
				_joueur2->recherche_coup(_jeu, coup, tour%2);
			}

			if(!_jeu.coup_licite(coup))
      {
				std::cout << "Coup non licite! " << tour%2 << std::endl;
        return -1;
      }
		} while (!_jeu.coup_licite(coup));

    _jeu.joue(coup, tour%2);

		std::cout << "Tour " << tour << " : " << ((tour%2) ? _joueur1->nom_abbrege() : _joueur2->nom_abbrege()) << coup+1 << " " << std::endl;
    _jeu.display();

	}
	std::cout << "\n"<< ((tour%2)? _joueur1->nom() : _joueur2->nom() )  <<" gagne. Nombre de tours : " << tour << std::endl;
	return ((tour%2)? 1 : 2);
}