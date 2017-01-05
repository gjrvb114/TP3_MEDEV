/*
 * Goban.cpp
 *
 *  Created on: 15 déc. 2016
 *      Author: user
 */

#include "Goban.h"
#include <iostream>
#include <vector>
#include "utilitaire.h"
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
    save.open("text.txt");

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



bool Goban::VerifierCase(int x, int y, int couleur, vector<vector<int> > &ListeGroupe)
{
	bool un  = (x < TAILLE && y< TAILLE);
	bool deux = (y >=0 && x >= 0 );
	bool trois = (plateau[x][y] == couleur);
	bool quatre (!EstDansListe(x,y,ListeGroupe));
	return  (un && deux && trois && quatre) ; // zéro !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

}

void Goban::GroupFinder(int couleur, vector<vector<int> > &tab, vector<vector<int> > &ListeGroupe)
{
	vector<vector<int> > Nouveau ;
		for (unsigned int i=0 ;i<tab.size();i++)
		{
			int x = tab[i][0];
			int y = tab[i][1];
			if (VerifierCase(x+1,y,couleur,ListeGroupe))
			{
				vector<int> couple;
				couple.push_back(x+1);
				couple.push_back( y);
				Nouveau.push_back(couple);
				ListeGroupe.push_back(couple);
			}

			if (VerifierCase(x-1,y,couleur,ListeGroupe))
					{
						vector<int> couple ;
						couple.push_back( x-1);
						couple.push_back( y);
						Nouveau.push_back(couple);
						ListeGroupe.push_back(couple);
					}
			if (VerifierCase(x,y+1,couleur,ListeGroupe))
					{
										vector<int> couple ;
										couple.push_back( x);
										couple.push_back( y+1);
						Nouveau.push_back(couple);
						ListeGroupe.push_back(couple);
					}
			if (VerifierCase(x,y-1,couleur,ListeGroupe))
					{
										vector<int> couple ;
										couple.push_back( x);
										couple.push_back( y-1);
						Nouveau.push_back(couple);
						ListeGroupe.push_back(couple);
					}


		}
		if (Nouveau.size() != 0)
		{
		GroupFinder(couleur,Nouveau,ListeGroupe);
		}

}

vector<vector<int> > Goban::ListeGroupe(int x,int y)
{
	vector<vector<int> > ListeGroupe;
	vector<vector<int> > tab;
	vector<int> couple ;
	couple.push_back( x);
	couple.push_back( y);
	ListeGroupe.push_back(couple);
	tab.push_back(couple);
	GroupFinder(plateau[x][y],tab,ListeGroupe);
	return ListeGroupe;



}

void Goban::Sauvegarder(int coup)
{
    // Sauvegarde le numéro du coup
    save << "Coup " << coup << endl;
    save << "Joueur ";
    
    // Sauvegarde le joueur qui a joué
    if(Joueur1Actif)
    {
        save << 1;
    }
    else
    {
        save << 2;
    }
    save << endl;
    
    // Sauvegarde le plateau
    for(int i=0; i<TAILLE; i++)
    {
        for(int j=0; j<TAILLE; j++)
        {
            save << plateau[i][j];
        }
        save << endl;
    }
    save << endl;
    
}
    
int Goban::LiberteGroupe(int a, int b)
{
	vector<vector<int> > ListGroupe = ListeGroupe(a,b);
	vector<vector<int> > ListeCaseVide;
	for (int i = 0 ; i< ListGroupe.size() ; i++)
	{
		int x = ListGroupe[i][0];
		int y = ListGroupe[i][1];
		if (VerifierCase(x+1,y,VIDE,ListeCaseVide))
					{
						vector<int> couple;
						couple.push_back(x+1);
						couple.push_back( y);
						ListeCaseVide.push_back(couple);
					}

					if (VerifierCase(x-1,y,VIDE,ListeCaseVide))
							{
								vector<int> couple ;
								couple.push_back( x-1);
								couple.push_back( y);
								ListeCaseVide.push_back(couple);
							}
					if (VerifierCase(x,y+1,VIDE,ListeCaseVide))
							{
												vector<int> couple ;
												couple.push_back( x);
												couple.push_back(y+1);
								ListeCaseVide.push_back(couple);
							}
					if (VerifierCase(x,y-1,VIDE,ListeCaseVide))
							{
												vector<int> couple ;
												couple.push_back( x);
												couple.push_back(y-1);
								ListeCaseVide.push_back(couple);
							}
	}
	return ListeCaseVide.size();
}

bool CoupDejaJoue()
{
    
}
