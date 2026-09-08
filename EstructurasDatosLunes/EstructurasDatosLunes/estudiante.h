#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

struct Estudiante
{
	int id;
	char nombre[30];
	int edad;
	float promedio;
};

//Seccion de funciones
void ingresarEstudiante(struct Estudiante* e);
//
void mostrarEstudiante(struct Estudiante e);

void actualizarEstudiante(struct Estudiante* e);


#endif // !ESTUDIANTE_H



