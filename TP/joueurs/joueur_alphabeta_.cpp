#include "joueur_alphabeta_.h"


Joueur_AlphaBeta_::Joueur_AlphaBeta_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{
	currentDepth = 0;
	maxDepth = 50;
	for (int i(0); i<maxDepth; ++i)
	{
		mainVar[maxDepth] = 0;
	}
}



char Joueur_AlphaBeta_::nom_abbrege() const
{
    return 'A';
}

int min(int a, int b)
{
	return (a <= b)? a : b;
}

int max(int a, int b)
{
	return (a <= b)? b : a;
}

int Joueur_AlphaBeta_::alphabeta(Jeu jeu, bool E, int a, int b, int const &tour)
{
	if(jeu.fini())
	{
		depth = currentDepth;
		if(E) 	return -1;
		else	return 1;
	}

	int alpha = a;
	int beta = b;

	if(E)
	{
		int ret = -999;
		int tmp = currentDepth;
		for (int i(jeu.nb_coups()-1); i>=0; --i)
		{
			if (tour != 0 && mainVar[depth-1] == i) return 10;
			Jeu g(jeu.etat());
			g.joue(i);

			currentDepth++;
			ret = max(ret, alphabeta(g, false, alpha, beta, tour));
			currentDepth = tmp;
			alpha = max(alpha, ret);
			if (alpha >= beta) 
			{
				mainVar[currentDepth] = i;
				break;
			}
		}
		return ret;
		
	}
	else
	{
		int ret = 999;
		for (int i(jeu.nb_coups()-1); i>=0; --i)
		{
			Jeu g(jeu.etat());
			g.joue(i);

			ret = min(ret, alphabeta(g, true, alpha, beta, tour));
			beta = min(beta, ret);
			if (alpha >= beta) break;
		}
		return ret;
	}
}

void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup, int tour)
{
	int v = -999;
	int tmp = currentDepth;
	for (int i(jeu.nb_coups()-1); i>=0; --i)
	{
		Jeu g(jeu.etat());
		if(!g.coup_licite(i)) { continue; }
		g.joue(i);

		mainVar[currentDepth] = i;
		currentDepth++;

		int tmp = alphabeta(g, false, -999, 999, tour);
		if (tmp > v) { v = tmp; coup = i;}

		currentDepth = tmp;
	}

	//displayMainVar();
}

void Joueur_AlphaBeta_::displayMainVar() const
{
	std::cout << "\n\n";
	for (int i(0); i<depth; ++i)
	{
		std::cout << i << ": " << mainVar[i] << "\n";
	}
	std::cout << "\n";
}