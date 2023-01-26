#include <stdio.h>
#include <math.h>

int main() {
	float a, b, x, xn, xk, dx, z;
	printf("input a: "), scanf("%f", &a);
	printf("input b: "), scanf("%f", &b);
	printf("input xn: "), scanf("%f", &xn);
	printf("input xk: "), scanf("%f", &xk);
	printf("input the step dx: "), scanf("%f", &dx);
	
	printf(" ________________________\n");
	printf(" |    x    | z = f(x)    |\n");
	printf(" ________________________\n");
	
	x = xn;
	while (x <= xk) {
		printf(" | %-9.3f|", x);
		(x <= a) ? (z=exp(x)*sin(x)) : ((x > a && x < b) ? (z=tan(x)*pow(x, 2)) : (z=pow(x, 7)+abs(x)));
		printf(" %-10.3f|\n", z);
		x += dx;
	}
	
	printf(" ________________________\n");
	printf("press any key");
	return 0;
}