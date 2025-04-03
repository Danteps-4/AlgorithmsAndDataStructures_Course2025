#ifndef SAQUEADOR_HPP
#define SAQUEADOR_HPP

#include "entidadGenerica.hpp"
#include <iostream>
#include <random>

/**
 * @class Saqueador
 * @brief Representa un grupo de saqueadores en el mundo post-apocalíptico.
 *
 * Los saqueadores pueden presentarse como agresivos, sigilosos u oportunistas.
 * Sus fuerzas varían entre 5 y 10 miembros.
 */
class Saqueador : public EntidadGenerica
{
public:
    enum class Estilo
    {
        AGRESIVO,
        SIGILOSO,
        OPORTUNISTA
    };

private:
    int m_numMiembros; ///< Número de integrantes del grupo
    Estilo m_estilo;   ///< Estilo de saqueo del grupo

public:
    /**
     * @brief Constructor del saqueador
     * @param nombre Nombre del grupo de saqueadores
     * @param estilo Estilo de comportamiento del grupo
     */
    Saqueador(const std::string& nombre, Estilo estilo)
        : EntidadGenerica(nombre)
        , m_estilo(estilo)
        , m_numMiembros(randomGroupSize())
    {
    }

    /**
     * @brief Muestra la información del grupo de saqueadores
     */
    void showInfo() const override
    {
        std::cout << "💀 Saqueadores: " << m_name << "\n"
                  << " - Estilo: " << estiloToString(m_estilo) << "\n"
                  << " - Miembros: " << m_numMiembros << "\n";
    }

    /**
     * @brief Simula una amenaza del grupo
     */
    void amenazar() const
    {
        switch (m_estilo)
        {
            case Estilo::AGRESIVO:
                std::cout << "💬" << m_name << " >>> ¡Entréganos tus recursos o lo pagarán caro!" << std::endl;
                break;
            case Estilo::SIGILOSO:
                std::cout << "💬" << m_name << " >>> Nadie nos vio entrar, nadie los verá salir..." << std::endl;
                break;
            case Estilo::OPORTUNISTA:
                std::cout << "💬" << m_name << " >>> Solo estamos aquí por lo que sobra... si queda algo." << std::endl;
                break;
        }
    }

private:
    /**
     * @brief Devuelve una cantidad aleatoria de miembros entre 5 y 10
     */
    int randomGroupSize() const
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(5, 10);
        return dist(gen);
    }

    /**
     * @brief Convierte el enum de estilo a string
     */
    std::string estiloToString(Estilo estilo) const
    {
        switch (estilo)
        {
            case Estilo::AGRESIVO: return "Agresivo";
            case Estilo::SIGILOSO: return "Sigiloso";
            case Estilo::OPORTUNISTA: return "Oportunista";
            default: return "Desconocido";
        }
    }
};

#endif // SAQUEADOR_HPP
