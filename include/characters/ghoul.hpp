#ifndef GHOUL_HPP
#define GHOUL_HPP

#include "entidadGenerica.hpp"
#include <iostream>
#include <random>

/**
 * @class Ghoul
 * @brief Representa una horda de ghouls salvajes.
 *
 * Los ghouls son mutantes desfigurados que actúan por instinto.
 * Aunque débiles individualmente, en grupo son extremadamente peligrosos.
 */
class Ghoul : public EntidadGenerica
{
private:
    int m_cantidad;  ///< Número de ghouls en la horda
    int m_saludBase; ///< Salud individual promedio
    int m_danyoBase; ///< Daño individual promedio

public:
    /**
     * @brief Constructor
     * @param nombre Nombre de la horda o designación
     */
    explicit Ghoul(const std::string& nombre)
        : EntidadGenerica(nombre)
        , m_cantidad(generarCantidad())
        , m_saludBase(generarSalud())
        , m_danyoBase(generarDanyo())
    {
    }

    /**
     * @brief Muestra la información general de la horda
     */
    void showInfo() const override
    {
        std::cout << "☣️ HORDA DE GHOULS: " << m_name << "\n"
                  << " - Individuos: " << m_cantidad << "\n"
                  << " - Salud por ghoul: " << m_saludBase << "\n"
                  << " - Daño por ghoul: " << m_danyoBase << "\n";
    }

    /**
     * @brief Daño total que puede causar la horda
     */
    int danyoTotal() const
    {
        return m_danyoBase * m_cantidad;
    }

    /**
     * @brief Simula una reducción del tamaño de la horda
     * @param eliminados Cantidad de ghouls eliminados
     */
    void eliminarGhouls(int eliminados)
    {
        m_cantidad -= eliminados;
        if (m_cantidad <= 0)
        {
            m_cantidad = 0;
            std::cout << "☠️ ¡La horda ha sido completamente aniquilada!" << std::endl;
        }
        else
        {
            std::cout << "⚠️ Han sido eliminados " << eliminados << " ghouls. Restan: " << m_cantidad << std::endl;
        }
    }

    /**
     * @brief Devuelve si la horda sigue siendo una amenaza
     */
    bool sigueActiva() const
    {
        return m_cantidad > 0;
    }

private:
    int generarCantidad() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::uniform_int_distribution<int> dist(30, 100);
        return dist(rng);
    }

    int generarSalud() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::uniform_int_distribution<int> dist(10, 20);
        return dist(rng);
    }

    int generarDanyo() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::uniform_int_distribution<int> dist(1, 3);
        return dist(rng);
    }
};

#endif // GHOUL_HPP
