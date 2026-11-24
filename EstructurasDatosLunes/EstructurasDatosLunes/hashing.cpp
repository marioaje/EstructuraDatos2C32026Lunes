#include <iostream>
#include <vector>
#include <list>


using namespace std;

class TablaDinamica {
private: 
	vector<list<int>> tabla;
	int capacidad;
	int cantidad;

	//Factr de carga o almacenimento
	const double FACTORMAXIMOCARGA = 0.75;

	double factorCarga() {
		return (double)cantidad / capacidad;
	}

	int fusionHashing(int calve) {
		return(calve % capacidad + capacidad) % capacidad;
	}
	//Inserta los datos sin hashing
	void insertarSinReashing(int clave) {
		int indice = fusionHashing(clave);
		tabla[indice].push_back(clave);
		cantidad++;
	}

	void resash() {
		int capacidadanterior = capacidad;

		vector<list<int>> tablaAnterior = tabla;

		capacidad = capacidad * 2;
		tabla.clear();
		tabla.resize(capacidad);

		cantidad = 0;

		cout << "Rehashing automatico \n";

		cout << "Capacidad Anterior: " << capacidadanterior << endl;
		cout << "Capacidad nueva: " << cantidad << endl;

		for (int i = 0; i < capacidadanterior; i++)
		{
			for (int clave : tablaAnterior[i]) {
				insertarSinReashing(clave);
			}
		}

	}


public:
	//Constructor
	TablaDinamica(int capacidadInicial = 5) {
		capacidad = capacidad > 0 ? capacidad : 5;

		cantidad = 0;
		tabla.resize(capacidad);

	}

	//Insertar elemenots
	void insertar(int clave) {
		int indice = fusionHashing(clave);

		//Evitar la duplicidad consultando
		for (int valor : tabla[indice]) {
			if (clave == valor) {
				cout << "***Valor duplicado: " << clave << endl;
				return;
			}
		}

		tabla[indice].push_back(clave);

		cantidad++;

		cout << "***Valor esta insertado: " << clave << ", indice:" << indice << endl;
		cout << "***El valor de carga: " << factorCarga()*100 << "%" << endl;

		if (factorCarga() > FACTORMAXIMOCARGA) {
			resash();
		}


	}


};

int main() {
	TablaDinamica hash(5);

	cout << "Hashing dinamico" << endl;
	hash.insertar(10);
	hash.insertar(21);
	hash.insertar(32);




}