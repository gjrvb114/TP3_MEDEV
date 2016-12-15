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

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


/*
int main()
{
	Goban machin = Goban();
	machin.Affichage();
	cout << endl ;
	machin.PoserPierre(2,2);
	machin.SetJoueur();
	machin.PoserPierre(3,3);
	machin.Affichage();
	return 0;
}
*/
