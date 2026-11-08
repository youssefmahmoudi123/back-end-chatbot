#pragma once

#include <string>

using namespace std;

class Departement
{
private:
	string id;
	string nom;
	string faculteId;

public:
	Departement() = default;
	Departement(const string& id, const string& nom, const string& faculteId)
		: id(id), nom(nom), faculteId(faculteId) {}

	string getId() const { return id; }
	string getNom() const { return nom; }
	string getFaculteId() const { return faculteId; }
};

