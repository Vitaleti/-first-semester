#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	// Инициализация и ввод переменных
	float a, b, x, z;
	cout << "Введите параметр a: ";
	cin >> a;
	cout << "Введите параметр b: ";
	cin >> b;
	cout << "Введите параметр x: ";
	cin >> x;
	// Вычисление и вывод z
	if (x <= a) {
		z = exp(x) - sin(x);
		cout << "Значение параметра z равно: " << z << endl;
	} else if (x > a && x < b) {
		z = tan(x) * pow(x, 2);
		cout << "Значение параметра z равно: " << z << endl;
	} else if (x >= b) {
		z = pow(x, 7) + abs(x);
		cout << "Значение параметра z равно: " << z << endl;
	}
	
	return 0;
}