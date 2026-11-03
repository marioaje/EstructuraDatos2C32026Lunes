#include <iostream>
#include "arborojonegro.h"

ArbolRojoNegro::ArbolRojoNegro() {
	root = nullptr;
}

ArbolRojoNegro::~ArbolRojoNegro() {
	liberar(root);
}

void ArbolRojoNegro::liberar(NodeRN* nodo) {
	if (nodo == nullptr) {
		return;

	}

	liberar(nodo->derecha);
	liberar(nodo->izquierda);

	delete nodo;
}


NodeRN* ArbolRojoNegro::crearNodo(int valor) {
	NodeRN* nuevoNodo = new NodeRN();

	nuevoNodo->valor = valor;
	nuevoNodo->rojo = true; // Nuevo nodo es rojo por defecto

	nuevoNodo->izquierda = nullptr;
	nuevoNodo->derecha = nullptr;
	nuevoNodo->padre = nullptr;
	return nuevoNodo;

}

void ArbolRojoNegro::insert(int valor) {
	NodeRN* nuevoNodo = crearNodo(valor);

	NodeRN* actual = root;

	NodeRN* padre = nullptr;


	//Buscar donde insertamos el nuevo nodo

	while (actual != nullptr) {
		padre = actual;

		if (valor < actual->valor)
		{
			actual = actual->izquierda;
		}

		else if (valor > actual->valor)
		{
			actual = actual->derecha;
		}
		else {
			std::cout << "Valor duplicado: " << valor << std::endl;
			delete nuevoNodo;
			return;
		}

	}


	nuevoNodo->padre = padre;


	if (padre == nullptr) {
		root = nuevoNodo;
	}
	else if (valor < padre->valor) {
		padre->izquierda = nuevoNodo;
	}
	else {
		padre->derecha = nuevoNodo;
	}

	corregirInsercion(nuevoNodo)	;

}


void ArbolRojoNegro::rotarIzquierda(NodeRN * nodo) {

	NodeRN* derecho = nodo->derecha;

	nodo->derecha = derecho->izquierda;

	if (derecho->izquierda != nullptr) {
		derecho->izquierda->padre = nodo;
	}
	derecho->padre = nodo->padre;

	if (nodo->padre == nullptr) {
		root = derecho;
	}
	
	else if (nodo == nodo->padre->izquierda) {
		nodo->padre->izquierda = derecho;
	}
	else {
		nodo->padre->derecha = derecho;
	}

	derecho->izquierda = nodo;
	nodo->padre = derecho;


}


void ArbolRojoNegro::rotarDerecha(NodeRN* nodo) {

	NodeRN* izquierda = nodo->izquierda;

	nodo->izquierda = izquierda->derecha;

	if (izquierda->derecha != nullptr) {
		izquierda->derecha->padre = nodo;
	}
	izquierda->padre = nodo->padre;

	if (nodo->padre == nullptr) {
		root = izquierda;
	}

	else if (nodo == nodo->padre->izquierda) {
		nodo->padre->izquierda = izquierda;
	}
	else {
		nodo->padre->derecha = izquierda;
	}

	izquierda->derecha = nodo;
	nodo->padre = izquierda;


}
