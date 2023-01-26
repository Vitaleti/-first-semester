#include <stdio.h>
#include <windows.h>

int main() {
	SetConsoleOutputCP(65001);
	int N;
	printf("input len list: "); scanf("%d", &N);
	float n[N];
	for (int i = 0; i < N; i++) {
		scanf("%f", &n[i]);
	}
	
	float pro_num = 1;
	
	for (int i = 0; i < N; i++) {
		if (n[i] > 0) pro_num *= n[i];
	}
	
	printf("1)product of numbers: %.5f\n", pro_num);
	
	int min_i = 1;
	for (int i = 0; i < N; i++) {
		if (n[i] < n[min_i]) min_i = i;
	}
	
	float n_sum = 0;
	
	for (int i = 0; i < min_i; i++) {
		n_sum += n[i];
	}
	
	printf("2)sum of all elements up to 'min': %.5f\n", n_sum);
	
	float temp; int j;
	for (int i = 0; i < N; i++) {
		temp = n[i];
		if (i%2 == 0 || i == 0) {
			j = i - 2;
			while (j >= 0 && n[j] > temp) {
				n[j+2] = n[j];
				n[j] = temp;
				j -= 2;
			}
		} else {
			j = i - 2;
			while (j >= 0 && n[j] > temp) {
				n[j+2] = n[j];
				n[j] = temp;
				j -= 2;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		printf(" %.3f", n[i]);
	}

	return 0;
}