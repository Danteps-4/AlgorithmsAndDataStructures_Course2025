#ifndef MERCADERAGUA_HPP
#define MERCADERAGUA_HPP

#include "entidadGenerica.hpp"
#include <iostream>
#include <string>

/**
 * @class MercaderAgua
 * @brief Representa un comerciante especializado en el intercambio de agua por otros recursos.
 *
 * Los Mercaderes de Agua son la única facción que posee acceso constante a reservas potables.
 * Son fundamentales para la supervivencia, pero sus precios son elevados.
 */
class MercaderAgua : public EntidadGenerica
{
private:
    int m_unidadesAgua;  ///< Cantidad de unidades de agua que posee
    double m_tasaCambio; ///< Tasa de cambio (ej: 1 unidad de agua = X unidades de otro recurso)
    bool m_esConfiable;  ///< Determina si el comerciante es justo o intenta estafar

public:
    /**
     * @brief Constructor
     * @param nombre Nombre del mercader
     * @param agua Cantidad inicial de agua
     * @param tasa Tasa de intercambio de agua
     * @param confiable ¿Es confiable o especulador?
     */
    MercaderAgua(const std::string& nombre, int agua, double tasa, bool confiable)
        : EntidadGenerica(nombre)
        , m_unidadesAgua(agua)
        , m_tasaCambio(tasa)
        , m_esConfiable(confiable)
    {
    }

    /**
     * @brief Muestra la información del mercader
     */
    void showInfo() const override
    {
        std::cout << "💧 Mercader de Agua: '" << m_name << "'\n"
                  << " - Agua disponible : " << m_unidadesAgua << " unidades\n"
                  << " - Tasa de cambio   : 1 agua = " << m_tasaCambio << " recursos\n"
                  << " - Estado moral     : " << (m_esConfiable ? "Confiable" : "Especulador") << "\n";

        std::cout << "💬" << m_name << ">>> Tengo el agua más pura del Yermo..." << std::endl;
        if (m_esConfiable)
        {
            std::cout << "Ofrezco un trato justo: 1 unidad de agua por " << m_tasaCambio << " unidades de recursos."
                      << std::endl;
        }
        else
        {
            std::cout << "Mmm... esos recursos no valen nada, pero si me das el doble, hablamos." << std::endl;
        }
    }

    /**
     * @brief Rellenar agua
     */
    void refillWater(int cantidad)
    {
        m_unidadesAgua += cantidad;
    }

    /**
     * @brief Intenta realizar una transacción
     * @param recursosDisponibles Recursos que ofrece el jugador
     * @return true si la transacción es exitosa
     */
    bool trade(int recursosDisponibles)
    {
        double requerido = m_tasaCambio;
        if (!m_esConfiable)
        {
            requerido *= 2;
        }

        if (recursosDisponibles >= requerido && m_unidadesAgua > 0)
        {
            std::cout << "💬" << m_name << ">>> Bussinesssss" << std::endl;
            m_unidadesAgua -= requerido;
            return true;
        }
        else
        {
            std::cout << "💬" << m_name << ">>> Acaso crees que soy Santa Claus? Vuelve cuando tengas recursos"
                      << std::endl;
            return false;
        }
    }
};

#endif // MERCADERAGUA_HPP
