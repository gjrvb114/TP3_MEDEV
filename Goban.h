/*
 * Goban.h


 *
 *  Created on: 8 déc. 2016
 *      Author: user
 */

#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int TAILLE = 5;
class Goban
	{
	private:
                ofstream save;
		int plateau[TAILLE][TAILLE];
		bool Joueur1Actif;
		bool Apasse;

	public:
		enum Case{VIDE =0,NOIR = 1 ,BLANC = 2};
		Goban();
		void SetJoueur();
		bool PoserPierre(int x, int y); // x = i et y = j dans le tableau
		vector<vector<int> > ListeGroupe(int x,int y);
		bool VerifierCase(int x, int y, int couleur, vector<vector<int> > &ListeGroupe);
		void GroupFinder(int couleur, vector<vector<int> > &tab, vector<vector<int> > &ListeGroupe);
		void Affichage();
		void Jouer();
		void EffacerGroupe(int x,int y);
		void Sauvegarder(int coup);
		bool CoupDejaJoue();
		void CompterPoints();
	};

bool EstDansListe(int x,int y, vector<vector<int> > &Liste);
