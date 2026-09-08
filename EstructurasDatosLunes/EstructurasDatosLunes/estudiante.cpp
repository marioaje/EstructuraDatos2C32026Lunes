
#include <stdio.h>
#include <iostream>
#include "estudiante.h"

using namespace std;

//Seccion de funciones
void ingresarEstudiante(struct Estudiante* e) {
	printf("Escriba la informacion del estudiante\n");
	printf("\nIngrese el ID del estudiante: ");
	cin >> e->id;

	printf("\nIngrese el ID del nombre: ");
	cin >> e->nombre;

	printf("\nIngrese el ID del edad: ");
	cin >> e->edad;

	printf("\nIngrese el ID del promedio: ");
	cin >> e->promedio;

}
//
void mostrarEstudiante(struct Estudiante e) {

	printf("Informacion del estudiante\n");

	printf("Id: %d", e.id);
	printf("\nNombre: %s", e.nombre);
	printf("\nEdad: %d", e.edad);
	printf("\nPromedio: %.2f", e.promedio);


}

void actualizarEstudiante(struct Estudiante* e) {
	printf("actualizar el estudiante\n");

	printf("\nIngrese el ID del edad: ");
	cin >> e->edad;

}



