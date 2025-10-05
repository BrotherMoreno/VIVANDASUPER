#pragma once
#include "Nodo.h"
#include <functional>
#include <string>

typedef unsigned int uint;

template <class T>
class Lista {
private:
    Nodo<T>* ini; // puntero al primer nodo
    typedef std::function<int(T, T)> Comp;
    uint lon; // número de elementos en la lista

public:
    // ---------- Constructores y destructor ----------
    Lista() : ini(nullptr), lon(0) {}
    ~Lista() { while (lon > 0) eliminaInicial(); }

    // ---------- Funciones básicas ----------
    uint longitud() const { return lon; }
    bool esVacia() const { return lon == 0; }

    // ---------- Agregar elementos ----------
    void agregaInicial(T elem) {
        Nodo<T>* nuevo = new Nodo<T>(elem);
        nuevo->set_Sgte(ini);
        ini = nuevo;
        ++lon;
    }

    void agregaPos(T elem, uint pos) {
        if (pos > lon) return;
        if (pos == 0) { agregaInicial(elem); return; }
        Nodo<T>* aux = ini;
        for (uint i = 1; i < pos; ++i)
            aux = aux->get_Sgte();
        Nodo<T>* nuevo = new Nodo<T>(elem);
        nuevo->set_Sgte(aux->get_Sgte());
        aux->set_Sgte(nuevo);
        ++lon;
    }

    void agregaFinal(T elem) { agregaPos(elem, lon); }

    // ---------- Eliminar elementos ----------
    void eliminaInicial() {
        if (ini) {
            Nodo<T>* aux = ini;
            ini = ini->get_Sgte();
            delete aux;
            --lon;
        }
    }

    void eliminaPos(uint pos) {
        if (pos >= lon) return;
        if (pos == 0) { eliminaInicial(); return; }
        Nodo<T>* prev = ini;
        for (uint i = 0; i < pos - 1; ++i)
            prev = prev->get_Sgte();
        Nodo<T>* target = prev->get_Sgte();
        prev->set_Sgte(target->get_Sgte());
        delete target;
        --lon;
    }

    void eliminaFinal() {
        if (lon > 0)
            eliminaPos(lon - 1);
    }

    // ---------- Modificar elementos ----------
    void modificarInicial(T elem) {
        if (ini != nullptr)
            ini->set_Elem(elem);
    }

    void modificarPos(T elem, uint pos) {
        if (pos < lon) {
            Nodo<T>* aux = ini;
            for (uint i = 0; i < pos; ++i)
                aux = aux->get_Sgte();
            aux->set_Elem(elem);
        }
    }

    void modificarFinal(T elem) {
        if (lon > 0)
            modificarPos(elem, lon - 1);
    }

    // ---------- Obtener elementos ----------
    T obtenerPos(uint pos) const {
        if (pos < lon) {
            Nodo<T>* aux = ini;
            for (uint i = 0; i < pos; ++i)
                aux = aux->get_Sgte();
            return aux->get_Elem();
        }
        return T(); // retorna valor "vacío"
    }

    T obtenerFinal() const {
        if (lon == 0) return T();
        return obtenerPos(lon - 1);
    }

    T obtenerInicial() const {
        if (ini == nullptr) return T();
        return ini->get_Elem();
    }

    // ---------- Buscar ----------
    T buscar(T elem) const {
        Nodo<T>* aux = ini;
        while (aux != nullptr) {
            if (aux->get_Elem() == elem)
                return aux->get_Elem();
            aux = aux->get_Sgte();
        }
        return T(); // devuelve valor por defecto si no lo encuentra
    }

    bool esta(T d) const {
        Nodo<T>* aux = ini;
        while (aux != nullptr) {
            if (aux->get_Elem() == d)
                return true;
            aux = aux->get_Sgte();
        }
        return false;
    }

    // ---------- Funciones adicionales ----------
    void borrarDato(T d) {
        if (lon == 0) return;
        if (ini->get_Elem() == d) {
            eliminaInicial();
            return;
        }
        Nodo<T>* prev = ini;
        Nodo<T>* curr = ini->get_Sgte();
        while (curr != nullptr) {
            if (curr->get_Elem() == d) {
                prev->set_Sgte(curr->get_Sgte());
                delete curr;
                --lon;
                return;
            }
            prev = curr;
            curr = curr->get_Sgte();
        }
    }

    void concat(Lista<T>* l1) {
        if (l1->esVacia()) return;
        if (this->esVacia()) {
            ini = l1->ini;
        }
        else {
            Nodo<T>* aux = ini;
            while (aux->get_Sgte() != nullptr)
                aux = aux->get_Sgte();
            aux->set_Sgte(l1->ini);
        }
        lon += l1->lon;
        l1->ini = nullptr;
        l1->lon = 0;
    }

    Lista<T>* copy() const {
        Lista<T>* nueva = new Lista<T>();
        Nodo<T>* aux = ini;
        while (aux != nullptr) {
            nueva->agregaFinal(aux->get_Elem());
            aux = aux->get_Sgte();
        }
        return nueva;
    }

    void tomar(int n) {
        if (n >= lon) return;
        Nodo<T>* aux = ini;
        for (int i = 1; i < n; ++i)
            aux = aux->get_Sgte();
        Nodo<T>* borrar = aux->get_Sgte();
        aux->set_Sgte(nullptr);
        while (borrar != nullptr) {
            Nodo<T>* temp = borrar;
            borrar = borrar->get_Sgte();
            delete temp;
            --lon;
        }
    }

    void addOrdenado(T d) {
        if (esVacia() || ini->get_Elem() >= d) {
            agregaInicial(d);
            return;
        }
        Nodo<T>* aux = ini;
        while (aux->get_Sgte() != nullptr && aux->get_Sgte()->get_Elem() < d)
            aux = aux->get_Sgte();
        Nodo<T>* nuevo = new Nodo<T>(d);
        nuevo->set_Sgte(aux->get_Sgte());
        aux->set_Sgte(nuevo);
        ++lon;
    }

    std::string toPrint(std::string sep = " ") const {
        std::string res;
        Nodo<T>* aux = ini;
        while (aux != nullptr) {
            res += std::to_string(aux->get_Elem());
            if (aux->get_Sgte() != nullptr)
                res += sep;
            aux = aux->get_Sgte();
        }
        return res;
    }
};
