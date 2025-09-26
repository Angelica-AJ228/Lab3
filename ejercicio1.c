#include <stdio.h>

int factorial (int n) {
	int i = 1;
	while (n > 1) {
		i = i * n;
		int n = n - 1;
	}

	return i;
}

int main (int argc, char *argv[]) {
	int fact4 = factorial(4);
	int fac5 = factorial(5);
	printf("4! = %5! = %d\n", fact4, fac5);
	return 0;
}
