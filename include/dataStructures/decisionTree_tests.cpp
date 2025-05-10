//
// Created by Usuario on 10/05/2025.
//

#include "decisionTree.h"

int main()
{
    auto* tree = new DecisionTree<std::string>();
    std::cout << "Esta vacio? " << tree->estaVacio() << std::endl;
    tree->insertar("Hola");
    tree->insertar("Chau");
    tree->insertar("Buenas");
    tree->insertar("Adios");
    tree->insertar("Hasta pronto");
    std::cout << "Esta vacio? " << tree->estaVacio() << std::endl;

    std::cout << "Recorrido: " << std::endl;
    tree->recorrerPreorden();

    std::cout << "Esta Buenas en el arbol: " << tree->buscar("Buenas") << std::endl;
    std::cout << "Esta Hasta en el arbol: " << tree->buscar("Hasta") << std::endl;
    std::cout << "Esta Hola en el arbol: " << tree->buscar("Hola") << std::endl;
    std::cout << "Esta Hasta pronto en el arbol: " << tree->buscar("Hasta pronto") << std::endl;
    std::cout << "Esta Saludos en el arbol: " << tree->buscar("Saludos") << std::endl;

    std::cout << "Recorrido antes de eliminar: " << std::endl;
    tree->recorrerPreorden();

    tree->eliminar("Chau");
    tree->eliminar("Hasta luego");
    tree->eliminar("Adios");
    tree->eliminar("Saludos");
    tree->eliminar("Algo");

    std::cout << "Recorrido despues de eliminar: " << std::endl;
    tree->recorrerPreorden();

    return 0;
}