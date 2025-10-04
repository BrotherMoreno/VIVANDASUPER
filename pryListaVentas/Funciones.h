//IMPLEMENTACION DE LOS MÉTODOS
void Pausar();
void LimpiarPantalla();
int Menu()
{
	cout << "\n";
	cout << "----------------------------------------------------" << endl;
	cout << "======================MENU==========================" << endl;
	cout << "<1> Registrar Productos." << endl;
	cout << "<2> Registrar Vendedor." << endl;
	cout << "<3> Registrar Boleta." << endl;
	cout << "<4> Listar Productos." << endl;
	cout << "<5> Listar Vendedores." << endl;
	cout << "<6> Listar Boletas." << endl;
	cout << "<7> Editar Producto (Vendedor)." << endl;
	cout << "<8> Eliminar Producto (Vendedor)." << endl;
	cout << "<9> Listar y Guardar Boletas en .txt." << endl;
	cout << "<10> Ordenar Productos por Precio (Menor a Mayor)" << endl;
	cout << "<11> Ordenar Productos por Precio (Mayor a Menor)" << endl;
	cout << "<12> Salir Del Programa" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Ingrese una opcion: ";

	int opcion;

	while (true) {
		if (!(cin >> opcion)) { cin.clear(); cin.ignore(1024, '\n'); cout << "Número inválido: "; continue; }
		if (opcion >= 1 && opcion <= 12) break;
		cout << "Ingrese una opción válida del 1 al 12: ";
	}
	return opcion;
}

void LimpiarPantalla() {
	system("cls");
}

void Pausar() {
	system("pause");
}

