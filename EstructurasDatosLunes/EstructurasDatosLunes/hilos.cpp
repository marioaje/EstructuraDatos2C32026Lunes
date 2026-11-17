//#include <iostream>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//
//
//void proceso(int idHijo) {
//	for (int i = 0; i < 9; i++)
//	{
//		cout << "Hijo: " << idHijo << " ejecuntado en pasos: " << i << endl;
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