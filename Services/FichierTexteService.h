#pragma once

#include <fstream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

#include "Utils/TexteUtils.h"

using namespace std;

class FichierTexteService
{
public:
	static vector<map<string, string>> lireEnregistrements(const string& chemin)
	{
		ifstream fichier(chemin);
		if (!fichier.is_open())
			return {};

		string contenu((istreambuf_iterator<char>(fichier)), istreambuf_iterator<char>());
		return analyserBlocs(contenu);
	}
};
