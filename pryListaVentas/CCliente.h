#pragma once
#include <string>
#include "CUsuario.h"
#include "CarritoEnvio.h"
using namespace std;

class CCliente : public Usuario {
private:
    string direccion;
    CarritoVentas carrito;   // composición
    Envio envio;             // dirección + productos para envío
public:
    CCliente() : Usuario(), direccion("") {}
    CCliente(const string& id, const string& n, const string& a, const string& dir)
        : Usuario(id, n, a), direccion(dir) {
        envio.setDireccion(dir);
    }
    string rol() const override { return "Cliente"; }

    void setDireccion(const string& d) { direccion = d; envio.setDireccion(d); }
    const string& getDireccion() const { return direccion; }

    CarritoVentas& getCarrito() { return carrito; }
    Envio& getEnvio() { return envio; }

    string toString() const override {
        return Usuario::toString() + " Direccion: " + direccion;
    }
};
