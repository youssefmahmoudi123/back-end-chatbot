#pragma once

#include <string>

using namespace std;

class Specialite
{
private:
	string id;
	string nom;
	string departementId;
	string description;

public:
	Specialite() = default;
	Specialite(const string& id, const string& nom, const string& departementId,
		const string& description)
		: id(id), nom(nom), departementId(departementId), description(description) {}

	string getId() const { return id; }
	string getNom() const { return nom; }
	string getDepartementId() const { return departementId; }
	string getDescription() const { return description; }
};

