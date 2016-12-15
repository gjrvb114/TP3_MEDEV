/*
 * Goban.cpp
 *
 *  Created on: 15 déc. 2016
 *      Author: user
 */

#include "Goban.h"
#include <iostream>
using namespace std;

void Goban::Affichage(){
	for (int i = 0;i<TAILLE;i++)
	{
		for (int j=0 ; j<TAILLE;j++)
		{
			if (plateau[i][j] == VIDE)
			{
			cout << "- " ;
			}
			else if(plateau[i][j] == NOIR)
			{
				cout << "N ";

			}
			else if(plateau[i][j] == BLANC)
			{
				cout << "B ";
			}
		}
		cout <<endl;
	}
}

Goban::Goban()
{

	for (int i = 0;i<TAILLE;i++)
		{
			for (int j=0 ; j<TAILLE;j++)
			{
				plateau[i][j] = VIDE ;
			}

		}

	Joueur1Actif = true;
	Apasse = false ;
}

bool Goban::PoserPierre(int x, int y)
{
	if(plateau[x][y] == VIDE)
	{
		if(Joueur1Actif)
		{
		plateau[x][y] = BLANC;
		}
		else
		{
			plateau[x][y] = NOIR;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void Goban::SetJoueur()
{
	Joueur1Actif = !Joueur1Actif;
}

