#pragma once
#include <iostream>
#include <string>
#include "CCliente.h"
#include "CVendedor.h"

using namespace std;

class CRegistro {
public:
    // Registra un cliente 
    static CCliente* registrarCliente() {
        string id, nombres, apellidos, direccion;
        cout << "Registro de Cliente\n";
        cout << "Ingrese ID: ";
        cin >> id;
        cout << "Ingrese Nombres: ";
        cin.ignore();
        getline(cin, nombres);
        cout << "Ingrese Apellidos: ";
        getline(cin, apellidos);
        cout << "Ingrese Dirección: ";
        getline(cin, direccion);

        return new CCliente(id, nombres, apellidos, direccion);
    }

    // Registra un administrador (vendedor)
    static CVendedor* registrarAdministrador() {
        string id, nombres, apellidos, cargo, area;
        cout << "Registro de Administrador\n";
        cout << "Ingrese Cod. Vendedor: ";
        cin >> id;
        cout << "Ingrese Nombres: ";
        cin.ignore();
        getline(cin, nombres);
        cout << "Ingrese Apellidos: ";
        getline(cin, apellidos);
        cout << "Ingrese Cargo: ";
        getline(cin, cargo);
        cout << "Ingrese Area: ";
        getline(cin, area);

        return new CVendedor(id, nombres, apellidos, cargo, area);
    }

    // Menú de registro
    static void menuRegistro() {
        int opcion;
        cout << "\n--- Registro ---\n";
        cout << "1. Registrarse como Cliente\n";
        cout << "2. Registrarse como Administrador\n";
        cout << "Seleccione opción: ";
        cin >> opcion;

        if (opcion == 1) {
            CCliente* cliente = registrarCliente();
            cout << "\nCliente registrado:\n" << cliente->toString() << endl;
            // Aquí puedes agregar el cliente a tu lista de clientes si lo deseas
            delete cliente; // Elimina si no lo vas a guardar
        }
        else if (opcion == 2) {
            CVendedor* admin = registrarAdministrador();
            cout << "\nAdministrador registrado:\n" << admin->toString() << endl;
            // Aquí puedes agregar el administrador a tu lista de vendedores si lo deseas
            delete admin; // Elimina si no lo vas a guardar
        }
        else {
            cout << "Opción inválida.\n";
        }
    }
};