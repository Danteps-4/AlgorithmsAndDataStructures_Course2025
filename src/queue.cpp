//
// Created by Usuario on 07/04/2025.
//

#include "../include/dataStructures/queue.hpp"

template<typename TData>
Queue<TData>::Queue(): m_front(nullptr), m_rear(nullptr), m_size(0){}

template<typename TData>
Queue<TData>::~Queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

template<typename TData>
void Queue<TData>::enqueue(const TData& value)
{
    Node* newNode = new Node(value);
    if (isEmpty())
    {
        m_front = m_rear = newNode;
    }
    else
    {
        m_rear->next = newNode;
        m_rear = newNode;
    }
    ++m_size;
}

template<typename TData>
void Queue<TData>::dequeue()
{
    if (isEmpty()){
        throw std::underflow_error("Queue is empty");
    }
    Node* temp = m_front;
    m_front = m_front->next;
    delete temp;
    --m_size;
}

template<typename TData>
TData Queue<TData>::front() const
{
    if (isEmpty()){
        throw std::underflow_error("Queue is empty");
    }
    return m_front->data;
}

template<typename TData>
bool Queue<TData>::isEmpty() const
{
    return m_size == 0;
}

template<typename TData>
size_t Queue<TData>::getSize() const
{
    return m_size;
}