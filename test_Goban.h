#include "gtest/gtest.h"
#include "Goban.h"

using namespace std ;

TEST (GobanClass,PoserPierre){
	Goban machin;
	machin.PoserPierre(2,2);
	machin.SetJoueur();
	EXPECT_TRUE(machin.PoserPierre(2,3));
	EXPECT_FALSE(machin.PoserPierre(2,2));
}
TEST (GobanClass, ListeGroupe)
{
	Goban machin;
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
	Goban machin;
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
