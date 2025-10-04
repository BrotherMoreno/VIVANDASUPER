#pragma once
#include "Nodo.h"
#include <functional>
#include <string>
using namespace std;

typedef unsigned int uint;
template <class T>
class Lista {
private:
    Nodo<T>* nodo;
    typedef function<int(T, T)> Comp;
    Nodo<T>* ini;
    uint lon; // número de elementos en la lista

public:
    Lista() : ini(nullptr), lon(0) { nodo = new Nodo<T>(); }
    ~Lista() { while (lon > 0) eliminaInicial(); }
    /*Lista() {
        nodo = new Nodo<T>();
    };*/
    Lista(Nodo<T>* pNodo) {
        nodo = pNodo;
    };
    uint longitud();
    bool esVacia();
    void agregaInicial(T elem);
    void agregaPos(T elem, uint pos);
    void agregaFinal(T elem);
    void modificarInicial(T elem);
    void modificarPos(T elem, uint pos);
    void modificarFinal(T elem);
    void eliminaInicial();
    void eliminaPos(uint pos);
    void eliminaFinal();
    T obtenerInicial();
    T obtenerPos(uint pos);
    T obtenerFinal();
    T buscar(T elem);


    //~Lista(void);
    void agregar(T pNodo); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista* resto(void); //retorna el puntero al "resto" de la lista
                        //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    T suma(T i);
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void addOrdenado(T d);// suma nodos ordenados de menor a mayor
    bool esta(T d); //retorna true cuando d est� en la lista
    void borrarDato(T d);// borra el nodo que contiene a d

};
template <class T>
uint Lista<T>::longitud() {
    return lon;
}
template <class T>
bool Lista<T>::esVacia() {
    return lon == 0;
}
template <class T>
void Lista<T>::agregaInicial(T elem) {
    Nodo<T>* nuevo = new Nodo<T>(elem);
    if (!nuevo) return;
    nuevo->set_Sgte(ini);   
    ini = nuevo;
    lon++;
}

template <class T>
T Lista<T>::buscar(T elem) {
    Nodo<T>* aux = ini;
    while (aux != nullptr) {
        if (aux->get_Elem() == elem) return aux->get_Elem(); // == para punteros
        aux = aux->get_Sgte();
    }
    return nullptr;
}

template <class T>
void Lista<T>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        Nodo<T>* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        Nodo<T>* nuevo = new Nodo<T>(elem);
        nuevo->set_Sgte(aux->get_Sgte());
        if (nuevo != nullptr) {

            aux->set_Sgte(nuevo);
            lon++;
        }
    }
}
template <class T>
void Lista<T>::agregaFinal(T elem) {
    agregaPos(elem, lon); // ;)
}

template <class T>
void Lista<T>::eliminaInicial() {
    if (lon > 0) {
        Nodo<T>* aux = ini;
        ini = ini->get_Sgte();  
        delete aux;
        lon--;
    }
}


template <class T>
void Lista<T>::eliminaPos(uint pos) {
    if (pos >= lon) return;
    if (pos == 0) { eliminaInicial(); return; }
    Nodo<T>* prev = ini;
    for (uint i = 0; i < pos - 1; ++i) prev = prev->get_Sgte();
    Nodo<T>* target = prev->get_Sgte();
    prev->set_Sgte(target->get_Sgte());  
    delete target;
    lon--;
}


template <class T>
void Lista<T>::eliminaFinal() {
    if (lon == 0) return;
    eliminaPos(lon - 1);
}

template <class T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->elem = elem;
    }
}

template <class T>
void Lista<T>::modificarPos(T elem, uint pos) {
    if (pos < lon) {
        Nodo<T>* aux = ini;
        for (uint i = 0; i < pos; ++i) aux = aux->get_Sgte();  
        aux->set_Elem(elem);                                   
    }
}


template <class T>
void Lista<T>::modificarFinal(T elem) {
    modificarPos(elem, lon - 1);
}

template <class T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) ini->set_Elem(elem);
}



template <class T>
T Lista<T>::obtenerPos(uint pos) {
    if (pos < lon) {
        Nodo<T>* aux = ini;
        for (uint i = 0; i < pos; ++i) aux = aux->get_Sgte();
        return aux->get_Elem();
    }
    return T();  // en listas de punteros => nullptr
}

template <class T>
T Lista<T>::obtenerFinal() {
    return obtenerPos(lon - 1);
}


template <class T>
void Lista<T>::agregar(T d) //100
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_Sgte(nodo);
    nodo = nuevo;
}




