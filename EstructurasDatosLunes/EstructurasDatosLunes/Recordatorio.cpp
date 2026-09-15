
#include <iostream>
#include "profesor.h"

int main() {
	std::cout << "Recordatorio de Arreglo\n";
	//Los arreglos
	int numeros[6];


	numeros[0] = 10;
	numeros[1] = 20;
	numeros[2] = 30;
	numeros[3] = 10;
	numeros[4] = 10;
	numeros[5] = 10;

	/*94... sin hacer nada*/

	std::cout << "datos del arreglo: " << numeros[0] << std::endl;


	//Accesos de punteros

	int numeroVariable = 100;
	std::cout << "numeroVariable: " << numeroVariable << std::endl;


	//Los punteros son  variables que almacenan direcciones de memoria
	int* punteroNumero = &numeroVariable;//& acceso a la memoria direccion
	std::cout << "punteroNumero: " << punteroNumero << std::endl;

	//numeroVariable = 3000;
	*punteroNumero = 3000;
	std::cout << "punteroNumero = 3000: " << numeroVariable << std::endl;
	std::cout << "punteroNumero: " << punteroNumero << std::endl;


	Profesor profesorEstructura;
	profesorEstructura.edad = 30;
	profesorEstructura.id = 1;
	profesorEstructura.salario = 1000.50;
	profesorEstructura.nombre = "Profe Mario";
}