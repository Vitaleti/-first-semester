#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleOutputCP(65001);
	int N;
	cout << "input len list: "; cin >> N;
	int n[N];
	for (int i = 0; i < N; i++) {
		cout << "n[" << i << "] = ";
		cin >> n[i];
	}	
	
	for (int i = 0; i < N; i++) {
		cout << n[i] << " ";
	}
	cout << endl;
	
	int k = 2, temp;
	while (k != 0) {
		temp = n[0];
		for (int i = 0; i < N; i++) {
			n[i] = n[i+1];
		}
		n[N-1] = temp;
		k -= 1;
	}
	
		
	for (int i = 0; i < N; i++) {
		cout << n[i] << " ";
	}
	cout << endl;
	
	system("pause");
	return 0;
}