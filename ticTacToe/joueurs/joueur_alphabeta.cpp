#include "joueur_alphabeta.h"


joueur_alphabeta::joueur_alphabeta(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char joueur_alphabeta::nom_abbrege() const
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

int alphabeta(Jeu jeu, bool E, int a, int b)
{
	if(jeu.fini())
	{
		if(jeu.winner() == 0)
			return 0;
		else if (E)
			return -10;
		else
			return 10;
	}

	int alpha = a;
	int beta = b;

	if(E)
	{
		int ret = -999;
		for (int i(0); i<9; ++i)
		{
			Jeu g(jeu.etat());
			if(!g.coup_licite(i)) { continue; }
			g.joue(i, E);

			ret = max(ret, alphabeta(g, false, alpha, beta));
			alpha = max(alpha, ret);
			if (alpha >= beta) break;
		}
		return alpha;
	}
	else
	{
		int ret = 999;
		for (int i(0); i<9; ++i)
		{
			Jeu g(jeu.etat());
			if(!g.coup_licite(i)) { continue; }
			g.joue(i, E);

			ret = min(ret, alphabeta(g, true, alpha, beta));
			beta = min(beta, ret);
			if (alpha >= beta) break;
		}
		return beta;
	}
}

void bestMove(Jeu jeu)
{
	int b = -999;
	for (int i(0); i<9; ++i)
	{
		if (jeu.coup_licite(i))
		{
			
		}
	}
}

void joueur_alphabeta::recherche_coup(Jeu jeu, int &coup, bool joueur)
{
	int v = -999;
	for (int i(0); i<9; ++i)
	{
		Jeu g(jeu.etat());
		if(!g.coup_licite(i)) { continue; }
		g.joue(i, joueur);
		int tmp = alphabeta(g, false, -999, 999);
		if (tmp > v) { v = tmp; coup = i;}
	}
}

