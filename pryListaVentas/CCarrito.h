#pragma once
#include "Lista.h"
#include "CProducto.h"
#include <iostream>
#include <iomanip>
using namespace std;

class CCarrito {
private:
    Lista<CProducto*>* lst_carrito;
public:
    CCarrito() {
        lst_carrito = new Lista<CProducto*>();
    }
    ~CCarrito() {
        // Liberar memoria de productos si es necesario
        delete lst_carrito;
    }

    void agregarProducto(CProducto* producto) {
        lst_carrito->agregaFinal(producto);
        cout << "Producto agregado al carrito: " << producto->toString() << endl;
    }

    void listarCarrito() {
        cout << "\n=======CARRITO DE COMPRAS=======" << endl;
        for (int i = 0; i < lst_carrito->longitud(); i++) {
            cout << lst_carrito->obtenerPos(i)->toString();
        }
        cout << endl;
    }

    float calcularTotal() {
        float total = 0.0f;
        for (int i = 0; i < lst_carrito->longitud(); i++) {
            total += lst_carrito->obtenerPos(i)->getPrecio();
        }
        return total;
    }

    int cantidadProductos() {
        return lst_carrito->longitud();
    }
};

