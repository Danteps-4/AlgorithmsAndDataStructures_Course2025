//
// Created by Usuario on 20/05/2025.
//

#include "avltree.hpp"

int main()
{
    AVLTree tree;

    std::cout << "Insertando nodos..." << std::endl;
    tree.insert(101, 50);
    tree.insert(102, 30);
    tree.insert(103, 70);
    tree.insert(104, 20);
    tree.insert(105, 40);
    tree.insert(106, 60);
    tree.insert(107, 80);

    std::cout << "Imprimiendo en orden:" << std::endl;
    tree.printInOrder();

    std::cout << "\nContiene outpostId 105? " << (tree.contains(105) ? "Si" : "No") << std::endl;
    std::cout << "Contiene outpostId 999? " << (tree.contains(999) ? "Si" : "No") << std::endl;

    std::cout << "\nMinimo: " << tree.findMin() << std::endl;
    std::cout << "Maximo: " << tree.findMax() << std::endl;

    tree.remove(104);
    std::cout << "\nEliminado outpostId 104" << std::endl;
    tree.printInOrder();

    tree.remove(101);
    std::cout << "\nEliminado outpostId 101" << std::endl;
    tree.printInOrder();

    std::cout << "\nEstadisticas del arbol:\n";
    tree.printStats();

    return 0;

}