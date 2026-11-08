#pragma once

#include <string>

using namespace std;

class Faculte
{
private:
	string id;
	string nom;
	string universiteId;

public:
	Faculte() = default;
	Faculte(const string& id, const string& nom, const string& universiteId)
		: id(id), nom(nom), universiteId(universiteId) {}

	string getId() const { return id; }
	string getNom() const { return nom; }
	string getUniversiteId() const { return universiteId; }
};

