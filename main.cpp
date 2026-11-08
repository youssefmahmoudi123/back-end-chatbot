#include <iostream>

#include "crow.h"
#include "crow/middlewares/cors.h"

#include "API/ApiController.h"

using namespace std;

int main()
{
    ChatbotService chatbot("Data/connaissances.txt");
    if (chatbot.nombreConnaissances() == 0)
    {
        cerr << "ERREUR: aucune connaissance chargee." << endl;
        cerr << "Verifiez Data/connaissances.txt et le repertoire de travail." << endl;
        return 1;
    }

    crow::App<crow::CORSHandler> app;

    auto& cors = app.get_middleware<crow::CORSHandler>();

    cors.global()
        .origin("*")
        .methods(crow::HTTPMethod::Get, crow::HTTPMethod::Post,
            crow::HTTPMethod::Options)
        .headers("Content-Type");

    enregistrerRoutes(app, chatbot);

    cout << "ElecBrain: " << chatbot.nombreConnaissances()
         << " connaissances chargees." << endl;
    cout << "API disponible sur http://localhost:18080" << endl;

    app.port(18080).multithreaded().run();

    return 0;
}
