#define ARCHIVO_PRODUCTOS "Productos.txt"
#define ARCHIVO_VENDEDORES "Vendedores.txt"
#define ARCHIVO_BOLETAS "Boletas.txt"


#include "CProducto.h"
#include "CVendedor.h"
#include "CBoleta.h"
#include "CUsuario.h"
#include "CCliente.h"
#include "Lista.h"
#include "Ordenamiento.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//Declarando las variables Globales
Lista<CProducto*>* lst_productos = new Lista<CProducto*>();
Lista<CVendedor*>* lst_vendedores = new Lista<CVendedor*>();
Lista<CBoleta*>* lst_boletas = new Lista<CBoleta*>();

//Declarando las funciones
int menuAdmin();
void RegistrarProducto();
void RegistrarVendedor();
void RegistrarBoleta();
void ListarProductos();
void ListarVendedores();
void ListarBoletas();
void EditarProducto(const CVendedor* vendedor);
void EliminarProducto(const CVendedor* vendedor);
void GuardarProductosArchivoCompleto(string nombreArchivo, Lista<CProducto*>* lista);
void GuardarBoletaTxt(CBoleta* b, const string& nombreArchivo);
CProducto* BuscarProducto(string);
CVendedor* BuscarVendedor(string);
Lista<CProducto*>* CargarProductos(string);
Lista<CVendedor*>* CargarVendedores(string);
void AgregarProductoArchivo(string, CProducto*);
void AgregarVendedorArchivo(string, CVendedor*);
void MostrarProductosOrdenadosPorPrecio(bool asc);


void RegistrarProducto()
{
	//Declarando las Variables temporales
	CProducto* objProducto = new CProducto();
	string pCodProducto, pProducto;
	int pStock;
	float pPrecio;
	//Registrando el producto
	cout << "\n======REGISTRAR PRODUCTO======" << endl;
	cout << "Ingrese Cod. Producto: "; cin >> pCodProducto;
	objProducto->setCodProducto(pCodProducto);
	cout << "Ingrese Producto: "; cin >> pProducto;
	objProducto->setProducto(pProducto);
	cout << "Ingrese Stock: "; cin >> pStock;
	objProducto->setStock(pStock);
	cout << "Ingrese Precio: "; cin >> pPrecio;
	objProducto->setPrecio(pPrecio);

	//Agregando el producto a la lista de productos
	lst_productos->agregaFinal(objProducto);
	//Almacenar en el archivo de texto "Productos.txt"
	AgregarProductoArchivo(ARCHIVO_PRODUCTOS, objProducto);
}

void RegistrarVendedor()
{
	//Declarando las Variables temporales
	CVendedor* objVendedor = new CVendedor();
	string pCodVendedor, pNombres, pApellidos, pCargo, pArea;

	//Registrando el vendedor
	cout << "\n======REGISTRAR VENDEDOR======" << endl;
	cout << "Ingrese Cod. Vendedor: "; cin >> pCodVendedor;
	objVendedor->setCodVendedor(pCodVendedor);
	cout << "Ingrese Nombres: "; cin >> pNombres;
	objVendedor->setNombres(pNombres);
	cout << "Ingrese Apellidos: "; cin >> pApellidos;
	objVendedor->setApellidos(pApellidos);
	cout << "Ingrese Cargo: "; cin >> pCargo;
	objVendedor->setCargo(pCargo);
	cout << "Ingrese Area: "; cin >> pArea;
	objVendedor->setArea(pArea);
	//Agregando el vendedor a la lista de vendedores
	lst_vendedores->agregaFinal(objVendedor);
	//Almacenar en el archivo de texto "Vendedor.txt"
	AgregarVendedorArchivo(ARCHIVO_VENDEDORES, objVendedor);
}

