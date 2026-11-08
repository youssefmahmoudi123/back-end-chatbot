#pragma once

#include <map>
#include <string>
#include <vector>

#include "FichierTexteService.h"

using namespace std;

class CatalogueService
{
public:
	vector<map<string, string>> charger(const string& chemin) const
	{
		return FichierTexteService::lireEnregistrements(chemin);
	}
};
