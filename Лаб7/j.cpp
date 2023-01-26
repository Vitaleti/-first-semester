#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
const int k = 5;

struct student {
	int record_book;
	char lastname[15];
	char name[15];
	int number_group;
	int year_of_birth;
	int year_of_admission;
	float grade_point_average;
};

student* create_arr(int size);
void in_arr (student *arr, int size);
void out_arr (student *arr, int size);
void sort (student *arr, int size);
void del_arr (student *arr);
void oldest (student *arr, int size);

int main() {
	int size;
	cout << "Enter the number of studets: ";
	cin >> size;
	student *arr = create_arr(size);

	int choise, z, k = 0;

	while (1){
		system("cls");
		cout << "1 - Filling in the data" << endl;
		cout << "2 - Sorting" << endl;
		cout << "3 - Output" << endl;
		cout << "4 - Finding the oldest student" << endl;
		cout << "5 - Exit" << endl << endl << endl;
		cout << "Enter the figure of menu point: ";
		cin >> choise;
	
		switch (choise){
			case 1: 
				in_arr(arr, size);
				k += 1;
				break;
			case 2:
				if (k == 0) {
					cout << "Data not entered yet!" << endl;
					cout << "First you need to fill in all the data..." << endl;
					getch();
					in_arr(arr, size);
					k += 1;
				} else {
					sort(arr, size);
				}
				break;
			case 3:
				if (k == 0) {
					cout << "Data not entered yet!" << endl;
					cout << "First you need to fill in all the data..." << endl;
					getch();
					in_arr(arr, size);
					k += 1;
				} else {
					out_arr(arr, size);
				}
				break;
			case 4:
				if (k == 0) {
					cout << "Data not entered yet!" << endl;
					cout << "First you need to fill in all the data..." << endl;
					getch();
					in_arr(arr, size);
					k += 1;
				} else {
					oldest(arr, size);
				}
				break;
			case 5: del_arr(arr); z = 1; break;
			default: cout << "Enter correct value!"; getch();
		}
		if (z) break;
	} 
	
	return 0;	
}

student* create_arr(int size) {
	student *arr = (student*) malloc(size*sizeof(student));
	
	if (arr != NULL) cout <<"\nMemory was allocated!" << endl;
	else {
		cout << "\nError of memory allocation:(" << endl;;
		exit(1);
		}
	cout << "Press any key";
	getch();
	
	return arr;
}

void in_arr (student *arr, int size){
	system ("cls");
	cout << "Entering student data.\n(Input in Russian is supported)\n" << endl;
	
	for (int i = 0; i < size; i++) {
		cout << "Enter the record book number: ";
		cin >> arr[i].record_book;
		
		while (!cin) {
			cin.clear();
			cin.ignore();
			
			cout << "Enter correct value!" << endl;
			cout << "Enter the record book number: ";
			cin >> arr[i].record_book;
		}
		
		cout << "Enter the lastname: ";
		cin >> arr[i].lastname;
		
		cout << "Enter the name: ";
		cin >> arr[i].name;
		
		cout << "Enter student group number: ";
		cin >> arr[i].number_group;
		
		while (!cin) {
			cin.clear();
			cin.ignore();
			
			cout << "Enter correct value!" << endl;
			cout << "Enter student group number: ";
			cin >> arr[i].number_group;
		}
		
		cout << "Enter student's year of birth: ";
		cin >> arr[i].year_of_birth;
		
		while (!cin) {
			cin.clear();
			cin.ignore();
			
			cout << "Enter correct value!" << endl;
			cout << "Enter student's year of birth: ";
			cin >> arr[i].year_of_birth;
		}
		
		cout << "Enter the student's year of entry: ";
		cin >> arr[i].year_of_admission;
		
		while (!cin) {
			cin.clear();
			cin.ignore();
			
			cout << "Enter correct value!" << endl;
			cout << "Enter the student's year of entry: ";
			cin >> arr[i].year_of_admission;
		}
		
		cout << "Average score of the student's certificate: ";
		cin >> arr[i].grade_point_average;
		
		while ((!cin) || (arr[i].grade_point_average < 0) || (arr[i].grade_point_average > 5)) {
			cin.clear();
			cin.ignore();
			
			cout << "Enter correct value!" << endl;
			cout << "Average score of the student's certificate: ";
			cin >> arr[i].grade_point_average;
		}	
		cout << endl;
	}
}

void out_arr (student *arr, int size) {
	system("cls");
	
	cout << "Rec-bookNum" << "\t" <<"Lastname" << "\t" << "Name" << "\t";
	cout << "Group number" << "\t" << "Year of birth" << "\t" << "Year of entry" << "\t";
	cout << "Average rating" << endl;
	cout << "____________________________________________________";
	cout << "____________________________________________________" << endl;
	for (int i = 0; i < size; i++){
		cout << " ";
		cout << arr[i].record_book << "\t\t";
		cout << arr[i].lastname << "\t\t";
		cout << arr[i].name << "\t\t";
		cout << arr[i].number_group << "\t\t";
		cout << arr[i].year_of_birth << "\t\t";
		cout << arr[i].year_of_admission << "\t\t";
		cout << arr[i].grade_point_average << endl;
	}
	
	cout << "\n\nPress any key to return";
	getch();
}

void sort (student *arr, int size) {
	system ("cls");
	student temp;
	
	for (int i = size - 1; i > 1; i-- ){
		for (int j = 0; j < i; j++){
			if(strcmp (arr[j].lastname, arr[i].lastname) > 0){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "\nArray was sorted!" << endl;
	cout << "Press any key";
	getch();
}

void oldest (student *arr, int size) {
	system ("cls");
	int group, old = 0;
	cout << "Enter student group: "; cin >> group;
	
	for (int i = 0; i < size - 1; i++) {
		if (arr[i].number_group != group) continue;
		if (arr[i].year_of_birth < arr[i+1].year_of_birth) old = i;
	}
	
	cout << "The oldest student: " << arr[old].lastname << " " << arr[old].name << endl;
	cout << "Press any key";
	getch();
}

void del_arr (student *arr) {
	free(arr); 
	cout << "\nMemory was freed up!";
}       