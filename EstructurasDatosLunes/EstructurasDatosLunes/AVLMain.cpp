#include <iostream>
#include "avl.h"


int main() {

	AVLTree tree;


	std::cout << "AVLTree" << std::endl;


	tree.insert(10);
	tree.insert( 20 );
	tree.insert( 30 );
	tree.insert( 40 );
	tree.insert( 50 );
	tree.insert( 60 );
	tree.insert( 70 );
	
	std::cout << "preordenAuxiliar: " << std::endl;
	tree.preordenAuxiliar();
	std::cout << "postordenAuxiliar: " << std::endl;
	tree.postordenAuxiliar();
	std::cout << "inordenAuxiliar: " << std::endl;
	tree.inordenAuxiliar();

	return 0;
}