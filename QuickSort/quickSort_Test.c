#include <stdio.h>
#include <stdlib.h>
#include "TADQuickSort.h"

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    quickSort q;
    Inicializar(&q, n);

    for (int j = 0; j < n; j++)
    {
        int val;
        scanf("%d", &val);
        EscribirPosicion(&q, j, val);
    }

    Ordenar(&q);

    printf("\nArreglo ordenado:\n");
    for (int j = 0; j < Tamano(&q); j++)
    {
        printf("[%d]", LeerPosicion(&q, j).numero);
    }

    Destruir(&q);
    printf("\n");

    return 0;
}