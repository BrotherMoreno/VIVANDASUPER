#pragma once
#include <vector>
using namespace std;

template <typename T>
class Pila {
    vector<T> v; 
public:
    void push(const T& x) { v.push_back(x); }
    void pop() { if (!v.empty()) v.pop_back(); }
    T& top() { return v.back(); }
    bool empty() const { return v.empty(); }
    int size() const { return (int)v.size(); }
    void clear() { v.clear(); }
};
