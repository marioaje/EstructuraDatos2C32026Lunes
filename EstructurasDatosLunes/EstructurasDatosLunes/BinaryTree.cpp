#include <iostream>
#include "BinaryTree.h"


Node::Node(int valor)
{
	 data = valor;
	 left = nullptr;
	 right = nullptr;
}


BinaryTree::BinaryTree()//Constructor
{
	root = nullptr;
}


//???
void BinaryTree::insert(int val) {
	root = insert(root, val);
}

Node* BinaryTree::insert(Node* node, int val) {
	if (node == nullptr) {
		return new Node(val);
	}

	if (val < node->data) {
		node->left = insert(node->left, val);
	}

	if (val > node->data) {
		node->right = insert(node->right, val);
	}

	return node;


}


void BinaryTree::preordenAuxiliar() {
	preorden(root);
	std::cout << std::endl;
}

void BinaryTree::preorden(Node* node) {

	if (node != nullptr) {
		std::cout << node->data << " ";//Primero raiz
		preorden(node->left);//Luego izquierda
		preorden(node->right);//Luego derecha
	}
}


//Preorden: 36, 25, 12, 6, 4, 23, 34, 28, 65, 87, 90



//~BinaryTree();//Destrutor


//
//
//struct Node
//{
//	int data;
//	Node* left;
//	Node* right;
//	Node(int valor);
//
//};

//
//BinaryTree();//Constructor
//~BinaryTree();//Destrutor
//
//void insert(int val);
//void preorden();
//void inorden();
//void postorden();
//
//private:
//	Node* root;
//	Node* insert(Node* node, int val);