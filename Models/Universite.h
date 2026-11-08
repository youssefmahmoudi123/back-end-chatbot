#pragma once

#include <string>

using namespace std;

class Universite
{
private:
	string id;
	string nom;
	string ville;
	string pays;
	string adresse;

public:
	Universite() = default;
	Universite(const string& id, const string& nom, const string& ville,
		const string& pays, const string& adresse)
		: id(id), nom(nom), ville(ville), pays(pays), adresse(adresse) {}

	string getId() const { return id; }
	string getNom() const { return nom; }
	string getVille() const { return ville; }
	string getPays() const { return pays; }
	string getAdresse() const { return adresse; }
};

