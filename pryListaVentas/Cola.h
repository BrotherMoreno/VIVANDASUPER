#pragma once
#include <deque>
#include <functional>
using namespace std;

template <typename T>
class Cola {
    deque<T> q;
public:
    void encolar(const T& x) { q.push_back(x); }
    void desencolar() { if (!q.empty()) q.pop_front(); }
    T& frente() { return q.front(); }
    bool vacia() const { return q.empty(); }
    int tamanio() const { return (int)q.size(); }

    //  aplica accion a cada elemento
    void forEach(function<void(T&)> accion) {
        for (auto& e : q) accion(e);
    }
    //elimina si pred(e) es verdadero
    void removeIf(function<bool(const T&)> pred) {
        deque<T> tmp;
        for (auto& e : q) if (!pred(e)) tmp.push_back(e);
        q.swap(tmp);
    }
    // devuelve puntero a primer elemento que cumpla pred
    T* findIf(function<bool(const T&)> pred) {
        for (auto& e : q) if (pred(e)) return &e;
        return nullptr;
    }
};
