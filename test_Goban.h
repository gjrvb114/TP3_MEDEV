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

TEST (GobanClass, Sauvegarder)
{
	Goban bonneJournee;
	bonneJournee.PoserPierre(2,2);
	bonneJournee.PoserPierre(2,3);
	bonneJournee.SetJoueur();
	bonneJournee.PoserPierre(1,2);
	bonneJournee.PoserPierre(3,3);
	bonneJournee.Sauvegarder(4);
	ifstream save("test_save.txt");
	string str_courant;
	int int_courant;
	save >> str_courant >> int_courant;
	EXPECT_EQ(4,int_courant);
	save >> str_courant >> int_courant;
	EXPECT_EQ(2,int_courant);
	
	for(int i=0; i<TAILLE; i++)
	{
		for(int j=0; j<TAILLE; j++)
		{
			EXPECT_FALSE(save.eof());
			save >> int_courant;
			if(i==2 && (j==2 || j==3))
			{
				EXPECT_EQ(int_courant, BLANC);
			}
			else if(i==1 && j==2 || i==3 && j==3)
			{
				EXPECT_EQ(int_courant, NOIR);
			}
			else
			{
				EXPECT_EQ(int_courant, VIDE);
			}
		}
	}
	save.close();
	remove("test_save.txt");
}


















