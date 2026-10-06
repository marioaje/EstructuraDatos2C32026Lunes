#pragma once
#pragma once
//Arbol - N: nada->Arbol - N(Constructora)
//Hijos : Arbol - N->Lista(Analizadora)
//raíz : Arbol - N->entero(Analizadora)
//HijoPos : Arbol - N, entero->entero(Analizadora)
//esVacio : Arbol - N -> bool(Analizadora)
//peso : Arbol - N->entero(Analizadora)
//altura : Arbol - N->entero(Analizadora)
//preorden : Arbol - N->nada(Salida pantalla)
//inorden : Arbol - N->nada(Salida pantalla)
//postorden : Arbol - N->nada(Salida pantalla)

#ifndef AVL_TREE_H
#define AVL_TREE_H


struct Node
{
	int data;
	Node* left;
	Node* right;

	int altura;
	//Node(int valor);

};


class AVLTree
{


private:
	Node* root;
	Node* insert(Node* node, int val);

	Node* crearNodo(int valor);

	int obtenerAltura(Node* node);
	int obtenerBalance(Node* node);

	Node* rotarDerecha(Node* node);
	Node* rotarIzquierda(Node* node);


	void preorden(Node* node);
	void inorden(Node* node);
	void postorden(Node* node);

	void destroyBinaryTree(Node* node);
	//preorden : Arbol - N->nada(Salida pantalla)
	//inorden : Arbol - N->nada(Salida pantalla)
	//postorden : Arbol - N->nada(Salida pantalla)

public:
	AVLTree();//Constructor
	~AVLTree();//Destrutor

	void insert(int val);
	void preordenAuxiliar();
	void inordenAuxiliar();
	void postordenAuxiliar();
};


#endif // !AVL_TREE_H
