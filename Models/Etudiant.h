#pragma once

#include <string>

using namespace std;

class Etudiant
{
private:
	string id;
	string nom;
	string prenom;
	string email;
	string niveau;
	string specialite;

public:
	Etudiant() = default;
	Etudiant(const string& id, const string& nom, const string& prenom,
		const string& email, const string& niveau, const string& specialite)
		: id(id), nom(nom), prenom(prenom), email(email),
		  niveau(niveau), specialite(specialite) {}

	string getId() const { return id; }
	string getNom() const { return nom; }
	string getPrenom() const { return prenom; }
	string getEmail() const { return email; }
	string getNiveau() const { return niveau; }
	string getSpecialite() const { return specialite;     }
};

