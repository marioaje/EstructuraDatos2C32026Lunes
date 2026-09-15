
//La clase es solo para estructuras de datos, pero con funciones que hacen algo con la estructura de datos
//Datos privados y funciones publicas + comportamientos y objeto
class ProfesorClase {
private:
	int idProfesor;
	char nombre[50];
	int edad;
	float salario;

public: 
	void depositarSalario(float monto) {
		salario += monto;
	}
};