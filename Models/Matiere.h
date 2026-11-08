#pragma once

#include <string>

using namespace std;

class Matiere
{
private:
	string id;
	string nom;
	string specialiteId;
	int coefficient = 1;

public:
	Matiere() = default;
	Matiere(const string& id, const string& nom, const string& specialiteId,
		int coefficient)
		: id(id), nom(nom), specialiteId(specialiteId), coefficient(coefficient) {}

	string getId() const { return id; }
	string getNom() const { return nom; }
	string getSpecialiteId() const { return specialiteId; }
	int getCoefficient() const { return coefficient; }
};

