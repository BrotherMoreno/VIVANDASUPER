#include <iostream>
#include <fstream>
#include <sstream>
#include "Controller.h"
#include "Funciones.h"
#include "CarritoEnvio.h"
#include "CRegistro.h"

int main() {
    // Cargar datos
    lst_productos = CargarProductos(ARCHIVO_PRODUCTOS);
    if (!lst_productos) {
        cout << "Error: No se pudieron cargar los productos." << endl;
        Pausar();
        return 1;
    }
    lst_vendedores = CargarVendedores(ARCHIVO_VENDEDORES);
    if (!lst_vendedores) {
        cout << "Error: No se pudieron cargar los vendedores." << endl;
        Pausar();
        return 1;
    }

    // Registro inicial
    cout << "\nBienvenido. Debe registrarse para continuar.\n";
    int tipoRegistro = 0; // 1 = cliente, 2 = admin
    CCliente* cliente = nullptr;
    CVendedor* admin = nullptr;

    while (tipoRegistro == 0) {
        cout << "\n--- Registro ---\n";
        cout << "1. Registrarse como Cliente\n";
        cout << "2. Registrarse como Administrador\n";
        cout << "Seleccione opción: ";
        cin >> tipoRegistro;

        if (tipoRegistro == 1) {
            cliente = CRegistro::registrarCliente();
            cout << "\nCliente registrado:\n" << cliente->toString() << endl;
        }
        else if (tipoRegistro == 2) {
            admin = CRegistro::registrarAdministrador();
            cout << "\nAdministrador registrado:\n" << admin->toString() << endl;
        }
        else {
            cout << "Opción inválida. Intente nuevamente.\n";
            tipoRegistro = 0;
        }
    }

    // Menú principal según tipo de registro
    while (true) {
        int opcionPrincipal = 0;
        cout << "\n--- Menú Principal ---\n";
        if (tipoRegistro == 1) {
            cout << "1. Menú Usuario\n";
            cout << "2. Salir\n";
            cout << "Seleccione opción: ";
            cin >> opcionPrincipal;
            if (opcionPrincipal == 2) break;
            if (opcionPrincipal == 1) {
                CarritoVentas carrito;
                while (true) {
                    int opcionUsuario = menuUsuario();
                    switch (opcionUsuario) {
                    case 1: // Ver productos y agregar al carrito
                        ListarProductos();
                        cout << "\n¿Desea agregar un producto al carrito? (s/n): ";
                        char resp;
                        cin >> resp;
                        if (resp == 's' || resp == 'S') {
                            string cod;
                            cout << "Ingrese el código del producto: ";
                            cin >> cod;
                            for (int i = 0; i < lst_productos->longitud(); ++i) {
                                CProducto* prod = lst_productos->obtenerPos(i);
                                if (prod && prod->getCodProducto() == cod) {
                                    carrito.agregarProducto(*prod);
                                    cout << "Producto agregado al carrito.\n";
                                    break;
                                }
                            }
                        }
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 2: // Ver boleta
                        ListarBoletas();
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 3: // Ver y quitar productos del carrito
                        carrito.mostrarCarrito();
                        cout << "\n¿Desea quitar un producto del carrito? (s/n): ";
                        cin >> resp;
                        if (resp == 's' || resp == 'S') {
                            string cod;
                            cout << "Ingrese el código del producto a quitar: ";
                            cin >> cod;
                            carrito.quitarProducto(cod);
                            cout << "Producto eliminado del carrito.\n";
                        }
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 4: // Comprar y limpiar carrito
                        cout << "\nProcesando compra...\n";
                        carrito.limpiarCarrito();
                        cout << "Compra realizada. Carrito vacío.\n";
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 5: // Volver al menú principal
                        LimpiarPantalla();
                        break;
                    }
                    if (opcionUsuario == 5) break;
                }
            }
        }
        else if (tipoRegistro == 2) {
            cout << "1. Menú Administrador\n";
            cout << "2. Salir\n";
            cout << "Seleccione opción: ";
            cin >> opcionPrincipal;
            if (opcionPrincipal == 2) break;
            if (opcionPrincipal == 1) {
                while (true) {
                    int opcionAdmin = menuAdmin();
                    switch (opcionAdmin) {
                    case 1: RegistrarProducto();
                        cout << "\n\tProducto Registrado..." << endl;
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 2: RegistrarVendedor();
                        cout << "\n\tVendedor Registrado..." << endl;
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 3: RegistrarBoleta();
                        cout << "\n\tBoleta Registrada..." << endl;
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 4: ListarProductos();
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 5: ListarVendedores();
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 6: ListarBoletas();
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 7: {
                        string cod;
                        cout << "Ingrese Cod. Vendedor para editar: ";
                        cin >> cod;
                        CVendedor* vend = BuscarVendedor(cod);
                        if (!vend) {
                            cout << "Vendedor no encontrado.\n";
                        }
                        else {
                            EditarProducto(vend);
                        }
                        Pausar();
                        LimpiarPantalla();
                        break;
                    }
                    case 8: {
                        string cod;
                        cout << "Ingrese Cod. Vendedor para eliminar: ";
                        cin >> cod;
                        CVendedor* vend = BuscarVendedor(cod);
                        if (!vend) {
                            cout << "Vendedor no encontrado.\n";
                        }
                        else {
                            EliminarProducto(vend);
                        }
                        Pausar();
                        LimpiarPantalla();
                        break;
                    }
                    case 9: ListarBoletas();
                        for (int i = 0; i < lst_boletas->longitud(); ++i) {
                            CBoleta* b = lst_boletas->obtenerPos(i);
                            GuardarBoletaTxt(b, ARCHIVO_BOLETAS);
                        }
                        cout << "\nBoletas guardadas en " << ARCHIVO_BOLETAS << "\n";
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 10: MostrarProductosOrdenadosPorPrecio(true);
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 11: MostrarProductosOrdenadosPorPrecio(false);
                        Pausar();
                        LimpiarPantalla();
                        break;
                    case 12: LimpiarPantalla();
                        break;
                    }
                    if (opcionAdmin == 12) break;
                }
            }
        }
    }
    // Liberar memoria si es necesario
    delete cliente;
    delete admin;
    return 0;
}