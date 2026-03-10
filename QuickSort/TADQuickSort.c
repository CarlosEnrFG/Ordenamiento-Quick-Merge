/*TAD Quick Sort, dirigido a ordenar un arreglo de números.
Autor: Flores González Carlos Enrique
Fecha: 09/03/26
*/
#include <stdio.h>
#include <stdlib.h>
#include "TADQuickSort.h"

/* Reserva el espacio necesario para crear el arreglo */
void Inicializar(quickSort *q, int n)
{
    *q = malloc(sizeof(arreglo));
    if (*q == NULL)
    {
        printf("\nError al reservar memoria para la estructura\n");
        exit(EXIT_FAILURE);
    }
    (*q)->datos = malloc(sizeof(elemento) * n);
    if ((*q)->datos == NULL)
    {
        printf("\nError al reservar memoria para los datos\n");
        free(*q);
        exit(EXIT_FAILURE);
    }
    (*q)->tamano = n;
}

/* Libera la memoria del arreglo */
void Destruir(quickSort *q)
{
    if (*q != NULL)
    {
        free((*q)->datos);
        free(*q);
        *q = NULL;
    }
}

/* Lee un valor en la posición dada */
elemento LeerPosicion(quickSort *q, int i)
{
    if (i < 0 || i >= (*q)->tamano)
    {
        printf("\nERROR: posición fuera de rango (LeerPosicion)\n");
        exit(EXIT_FAILURE);
    }
    return (*q)->datos[i];
}

/* Escribe un valor en la posición dada */
void EscribirPosicion(quickSort *q, int i, int valor)
{
    if (i < 0 || i >= (*q)->tamano)
    {
        printf("\nERROR: posición fuera de rango (EscribirPosicion)\n");
        exit(EXIT_FAILURE);
    }
    (*q)->datos[i].numero = valor;
}

/* Verifica si el arreglo está vacío */
boolean Vacio(quickSort *q)
{
    return ((*q)->tamano == 0);
}

/* Devuelve el tamaño del arreglo */
int Tamano(quickSort *q)
{
    return (*q)->tamano;
}

/* Ordena el arreglo completo usando Quick Sort */
void Ordenar(quickSort *q)
{
    QuickSort(q, 0, (*q)->tamano - 1);
}

/* Divide recursivamente el arreglo */
void QuickSort(quickSort *q, int p, int r)
{
    int j;
    if (p < r)
    {
        j = Pivot(q, p, r);
        QuickSort(q, p, j - 1);
        QuickSort(q, j + 1, r);
    }
}

/* Encuentra la posición del pivote y reordena */
int Pivot(quickSort *q, int p, int r)
{
    int piv = (*q)->datos[p].numero;
    int i = p + 1;
    int j = r;

    while (i < j)
    {
        while ((*q)->datos[i].numero <= piv && i <= r)
        {
            i++;
        }
        while ((*q)->datos[j].numero > piv && j >= p)
        {
            j--;
        }
        if (i < j)
        {
            Intercambio(q, i, j);
        }
    }

    Intercambio(q, p, j);
    return j;
}

/* Intercambia dos elementos del arreglo */
void Intercambio(quickSort *q, int i, int j)
{
    elemento temp = (*q)->datos[j];
    (*q)->datos[j] = (*q)->datos[i];
    (*q)->datos[i] = temp;
}