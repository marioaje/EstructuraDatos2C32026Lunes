
const int MAX_CLAVES = 3;//Maximo de insercciones node

struct NodeBPlus
{
	int claves[MAX_CLAVES + 1];

	NodeBPlus* hijos[MAX_CLAVES + 2];

	int cantidad;
	bool esHoja;


	NodeBPlus* siguiente;

};


class ArbolPlus
{


private:
	NodeBPlus* root;

	NodeBPlus* crearNodo(bool esHoja);

	void insertEnHoja(NodeBPlus* node, int val);

	void dividirEnHoja(NodeBPlus* node, int val);



public:

	ArbolPlus();

	void insert(int val);

	void mostrarArbol();
	
};



