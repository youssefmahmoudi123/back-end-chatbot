#pragma once

#include <string>
#include <vector>

#include "Models/Etudiant.h"
#include "FichierTexteService.h"

using namespace std;

class EtudiantService
{
private:
	vector<Etudiant> etudiants;

public:
	bool charger(const string& chemin)
	{
		etudiants.clear();
		for (const auto& record : FichierTexteService::lireEnregistrements(chemin))
		{
			auto get = [&](const string& key) -> string
			{
				auto it = record.find(key);
				return it == record.end() ? "" : it->second;
			};

			if (!get("ID").empty())
				etudiants.emplace_back(get("ID"), get("NOM"), get("PRENOM"),
					get("EMAIL"), get("NIVEAU"), get("SPECIALITE"));
		}
		return !etudiants.empty();
	}

	const vector<Etudiant>& getTous() const { return etudiants; }
};

