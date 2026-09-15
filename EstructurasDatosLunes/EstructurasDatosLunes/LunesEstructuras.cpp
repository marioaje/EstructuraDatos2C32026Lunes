//
//#include <iostream>
//#include "estudiante.h"
//
//
//
//
//int main() {
//
//	std::cout << "Programa para gestionar informacion de estudiantes\n";
//
//	struct Estudiante estudiante[3];
//
//	//Insercion de datos
//
//
//	for (size_t i = 0; i < 3; i++)
//	{
//		printf("--------------------------\n");
//		printf("Ingrese la informacion del estudiante \n");
//
//		ingresarEstudiante(&estudiante[i]);
//
//		printf("--------------------------\n");
//	}
//
//
//	for (size_t i = 0; i < 3; i++)
//	{
//		printf("--------------------------\n");
//		mostrarEstudiante(	estudiante[i]);
//
//		printf("--------------------------\n");
//	}
//
//
//		printf("Actualizar informacion del estudiante \n");
//		actualizarEstudiante(&estudiante[2]);
//
//		printf("--------------------------\n");
//
//
//
//
//
//
//	for (size_t i = 0; i < 3; i++)
//	{
//		printf("--------------------------\n");
//		mostrarEstudiante(estudiante[i]);
//
//		printf("--------------------------\n");
//	}
//
//	return 0;
//
//
//}
//
//
////#pragma once
//
////
////📝 Enunciado
////
////Una universidad desea desarrollar un programa sencillo en lenguaje C para gestionar información básica de estudiantes.
////Cada estudiante debe almacenar :
////
////Un ID(entero)
////
////Un nombre(cadena de caracteres)
////
////Una edad(entero)
////
////Un promedio(decimal)
////
////El programa deberá permitir registrar varios estudiantes y mostrar su información utilizando punteros y funciones.
////📋 Requisitos
////
////El programa debe cumplir con lo siguiente :
////
////Definir una estructura llamada Estudiante que contenga :
////
////int id
////
////char nombre[30]
////
////int edad
////
////float promedio
////
////Crear un arreglo para almacenar hasta 3 estudiantes.
////
////Implementar las siguientes funciones :
////
////void ingresarEstudiante(struct Estudiante* e);
////
////void mostrarEstudiante(struct Estudiante e);
////
////En la función main :
////
////Solicitar al usuario los datos de cada estudiante.
////
////Almacenar la información en el arreglo.
////
////Actualizar la información en el arreglo.
////
////Mostrar la información completa de todos los estudiantes registrados.
////
////El acceso a los campos de la estructura debe realizarse usando punteros en al menos una función.
////