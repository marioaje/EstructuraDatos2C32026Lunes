#include "NaryTree.h"

///Creando el arbol
NaryNode::NaryNode(int valor) {
	data = valor;
}

NaryTree::NaryTree(int rootValor) {
	root = new NaryNode(rootValor);
}


NaryNode::~NaryNode()//Destrutor
{
	for (NaryNode* child : children) {
		delete child;
	}
}

NaryTree::~NaryTree() {
	delete root;
}


NaryNode* NaryTree::getRoot() {
	return root;
}


bool NaryTree::addChild(NaryNode* parent, int val) {
	if (parent == nullptr) {
		return false;
	}

	NaryNode* newNode = new NaryNode(val);

	parent->children.push_back(newNode);

	return true;

}


void NaryTree::preordenAuxiliar() {
	preorden(root);
	std::cout << std::endl;
}


void NaryTree::preorden(NaryNode* node) {
	if (node != nullptr) {
		std::cout << node->data << " ";

		for (NaryNode* child : node->children) {
			preorden(child);
		}

	}
}


//Preorden: 24, 13, 1, 7, 7, 61, 45, 58, 90, 88, 6, 9, 100, 7


//	bool addChild(NaryNode* parent, int val);
//
//
//	//void insert(int val);
//	//Metodos auxiliares
//	//void preordenAuxiliar();
//	//void inordenAuxiliar();
//	//void postordenAuxiliar();
//};
//
//
//#endif // !BINARY_TREE_H
