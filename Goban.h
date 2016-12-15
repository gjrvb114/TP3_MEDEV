/*
 * Goban.h


 *
 *  Created on: 8 déc. 2016
 *      Author: user
 */

#pragma once
#include <iostream>
using namespace std;

const int TAILLE = 5;
class Goban
	{
	private:
		//fstream save;
		int plateau[TAILLE][TAILLE];
		bool Joueur1Actif;
		bool Apasse;
	enum Case{VIDE =0,NOIR = 1 ,BLANC = 2};
	public:
		Goban();
		void SetJoueur();
		bool PoserPierre(int x, int y); // x = i et y = j dans le tableau
		int LiberteGroupe(int x,int y);
		void Affichage();
		void Jouer();
		void EffacerGroupe(int x,int y);
		void Sauvegarder();
		bool CoupDejaJoue();
		void CompterPoints();
	};
