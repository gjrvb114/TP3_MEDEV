#include "Goban.h"


using namespace std;

// Commentaire
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
	cout << endl;
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
	vector<int> couple;
	couple.push_back(x);
	couple.push_back(y);
	ListeGroupe.push_back(couple);
	tab.push_back(couple);
	GroupFinder(plateau[x][y],tab,ListeGroupe);
	return ListeGroupe;
}

void Goban::Sauvegarder(int coup)
{
	ofstream save("test_save.txt", ofstream::ate);
	
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
            save << plateau[i][j] << "\t";
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

// Renvoie true ssi la case existe dans le goban
bool Goban::EstDedans(int x, int y)
{
	return (x>=0 && y>=0 && x<TAILLE && y<TAILLE);
}

// Renvoie les 4 voisins d'une case
vector<pair<int,int>> Goban::Voisins(int x, int y)
{
	// On parcourt les voisins et vérifie qu'ils sont dans le plateau
	vector<pair<int,int>> v;
	for(int i=-1; i<2; i+=2)
	{
		if(EstDedans(x+i, y))
		{
			v.push_back(pair<int,int>(x+i, y));
		}
	}
	for(int j=-1; j<2; j+=2)
	{
		if(EstDedans(x, y+j))
		{
			v.push_back(pair<int,int>(x, y+j));
		}
	}
	return v;
}

//Retourne la couleur inverse
//si la couleur est VIDE, renvoie VIDE
int Goban::couleurInverse(const int& couleur)
{
	int inverse(VIDE);
	if(couleur==NOIR)
	{
		inverse = BLANC;
	}
	else if(couleur==BLANC)
	{
		inverse = NOIR;
	}
	return inverse;
}

// Efface les groupes voisins qui appartiennent à l'adversaire et qui sont capturés
void Goban::EffacerGroupe(int x,int y)
{
	// Voisin contient les voisins de la case en (x,y)
	vector<pair<int,int>> voisins(Voisins(x, y));
	// Groupe contiendra un groupe de pierres à supprimer
	vector<vector<int>> groupe;
	// On parcourt la liste des voisins
	for(vector<pair<int,int>>::iterator it=voisins.begin(); it!=voisins.end(); it++)
	{
		cout << it->first << " , " << it->second << endl;
		// Si le voisins n'est pas de la même couleur que la pierre en (x,y) et que son groupe n'est plus libre
		// Alors on le supprime
		if (plateau[it->first][it->second]==couleurInverse(plateau[x][y]) && LiberteGroupe(it->first, it->second)==0)
		{
			groupe = ListeGroupe(it->first, it->second);
			for(vector<vector<int>>::iterator itGroupe=groupe.begin(); itGroupe!=groupe.end(); itGroupe++)
			{
				plateau[(*itGroupe)[0]][(*itGroupe)[1]] = VIDE;
			}
		}
	}
}

bool Goban::CoupDejaJoue()
{
    
}

