#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "CProducto.h"

class CarritoVentas {
private:
    std::vector<CProducto> productos;
public:
    void agregarProducto(const CProducto& producto) {
        productos.push_back(producto);
    }
    void quitarProducto(const std::string& codProducto) {
        productos.erase(
            std::remove_if(productos.begin(), productos.end(),
                [codProducto](const CProducto& p) { return p.getCodProducto() == codProducto; }),
            productos.end());
    }
    void mostrarCarrito() const {
        std::cout << "\nProductos en el carrito:\n";

        for (const auto& p : productos) {
            std::cout << "Cod: " << p.getCodProducto() << " - " << p.getProducto() << std::endl;
        }
    }
    void limpiarCarrito() {
        productos.clear();
    }
    const std::vector<CProducto>& obtenerProductos() const {
        return productos;
    }
};

class Envio {
private:
    std::string direccion;
    std::vector<CProducto> productosEnvio;
public:
    void setDireccion(const std::string& dir) {
        direccion = dir;
    }
    std::string getDireccion() const {
        return direccion;
    }
    void agregarProductoEnvio(const CProducto& producto) {
        productosEnvio.push_back(producto);
    }
    void quitarProductoEnvio(const std::string& codProducto) {
        productosEnvio.erase(
            std::remove_if(productosEnvio.begin(), productosEnvio.end(),
                [codProducto](const CProducto& p) { return p.getCodProducto() == codProducto; }),
            productosEnvio.end());
    }
    void mostrarEnvio() const {
        std::cout << "\nEnvio a: " << direccion << "\nProductos:\n";
        for (const auto& p : productosEnvio) {
            std::cout << "Cod: " << p.getCodProducto() << " - " << p.getProducto() << std::endl;
        }
    }
    void limpiarEnvio() {
        productosEnvio.clear();
    }
    const std::vector<CProducto>& obtenerProductosEnvio() const {
        return productosEnvio;
    }
};