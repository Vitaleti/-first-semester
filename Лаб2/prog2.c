#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	// Инициализация и ввод переменных
	float a, b, x, z;
	printf("Введите параметр а: ");
	scanf("%f", &a);
	printf("Введите параметр b: ");
	scanf("%f", &b);
	printf("Введите параметр x: ");
	scanf("%f", &x);
	// Вычисление и вывод z
	if (x <= a) {
		z = exp(x) - sin(x);
		printf("Значение параметра z равно: %g", z);
	}
	else if (x > a && x < b) {
		z = tan(x) * pow(x, 2);
		printf("Значение параметра z равно: %g", z);
	}
	else if (x >= b) {
		z = pow(x, 7) + abs(x);
		printf("Значение параметра z равно: %g", z);
	}
	
	return 0;
}