#pragma once

#ifndef NARY_TREE_H
#define NARY_TREE_H

#include <vector>;
#include <iostream>;


struct NaryNode
{
	int data;


	std::vector< NaryNode*> children;//vector dinamico para n cantidad de hijos
	/*Node* left;
	Node* right;*/
	NaryNode(int valor);
	~NaryNode();

};


class NaryTree
{


private:
	NaryNode* root;
	

	void preorden(NaryNode* node);
	//void inorden(NaryNode* node);
	//void postorden(NaryNode* node);

	void destroyNaryTree(NaryNode* node);
	//preorden : Arbol - N->nada(Salida pantalla)
	//inorden : Arbol - N->nada(Salida pantalla)
	//postorden : Arbol - N->nada(Salida pantalla)

public:
	NaryTree(int rootVal);//Constructor
	~NaryTree();//Destrutor

	NaryNode* getRoot();

	bool addChild(NaryNode* parent, int val);


	//void insert(int val);
	//Metodos auxiliares
	void preordenAuxiliar();
	//void inordenAuxiliar();
	//void postordenAuxiliar();
};


#endif // !BINARY_TREE_H
