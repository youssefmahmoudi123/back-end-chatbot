#pragma once

#include "crow.h"
#include "crow/middlewares/cors.h"

#include "Services/ChatbotService.h"

using namespace std;

inline void enregistrerRoutes(crow::App<crow::CORSHandler>& app,
	ChatbotService& chatbot)
{
	CROW_ROUTE(app, "/")
	([]()
	{
		crow::json::wvalue response;
		response["message"] = "Bienvenue dans l'API ElecBrain";
		response["status"] = "running";
		auto result = crow::response(response);
		result.set_header("Content-Type", "application/json; charset=utf-8");
		return result;
	});

	CROW_ROUTE(app, "/api/health")
	([&chatbot]()
	{
		crow::json::wvalue response;
		response["status"] = "ok";
		response["service"] = "ElecBrain";
		response["knowledge_count"] = static_cast<int>(chatbot.nombreConnaissances());
		auto result = crow::response(response);
		result.set_header("Content-Type", "application/json; charset=utf-8");
		return result;
	});

	CROW_ROUTE(app, "/api/chat")
	.methods(crow::HTTPMethod::Post)
	([&chatbot](const crow::request& request)
	{
		auto data = crow::json::load(request.body);
		if (!data || !data.has("message") || data["message"].t() != crow::json::type::String)
		{
			crow::json::wvalue error;
			error["error"] = "Le champ message est obligatoire et doit etre une chaine.";
			auto result = crow::response(400, error);
			result.set_header("Content-Type", "application/json; charset=utf-8");
			return result;
		}

		ResultatChatbot resultat = chatbot.repondre(data["message"].s());
		crow::json::wvalue response;
		response["reply"] = resultat.reply;
		response["matched"] = resultat.trouve;
		response["id"] = resultat.id;
		response["category"] = resultat.categorie;
		auto result = crow::response(response);
		result.set_header("Content-Type", "application/json; charset=utf-8");
		return result;
	});
}

