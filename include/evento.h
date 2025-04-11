//
// Created by Usuario on 07/04/2025.
//

#ifndef EVENTO_H
#define EVENTO_H
#include <queue.hpp>
#include <string>
#include <utility>

struct Evento
{
    enum class Tipo {
        EXPLORACION,
        COMBATE,
        DESCANSO,
        OTRO,
    };

    Tipo m_tipo;
    std::string m_descripcion;

    Evento(Tipo tipo, std::string descripcion): m_tipo(tipo), m_descripcion(std::move(descripcion)){}
};

#endif //EVENTO_H
