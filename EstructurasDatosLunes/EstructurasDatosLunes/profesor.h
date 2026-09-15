#pragma once
//Funcione como los includes o libreiras analogia

#ifndef PROFESOR_H
#define PROFESOR_H
//La estructura de datos, solo va agrupas los datos
struct Profesor
{
	int id;
	char nombre[50];
	int edad;
	float salario;
};
//las funcions que son para hacer algo con la estructura de datos 

void ingresarProfesor(Profesor* profesor);
void mostrarProfesor(Profesor profesor);


#endif // !PROFESOR_H
