#include <iostream>
#include <fstream>
#include <sstream>
#include "Controller.h"
#include "Funciones.h"


int main() {
    // Load data and check for errors
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

    while (true) {
        int opcionPrincipal = menuPrincipal();

        if (opcionPrincipal == 3) {
            cout << "\n\tPrograma Terminado..." << endl;
            Pausar();
            LimpiarPantalla();
            break;
        }

        if (opcionPrincipal == 1) { // Usuario
            while (true) {
                int opcionUsuario = menuUsuario();
                switch (opcionUsuario) {
                case 1: // Ver productos
                    ListarProductos();
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 2: // Ver boleta
                    ListarBoletas();
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 3: // Ver carrito
                    // Note: Requires ListarCarrito() implementation in Controller.h or Funciones.h
                    cout << "\n\tMostrando carrito..." << endl;
                    cout<< "Mostrar carrito";
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 4: // Consultar estado de envio
                    // Note: Requires ConsultarEnvio() implementation in Controller.h or Funciones.h
                    cout << "\n\tConsultando estado de envio..." << endl;
                    // Placeholder: ConsultarEnvio();
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 5: // Volver al menu principal
                    LimpiarPantalla();
                    break;
                }
                if (opcionUsuario == 5) break;
            }
        }
        else if (opcionPrincipal == 2) { // Administrador
            while (true) {
                int opcionAdmin = menuAdmin();
                switch (opcionAdmin) {
                case 1: // Registrar producto
                    RegistrarProducto();
                    cout << "\n\tProducto Registrado..." << endl;
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 2: // Registrar vendedor
                    RegistrarVendedor();
                    cout << "\n\tVendedor Registrado..." << endl;
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 3: // Registrar boleta
                    RegistrarBoleta();
                    cout << "\n\tBoleta Registrada..." << endl;
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 4: // Listar productos
                    ListarProductos();
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 5: // Listar vendedores
                    ListarVendedores();
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 6: // Listar boletas
                    ListarBoletas();
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 7: // Editar producto
                {
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

                case 8: // Eliminar producto
                {
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

                case 9: // Guardar boletas en archivo
                    ListarBoletas();
                    for (int i = 0; i < lst_boletas->longitud(); ++i) {
                        CBoleta* b = lst_boletas->obtenerPos(i);
                        GuardarBoletaTxt(b, ARCHIVO_BOLETAS);
                    }
                    cout << "\nBoletas guardadas en " << ARCHIVO_BOLETAS << "\n";
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 10: // Mostrar productos ordenados por precio (ascendente)
                    MostrarProductosOrdenadosPorPrecio(true);
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 11: // Mostrar productos ordenados por precio (descendente)
                    MostrarProductosOrdenadosPorPrecio(false);
                    Pausar();
                    LimpiarPantalla();
                    break;

                case 12: // Volver al menu principal
                    LimpiarPantalla();
                    break;
                }
                if (opcionAdmin == 12) break;
            }
        }
    }
    return 0;
}



