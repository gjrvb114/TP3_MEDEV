#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "utilitaire.h"
#include <utility>

using namespace std;

const int TAILLE = 5;
enum Case{VIDE =0,NOIR = 1 ,BLANC = 2};

class Goban
{
private:
	int plateau[TAILLE][TAILLE];
	bool Joueur1Actif;
	bool Apasse;

public:
	Goban();
	void SetJoueur();
	bool PoserPierre(int x, int y); // x = i et y = j dans le tableau
	vector<vector<int> > ListeGroupe(int x,int y);
	int LiberteGroupe(int x, int y);
	bool VerifierCase(int x, int y, int couleur, vector<vector<int> > &ListeGroupe);
	void GroupFinder(int couleur, vector<vector<int> > &tab, vector<vector<int> > &ListeGroupe);
	void Affichage();
	void Jouer();
	// Efface les groupes voisins qui appartiennent à l'adversaire et qui sont capturés
	void EffacerGroupe(int x,int y);
	void Sauvegarder(int coup);
	bool CoupDejaJoue();
	void CompterPoints();
};

// Retourne la couleur inverse
// si la couleur est VIDE, renvoie VIDE
int couleurInverse(const int& couleur);

// Renvoie true ssi la case existe dans le goban
bool estDedans(int x, int y);

// Renvoie les au plus 4 cases voisines d'une case
vector<pair<int,int> > Voisins(int x, int y);
