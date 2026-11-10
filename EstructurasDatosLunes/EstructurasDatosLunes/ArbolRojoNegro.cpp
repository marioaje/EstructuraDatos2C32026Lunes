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




void ArbolRojoNegro::corregirInsercion(NodeRN* nodo) {

	while (nodo != root && nodo->padre != nullptr && nodo->padre->rojo) {
	
		NodeRN* padre = nodo->padre;
		NodeRN* abuelo = padre->padre;

		if (abuelo == nullptr) {
			break; // No hay abuelo, salir del bucle
		}


		//Si el padre tiene padre ( Abulo)

		if (padre == abuelo->izquierda) {
			NodeRN* tio = abuelo->derecha;

			//caso cuando tio es rojo


			if ( tio != nullptr && tio->rojo) {
				padre->rojo = false;
				tio->rojo = false;
				abuelo->rojo = true;
				nodo = abuelo;
			}
			else {
				//caso de izquierda derecha
				if (nodo == padre->derecha) {
					nodo = padre;
					rotarIzquierda(nodo);
				}
				///izquierda izquierda
				padre->rojo = false;
				abuelo->rojo = true;
				rotarDerecha(abuelo);
			}
		}
		else {
			//caso donde son iguales el padre hacia la derecha

			NodeRN* tio = abuelo->izquierda;

			if (tio != nullptr && tio->rojo) {
				padre->rojo = false;
				tio->rojo = false;
				abuelo->rojo = true;
				nodo = abuelo;
			}
			else {
				//caso de derecha izquierda
				if (nodo == padre->izquierda) {
					nodo = padre;
					rotarDerecha(nodo);
				}
				///derecha derecha
				padre->rojo = false;
				abuelo->rojo = true;
				rotarIzquierda(abuelo);
			}

		}
	
	}

	root -> rojo = false; // Asegurarse de que la raíz sea negra

}

void ArbolRojoNegro::mostrarArbol() {
	if (root == nullptr) {
		std::cout << "El arbol esta vacio.\n";
		return;
	}
	mostrarNodo(root, 0);
}

void ArbolRojoNegro::mostrarNodo(NodeRN* nodo, int nivel) {
	if (nodo == nullptr) {
		return;
	}
	
	for (int i = 0; i < nivel; i++) {
		std::cout << "    ";
	}
	std::cout << nodo->valor << (nodo->rojo ? " (R)" : " (N)") << std::endl;
	mostrarNodo(nodo->izquierda, nivel + 1);
	mostrarNodo(nodo->derecha, nivel + 1);
}