void RegistrarBoleta()
{
	//Declarando las Variables temporales
	CBoleta* objBoleta = new CBoleta();
	CProducto* objProducto = nullptr;
	CVendedor* objVendedor = nullptr;
	string pNroBoleta, pFecha, pCodProducto, pCodVendedor;
	int pCantidad, pStock;
	//Monto es un campo calculado, depente de la cantidad y el precio del producto
	//Registrando la Boleta
	cout << "\n======REGISTRAR BOLETA======" << endl;
	cout << "Ingrese Nro. Boleta: "; cin >> pNroBoleta;
	objBoleta->setNroBoleta(pNroBoleta);
	cout << "Ingrese Fecha: "; cin >> pFecha;
	objBoleta->setFecha(pFecha);

	//Ingresando producto existente
	cout << "Ingrese Cod. Producto: ";
	cin >> pCodProducto;
	do {
		objProducto = BuscarProducto(pCodProducto);
		if (objProducto == nullptr)
		{
			cout << "*********Producto No encontrado*********";
			ListarProductos();
			cout << "\nIngrese un Cod. producto: ";
			cin >> pCodProducto;
		}
	} while (objProducto == nullptr);
	//Mostrando el producto ingresado
	cout << objProducto->toString();
	//Ingresando la cantidad de productos a vender
	cout << "\nIngrese Cantidad: "; cin >> pCantidad;
	//Verificando cantidad debe ser menor al stock del Producto
	pStock = objProducto->getStock() - pCantidad;
	do {
		if (pStock < 0)
		{
			cout << "Cantidad debe ser menor al stock, ingrese cantidad: ";
			cin >> pCantidad;
			pStock = objProducto->getStock() - pCantidad;
		}
	} while (pStock < 0);

	objBoleta->setCantidad(pCantidad);
	//Actualizando el stock del producto
	objProducto->setStock(pStock);
	// Calculando el Monto de la boleta
	objBoleta->setMonto(objProducto->getPrecio() * pCantidad);


	objBoleta->setProducto(objProducto);
	//Ingresando vendedor existente
	cout << "Ingrese Cod. Vendedor: ";
	cin >> pCodVendedor;
	do {
		objVendedor = BuscarVendedor(pCodVendedor);
		if (objVendedor == nullptr)
		{
			cout << "Vendedor No encontrado, ingrese un Cod. Vendedor: ";
			cin >> pCodVendedor;
		}
	} while (objVendedor == nullptr);
	objBoleta->setVendedor(objVendedor);

	//Agregando el producto a la lista de productos
	lst_boletas->agregaFinal(objBoleta);
}

void ListarProductos()
{
	cout << "\n=======LISTA DE PRODUCTOS=======";
	for (int i = 0; i < lst_productos->longitud(); i++)
	{
		cout << lst_productos->obtenerPos(i)->toString();
	}
	cout << endl;
}

void ListarVendedores()
{
	cout << "\n=======LISTA DE VENDEDORES=======" << endl;
	for (int i = 0; i < lst_vendedores->longitud(); i++)
	{
		cout << lst_vendedores->obtenerPos(i)->toString();
	}
	cout << endl;
}

void ListarBoletas()
{
	cout << "\n=======LISTA DE BOLETAS=======" << endl;
	for (int i = 0; i < lst_boletas->longitud(); i++)
	{
		cout << "BOLETAS NRO: " << i <<": " << endl;
		cout << lst_boletas->obtenerPos(i)->toString();
	}
	cout << endl;
}

inline CVendedor* SolicitarVendedor() {
	cout << "Ingrese Cod. Vendedor: ";
	string cod; cin >> cod;
	return BuscarVendedor(cod);
}

void GuardarProductosArchivoCompleto(string nombreArchivo, Lista<CProducto*>* lista) {
	ofstream archivo(nombreArchivo, ios::trunc); // reescribe todo
	if (!archivo.is_open()) {
		cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
		return;
	}
	for (int i = 0; i < lista->longitud(); ++i) {
		CProducto* p = lista->obtenerPos(i);
		if (!p) continue;
		if (i > 0) archivo << '\n';
		archivo << p->getCodProducto() << " "
			<< p->getProducto() << " "
			<< p->getStock() << " "
			<< p->getPrecio();
	}
	archivo.close();
}

