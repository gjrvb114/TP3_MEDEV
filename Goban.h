/*
 * Goban.h
 *
 *  Created on: 8 déc. 2016
 *      Author: user
 */
#include <iostream>
using namespace std;

const int TAILLE = 5;
class Goban
	{
	private:
		fstream save;
		int** plateau;
		bool JoueurActif;
		bool Apasse;
	enum Case{VIDE =0,Noir = 1 ,BLANC = 2};
	public:
		Goban();
		bool PoserPierre(int x, int y);
		int LiberteGroupe(int x,int y);
		void Affichage();
		void Jouer();
		void EffacerGroupe(int x,int y);
		void Sauvegarder();
		bool CoupDejaJoue();
		void CompterPoints();
	};
