#include <iostream>
#include "BinaryTree.h"


int main() {

	BinaryTree tree;


	std::cout << "BinaryTree" ;


	tree.insert(36);
	tree.insert( 25 );
	tree.insert( 12 );
	tree.insert( 65 );
	tree.insert( 87 );
	tree.insert( 6 );
	tree.insert( 23 );
	tree.insert( 34 );
	tree.insert( 28 );
	tree.insert( 90 );
	tree.insert( 4 );
	
	std::cout << "preordenAuxiliar: ";
	tree.preordenAuxiliar();
	std::cout << "postordenAuxiliar: ";
	tree.postordenAuxiliar();
	std::cout << "inordenAuxiliar: ";
	tree.inordenAuxiliar();

	return 0;
}