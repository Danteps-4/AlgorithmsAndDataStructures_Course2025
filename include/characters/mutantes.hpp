#ifndef MUTANTE_HPP
#define MUTANTE_HPP

#include "entidadGenerica.hpp"
#include <iostream>
#include <random>

/**
 * @class Mutante
 * @brief Representa un mutante hostil en el yermo.
 *
 * Los mutantes son enemigos formidables. Generalmente actúan solos o en pareja,
 * poseen gran fuerza y resistencia, y rara vez pueden ser derrotados fácilmente.
 */
class Mutante : public EntidadGenerica
{
private:
    int m_salud;     ///< Salud del mutante
    int m_ataque;    ///< Poder de ataque
    bool m_enPareja; ///< Si está acompañado por otro mutante

public:
    /**
     * @brief Constructor
     * @param nombre Nombre del mutante
     */
    explicit Mutante(const std::string& nombre)
        : EntidadGenerica(nombre)
        , m_salud(generarSalud())
        , m_ataque(generarAtaque())
        , m_enPareja(dobleAmenaza())
    {
    }

    /**
     * @brief Muestra la información del mutante
     */
    void showInfo() const override
    {
        std::cout << "💀 MUTANTE: " << m_name << "\n"
                  << " - Salud: " << m_salud << "\n"
                  << " - Ataque: " << m_ataque << "\n"
                  << " - ¿Está acompañado?: " << (m_enPareja ? "Sí" : "No") << "\n";
    }

    /**
     * @brief Devuelve el poder de ataque total del encuentro
     */
    int poderTotal() const
    {
        return m_enPareja ? m_ataque * 2 : m_ataque;
    }

    /**
     * @brief Devuelve si el mutante está en pareja
     */
    bool enPareja() const
    {
        return m_enPareja;
    }

    /**
     * @brief Simula el daño recibido por el mutante
     * @param dmg Cantidad de daño
     */
    void recibirDanyo(int dmg)
    {
        m_salud -= dmg;
        if (m_salud <= 0)
        {
            std::cout << "☠️ " << m_name << " ha sido derrotado." << std::endl;
        }
        else
        {
            std::cout << "⚠️ " << m_name << " recibió " << dmg << " de daño. Salud restante: " << m_salud << std::endl;
        }
    }

    /**
     * @brief Devuelve si el mutante sigue con vida
     */
    bool estaVivo() const
    {
        return m_salud > 0;
    }

private:
    int generarSalud() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::uniform_int_distribution<int> dist(150, 250);
        return dist(rng);
    }

    int generarAtaque() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::uniform_int_distribution<int> dist(30, 60);
        return dist(rng);
    }

    bool dobleAmenaza() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::bernoulli_distribution coin(0.35); // 35% probabilidad de que venga en pareja
        return coin(rng);
    }
};

#endif // MUTANTE_HPP
