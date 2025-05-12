//
// Created by Usuario on 08/05/2025.
//

#ifndef DECISIONTREE_HPP
#define DECISIONTREE_HPP
#include <iostream>

/**
 * @brief Nodo de decisionTree
 *
 * @tparam TData Tipo de dato almacenado
 */
template <typename TData>
struct Nodo {
    TData decision;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(const TData& d)
        : decision(d), izquierda(nullptr), derecha(nullptr) {}
};

/**
 * @brief Implementacion de decisionTree
 *
 * @tparam TData Tipo de dato almacenado
 */
template <typename TData>
class DecisionTree {
public:
    DecisionTree(): raiz(nullptr){}
    ~DecisionTree()
    {
        destruir(raiz);
    }

    /**
     * @brief Inserta un nuevo elemento
     *
     * @param decision Decision a insertar
     */
    void insertar(const TData& decision)
    {
        insertar(raiz, decision);
    }

    /**
     * @brief Busca un elemento en el decisionTree
     *
     * @param decision Decision a buscar
     */
    bool buscar(const TData& decision) const
    {
        return buscar(raiz, decision);
    }

    /**
     * @brief Elimina un elemento del decisionTree
     *
     * @param decision Decision a eliminar
     */
    void eliminar(const TData& decision)
    {
        eliminarNodo(raiz, decision);
    }

    /**
     * @brief Comprueba si el tree esta vacío
     *
     * @return True si esta vacio, false si no esta vacio
     */
    bool estaVacio() const
    {
        return raiz == nullptr;
    }

    /**
     * @brief Recorre el arbol en preorden (Raiz-Izq-Der)
     *
     */
    void recorrerPreorden() const
    {
        recorrerPreorden(raiz);
    }

private:
    Nodo<TData>* raiz;

    void insertar(Nodo<TData>*& nodo, const TData& decision)
    {
        if (nodo == nullptr)
        {
            nodo = new Nodo<TData>(decision);
            nodo->izquierda = nodo->derecha = nullptr;
        }
        else if (decision < nodo->decision)
        {
            insertar(nodo->izquierda, decision);
        } else
        {
            insertar(nodo->derecha, decision);
        }
    }

    bool buscar(Nodo<TData>* nodo, const TData& decision) const
    {
        if (nodo == nullptr)
        {
            return false;
        }
        if (nodo->decision == decision)
        {
            return true;
        }
        if (decision < nodo->decision)
        {
            return buscar(nodo->izquierda, decision);
        }
        return buscar(nodo->derecha, decision);
    }

    Nodo<TData>* encontrarMinimo(Nodo<TData>* nodo) const
    {
        while (nodo && nodo->izquierda)
        {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    void eliminarNodo(Nodo<TData>*& nodo, const TData& decision)
    {
        if (nodo == nullptr)
        {
            return;
        }
        if (decision < nodo->decision)
        {
            eliminarNodo(nodo->izquierda, decision);
        }else if (nodo->decision < decision)
        {
            eliminarNodo(nodo->derecha, decision);
        }else
        {
            if (nodo->izquierda == nullptr)
            {
                auto* temporal = nodo->derecha;
                delete nodo;
                nodo = temporal;
            }
            else if (nodo->derecha == nullptr)
            {
                auto* temporal = nodo->izquierda;
                delete nodo;
                nodo = temporal;
            }
            else
            {
                auto* temporal = encontrarMinimo(nodo->derecha);
                nodo->decision = temporal->decision;
                eliminarNodo(nodo->derecha, temporal->decision);
            }
        }
    }

    void recorrerPreorden(Nodo<TData>* nodo) const
    {
        if (nodo == nullptr)
        {
            return;
        }
        std::cout << nodo->decision << std::endl;
        recorrerPreorden(nodo->izquierda);
        recorrerPreorden(nodo->derecha);

    }

    void destruir(Nodo<TData>* nodo)
    {
        if (nodo)
        {
            destruir(nodo->izquierda);
            destruir(nodo->derecha);
            delete nodo;
        }
    }
};

#endif //DECISIONTREE_HPP
