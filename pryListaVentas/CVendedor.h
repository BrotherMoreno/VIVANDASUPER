#include <iostream>
using namespace std;
class CVendedor
{
private:
	//Propiedades o Atributos
	string aCodVendedor;
	string aNombres;
	string aApellidos;
	string aCargo;
	string aArea;
public:
	//Constructores y Destructores
	CVendedor()
	{
		this->aCodVendedor = "";
		this->aNombres = "";
		this->aApellidos = "";
		this->aCargo = "";
		this->aArea = "";
	}
	CVendedor(string pCodVendedor, string pNombres, string pApellidos, string pCargo, string pArea)
	{
		this->aCodVendedor = pCodVendedor;
		this->aNombres = pNombres;
		this->aApellidos = pApellidos;
		this->aCargo = pCargo;
		this->aArea = pArea;
	}
	~CVendedor() {}

	//Metodos Setter/Getter
	//SET
	void setCodVendedor(string pCodVendedor) { this->aCodVendedor = pCodVendedor; }
	void setNombres(string pNombres) { this->aNombres = pNombres; }
	void setApellidos(string pApellidos) { this->aApellidos = pApellidos; }
	void setCargo(string pCargo) { this->aCargo = pCargo; }
	void setArea(string pArea) { this->aArea = pArea; }
	//GET
	string getCodVendedor() { return this->aCodVendedor; }
	string getNombres() { return this->aNombres; }
	string getApellidos() { return this->aApellidos; }
	string getCargo() { return this->aCargo; }
	string getArea() { return this->aArea; }

	//Metodos de Servicio
	string toString()
	{
		string cadena = "\nCod. Vendedor: " + aCodVendedor +
			" Nombres: " + aNombres +
			" Apellidos: " + aApellidos +
			" Cargo: " + aCargo +
			" Area: " + aArea;
		return cadena;
	}
	
};
