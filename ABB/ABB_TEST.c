#include <stdio.h>
#include <stdlib.h>
#include "TADArbolBin.h"
int main(int argc, char *argv[])
{
	int i;
	arbolBinario arbol;
	Inicializar(&arbol);
	int n = atoi(argv[1]);
	int *A = malloc(sizeof(int) * n);
	if (A == NULL)
	{
		printf("\nError al reservar memoria para %d elementos\n", n);
		exit(EXIT_FAILURE);
	}

	for (int j = 0; j < n; j++)
	{
		scanf("%d", &A[j]);
	}
	for (i = 0; i < n; i++)
	{
		Insert(&arbol, A[i]);
	}
	i = 0;
	InOrden(&arbol, Raiz(&arbol), A, &i);

	Destruir(&arbol);
	printf("\nArreglo ordenado:\n");
	for (int j = 0; j < n; j++)
	{
		printf("[%d]", A[j]);
	}
	free(A);
	printf("\n");
}
