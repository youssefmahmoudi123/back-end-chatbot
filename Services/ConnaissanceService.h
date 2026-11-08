#pragma once

#include <string>
#include <vector>

#include "Models/Connaissance.h"
#include "FichierTexteService.h"

using namespace std;

class ConnaissanceService
{
private:
	vector<Connaissance> connaissances;

public:
	bool charger(const string& chemin)
	{
		connaissances.clear();
		auto records = FichierTexteService::lireEnregistrements(chemin);

		for (const auto& record : records)
		{
			auto get = [&](const string& key) -> string
			{
				auto it = record.find(key);
				return it == record.end() ? "" : it->second;
			};

			vector<string> motsCles = separerMotsCles(get("MOTS_CLES"));
			if (!get("ID").empty() && !get("QUESTION").empty() && !get("REPONSE").empty())
			{
				connaissances.emplace_back(get("ID"), get("QUESTION"), motsCles,
					get("REPONSE"), get("CATEGORIE"));
			}
		}

		return !connaissances.empty();
	}

	const vector<Connaissance>& getToutes() const { return connaissances; }
	size_t nombre() const { return connaissances.size(); }
};