void EditarProducto(const CVendedor* vendedor) {
	if (!vendedor) { cout << "Acceso denegado.\n"; return; }
	cout << "\n=== EDITAR PRODUCTO (Solo Vendedor) ===\n";
	cout << "Cod. Producto a editar: ";
	string code; cin >> code;

	// lambda para buscar índice
	auto findIndex = [&](const string& c)->int {
		for (int i = 0; i < lst_productos->longitud(); ++i) {
			CProducto* p = lst_productos->obtenerPos(i);
			if (p && p->getCodProducto() == c) return i;
		}
		return -1;
		};
	int idx = findIndex(code);
	if (idx < 0) { cout << "No existe el producto.\n"; return; }

	CProducto* p = lst_productos->obtenerPos(idx);
	cout << "Actual: " << p->toString() << "\n";

	cout << "Campo a editar: 1)Nombre  2)Stock  3)Precio : ";
	int op; cin >> op;

	if (op == 1) {
		cout << "Nuevo nombre: ";
		string nombre; cin >> nombre;
		p->setProducto(nombre);
	}
	else if (op == 2) {
		cout << "Nuevo stock: ";
		int s; cin >> s;
		p->setStock(s);
	}
	else if (op == 3) {
		cout << "Nuevo precio: ";
		float pr; cin >> pr;
		p->setPrecio(pr);
	}
	else {
		cout << "Opción inválida.\n"; return;
	}

	// Persistir lista completa tras edición
	GuardarProductosArchivoCompleto(ARCHIVO_PRODUCTOS, lst_productos);
	cout << "Producto actualizado: " << p->toString() << "\n";
}

void EliminarProducto(const CVendedor* vendedor) {
	if (!vendedor) { cout << "Acceso denegado.\n"; return; }
	cout << "\n=== ELIMINAR PRODUCTO (Solo Vendedor) ===\n";
	cout << "Cod. Producto a eliminar: ";
	string code; cin >> code;

	// buscar índice con lambda
	int idx = -1;
	auto match = [&](CProducto* p) { return p && p->getCodProducto() == code; };
	for (int i = 0; i < lst_productos->longitud(); ++i) {
		if (match(lst_productos->obtenerPos(i))) { idx = i; break; }
	}
	if (idx < 0) { cout << "No existe el producto.\n"; return; }

	// opcional: apilar en Pila<CProducto*> para undo
	lst_productos->eliminaPos(idx); // requiere el parche en Lista<T>
	GuardarProductosArchivoCompleto(ARCHIVO_PRODUCTOS, lst_productos);
	cout << "Producto eliminado y archivo actualizado.\n";
}

void GuardarBoletaTxt(CBoleta* b, const string& nombreArchivo) {
	ofstream archivo(nombreArchivo, ios::app);
	if (!archivo.is_open()) {
		cerr << "No se pudo abrir " << nombreArchivo << endl; return;
	}
	archivo << "Nro: " << b->getNroBoleta()
		<< " | Fecha: " << b->getFecha()
		<< " | Cant: " << b->getCantidad()
		<< " | Monto: " << b->getMonto() << "\n";
	if (b->getProducto())
		archivo << "   Producto: " << b->getProducto()->getCodProducto()
		<< " - " << b->getProducto()->getProducto()
		<< " x" << b->getCantidad()
		<< " @ " << b->getProducto()->getPrecio() << "\n";
	if (b->getVendedor())
		archivo << "   Vendedor: " << b->getVendedor()->getCodVendedor()
		<< " - " << b->getVendedor()->getNombres() << " "
		<< b->getVendedor()->getApellidos() << "\n";
	archivo << "----------------------------------------\n";
	archivo.close();
}


CProducto* BuscarProducto(string pCodProducto)
{
	for (int i = 0; i < lst_productos->longitud(); i++)
	{
		if (lst_productos->obtenerPos(i)->getCodProducto() == pCodProducto)
		{
			return lst_productos->obtenerPos(i);
		}
	}
	return nullptr;
}

