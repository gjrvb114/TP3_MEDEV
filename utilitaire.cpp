/*
 * utilitaire.cpp
 *
 *  Created on: 15 déc. 2016
 *      Author: user
 */

#include "utilitaire.h"
#include <vector>
#include <iostream>
using namespace std;

bool EstDansListe(int x, int y, vector<vector<int> > &Liste)
{
	bool Sortie = false ;

	for (int i = 0 ; i< Liste.size(); i++)
	{

		if (Liste[i][0] == x &&  Liste[i][1] == y)
		{

			Sortie = true;
		}
	}
	return Sortie;
}


