#include <iostream>
#include <fstream>
#include <sstream>
#include "Controller.h"
#include "Funciones.h"


int main()
{
	lst_productos = CargarProductos(ARCHIVO_PRODUCTOS);
	lst_vendedores = CargarVendedores(ARCHIVO_VENDEDORES);
	while (true)
	{
		int opcion = Menu();
		switch (opcion)
		{
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
			// autenticación si es vendedir
			cout << "Ingrese Cod. Vendedor para editar: ";
			string cod; cin >> cod;
			CVendedor* vend = BuscarVendedor(cod); // si ya existe
			if (!vend) { cout << "Vendedor no encontrado.\n"; break; }
			EditarProducto(vend);
			Pausar();
			LimpiarPantalla();
		} break;

		case 8: {
			cout << "Ingrese Cod. Vendedor para eliminar: ";
			string cod; cin >> cod;
			CVendedor* vend = BuscarVendedor(cod);
			if (!vend) { cout << "Vendedor no encontrado.\n"; break; }
			EliminarProducto(vend);
			Pausar();
			LimpiarPantalla();
		} break;

		case 9: {
			ListarBoletas();
			
			for (int i = 0; i < lst_boletas->longitud(); ++i) {
				CBoleta* b = lst_boletas->obtenerPos(i);
				GuardarBoletaTxt(b, ARCHIVO_BOLETAS);
			}
			cout << "\nBoletas guardadas en " << ARCHIVO_BOLETAS << "\n";
			Pausar();
			LimpiarPantalla();
		} break;

		case 10: MostrarProductosOrdenadosPorPrecio(true);
			Pausar();
			LimpiarPantalla();
			break;

		case 11: MostrarProductosOrdenadosPorPrecio(false);
			Pausar();
			LimpiarPantalla();
			break;

		case 12: cout << "\n\tPrograma Terminado...";
			Pausar();
			LimpiarPantalla();
			exit(0);
			break;
		}
	}
}



