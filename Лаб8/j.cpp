#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
const int len_n = 1000;

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	
	char n[len_n];
	char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
	
	ifstream file;
	ofstream file_new;
	
	file.open("text_old.txt");
	file_new.open("text_new.txt");
	if ((!file.is_open()) && (!file_new.is_open())) {
		cout << "### File opening error ###" << endl;
	} else {
		cout << "### File is opening! ###" << endl;
		cout << "### Before: " << endl;
		while (!file.eof()) {
			file.getline(n, len_n);
			cout << n << endl;
		}
		
		file.clear();
		file.seekg(0, file.beg);
		system("pause");
		system("cls");
		cout << "### After: " << endl;
			
		while (!file.eof()) {
			file.getline(n, len_n);
			for (int i = 0; i < strlen(n); i++) {
				for (int j = 0; j < 6; j++) {
					if (n[i] == vowels[j]) n[i] -= 32;
				}
	 		}
			cout << n << endl;
			file_new << n << '\n';
		}
	}
	
	file.close();
	file_new.close();
	
	system("pause");
	system("cls");
	cout << "### File file_new was created with modified content ###" << endl;
	system("pause");
	return 0;
}