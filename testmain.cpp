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
using namespace std;
/*
GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
//PROUT
*/

int main()
{
	Goban machin = Goban();
		machin.PoserPierre(2,2);
		machin.PoserPierre(2,3);
		machin.PoserPierre(1,2);
		machin.PoserPierre(3,3);
		machin.SetJoueur();
		machin.PoserPierre(1,3);
		machin.Affichage();
		cout << endl;
		cout << "ta mère la caissière";
		cout << machin.ListeGroupe(2,2).size() ;
		cout << "ta mère la caissière" ;
	return 0;
}

