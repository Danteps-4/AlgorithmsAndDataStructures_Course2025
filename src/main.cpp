#include <iostream>
#include <sstream>
#include <thread>

#include "engine.hpp"
#include "wrapperVector.hpp"
#include "refugio.hpp"
#include "personaje.h"
#include "enemigo.h"

int main()
{

   Refugio refugio("Refugio 33", 100, 200);
    Refugio::Faccion faccion = Refugio::Faccion::Humanos;
    Refugio::Faccion faccion2 = Refugio::Faccion::Mutantes;
    std::cout << refugio.isSafeFaction(faccion) << std::endl;
    refugio.registerVisitant("Dante", faccion);
    refugio.registerVisitant("Jorge", faccion2);
    refugio.showVisits();

    std::cout << "Bienvenida/o sistema de control 'Refugio 33'" << std::endl;
    // Crea un nuevo jugador
    PlayerInfo player;
    std::cout << "Ingrese tu nombre: ";
    std::string playerName;
    std::getline(std::cin, playerName);
    std::cout << "Ingrese tu nivel: ";
    std::string level;
    std::getline(std::cin, level);

    player.level = level;
    player.name = playerName;

    auto engine = std::make_unique<Engine>();

    std::cout << "Cargando";

    for (int i = 0; i <= 100; i += 10)
    {
        std::cout << "[" << i << "%]" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (i < 100)
        {
            std::cout << "\b\b\b\b\b" << std::flush;
        }
    }

    std::cout << std::endl;
    std::cout << "Sistema de control 'Refugio 33' iniciado correctamente" << std::endl;
    engine->start(player);


    return 0;
}
