#include <iostream>
#include <cstdlib> //administrar memoria dinamica



using namespace std;


int main() {

	int cantiades;
	int* datos;

	cout << "Ejemplo de memoria dinamica en C++ (Malloc y Free)" << endl;

	//reserva en la memoria dinamica
	cantiades = 10;
	datos = (int*)malloc(cantiades * sizeof(int));


	//Mostrar la direccion de memoria

	cout << "Direccion de memoria reservada: " << datos << endl;

	//Tamano de la memoria reservada
	cout << "Tamano de la memoria reservada: " << cantiades * sizeof(int) << " bytes" << endl;


	for (int i = 0; i < cantiades; i++)
	{
		cout << "datos [" << i << "] valor: " << datos[i] << " direccion: " << &datos << endl;
	}


	if (datos == nullptr) {
		cout << "Error al reservar memoria" << endl;
		return 1;
	}

	free(datos); //liberar memoria reservada
	datos = nullptr; //evitar dangling pointer

	//Mostrar la direccion de memoria

	cout << "Direccion de memoria reservada despues del free: " << datos << endl;

	//Tamano de la memoria reservada
	cout << "Tamano de la memoria reservada despues del free: " << cantiades * sizeof(int) << " bytes" << endl;



	if (datos == nullptr) {
		cout << "Error al reservar memoria, despues del free" << endl;
		return 1;
	}

	for (int i = 0; i < cantiades; i++)
	{
		cout << "datos [" << i << "] valor: " << datos[i] << " direccion: " << &datos << endl;
	}



	return 0;
}