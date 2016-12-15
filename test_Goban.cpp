/*
 * test_Goban.cpp
 *
 *  Created on: 8 déc. 2016
 *      Author: user
 */


# include "gtest/gtest.h"
#include "Goban.h"
#include <iostream>
using namespace std ;

TEST(GobanClass,PoserPierre){
	Goban machin = Goban();
	machin.PoserPierre(2,2);
	machin.SetJoueur();
	EXPECT_EQ(true,machin.PoserPierre(2,3));
	EXPECT_EQ(false,machin.PoserPierre(2,2));
}
TEST (GobanClass, ListeGroupe)
{
	Goban machin = Goban();
	machin.PoserPierre(2,2);
	machin.PoserPierre(2,3);
	machin.PoserPierre(1,2);
	machin.PoserPierre(3,3);
	machin.SetJoueur();
	machin.PoserPierre(1,3);
	machin.Affichage();
	EXPECT_EQ(4,machin.ListeGroupe(2,2).size());
	EXPECT_EQ(4,machin.ListeGroupe(2,3).size());
	EXPECT_EQ(1,machin.ListeGroupe(1,3).size());
	EXPECT_EQ(20,machin.ListeGroupe(4,4).size());
}
TEST (GobanClass, LiberteGroupe)
{
	Goban machin = Goban();
	machin.PoserPierre(2,2);
	machin.PoserPierre(2,3);
	machin.PoserPierre(1,2);
	machin.PoserPierre(3,3);
	machin.SetJoueur();
	machin.PoserPierre(1,3);
	machin.Affichage();
	EXPECT_EQ(7,machin.LiberteGroupe(2,2));
	EXPECT_EQ(2,machin.LiberteGroupe(1,3));

}
/*
TEST(IntegerFunctionTest, negative) {
        EXPECT_EQ(1, factorial(-5));
        EXPECT_EQ(1, factorial(-1));
        EXPECT_GT(factorial(-10), 0);
}

TEST(IntegerFunctionTest, DISABLED_zero) {
         EXPECT_EQ(1, factorial(0));
}

TEST(IntegerFunctionTest, postive) {
         EXPECT_EQ(1, factorial(1));
         EXPECT_EQ(2, factorial(2));
         EXPECT_EQ(6, factorial(3));
         EXPECT_EQ(40320, factorial(8));
}
*/
