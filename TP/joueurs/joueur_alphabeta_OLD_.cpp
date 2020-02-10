#include "joueur_alphabeta_OLD_.h"


Joueur_AlphaBeta_OLD_::Joueur_AlphaBeta_OLD_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char Joueur_AlphaBeta_OLD_::nom_abbrege() const
{
    return 'O';
}

int Joueur_AlphaBeta_OLD_::min(int a, int b)
{
	return (a <= b)? a : b;
}

int Joueur_AlphaBeta_OLD_::max(int a, int b)
{
	return (a <= b)? b : a;
}

int Joueur_AlphaBeta_OLD_::alphabeta(Jeu jeu, bool E, int a, int b)
{
	if(jeu.fini())
	{
		if(E) 	return -1;
		else	return 1;
	}

	int alpha = a;
	int beta = b;

	if(E)
	{
		int ret = -999;
		for (int i(0); i<jeu.nb_coups(); ++i)
		{
			Jeu g(jeu.etat());
			g.joue(i);

			ret = max(ret, alphabeta(g, false, alpha, beta));
			alpha = max(alpha, ret);
			if (alpha >= beta) break;
		}
		return ret;
		
	}
	else
	{
		int ret = 999;
		for (int i(0); i<jeu.nb_coups(); ++i)
		{
			Jeu g(jeu.etat());
			g.joue(i);

			ret = min(ret, alphabeta(g, true, alpha, beta));
			beta = min(beta, ret);
			if (alpha >= beta) break;
		}
		return ret;
	}
}

void Joueur_AlphaBeta_OLD_::recherche_coup(Jeu jeu, int &coup, int tour)
{
	int v = -999;
	for (int i(0); i<jeu.nb_coups(); ++i)
	{
		Jeu g(jeu.etat());
		if(!g.coup_licite(i)) { continue; }
		g.joue(i);

		int tmp = alphabeta(g, false, -999, 999);
		if (tmp > v) { v = tmp; coup = i;}
	}

}
