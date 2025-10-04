#pragma once
#include <iostream>
#include <string>
using namespace std;

class CProducto
{
private:
    //Propiedades o Atributos
    string aCodProducto;
    string aProducto;
    int aStock;
    float aPrecio;

public:
    //Constructores y Destructor
    CProducto() : aCodProducto(""), aProducto(""), aStock(0), aPrecio(0.0f) {}
    CProducto(const string& pCodProducto, const string& pProducto, int pStock, float pPrecio)
        : aCodProducto(pCodProducto), aProducto(pProducto), aStock(pStock), aPrecio(pPrecio) {
    }
    ~CProducto() = default;

    // SET
    void setCodProducto(const string& pCodProducto) { aCodProducto = pCodProducto; }
    void setProducto(const string& pProducto) { aProducto = pProducto; }
    void setStock(int pStock) { aStock = pStock; }
    void setPrecio(float pPrecio) { aPrecio = pPrecio; }

    // GET  (todos const)
    const string& getCodProducto() const { return aCodProducto; }
    const string& getProducto() const { return aProducto; }
    int getStock() const { return aStock; }
    float getPrecio() const { return aPrecio; }

    // Método de Servicio (const)
    string toString() const {
        string cadena = "\nCod. Producto: " + aCodProducto +
            " Producto: " + aProducto +
            " Stock: " + to_string(aStock) +
            " Precio: " + to_string(aPrecio);
        return cadena;
    }


};
