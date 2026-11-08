#pragma once

#include <string>
#include <vector>

#include "Models/Universite.h"
#include "FichierTexteService.h"

using namespace std;

class UniversiteService
{
private:
	vector<Universite> universites;

public:
	bool charger(const string& chemin)
	{
		universites.clear();
		for (const auto& record : FichierTexteService::lireEnregistrements(chemin))
		{
			auto get = [&](const string& key) -> string
			{
				auto it = record.find(key);
				return it == record.end() ? "" : it->second;
			};

			if (!get("ID").empty() && !get("NOM").empty())
				universites.emplace_back(get("ID"), get("NOM"), get("VILLE"),
					get("PAYS"), get("ADRESSE"));
		}
		return !universites.empty();
	}

	const vector<Universite>& getToutes() const { return universites; }
};

