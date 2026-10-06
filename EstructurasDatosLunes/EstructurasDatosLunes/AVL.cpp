//#pragma once
//#pragma once
////Arbol - N: nada->Arbol - N(Constructora)
////Hijos : Arbol - N->Lista(Analizadora)
////raíz : Arbol - N->entero(Analizadora)
////HijoPos : Arbol - N, entero->entero(Analizadora)
////esVacio : Arbol - N -> bool(Analizadora)
////peso : Arbol - N->entero(Analizadora)
////altura : Arbol - N->entero(Analizadora)
////preorden : Arbol - N->nada(Salida pantalla)
////inorden : Arbol - N->nada(Salida pantalla)
////postorden : Arbol - N->nada(Salida pantalla)
//
//#ifndef AVL_TREE_H
//#define AVL_TREE_H
//
//
//struct Node
//{
//	int data;
//	Node* left;
//	Node* right;
//
//	int altura;
//	//Node(int valor);
//
//};
//
//
//class AVLTree
//{
//
//
//private:
//	Node* root;
//	Node* insert(Node* node, int val);
//
//	Node* crearNodo(int valor);
//
//	int obtenerAltura(Node* node);
//	int obtenerBalance(Node* node);
//
//	Node* rotarDerecha(Node* node);
//	Node* rotarIzquierda(Node* node);
//
//
//	void preorden(Node* node);
//	void inorden(Node* node);
//	void postorden(Node* node);
//
//	void destroyBinaryTree(Node* node);
//	//preorden : Arbol - N->nada(Salida pantalla)
//	//inorden : Arbol - N->nada(Salida pantalla)
//	//postorden : Arbol - N->nada(Salida pantalla)
//
//public:
//	AVLTree();//Constructor
//	~AVLTree();//Destrutor
//
//	void insert(int val);
//	void preordenAuxiliar();
//	void inordenAuxiliar();
//	void postordenAuxiliar();
//};
//
//
//#endif // !AVL_TREE_H


#include <iostream>
#include "avl.h"


Node* AVLTree::crearNodo(int val) {
		Node* newNode = new Node;
		newNode->data = val;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->altura = 1; // Altura inicial de un nodo recién creado es 1

		return newNode;
}

//Node::Node(int valor)
//{
//	data = valor;
//	left = nullptr;
//	right = nullptr;
//}


AVLTree::AVLTree()//Constructor
{
	root = nullptr;
}


AVLTree::~AVLTree() {
	destroyBinaryTree(root);
}


void AVLTree::destroyBinaryTree(Node* node) {
	if (node != nullptr) {
		destroyBinaryTree(node->left);
		destroyBinaryTree(node->right);
		delete node;
	}
}


Node* AVLTree::rotarDerecha(Node* nodeIzquierdo) {


	Node* nodeDerecho = nodeIzquierdo->left;
	Node* nodeTemportal = nodeDerecho->right;

	//La rotación

	nodeDerecho->right = nodeIzquierdo;
	nodeDerecho->left = nodeTemportal;

	//Actualizar la altura
	
	nodeIzquierdo->altura = 1 + std::max(obtenerAltura(nodeIzquierdo->left), obtenerAltura(nodeIzquierdo->right));
	nodeDerecho->altura = 1 + std::max(obtenerAltura(nodeDerecho->left), obtenerAltura(nodeDerecho->right));

	//Node* rotarDerecha(Node * node);
	//Node* rotarIzquierda(Node * node);

	return nodeDerecho;
}



Node* AVLTree::rotarIzquierda(Node* nodeDerecho) {


	Node* nodeIzquierdo = nodeDerecho->right;
	Node* nodeTemportal = nodeIzquierdo->left;
	/*Node* nodeDerecho = nodeIzquierdo->left;
	Node* nodeTemportal = nodeDerecho->right;*/

	//La rotación

	nodeIzquierdo->left = nodeDerecho;
	nodeDerecho->right = nodeTemportal;

	/*nodeDerecho->right = nodeIzquierdo;
	nodeDerecho->left = nodeTemportal;*/

	//Actualizar la altura

	nodeDerecho->altura = 1 + std::max(obtenerAltura(nodeDerecho->left), obtenerAltura(nodeDerecho->right));
	nodeIzquierdo->altura = 1 + std::max(obtenerAltura(nodeIzquierdo->left), obtenerAltura(nodeIzquierdo->right));
	

	//Node* rotarDerecha(Node * node);
	//Node* rotarIzquierda(Node * node);

	return nodeIzquierdo;
}


int AVLTree::obtenerAltura(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	return node->altura;
}


int AVLTree::obtenerBalance(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	return obtenerAltura(node->left) - obtenerAltura(node->right);
}







//???
void AVLTree::insert(int val) {
	root = insert(root, val);
}

Node* AVLTree::insert(Node* node, int val) {
	if (node == nullptr) {
		return crearNodo(val);
	}

	if (val < node->data) {
		node->left = insert(node->left, val);
	}

	else if (val > node->data) {
		node->right = insert(node->right, val);
	}

	else {
		std::cout << "Valor duplicado: " << val << std::endl;
		return node; // No se permiten valores duplicados

	}

	//actyualizar altura


	node->altura = 1 + std::max(obtenerAltura(node->left), obtenerAltura(node->right));


	///calcular el balance del nodo actual

	int balance = obtenerBalance(node);


	//Caso 1 izquierda izquierda
	if (balance > 1 && val < node->left->data) {
		return rotarDerecha(node);
	}

	//Caso 2 derecha derecha
	if (balance < -1 && val > node->right->data) {
		return rotarIzquierda(node);
	}

	//Caso 3 izquierda derecha
	if (balance > 1 && val > node->left->data) {

		node->left = rotarIzquierda(node->left);

		return rotarDerecha(node);
	}

	//Caso 4 derecha izquierda
	if (balance < -1 && val < node->right->data) {


		node->right = rotarDerecha(node->right);

		return rotarIzquierda(node);
	}



	return node;


}


void AVLTree::preordenAuxiliar() {
	preorden(root);
	std::cout << std::endl;
}

void AVLTree::preorden(Node* node) {

	if (node != nullptr) {
		std::cout << node->data << " ";//Primero raiz
		preorden(node->left);//Luego izquierda
		preorden(node->right);//Luego derecha
	}
}



void AVLTree::inordenAuxiliar() {
	inorden(root);
	std::cout << std::endl;
}

void AVLTree::inorden(Node* node) {

	if (node != nullptr) {
		inorden(node->left);//Luego izquierda

		std::cout << node->data << " ";//Primero raiz

		inorden(node->right);//Luego derecha
	}
}




void AVLTree::postordenAuxiliar() {
	postorden(root);
	std::cout << std::endl;
}

void AVLTree::postorden(Node* node) {

	if (node != nullptr) {
		postorden(node->left);//Luego izquierda

		postorden(node->right);//Luego derecha

		std::cout << node->data << " ";//Primero raiz
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