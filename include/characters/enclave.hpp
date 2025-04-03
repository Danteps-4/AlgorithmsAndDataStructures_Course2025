#ifndef ENCLAVE_HPP
#define ENCLAVE_HPP

#include "entidadGenerica.hpp"
#include <iostream>
#include <random>

/**
 * @class Enclave
 * @brief Representa una fuerza de combate de la facción ENCLAVE.
 *
 * Altamente equipada y letal, no se puede razonar con ellos. Atacan con fuerza total
 * y su presencia representa un peligro inmediato para el refugio.
 */
class Enclave : public EntidadGenerica
{
private:
    int m_fuerza;      ///< Cantidad de soldados (entre 10 y 50)
    double m_potencia; ///< Nivel de potencia de fuego estimado (escala 1.0 a 5.0)
    bool m_detectado;  ///< Si han detectado el refugio

public:
    /**
     * @brief Constructor
     * @param nombre Nombre del escuadrón
     */
    explicit Enclave(const std::string& nombre)
        : EntidadGenerica(nombre)
        , m_fuerza(generarFuerza())
        , m_potencia(generarPotencia())
        , m_detectado(false)
    {
    }

    /**
     * @brief Muestra información de la escuadra ENCLAVE
     */
    void showInfo() const override
    {
        std::cout << "💂🏻 ENCLAVE - Escuadrón: " << m_name << "\n"
                  << " - Soldados: " << m_fuerza << "\n"
                  << " - Potencia táctica: " << m_potencia << "\n"
                  << " - ¿Han detectado el refugio?: " << (m_detectado ? "Sí" : "No") << "\n";
    }

    /**
     * @brief Simula la detección del refugio
     */
    void detectarRefugio()
    {
        m_detectado = true;
        std::cout << "💬 " << m_name << " >>> Objetivo confirmado. Preparando ofensiva." << std::endl;
    }

    /**
     * @brief Devuelve si la escuadra ya ha detectado el refugio
     */
    bool haDetectado() const
    {
        return m_detectado;
    }

    /**
     * @brief Devuelve la fuerza de combate
     */
    int fuerza() const
    {
        return m_fuerza;
    }

    /**
     * @brief Devuelve la potencia de ataque
     */
    double potencia() const
    {
        return m_potencia;
    }

private:
    /**
     * @brief Genera aleatoriamente una cantidad de soldados entre 10 y 50
     */
    int generarFuerza() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::uniform_int_distribution<int> dist(10, 50);
        return dist(rng);
    }

    /**
     * @brief Genera aleatoriamente un valor de potencia entre 2.5 y 5.0
     */
    double generarPotencia() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::uniform_real_distribution<double> dist(2.5, 5.0);
        return dist(rng);
    }
};

#endif // ENCLAVE_HPP
