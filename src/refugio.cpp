#include "refugio.hpp"
#include "asaltante.hpp"
#include "refugiado.hpp"
#include <variant>

Refugio::Refugio(const std::string& name, const std::string& leader)
    : EntidadGenerica(name)
    , m_leader(leader)
{
}

void Refugio::showInfo() const
{
    std::cout << "🏠 Refugio: " << m_name << "\t A cargo de: " << m_leader << "\n";
    std::cout << "\t🛡️  Defensa: " << m_defense << "\n";
    std::cout << "\t⚔️  Ataque: " << m_attack << "\n";
    std::cout << "👥 Moradores: " << "\n";
    for (const auto& refugee : m_refugees)
    {
        refugee.showInfo();
    }
    std::cout << "\n";
    std::cout << "\t📦 Recursos: \n";
}

void Refugio::doAction() const
{
    throw std::runtime_error("Not implemented yet");
}

void Refugio::addRefugee(const std::string& refugee)
{
    for (size_t i = 0; i < m_refugees.size(); i++)
        {
        if (refugee == m_refugees.at(i))
        {
            std::cout << "El refugiado " << refugee << " ya esta en el refugio" << std::endl;
            return;
        }
    }
    m_refugees.push_back(refugee);
}

size_t Refugio::verifyResource(const std::string& resource)
{
    for (size_t i = 0; i < m_refugees.size(); i++)
    {
        if (resource == m_resources.at(i).first)
        {
            return i;
        }
    }
    return 0;
}

void Refugio::addResource(const std::string& resource, float amount)
{
    size_t index = verifyResource(resource);
    if (index != 0)
    {
        std::cout << "El recurso " << resource << " ya esta en el refugio" << std::endl;
        std::cout << "Se le agregara al recurso " << resource << "la cantidad de: " << amount << std::endl;
        m_resources[index].second += amount;
    } else
    {
        m_resources.push_back(std::make_pair(resource, amount));
    }
}

bool Refugio::consumeResource(const std::string& resource, float amount)
{
    size_t index = verifyResource(resource);
    if (index != 0)
    {
        std::cout << "El recurso " << resource << " ya esta en el refugio" << std::endl;
        if (amount <= m_resources.at(index).second)
        {
            std::cout << "Se consumira la cantidad de  " << amount << " del recurso " << resource << std::endl;
            m_resources[index].second -= amount;
            return true;
        }
    }
    return false;
}

void Refugio::registerVisitant(const NPC::VisitanteVariant& visitante)
{
    std::visit(
        [this](const auto& visitor)
        {
            using VisitorType = std::decay_t<decltype(visitor)>;

            if constexpr (std::is_same_v<VisitorType, Raider>)
            {
                std::cout << " 🔺 VAULT detecta problemas... " << '\n';
                visitor.showInfo();
            }
            else if constexpr (std::is_same_v<VisitorType, Refugee>)
            {
                visitor.showInfo();
                m_refugees.push_back(visitor);
            }
            else
            {
                std::cout << "👀 Visitante sin comportamiento definido." << '\n';
                throw std::runtime_error("Visitante sin comportamiento definido");
            }
        },
        visitante);
}

void Refugio::showVisits()
{
    std::cout << "📖 Registro de visitas al Refugio " << m_name << ":\n";
    printRecursive(m_visitants->get_head());
}

void Refugio::printRecursive(DoublyListNode<NPC::VisitanteVariant>* mNode)
{
    if (!mNode)
    {
        std::cout << "Fin del registro!" << '\n';
        return;
    }
}

bool Refugio::isSafeFaction(const EngineData::Faction faccion) const
{
    return (faccion == EngineData::Faction::REFUGEES || faccion == EngineData::Faction::WATER_MERCHANTS ||
            faccion == EngineData::Faction::MERCHANTS || faccion == EngineData::Faction::STEEL_BROTHERS ||
            faccion == EngineData::Faction::CARAVAN);
}
