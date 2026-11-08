#pragma once

#include <string>
#include <vector>

using namespace std;

class Connaissance
{
private:
	string id;
	string question;
	vector<string> motsCles;
	string reponse;
	string categorie;

public:
	Connaissance() = default;

	Connaissance(
		const string& id, const string& question,
		const vector<string>& motsCles, const string& reponse,
		const string& categorie)
		: id(id), question(question), motsCles(motsCles),
		  reponse(reponse), categorie(categorie)
	{
	}

	string getId() const { return id; }
	string getQuestion() const { return question; }
	vector<string> getMotsCles() const { return motsCles; }
	string getReponse() const { return reponse; }
	string getCategorie() const { return categorie; }
};
