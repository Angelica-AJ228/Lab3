#include <stdio.h>

int factorial (int n) {
	int i = 1;
	while (n > 1) {
		i = i * n;
		n = n - 1; //se estaba redeclarando n, entonces que quita int
	}
	return i;
}

int main (int argc, char *argv[]) {
	int numero;

	printf("Ingrese el numero a calcular: ");
	scanf("%d", &numero);

	int resultado = factorial(numero);
	printf("%d! = %d\n", numero, resultado);
	return 0;

}

