#ifndef MERCADER_HPP
#define MERCADER_HPP

#include "engineData.hpp"
#include "entidadGenerica.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

/**
 * @brief Función auxiliar para convertir enum Resources a string legible
 */
inline std::string resourceToString(EngineData::Resources res)
{
    switch (res)
    {
        case EngineData::Resources::FOOD: return "comida";
        case EngineData::Resources::WATER: return "agua";
        case EngineData::Resources::MEDICINE: return "medicina";
        case EngineData::Resources::AMMO: return "munición";
        case EngineData::Resources::WEAPONS: return "armas";
        case EngineData::Resources::ARMOR: return "armaduras";
        case EngineData::Resources::TOOLS: return "herramientas";
        case EngineData::Resources::MATERIALS: return "materiales";
        case EngineData::Resources::ELECTRONICS: return "electrónica";
        case EngineData::Resources::ALCHOHOL: return "alcohol";
        default: return "desconocido";
    }
}

/**
 * @class Mercader
 * @brief Representa un comerciante general en el mundo post-apocalíptico.
 *
 * Los Mercaderes ofrecen diversos recursos a cambio de otros. No comercian con agua, y su stock puede variar.
 */
class Mercader : public EntidadGenerica
{
private:
    std::unordered_map<EngineData::Resources, int> m_inventario; ///< Inventario del mercader (recurso → cantidad)
    bool m_esAmistoso; ///< Define si el comerciante ofrece descuentos o es neutral

public:
    /**
     * @brief Constructor
     * @param nombre Nombre del mercader
     * @param esAmistoso Indica si es amigable (mejores precios)
     */
    Mercader(const std::string& nombre, bool esAmistoso)
        : EntidadGenerica(nombre)
        , m_esAmistoso(esAmistoso)
    {
        // Inventario inicial básico (sin agua)
        m_inventario[EngineData::Resources::TOOLS] = 10;
        m_inventario[EngineData::Resources::AMMO] = 5;
        m_inventario[EngineData::Resources::MEDICINE] = 3;
        m_inventario[EngineData::Resources::MATERIALS] = 6;
    }

    /**
     * @brief Muestra información del mercader y su inventario
     */
    void showInfo() const override
    {
        std::cout << "💰 Mercader: " << m_name << "\n"
                  << " - Inventario:\n";
        for (const auto& [item, cantidad] : m_inventario)
        {
            std::cout << "   * " << resourceToString(item) << ": " << cantidad << "\n";
        }
    }

    /**
     * @brief Intenta comprar un recurso específico
     * @param recurso Nombre del recurso
     * @param cantidad Cantidad solicitada
     * @return true si la operación es exitosa
     */
    bool trade(const EngineData::Resources& recurso, int cantidad)
    {

        std::cout << "💬" << m_name << ">>> Tengo lo que necesitas... a un excelente precio." << std::endl;

        if (recurso == EngineData::Resources::WATER)
        {

            return false;
        }

        if (m_inventario.find(recurso) != m_inventario.end() && m_inventario[recurso] >= cantidad)
        {
            m_inventario[recurso] -= cantidad;
            std::cout << "💬" << m_name << ">>> Excelente compra!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "💬" << m_name << ">>> Probaremos la próxima vez... No tengo en stock" << std::endl;
            return false;
        }
    }
};

#endif // MERCADER_HPP