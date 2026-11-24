#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <iomanip>


using namespace std;


struct Nodo {
	char caracter;
	int frecuencia;
	Nodo* izquierda;
	Nodo* derecha;


	Nodo(char c, int f) {
		caracter = c;
		frecuencia = f;
		izquierda = nullptr;
		derecha = nullptr;

	}

	Nodo(Nodo* izq, Nodo* der) {
		caracter = '\0';
		frecuencia = izq -> frecuencia + der->frecuencia;
		izquierda = izq;
		derecha = der;

	}

	bool esHoja() {
		return izquierda == nullptr && derecha == nullptr;
	}


};
//Para revisar la cola de prioridad
struct Comparador
{
	bool operator()(Nodo* a, Nodo* b) {
		return a->frecuencia > b->frecuencia;
	}
};

Nodo* construirArbol(map <char, int>& frecuencias) {
	priority_queue < Nodo*, vector<Nodo*>, Comparador > cola;


	for (auto par : frecuencias) {
		cola.push(new Nodo(par.first, par.second));
	}

	if (cola.empty()) {
		return nullptr;
	}

	while (cola.size() > 1) {
		Nodo* izquerda = cola.top();
		cola.pop();

		Nodo* derecha = cola.top();
		cola.pop();

		Nodo* padre = new Nodo(izquerda, derecha);

		cola.push(padre);


	}

	return cola.top();



}


void generarCodigos(Nodo* raiz, string codigo, map <char, string>& codigos) {
	if (raiz == nullptr) {
		return;
	}

	if (raiz->esHoja()) {
		codigos[raiz->caracter] = codigo.empty() ? "0" : codigo;
		return;
	}

	generarCodigos(raiz->izquierda, codigo + '0', codigos);
	generarCodigos(raiz->derecha, codigo + '1', codigos);

}

//Comprimir texto
string comprimir(string texto, map <char, string>& codigo) {
	string resultado = "";
	for (char c : texto) {
		resultado += codigo[c];
	}

	return resultado;
}


string descomprimir(string binario, Nodo* raiz) {
	string resultado = "";
	if (raiz == nullptr) {
		return resultado;
	}

	if (raiz->esHoja()) {
		return string(binario.size(), raiz->caracter);
	}


	Nodo* actual = raiz;

	for (char bit : binario) {
		if (bit == '0')
			actual = actual->izquierda;
		else
			actual = actual->derecha;


		if (actual->esHoja()) {
			resultado += actual->caracter;
			actual = raiz;
		}



	}

	return resultado;


}

void liberArbol(Nodo* raiz) {
	if (raiz == nullptr)
		return;

	liberArbol(raiz->izquierda);
	liberArbol(raiz->derecha);
	
		delete raiz;
}


int main() {
	string texto = "saludos clase";


	map <char, int> frecuencias;

	for (char c : texto) {
		frecuencias[c]++;
	}

	cout << "\nTABLA DE FRECUENCIAS\n";



	for ( auto par : frecuencias)
	{
		cout << par.first << " : "
			<< par.second << endl;
	}


	Nodo* raiz = construirArbol(frecuencias);
	map <char, string> codigos;

	generarCodigos(raiz, "", codigos);
	cout << "\nCODIGO HUFFMAN\n";

	for (auto par : codigos)
	{
		cout << par.first << " : "
			<< par.second << endl;
	}

	string comprimido = comprimir(texto, codigos);

	cout << "\TEXTO ORIGINAL:\n";
	cout << texto << endl;

	cout << "\TEXTO COMPRIMIDO:\n";
	cout << comprimido << endl;

	string recuperado = descomprimir(comprimido, raiz);
	cout << "\TEXTO DESCOMPRIMIDO:\n";
	cout << recuperado << endl;


	int bitOriginales = texto.size() * 8;
	int bitComprimidos = comprimido.size();


	double ahorro = 100.0 * (1.0 - (double)bitComprimidos / bitOriginales);

	cout << "\ESTADISTICA:\n";

	cout << "Bits Originales: " << bitOriginales << endl;
	cout << "Bits Huffman: " << bitComprimidos << endl;

	cout << "Ahorro: " << ahorro << "%" << endl;

	cout << "Verificacion: " << (texto == recuperado ? "CORRECTA" : "INCORRECTA") << endl;

	liberArbol(raiz);

	return 0;

}