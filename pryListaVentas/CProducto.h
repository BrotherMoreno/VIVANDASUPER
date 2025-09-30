#include <iostream>
#include <string>
using namespace std;
class CProducto
{
private:
	//Propiedades o Atributos
	string aCodProducto;
	string aProducto;
	int aStock;
	float aPrecio;
public:
	//Constructores y Destructores
	CProducto()
	{
		this->aCodProducto = "";
		this->aProducto = "";
		this->aStock = 0;
		this->aPrecio = 0;
	}
	CProducto(string pCodProducto, string pProducto, int pStock, float pPrecio)
	{
		this->aCodProducto = pCodProducto;
		this->aProducto = pProducto;
		this->aStock = pStock;
		this->aPrecio = pPrecio;
	}
	~CProducto() {}

	//Métodos Setter/Getter
	//SET
	void setCodProducto(string pCodProducto) { this->aCodProducto = pCodProducto; }
	void setProducto(string pProducto) { this->aProducto = pProducto; }
	void setStock(int pStock) { this->aStock = pStock; }
	void setPrecio(float pPrecio) { this->aPrecio = pPrecio; }
	//GET
	string getCodProducto() { return this->aCodProducto; }
	string getProducto() { return this->aProducto; }
	int getStock() { return this->aStock; }
	float getPrecio() { return this->aPrecio; }

	//Métodos de Servicio
	string toString()
	{
		string cadena = "\nCod. Producto: " + aCodProducto +
			" Producto: " + aProducto +
			" Stock: " + to_string(aStock) +
			" Precio: " + to_string(aPrecio);
		return cadena;
	}

	
};
