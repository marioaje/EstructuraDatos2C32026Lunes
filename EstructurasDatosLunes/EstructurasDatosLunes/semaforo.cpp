#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <semaphore>

using namespace std;

int contado = 0;
mutex miMutex;
counting_semaphore<6> semefaro(6);

void usuarComputadora(int idEstudiante) {

		semefaro.acquire();
		//Inicio de la proteccion de recursos que sean compartidos
		{
			lock_guard<mutex> bloqueo(miMutex);

			cout << "Estudiante: " << idEstudiante << " utiliznado la pc: " << endl;
		}
		//Fin de la proteccion de recursos que sean compartidos

		this_thread::sleep_for(chrono::seconds(6));

		{
			lock_guard<mutex> bloqueo(miMutex);

			cout << "Estudiante: " << idEstudiante << " finalizo la pc: " << endl;
		}


		semefaro.release();
	
}

int main() {

	//proceso(4);
	cout << "Hilos inclusion de pc \n";

	thread estudinates[9];

	for (int i = 0; i < 9; i++)
	{
		estudinates[i] = thread(usuarComputadora, i + 1);
	}

	cout << "Inicio de los hilos inclusion de pc \n";

	for (int i = 0; i < 9; i++)
	{
		estudinates[i].join();
	}


	cout << "Todos los hilos fin \n";

	return 0;

}