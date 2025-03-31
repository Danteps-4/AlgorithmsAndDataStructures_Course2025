#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

/**
 * @brief Nodo de lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct ListNode
{
    TData data;
    ListNode* next;

    explicit ListNode(const TData& value)
        : data(value)
        , next(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class LinkedList
{
private:
    ListNode<TData>* head;

public:
    LinkedList()
        : head(nullptr)
    {
    }

    ~LinkedList()
    {
        while (head != nullptr)
        {
            auto aux = head;
            head = head->next;
            delete aux;
        }
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        auto node = new ListNode<TData>(value);
        node->next = head;
        head = node;
    }

    /**
     * @brief Elimina el primer elemento al inicio de la lista
     *
     */
    void remove_first()
    {
        if (head->next == nullptr)
        {
            delete head;
        } else
        {
            auto aux = head;
            head = head->next;
            delete aux;
        }
    }


    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        if (head == nullptr)
        {
            return;  // La lista esta vacia
        }

        if (position == 0)
        {
            remove_first();  // Se elimina el primero
        } else
        {
            ListNode<TData>* temporal = head;
            for (size_t i = 0; i < position - 1; i++)
            {
                temporal = temporal->next;
            }
            if (temporal == nullptr || temporal->next == nullptr)
            {
                return;  // Posicion no valida
            }
            auto a_eliminar = temporal->next;
            temporal->next = temporal->next->next;
            delete a_eliminar;
        }
    }

    /**
    * @brief Crea una lista nueva de n elementos a partir de una posición dada
    *
    */
    ListNode<TData>* take(size_t startPosition, size_t nElements)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        ListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

/**
 * @brief Nodo de lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct DoublyListNode
{
    TData data;
    DoublyListNode* next;
    DoublyListNode* prev;

    explicit DoublyListNode(const TData& value)
        : data(value)
        , next(nullptr)
        , prev(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class DoublyLinkedList
{
private:
    DoublyListNode<TData>* head;

public:
    DoublyLinkedList()
        : head(nullptr)
    {
    }

    ~DoublyLinkedList()
    {
        while(head != nullptr)
        {
            auto temporalNode = head;
            head = head->next;
            delete temporalNode;
        }
    }

    /**
     * @brief Retorna el primer elemento de la lista
     *
     * @return Primer elemento de la lista
     */
    DoublyListNode<TData>* get_head() const
    {
        return head;
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        auto new_node = new DoublyListNode<TData>(value);
        new_node->prev = nullptr;
        new_node->next = head;
        if (head != nullptr)
        {
            head->prev = new_node;
        }
        head = new_node;
    }

    /**
     * @brief Inserta un nuevo elemento al final de la lista
     *
     * @param value Valor a insertar
     */
    void push_back(const TData& value)
    {
        auto new_node = new DoublyListNode<TData>(value);
        if (head == nullptr)
        {
            head = new_node;
        } else
        {
            DoublyListNode<TData>* temporal = head;
            while (temporal->next != nullptr)
            {
                temporal = temporal->next;

            }
            temporal->next = new_node;
            new_node->prev = temporal;
        }
    }

    /**
    * @brief Remueve el primer elemento de la lista
    *
    */
    void remove_first()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        auto aux = head;
        head = head->next;
        head->prev = nullptr;
        delete aux;
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        if (head == nullptr)
        {
            return; // La lista esta vacia
        }

        if (position == 0)
        {
            remove_first(); // Se remueve el primer elemento
            return;
        }

        DoublyListNode<TData>* temporal = head;
        for (size_t i = 0; i < position && temporal != nullptr; i++)
        {
            temporal = temporal->next;
        }
        if (temporal == nullptr)
        {
            return;
        }
        if (temporal->prev != nullptr)
        {
            temporal->prev->next = temporal->next;
        }
        if (temporal->next != nullptr)
        {
            temporal->next->prev = temporal->prev;
        }
        delete temporal;
    }

    /**
    * @brief Copia los elementos de otra lista
    *
    * @param other Lista de la cual copiar los elementos
    */
    void copy_list(const DoublyLinkedList& other)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        DoublyListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

#endif // LIST_HPP
