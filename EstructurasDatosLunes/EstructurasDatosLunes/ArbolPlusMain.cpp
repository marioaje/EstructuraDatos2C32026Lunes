#include <iostream>
#include "arbolplus.h"


int main() {

	ArbolPlus tree;


	std::cout << "Arbolplus" << std::endl;


	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	//tree.insert(50);
	//tree.insert(60);
	//tree.insert(70);
	//tree.insert(80);
	//Ejemplo cargado : 10, 20, 30, 40, 50, 60, 70, 80.

	tree.mostrarArbol();

	/*std::cout << "preordenAuxiliar: " << std::endl;
	tree.preordenAuxiliar();
	std::cout << "postordenAuxiliar: " << std::endl;
	tree.postordenAuxiliar();
	std::cout << "inordenAuxiliar: " << std::endl;
	tree.inordenAuxiliar();*/

	return 0;
}