CVendedor* BuscarVendedor(string pCodVendedor)
{
	for (int i = 0; i < lst_vendedores->longitud(); i++)
	{
		if (lst_vendedores->obtenerPos(i)->getCodVendedor() == pCodVendedor)
		{
			return lst_vendedores->obtenerPos(i);
		}
	}
	return nullptr;
}

Lista<CProducto*>* CargarProductos(string nombreArchivo) {
	Lista<CProducto*>* lst_File_Productos = new Lista<CProducto*>();
	ifstream archivo(nombreArchivo);

	if (!archivo.is_open()) {
		cerr << " No se pudo abrir el archivo: " << nombreArchivo << endl;
		return lst_File_Productos;
	}

	string linea;
	while (getline(archivo, linea)) {
		istringstream ss(linea);
		string pCodProducto, pProducto, pStock, pPrecio;

		ss >> pCodProducto >> pProducto >> pStock >> pPrecio;

		if (!pCodProducto.empty() && !pProducto.empty() && !pStock.empty() && !pPrecio.empty()) {
			lst_File_Productos->agregaFinal(new CProducto(pCodProducto, pProducto, stoi(pStock), stof(pPrecio)));
		}
	}

	archivo.close();
	return lst_File_Productos;
}

Lista<CVendedor*>* CargarVendedores(string nombreArchivo) {
	Lista<CVendedor*>* lst_File_Vendedores = new Lista<CVendedor*>();
	ifstream archivo(nombreArchivo);

	if (!archivo.is_open()) {
		cerr << " No se pudo abrir el archivo: " << nombreArchivo << endl;
		return lst_File_Vendedores;
	}

	string linea;
	while (getline(archivo, linea)) {
		istringstream ss(linea);
		string pCodVendedor, pNombres, pApellidos, pCargo, pArea;

		ss >> pCodVendedor >> pNombres >> pApellidos >> pCargo >> pArea;

		if (!pCodVendedor.empty() && !pNombres.empty() && !pApellidos.empty() && !pCargo.empty() && !pArea.empty()) {
			lst_File_Vendedores->agregaFinal(new CVendedor(pCodVendedor, pNombres, pApellidos, pCargo, pArea));
		}
	}

	archivo.close();
	return lst_File_Vendedores;
}

void AgregarProductoArchivo(string nombreArchivo, CProducto* objProducto) {
	ofstream archivo(nombreArchivo, ios::app); // Inserta al final

	if (!archivo.is_open()) {
		cerr << "No se pudo abrir el archivo para escritura: " << nombreArchivo << endl;
		return;
	}

	archivo << endl << objProducto->getCodProducto() << " " << objProducto->getProducto() << " " 
		<< objProducto->getStock() << " " << objProducto->getPrecio();
	archivo.close();

	cout << "Producto Guardado: " << objProducto->toString() << endl;
}

void AgregarVendedorArchivo(string nombreArchivo, CVendedor* objVendedor) {
	ofstream archivo(nombreArchivo, ios::app); // Inserta al final

	if (!archivo.is_open()) {
		cerr << "No se pudo abrir el archivo para escritura: " << nombreArchivo << endl;
		return;
	}

	archivo << endl << objVendedor->getCodVendedor() << " " << objVendedor->getNombres() << " "
		<< objVendedor->getApellidos() << " " << objVendedor->getCargo() << " " << objVendedor->getArea();
	archivo.close();

	cout << "Vendedor Guardado: " << objVendedor->toString() << endl;
}

void MostrarProductosOrdenadosPorPrecio(bool asc) {
	using P = CProducto*;
	vector<P> v;
	for (int i = 0; i < lst_productos->longitud(); ++i)
		v.push_back(lst_productos->obtenerPos(i));

	// comparador con lambda
	auto cmp = [&](const P& a, const P& b) {
		return asc ? (a->getPrecio() < b->getPrecio())
			: (a->getPrecio() > b->getPrecio());
		};
	mergeSort(v, cmp);

	cout << "\n=== PRODUCTOS ORDENADOS POR PRECIO (" << (asc ? "ASC" : "DESC") << ") ===\n";
	for (auto* p : v) cout << p->toString();
	cout << endl;
}


