#include <stdio.h>
#include <string>
#include <fstream>
#include <windows.h>
const int len_n = 1000;

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	
	char n[len_n];
	char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
	
	FILE *file;
	FILE *file_new;
	
	file = fopen("text_old.txt", "r");
	if (file != NULL) {
		printf("### File is opening! ###\n");
		printf("### Before: \n");
		while (!feof(file)) {
			if (fgets(n, 1000, file) != NULL) {
	 			printf(n, "\n");
			}
		}
	} else {
		printf("### Opening file error! ###\n");
		return 0;
	}
	
	system("pause");
	system("cls");
	fclose(file);
	
	file = fopen("text_old.txt", "r");
	file_new = fopen("text_new.txt", "w");
	if (file != NULL) {
		printf("### After: \n");
		while (!feof(file)) {
			if (fgets(n, 1000, file) != NULL) {
				for (int i = 0; i < strlen(n); i++) {
					for (int j = 0; j < 6; j++) {
						if (n[i] == vowels[j]) n[i] -= 32;
					}
	 			}
	 			printf(n, '\n');
	 			fputs(n, file_new);
			}
		}
	} else {
		printf("### Opening file error! ###\n");
		return 0;
	}
	fclose(file);
	fclose(file_new);
	
	system("pause");
	return 0;
}