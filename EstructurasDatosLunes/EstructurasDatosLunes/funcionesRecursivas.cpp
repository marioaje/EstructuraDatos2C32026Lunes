//Escribir una función o método que calcule xy, donde e son números enteros positivos.
//Escribir una función o método que calcule, donde y son números positivos.
//Escribir una función o método que calcule, donde e son números enteros positivos, y.
//Escribir una función o método que calcule el MCD(máximo común divisor) entre dos números y
// , donde e son números enteros positivos.
int calcularPotencia(int x, int y) {

	int resultado = 1;

	for (int i = 0; i < y; i++)
	{
		resultado *= x;
	}

	return resultado;

}


int calcularPotenciaRecusiv(int x, int y) {

	if (y == 0) return 1;

	return x * calcularPotenciaRecusiv( x, y-1);

	//int resultado = 1;

	//for (int i = 0; i < y; i++)
	//{
	//	resultado *= x;
	//}

	//return resultado;

}


//Escribir una función o método que calcule, donde y son números positivos.

int calcularSumaMultiplicacion(int m, int n) {
	int resultado = 0;

	for (int i = 0; i < n; i++)
	{
		resultado += m;
	}

	return resultado;

}


int calcularSumaMultiplicacionRecursivo(int m, int n) {
	
	if (n == 0) return 0;
	
	return m + calcularSumaMultiplicacionRecursivo(m, n - 1);
	/*
	int resultado = 0;

	for (int i = 0; i < n; i++)
	{
		resultado += m;
	}

	return resultado;*/



}


