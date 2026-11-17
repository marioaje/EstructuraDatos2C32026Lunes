//#include <iostream>
//#include <thread>
//#include <chrono>
//#include <mutex>
//#include <semaphore>
//
//using namespace std;
//
//int contado = 0;
//mutex miMutex;
//
//void proceso(int idHijo) {
//	for (int i = 0; i < 9; i++)
//	{
//
//		//Inicio de la proteccion de recursos que sean compartidos
//		{
//			lock_guard<mutex> bloqueo(miMutex);
//
//			cout << "Hijo: " << idHijo << " ejecuntado en pasos: " << i << endl;
//		}
//		//Fin de la proteccion de recursos que sean compartidos
//
//		this_thread::sleep_for(chrono::milliseconds(600));
//	}
//}
//
//int main() {
//
//	proceso(4);
//	cout << "Hilos fin \n";
//	thread hilouno(proceso, 1);
//	thread hilodos(proceso, 2);
//
//	hilouno.join();
//	hilodos.join();
//
//	cout << "Todos los hilos fin \n";
//
//	return 0;
//
//}