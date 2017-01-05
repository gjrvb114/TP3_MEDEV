/*
 * testmain.cpp
 *
 *  Created on: 8 déc. 2016
 *      Author: user
 */



// gtest_main.cpp
#include <stdio.h>
#include "gtest/gtest.h"
#include <iostream>
#include "Goban.h"
#include "utilitaire.h"
using namespace std;

/*GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
//PROUT

*/
int main()
{
		Goban machin = Goban();
		bool victoire = false;
		while(victoire==false)
		{
			machin.Affichage();
			int x,y;
			bool coupvalide = false;
			while(!coupvalide){
			cout << "C'est aux blancs de jouer" << endl;
			cout << "x =";
			cin >> x;
			cout << endl << "y =";
			cin >> y;
			coupvalide = machin.PoserPierre(x,y);
			if(!coupvalide){
				cout << "coup non valide veuillez recommencer" << endl;
			}
			}
			machin.Affichage();
			coupvalide = false;
			machin.SetJoueur();
			while(!coupvalide){
			cout << "C'est aux noirs de jouer" << endl;
			cout << "x =";
			cin >> x;
			cout << endl << "y =";
			cin >> y;
			coupvalide = machin.PoserPierre(x,y);
			if(!coupvalide){
				cout << "coup non valide veuillez recommencer" << endl;
			}
			}

		}


/*
		machin.PoserPierre(2,2);
		machin.PoserPierre(2,3);
		machin.PoserPierre(1,2);
		machin.PoserPierre(3,3);
		machin.SetJoueur();
		machin.PoserPierre(1,3);
		machin.Affichage();
		cout << endl;
		cout << "truc"<< endl;
		vector<vector<int> > ListeGroupe;


		//cout << machin.VerifierCase(2,3,Goban::BLANC, ListeGroupe);
		int truc =  machin.ListeGroupe(4,4).size();
		cout << "taille du groupe = " << truc<< endl;
		*/
	return 0;
}

