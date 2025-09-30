#include <iostream>
#include "CProducto.h"
#include "CVendedor.h"
using namespace std;
class CBoleta
{
private:
	//Propiedades y atributos
	string aNroBoleta;
	string aFecha;
	int aCantidad;
	float aMonto;
	CProducto* aProducto;
	CVendedor* aVendedor;
public:
	//Constructores y Destructores
	CBoleta()
	{
		this->aNroBoleta = "";
		this->aFecha = "";
		this->aCantidad= 0;
		this->aMonto = 0;
		this->aProducto = nullptr;
		this->aVendedor = nullptr;
	}

	CBoleta(string pNroBoleta, string pFecha, int pCantidad,
		CProducto* pProducto, CVendedor* pVendedor)
	{
		this->aNroBoleta = pNroBoleta;
		this->aFecha = pFecha;
		this->aCantidad = pCantidad;
		this->aProducto = pProducto;
		this->aVendedor = pVendedor;
	}
	~CBoleta(){}

	//Métodos Setter y Getter
	//SET
	void setNroBoleta(string pNroBoleta) { this->aNroBoleta = pNroBoleta; }
	void setFecha(string pFecha) { this->aFecha = pFecha; }
	void setCantidad(int pCantidad) { this->aCantidad= pCantidad; }
	void setMonto(int pMonto) { this->aMonto = pMonto; }
	void setProducto(CProducto* pProducto) { this->aProducto= pProducto; }
	void setVendedor(CVendedor* pVendedor) { this->aVendedor = pVendedor; }

	//GET
	string getNroBoleta() { return this->aNroBoleta; }
	string getFecha() { return this->aFecha; }
	int getCantidad() { return this->aCantidad; }
	float getMonto() { return this->aMonto; }
	CProducto* getProducto() { return this->aProducto; }
	CVendedor* getVendedor() { return this->aVendedor; }

	//Métodos de Servicio
	string toString()
	{
		string cadena = "Nro. Boleta: " + aNroBoleta +
			" Fecha: " + aFecha +
			" Candidad: " + to_string(aCantidad)+
			" Monto: "+ to_string(aMonto);
		cadena += aProducto->toString();
		cadena += aVendedor->toString();
		return cadena;
	}

};
