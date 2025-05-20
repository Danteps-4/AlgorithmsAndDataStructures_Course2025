//
// Created by Usuario on 20/05/2025.
//

#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include <algorithm>
#include <iostream>

struct Nodo {
    int outpostId;
    int priority;
    int height;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(const size_t& outpostId, const size_t& priority)
        : outpostId(outpostId), priority(priority), height(1), izquierda(nullptr), derecha(nullptr) {}
};

class AVLTree
{
private:
    Nodo* root;

    int height(Nodo* nodo)
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        return nodo->height;
    }

    int treeHeight(Nodo* nodo)
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        return 1 + max(height(nodo->izquierda), height(nodo->derecha));
    }

    int balance(Nodo* nodo)
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        return height(nodo->izquierda) - height(nodo->derecha);
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    void updateHeight(Nodo* nodo)
    {
        if (nodo == nullptr)
        {
            return;
        }
        nodo->height = 1 + max(height(nodo->izquierda), height(nodo->derecha));
    }

    int countNodes(Nodo* nodo)
    {
        if (nodo == nullptr)
        {
            return 0;
        }
        return 1 + countNodes(nodo->izquierda) + countNodes(nodo->derecha);
    }

    Nodo* rotateRight(Nodo* y)
    {
        Nodo* x = y->izquierda;
        Nodo* T2 = x->derecha;

        x->derecha = y;
        y->izquierda = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Nodo* rotateLeft(Nodo* x)
    {
        Nodo* y = x->derecha;
        Nodo* z = y->izquierda;

        y->izquierda = x;
        x->derecha = z;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Nodo* rotateCases(Nodo* nodo, int priority, int b)
    {
        if (b > 1 && priority < nodo->izquierda->priority)
        {
            return rotateRight(nodo);
        }
        if (b < -1 && priority > nodo->derecha->priority)
        {
            return rotateLeft(nodo);
        }
        if (b > 1 && priority > nodo->izquierda->priority)
        {
            nodo->izquierda = rotateLeft(nodo->izquierda);
            return rotateRight(nodo);
        }
        if (b < -1 && priority < nodo->derecha->priority)
        {
            nodo->derecha = rotateRight(nodo->derecha);
            return rotateLeft(nodo);
        }
        return nodo;
    }

    Nodo* insert(Nodo* nodo, int oupostId, int priority)
    {
        if (nodo == nullptr)
        {
            return new Nodo(oupostId, priority);
        }
        if (priority < nodo->priority)
        {
            nodo->izquierda = insert(nodo->izquierda, oupostId, priority);
        }else if (priority > nodo->priority)
        {
            nodo->derecha = insert(nodo->derecha, oupostId, priority);
        }else
        {
            return nodo;
        }

        updateHeight(nodo);

        int b = balance(nodo);

        return rotateCases(nodo, priority, b);
    }

    Nodo* remove(Nodo* nodo, int outpostId)
    {
        if (nodo == nullptr) return nullptr;

        // Buscar en ambos subárboles
        nodo->izquierda = remove(nodo->izquierda, outpostId);
        nodo->derecha = remove(nodo->derecha, outpostId);

        // Si encontramos el nodo a eliminar
        if (nodo->outpostId == outpostId) {
            // Caso 1: sin hijos o un hijo
            if (nodo->izquierda == nullptr || nodo->derecha == nullptr) {
                Nodo* temp = nodo->izquierda ? nodo->izquierda : nodo->derecha;
                delete nodo;
                return temp;
            }

            // Caso 2: dos hijos — reemplazar por el mínimo del subárbol derecho
            Nodo* sucesor = nodo->derecha;
            while (sucesor->izquierda != nullptr) {
                sucesor = sucesor->izquierda;
            }

            nodo->outpostId = sucesor->outpostId;
            nodo->priority = sucesor->priority;

            // Eliminar el sucesor
            nodo->derecha = remove(nodo->derecha, sucesor->outpostId);
        }

        updateHeight(nodo);
        int b = balance(nodo);

        return rotateCases(nodo, nodo->priority, b);
    }

    bool contains(Nodo* nodo, int outpostId)
    {
        if (nodo == nullptr)
        {
            return false;
        }
        if (nodo->outpostId == outpostId)
        {
            return true;
        }
        return contains(nodo->izquierda, outpostId) || contains(nodo->derecha, outpostId);
    }

    int findMin(Nodo* nodo)
    {
        if (nodo->izquierda == nullptr)
        {
            return nodo->outpostId;
        }
        return findMin(nodo->izquierda);
    }

    int findMax(Nodo* nodo)
    {
        if (nodo->derecha == nullptr)
        {
            return nodo->outpostId;
        }
        return findMax(nodo->derecha);
    }

    void printInOrder(Nodo* nodo)
    {
        if (nodo == nullptr)
        {
            return;
        }
        printInOrder(nodo->izquierda);
        std::cout << "ID: " << nodo->outpostId << " - Priority: " << nodo->priority << std::endl;
        printInOrder(nodo->derecha);
    }

    void printStats(Nodo* nodo)
    {
        std::cout << "Min outpostId: " << findMin(nodo) << std::endl;
        std::cout << "Max outpostId: " << findMax(nodo) << std::endl;
        std::cout << "Height: " << treeHeight(nodo) << std::endl;
        std::cout << "Count of nodes:" << countNodes(nodo) << std::endl;
    }

    void destroy(Nodo* nodo)
    {
        if (nodo == nullptr)
        {
            return;
        }
        destroy(nodo->izquierda);
        destroy(nodo->derecha);
        delete nodo;
    }

public:
    AVLTree(): root(nullptr){}
    ~AVLTree()
    {
        destroy(root);
    }
    void insert(int outpostId, int priority)
    {
        root = insert(root, outpostId, priority);
    }

    void remove(int outpostId)
    {
        root = remove(root, outpostId);
    }
    bool contains(int outpostId)
    {
        return contains(root, outpostId);
    }
    int findMin()
    {
        return findMin(root);
    }
    int findMax()
    {
        return findMax(root);
    }
    void printInOrder()
    {
        printInOrder(root);
    }
    void printStats()
    {
        printStats(root);
    }
};

#endif //AVLTREE_HPP
