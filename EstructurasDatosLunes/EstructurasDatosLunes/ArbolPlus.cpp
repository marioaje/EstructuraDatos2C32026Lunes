#include <iostream>
#include "arbolplus.h"


ArbolPlus::ArbolPlus() {
	root = nullptr;
}

NodeBPlus* ArbolPlus::ArbolPlus::crearNodo(bool esHoja) {
	NodeBPlus* nuevo = new NodeBPlus;

	nuevo->cantidad = 0;

	nuevo->esHoja = esHoja;

	nuevo->siguiente = nullptr;


	for (int i = 0; i < MAX_CLAVES; i++)
	{
		nuevo->hijos[i] = nullptr;
	}
	return nuevo;

}


//Insertamos las hojas ordenamente
void ArbolPlus::insertEnHoja(NodeBPlus* nodeHoja, int val) {
	int i = nodeHoja->cantidad - 1;

	while (i >= 0 && nodeHoja->claves[i] > val) {
		nodeHoja->claves[i + 1] = nodeHoja->claves[i];
		i--;
	}

	nodeHoja->claves[i + 1] = val;
	nodeHoja->cantidad++;
}


void ArbolPlus::insert(int valor) {
	//Vaidamos si esa vacio
	if (root == nullptr) {
		root = crearNodo(true);
		insertEnHoja(root, valor);

		return;
	}


	if (root->esHoja) {
		//Verificamos espacio en la hoja;
		if (root->cantidad < MAX_CLAVES) {
			insertEnHoja(root, valor);
			return;
		}

		//La raiz este llena, entonces divide y guarda


		NodeBPlus* izquierda = crearNodo(true);
		NodeBPlus* derecha = crearNodo(true);

		izquierda->claves[0] = root->claves[0];
		izquierda->cantidad = 1;


		derecha->claves[0] = root->claves[1];//Valores 
		derecha->claves[1] = root->claves[2];//Valores 

		//Interconecte las hojas
		izquierda->siguiente = derecha;
		//Creamos una nueva raiz.
		NodeBPlus* nuevaRaiz = crearNodo(false);

		nuevaRaiz->claves[0] = derecha->claves[0];
		nuevaRaiz->cantidad = 1;

		nuevaRaiz->hijos[0] = izquierda;
		nuevaRaiz->hijos[1] = derecha;

		delete root;

		root = nuevaRaiz;

		return;
	}
	std::cout << "La siguiente etapa de acceso a los splits" << std::endl;



}



void ArbolPlus::mostrarArbol() {
	if (root == nullptr) {
		std::cout << "El arbol esta vacio" << std::endl;
		return;
	}
	/*else {
		std::cout << "El arbol no esta vacio" << std::endl;
		return;
	}*/

	NodeBPlus* actual = root;


	//if (node != nullptr) { -1
	//	inorden(node->left);//Luego izquierda

	//	std::cout << node->data << " ";//Primero raiz

	//	inorden(node->right);//Luego derecha
	//}
	// 
	//Buscar en la hoja que este mas la izquierda
	while (!actual->esHoja) {
		actual = actual->hijos[0];
	}
	//std::cout << "El arbol esta vacio" << std::endl;
	std::cout << "El valor de la hoja: ";

	while (actual != nullptr) {
		std::cout << " [ ";

		for (int  i = 0; i < actual->cantidad; i++)
		{
			std::cout << actual->claves[i];

			if (i < actual->cantidad - 1) {
				std::cout << " ||| ";
			}
		}
		std::cout << " ] ";

		actual = actual->siguiente;
		if (actual != nullptr) {
			std::cout << " -> ";
		}

		std::cout << " " << std::endl;

	}


}