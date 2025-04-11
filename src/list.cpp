//
// Created by Usuario on 07/04/2025.
//

#include "dataStructures/list.hpp"
#include "refugio.hpp"

template class Queue<Evento>;

template <typename TData>
LinkedList<TData>::LinkedList(): head(nullptr){}

template <typename TData>
LinkedList<TData>::~LinkedList()
{
    while (head != nullptr)
    {
        auto aux = head;
        head = head->next;
        delete aux;
    }
}

template <typename TData>
void LinkedList<TData>::push_front(const TData& value)
{
    auto nuevo = new ListNode<TData>(value);
    nuevo->next = head;
    head = nuevo;
}

template <typename TData>
void LinkedList<TData>::remove_at(size_t position)
{
    if (head == nullptr)
    {
        return;
    }

    if (position == 0)
    {
        auto temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Para cualquier otra posicion necesitamos mantener un puntero al nodo anterior
    auto prev = head;
    auto current = head->next;
    size_t current_position = 1;

    // Avanzamos hasta encontrar la posicion o llegar al final de la lista
    while (current != nullptr && current_position < position)
    {
        prev = current;
        current = current->next;
        current_position++;
    }

    // Si current es nullptr quiere decir que la posicion especifica es mas grande que la lista,
    // no se encuentra la posicion
    if (current == nullptr) return;

    // Hacemos que el nodo anterior apunte al nodo siguiente actual
    prev->next = current->next;

    delete current;
}

template <typename TData>
ListNode<TData>* LinkedList<TData>::take(size_t startPosition, size_t nElements)
{
    // Si la lista esta vacia retornamos nullptr
    if (head == nullptr)
    {
        return nullptr;
    }

    // Buscamos el nodo de inicio
    ListNode<TData>* current = head;
    size_t current_position = 0;

    // Avanzamos hasta la posicion de inicio
    while (current != nullptr && current_position < startPosition)
    {
        current = current->next;
        current_position++;
    }

    // Si current es nullptr, la posicion esta fuera de rango
    if (current == nullptr) return nullptr;

    // Creamos el primer nodo de la nueva lista
    ListNode<TData>* new_head = new ListNode<TData>(current->data);
    ListNode<TData>* new_current = new_head;

    // Avanzamos al siguiente nodo en la lista original
    current = current->next;

    // Copiamos los siguientes mElements-1 nodos (ya copiamos 1)
    for (size_t i = 1; i < nElements && current != nullptr; i++)
    {
        // Creamos un nuevo nodo con el valor actual
        new_current->next = new ListNode<TData>(current->data);

        // Avanzamos en ambas listas
        new_current = new_current->next;
        current = current->next;
    }

    return new_head;
}

template <typename TData>
void LinkedList<TData>::print() const
{
    ListNode<TData>* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

template <typename TData>
DoublyLinkedList<TData>::DoublyLinkedList(): head(nullptr){}

template <typename TData>
DoublyLinkedList<TData>::~DoublyLinkedList()
{
    while(head != nullptr)
    {
        auto temporalNode = head;
        head = head->next;
        delete temporalNode;
    }
}

template <typename TData>
DoublyListNode<TData>* DoublyLinkedList<TData>::get_head() const
{
    return head;
}

template <typename TData>
void DoublyLinkedList<TData>::push_front(const TData& value)
{
    auto nuevo = new DoublyListNode<TData>(value);
    nuevo->next = head;
    head = nuevo;
}

template <typename TData>
void DoublyLinkedList<TData>::push_back(const TData& value)
{
    auto new_node = new DoublyListNode<TData>(value);
    if (head == nullptr)
    {
        head = new_node;
    } else
    {
        auto temporal = get_head();
        while (temporal->next != nullptr)
        {
            temporal = temporal->next;

        }
        temporal->next = new_node;
        new_node->prev = temporal;
    }
}

template <typename TData>
void DoublyLinkedList<TData>::remove_at(size_t position)
{
    // Si la lista esta vacia no hay nada que eliminar
    if (head == nullptr)
    {
        return;
    }

    // Caso que el nodo a eliminar sea el primero (nodo 0)
    if (position == 0)
    {
        DoublyListNode<TData>* temp = head;
        head = head->next;

        // Si hay mas nodos despues del primero actualizamos el prev del nuevo head
        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        delete temp;
        return;
    }

    // Para cualquier otra posicion recorremos la lista, hacemos un contador para llevar track de
    // la posicion en la lista
    DoublyListNode<TData>* current = head;
    size_t current_position = 0;

    while (current != nullptr && current_position < position)
    {
        current = current->next;
        current_position++;
    }

    // Si current es nullptr quiere decir que la posicion especifica es mas grande que la lista,
    // no se encuentra la posicion
    if (current == nullptr) return;

    // current es el nodo que queremos eliminar, conectamos sus
    // nodos adyacentes
    if (current->prev != nullptr)
    {
        current->prev->next = current->next;
    }

    if (current->next != nullptr)
    {
        current->next->prev = current->prev;
    }

    delete current;
}

template <typename TData>
void DoublyLinkedList<TData>::copy_list(const DoublyLinkedList& other)
{
    // PREGUNTAR: Borramos los nodos actuales?
    while (head != nullptr)
    {
        auto temporalNode = head;
        head = head->next;
        delete temporalNode;
    }

    // Copiamos los nodos de la otra lista con push_bakc()
    auto current = other.get_head();
    while (current != nullptr)
    {
        push_back(current->data);
        current = current->next;
    }
}

template <typename TData>
void DoublyLinkedList<TData>::print() const
{
    DoublyListNode<TData>* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
