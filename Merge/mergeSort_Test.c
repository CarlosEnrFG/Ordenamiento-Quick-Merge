#include <stdio.h>
#include <stdlib.h>
#include "TAD-Merge-Sort.h"

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    mergeSort m;
    Inicializar(&m, n);

    for (int j = 0; j < n; j++)
    {
        int val;
        scanf("%d", &val);
        EscribirPosicion(&m, j, val);
    }

    Ordenar(&m);

    printf("\nArreglo ordenado:\n");
    for (int j = 0; j < Tamano(&m); j++)
    {
        printf("[%d]", LeerPosicion(&m, j).numero);
    }

    Destruir(&m);
    printf("\n");

    return 0;
}