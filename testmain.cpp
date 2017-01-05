#include <iostream>
#include "Goban.h"
#include "utilitaire.h"
using namespace std;

int main()
{
    ifstream load("text.txt");
	Goban machin;
        machin.PoserPierre(2,2);
        machin.PoserPierre(2,3);
        machin.PoserPierre(1,2);
        machin.PoserPierre(3,3);
        machin.SetJoueur();
        machin.PoserPierre(1,3);
        machin.Affichage();
        machin.Sauvegarder(1);
        cout << endl;
        cout << "truc"<< endl;
        vector<vector<int> > ListeGroupe;


        //cout << machin.VerifierCase(2,3,Goban::BLANC, ListeGroupe);
        int truc =  machin.ListeGroupe(4,4).size();
        cout << "taille du groupe = " << truc<< endl;
	return 0;
}
