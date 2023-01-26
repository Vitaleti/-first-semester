#include <iostream>
#include <iomanip>
#include <windows.h>
#include <math.h>
using namespace std;

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	float a, b, x, xn, xk, dx, z;
	cout << "input a: ", cin >> a;
	cout << "input b: ", cin >> b;
	cout << "input xn: ", cin >> xn;
	cout << "input xk: ", cin >> xk;
	cout << "input the step dx: ", cin >> dx;
	
	cout << "z=f(x)" << endl
		<< " ________________________" << endl
		<< " |    x    | z = f(x)    |" << endl
		<< " ________________________" << endl;
	cout.precision(3), cout.setf(ios::showpoint);
	cout.setf(ios::left,ios::adjustfield);
	cout.setf(ios::fixed,ios::floatfield);
	for (x=xn; x<=xk; x+=dx) {
		cout << " | " << setw(9) << x << "|";
		(x <= a) ? (z=exp(x)*sin(x)) : ((x > a && x < b) ? (z=tan(x)*pow(x, 2)) : (z=pow(x, 7)+abs(x)));
		cout << " " << setw(10) << z << "|" << endl;
	}
	
	cout << " _________________________" << endl;
	return 0;
}
