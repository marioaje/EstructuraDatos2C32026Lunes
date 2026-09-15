
#include <iostream>
#include "profesor.h"
#include <cstring>
#include "listas.h"

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
//	profesorEstructura.nombre = "Profe Mario";//?? el tipo de dato nos da el error
	strcpy_s(profesorEstructura.nombre, "Profe Mario");//?? el tipo de dato nos da el error
	//String (Clase) nombre.Upper() a string tipo de dato
	// //varchar o nvarchar(100) o TEXT
	//7*100
	///"Profe Mario"
	//nombre[50] =
	//"P","r","o","f","e"," ","M","a","r","i","o","","","","","","","","","","","","","","","","","","","","",""

	//Necesito corregir el problema del arreglo	int numeros[100];
	// //int numeros[]
	//0,1,2,3,4,5,6,7,8,9,0,11,21,121,23,4,5,6,7,8,9,//algo dinamico
	//Listas???
	//Memoria dinamica
	Nodo* nodoListas = new Nodo();
	nodoListas->dato = 10;
	nodoListas->siguiente = nullptr;

	return 0;
}