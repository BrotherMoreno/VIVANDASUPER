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
		case 7: cout << "\n\tPrograma Terminado...";
			Pausar();
			LimpiarPantalla();
			exit(0);
			break;
		}
	}
}



