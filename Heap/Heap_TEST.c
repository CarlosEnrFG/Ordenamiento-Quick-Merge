#include <stdio.h>
#include <stdlib.h>
#include "SortHeap.h"
int main(int argc, char *argv[])
{
    int i;
    int n = atoi(argv[1]);
    int *A = malloc(sizeof(int) * n);
    if (A == NULL)
    {
        printf("\nError al reservar memoria para %d elementos\n", n);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    Heap H;
    Initialize_Heap(&H, n);
    element e;
    for (i = 0; i < n; i++)
    {
        e.number = A[i];
        Insert_Heap(&H, e);
    }
    for (i = 0; i < n; i++)
    {
        A[i] = Remove_Heap(&H).number;
    }
    Destroy_Heap(&H);

    for (i = 0; i < n; i++)
    {
        printf("[%d]", A[i]);
    }
	printf("\n");	
	free(A);
}
