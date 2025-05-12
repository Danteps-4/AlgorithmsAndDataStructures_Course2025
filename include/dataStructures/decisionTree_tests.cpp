//
// Created by Usuario on 10/05/2025.
//

#include "decisionTree.hpp"

class Producto {
public:
    std::string nombre;
    double precio;

    Producto(std::string n, double p) : nombre(n), precio(p) {}

    // Sobrecarga de operator< para comparar por precio
    bool operator<(const Producto& otro) const {
        return precio < otro.precio;
    }

    // Sobrecarga de operator== para comparar Productos (solo basado en el nombre)
    bool operator==(const Producto& otro) const {
        return nombre == otro.nombre;
    }

    // Para la salida en recorrerPreorden
    friend std::ostream& operator<<(std::ostream& os, const Producto& p) {
        os << p.nombre << ": $" << p.precio;
        return os;
    }
};

int main()
{
    // Prueba con un TData de tipo Producto
    DecisionTree<Producto> arbolProductos;

    std::cout << "El arbol esta vacio? " << (arbolProductos.estaVacio() ? "Si" : "No") << std::endl;
    arbolProductos.insertar(Producto{"Monitor", 200});
    arbolProductos.insertar(Producto{"Mouse", 50});
    arbolProductos.insertar(Producto{"Teclado", 150});
    arbolProductos.insertar(Producto{"MousePad", 35});
    arbolProductos.insertar(Producto{"HDMI", 10});
    std::cout << "El arbol esta vacio? " << (arbolProductos.estaVacio() ? "Si" : "No") << std::endl;

    arbolProductos.recorrerPreorden();

    std::cout << "Buscando Mesa: " << (arbolProductos.buscar(Producto{"Mesa", 100}) ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscando Teclado: " << (arbolProductos.buscar(Producto{"Teclado", 160}) ? "Encontrado" : "No encontrado") << std::endl;

    arbolProductos.eliminar(Producto{"Mouse", 50});
    arbolProductos.eliminar(Producto{"Teclado", 150});
    arbolProductos.eliminar(Producto{"Silla", 120});

    arbolProductos.recorrerPreorden();

    arbolProductos.~DecisionTree();

    return 0;

}