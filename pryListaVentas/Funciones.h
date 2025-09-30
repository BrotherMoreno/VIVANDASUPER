//IMPLEMENTACION DE LOS MÉTODOS
void Pausar();
void LimpiarPantalla();
int Menu()
{
	cout << "\n";
	cout << "-------------------------------------" << endl;
	cout << "======================MENU===========" << endl;
	cout << "<1> Registrar Productos." << endl;
	cout << "<2> Registrar Vendedor." << endl;
	cout << "<3> Registrar Boleta." << endl;
	cout << "<4> Listar Productos." << endl;
	cout << "<5> Listar Vendedores." << endl;
	cout << "<6> Listar Boletas." << endl;
	cout << "<7> Salir." << endl;
	cout << "-------------------------------------" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	do
	{
		cin >> opcion;
		if (opcion < 0 || opcion>7)
			cout << "Ingrese una opcion valida... ";
	} while (opcion < 0 || opcion>7);

	return opcion;
}

void LimpiarPantalla() {
	system("cls");
}

void Pausar() {
	system("pause");
}

