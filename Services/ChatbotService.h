#pragma once

#include <string>

#include "Models/Connaissance.h"
#include "Utils/TexteUtils.h"
#include "ConnaissanceService.h"

using namespace std;

struct ResultatChatbot
{
	string reply;
	string id;
	string categorie;
	bool trouve = false;
};

class ChatbotService
{
private:
	ConnaissanceService connaissanceService;
	string messageParDefaut =
		"Desole, je n'ai pas trouve de reponse a cette question dans ma base de connaissances. Essayez de reformuler.";

public:
	explicit ChatbotService(const string& chemin) { connaissanceService.charger(chemin); }
	size_t nombreConnaissances() const { return connaissanceService.nombre(); }

	ResultatChatbot repondre(const string& questionUtilisateur) const
	{
		string question = normaliserTexte(trim(questionUtilisateur));
		if (question.empty())
			return { "Veuillez saisir une question.", "", "", false };

		const Connaissance* meilleure = nullptr;
		int meilleurScore = 0;
		for (const auto& connaissance : connaissanceService.getToutes())
		{
			int score = 0;
			string questionFAQ = normaliserTexte(connaissance.getQuestion());
			if (question == questionFAQ)
				score += 100;
			if (!questionFAQ.empty() && question.find(questionFAQ) != string::npos)
				score += 50;

			for (const string& motCleBrut : connaissance.getMotsCles())
			{
				string motCle = normaliserTexte(trim(motCleBrut));
				if (!motCle.empty() && question.find(motCle) != string::npos)
					score += 10 + static_cast<int>(motCle.length());
			}

			if (score > meilleurScore)
			{
				meilleurScore = score;
				meilleure = &connaissance;
			}
		}

		if (meilleure != nullptr && meilleurScore >= 10)
			return { meilleure->getReponse(), meilleure->getId(), meilleure->getCategorie(), true };

		return { messageParDefaut, "", "", false };
	}
};

