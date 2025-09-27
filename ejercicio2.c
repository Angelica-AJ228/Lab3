#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3   // puede cambiar el tamaño de la matriz

// Devuelve uno si es cuadrado, cero si no lo es
int findLargestLine(int matrix[][SIZE]) {
    int sumaRef = 0;
    int sumaFila, sumaCol;
    int sumaDiag1 = 0, sumaDiag2 = 0;

    // suma de la primera fila como referencia
    for (int j = 0; j < SIZE; j++) {
        sumaRef += matrix[0][j];
    }

    // filas
    for (int i = 0; i < SIZE; i++) {
        sumaFila = 0;
        for (int j = 0; j < SIZE; j++) {
            sumaFila += matrix[i][j];
        }
        if (sumaFila != sumaRef) {
            return 0; // no es cuadrado magico
        }
    }

    // columnas
    for (int j = 0; j < SIZE; j++) {
        sumaCol = 0;
        for (int i = 0; i < SIZE; i++) {
            sumaCol += matrix[i][j];
        }
        if (sumaCol != sumaRef) {
            return 0;
        }
    }

    // diagonales
    for (int i = 0; i < SIZE; i++) {
        sumaDiag1 += matrix[i][i];
        sumaDiag2 += matrix[i][SIZE - 1 - i];
    }
    if (sumaDiag1 != sumaRef || sumaDiag2 != sumaRef) {
        return 0;
    }

    return 1; // si paso todas las pruebas, es cuadrado magico
}


void imprimirMatriz(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[SIZE][SIZE] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    printf("La matriz utilizada corresponde a:\n");
    imprimirMatriz(matrix);

    if (findLargestLine(matrix)) {
        printf("La matriz es cuadrado magico.\n");
    } else {
        printf("La matriz NO es cuadrado magico.\n");
    }

    //Aleatoria adicional
    int aleatoria[SIZE][SIZE];
    srand (time(NULL));
    
    for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j < SIZE; j++) {
			    aleatoria[i][j] = rand() % 9 + 1;
	    }
    }

    printf("\nLa matriz aleatoria es:\n");
    imprimirMatriz(aleatoria);

    if (findLargestLine(aleatoria)) {
	    printf("La matriz es cuadrado magico.\n");
    } else {
	    printf("La matriz NO es cuadrado magico.\n");

    }

    return 0;
}
