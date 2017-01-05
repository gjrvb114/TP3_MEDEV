#include <stdio.h>
#include <iostream>

#include "Goban.h"
#include "utilitaire.h"

using namespace std;

int main()
{
	Goban machin;
	machin.PoserPierre(0,3);
	machin.PoserPierre(1,4);
	machin.PoserPierre(2,2);
	machin.PoserPierre(2,4);
	machin.PoserPierre(3,3);
	machin.SetJoueur();
	machin.PoserPierre(1,3);
	machin.PoserPierre(2,3);
	machin.Affichage();
	
	machin.SetJoueur();
	machin.PoserPierre(1,2);
	machin.Affichage();
	machin.EffacerGroupe(1,2);
	
	machin.Affichage();
	
	vector<vector<int> > ListeGroupe;

	//cout << machin.VerifierCase(2,3,Goban::BLANC, ListeGroupe);
	int truc =  machin.ListeGroupe(4,4).size();
	cout << "taille du groupe = " << truc<< endl;
	
	machin.Sauvegarder(1);
	return 0;
}
