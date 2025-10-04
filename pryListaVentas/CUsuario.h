#pragma once
#include <string>
using namespace std;

class Usuario {
protected:
    string id;
    string nombres;
    string apellidos;
public:
    Usuario() = default;
    Usuario(const string& id, const string& n, const string& a)
        : id(id), nombres(n), apellidos(a) {
    }
    virtual ~Usuario() = default;

    // GET/SET
    const string& getId() const { return id; }
    const string& getNombres() const { return nombres; }
    const string& getApellidos() const { return apellidos; }
    void setId(const string& v) { id = v; }
    void setNombres(const string& v) { nombres = v; }
    void setApellidos(const string& v) { apellidos = v; }

    // Polimorfismo
    virtual string rol() const = 0;

    virtual string toString() const {
        return "\nUsuario: " + id + " " + nombres + " " + apellidos +
            " Rol: " + rol();
    }
};
