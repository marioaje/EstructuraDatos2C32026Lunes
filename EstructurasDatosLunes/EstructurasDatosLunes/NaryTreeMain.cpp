#include <iostream>
#include "NaryTree.h"


int main() {
//
	NaryTree tree(24);
//
//
	std::cout << "NaryTree "  ;


	NaryNode* root = tree.getRoot();

	tree.addChild(root, 13);
	tree.addChild(root, 61);
	tree.addChild(root, 6);
	tree.addChild(root, 9);
	tree.addChild(root, 100);
	tree.addChild(root, 7);

	tree.addChild(root->children[0], 1);
	tree.addChild(root->children[0], 7);
	tree.addChild(root->children[0], 7);

	tree.addChild(root->children[1], 45);
	tree.addChild(root->children[1]->children[0], 58);
	tree.addChild(root->children[1]->children[0], 90);
	tree.addChild(root->children[1], 88);


	std::cout << "preordenAuxiliar " << std::endl;
	tree.preordenAuxiliar();

	std::cout << "postordenAuxiliar " << std::endl;
	tree.postordenAuxiliar();

//Preorden: 24, 13, 1, 7, 7, 61, 45, 58, 90, 88, 6, 9, 100, 7
//
// 
//// └── 24
//    └── 13 
//        └── 1
//        └── 7
//        └── 7
//    └── 61
//        └── 45
//            └── 58
//            └── 90
//        └── 88
//    └── 6
//    └── 9
//    └── 100
//    └── 7
// 
//
//	tree.insert(36);
//	tree.insert( 25 );
//	tree.insert( 12 );
//	tree.insert( 65 );
//	tree.insert( 87 );
//	tree.insert( 6 );
//	tree.insert( 23 );
//	tree.insert( 34 );
//	tree.insert( 28 );
//	tree.insert( 90 );
//	tree.insert( 4 );
//	
//	std::cout << "preordenAuxiliar: ";
//	tree.preordenAuxiliar();
//	std::cout << "postordenAuxiliar: ";
//	tree.postordenAuxiliar();
//	std::cout << "inordenAuxiliar: ";
//	tree.inordenAuxiliar();
//
	return 0;
}