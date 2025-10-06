//IMPLEMENTACION DE LOS MÉTODOS

void Pausar();
void LimpiarPantalla();
int menuAdmin()
{
	cout << "\n";
	cout << "----------------------------------------------------" << endl;
	cout << "===================VIVANDA_ADMIN====================" << endl;
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
int menuPrincipal() {
	int opcion;
	cout << "\n";
	cout << "----------------------------------------------------" << endl;
	cout << "============= Bienvenidos a Vivanda ================" << endl;
	cout << "1. Ingresar como Usuario" << endl;
	cout << "2. Ingresar como Administrador" << endl;
	cout << "3. Salir" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Seleccione una opcion: ";
	cin >> opcion;
	return opcion;
}
int menuUsuario() {
	int opcion;
	cout << "\n";
	cout << "----------------------------------------------------" << endl;
	cout << "===================VIVANDA_USUARIO===================" << endl;
	cout << "1. Ver productos" << endl;
	cout << "2. Ver boleta" << endl;
	cout << "3. Ver carrito" << endl;
	cout << "4. Consultar estado de envio" << endl;
	cout << "5. Salir" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Seleccione una opcion: ";
	cin >> opcion;
	return opcion;
}

void LimpiarPantalla() {
	system("cls");
}

void Pausar() {
	system("pause");
}

