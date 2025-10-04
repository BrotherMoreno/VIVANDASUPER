#pragma once
#include <iostream>
#include <string>
#include "CUsuario.h"
using namespace std;

class CVendedor : public Usuario {
private:
    string aCargo;
    string aArea;
public:
    CVendedor() : Usuario(), aCargo(""), aArea("") {}
    CVendedor(const string& pCodVendedor, const string& pNombres,
        const string& pApellidos, const string& pCargo, const string& pArea)
        : Usuario(pCodVendedor, pNombres, pApellidos), aCargo(pCargo), aArea(pArea) {
    }

    // SET/GET extras
    void setCodVendedor(const string& v) { setId(v); }
    void setNombres(const string& v) { Usuario::setNombres(v); }
    void setApellidos(const string& v) { Usuario::setApellidos(v); }
    void setCargo(const string& v) { aCargo = v; }
    void setArea(const string& v) { aArea = v; }

    string getCodVendedor() { return getId(); }
    string getNombres() { return Usuario::getNombres(); }
    string getApellidos() { return Usuario::getApellidos(); }
    string getCargo() { return aCargo; }
    string getArea() { return aArea; }

    string rol() const override { return "Vendedor"; }

    string toString() {
        string cadena = "\nCod. Vendedor: " + getId() +
            " Nombres: " + getNombres() +
            " Apellidos: " + getApellidos() +
            " Cargo: " + aCargo +
            " Area: " + aArea;
        return cadena;
    }
};
