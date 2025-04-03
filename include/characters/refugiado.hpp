#ifndef REFUGIADO_HPP
#define REFUGIADO_HPP

#include "entidadGenerica.hpp"
#include <iostream>
#include <string>

/**
 * @class Refugiado
 * @brief Representa a un refugiado en el mundo post-apocalíptico.
 *
 * Los refugiados pueden unirse a un refugio. Necesitan recursos para mantenerse
 * y, de no tenerlos, buscarán otro refugio donde vivir.
 */
class Refugiado : public EntidadGenerica
{
private:
    int m_maxHealth;    ///< Salud del
    int m_health;       ///< Salud actual del refugiado
    int m_supplies;     ///< Suministros que posee
    bool m_isFromVault; ///< Si proviene de un refugio Vault (más débil)

public:
    /**
     * @brief Constructor del refugiado
     * @param name Nombre del refugiado
     * @param isFromVault Indica si proviene de un Vault o de la superficie
     */
    Refugiado(const std::string& name, bool isFromVault = false)
        : EntidadGenerica(name)
        , m_maxHealth(isFromVault ? 80 : 100)
        , m_supplies(0)
        , m_isFromVault(isFromVault)
    {
    }

    /**
     * @brief Muestra la información del refugiado
     */
    void showInfo() const override
    {
        std::cout << "👤 Refugiado: " << m_name << "\n"
                  << " - Salud: " << m_health << "/" << m_maxHealth << "\n"
                  << " - Suministros: " << m_supplies << "\n"
                  << " - Origen: " << (m_isFromVault ? "VAULT" : "Superficie") << "\n";
    }

    /**
     * @brief Consume suministros cada ciclo
     * @param cantidad Cantidad a consumir
     */
    void consumeSupplies(int cantidad)
    {
        if (m_supplies >= cantidad)
        {
            m_supplies -= cantidad;
            std::cout << "💬" << m_name << " >>> Gracias por mantenerme alimentado." << std::endl;
        }
        else
        {
            m_supplies = 0;
            std::cout << "💬" << m_name << " >>> No puedo quedarme sin recursos... buscaré otro lugar." << std::endl;
        }
    }

    /**
     * @brief Intenta ingresar al refugio
     * @param espacioDisponible Si hay lugar y recursos disponibles
     */
    void requestShelter(bool espacioDisponible)
    {
        if (espacioDisponible)
        {
            std::cout << "💬" << m_name << " >>> Gracias por recibirme en su refugio." << std::endl;
        }
        else
        {
            std::cout << "💬" << m_name << " >>> Entiendo, seguiré buscando un lugar donde quedarme..." << std::endl;
        }
    }

    /**
     * @brief Devuelve si es de un Vault
     */
    bool isFromVault() const
    {
        return m_isFromVault;
    }
};

#endif // REFUGIADO_HPP
