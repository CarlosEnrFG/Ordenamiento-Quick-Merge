/*TAD Merge Sort, dirigido a ordenar un arreglo de números.
Autor: Flores González Carlos Enrique
Fecha: 09/03/26
*/
#include <stdio.h>
#include <stdlib.h>
#include "TAD-Merge-Sort.h"

/* Reserva el espacio necesario para crear el arreglo y su auxiliar */
void Inicializar(mergeSort *m, int n)
{
    *m = malloc(sizeof(arreglo));
    if (*m == NULL)
    {
        printf("\nError al reservar memoria para la estructura\n");
        exit(EXIT_FAILURE);
    }
    (*m)->datos = malloc(sizeof(elemento) * n);
    if ((*m)->datos == NULL)
    {
        printf("\nError al reservar memoria para los datos\n");
        free(*m);
        exit(EXIT_FAILURE);
    }
    (*m)->auxiliar = malloc(sizeof(elemento) * n);
    if ((*m)->auxiliar == NULL)
    {
        printf("\nError al reservar memoria para el auxiliar\n");
        free((*m)->datos);
        free(*m);
        exit(EXIT_FAILURE);
    }
    (*m)->tamano = n;
}

/* Libera la memoria del arreglo y su auxiliar */
void Destruir(mergeSort *m)
{
    if (*m != NULL)
    {
        free((*m)->datos);
        free((*m)->auxiliar);
        free(*m);
        *m = NULL;
    }
}

/* Lee un valor en la posición dada */
elemento LeerPosicion(mergeSort *m, int i)
{
    if (i < 0 || i >= (*m)->tamano)
    {
        printf("\nERROR: posición fuera de rango (LeerPosicion)\n");
        exit(EXIT_FAILURE);
    }
    return (*m)->datos[i];
}

/* Escribe un valor en la posición dada */
void EscribirPosicion(mergeSort *m, int i, int valor)
{
    if (i < 0 || i >= (*m)->tamano)
    {
        printf("\nERROR: posición fuera de rango (EscribirPosicion)\n");
        exit(EXIT_FAILURE);
    }
    (*m)->datos[i].numero = valor;
}

/* Verifica si el arreglo está vacío */
boolean Vacio(mergeSort *m)
{
    return ((*m)->tamano == 0);
}

/* Devuelve el tamaño del arreglo */
int Tamano(mergeSort *m)
{
    return (*m)->tamano;
}

/* Ordena el arreglo completo usando Merge Sort */
void Ordenar(mergeSort *m)
{
    Merge(m, 0, (*m)->tamano - 1);
}

/* Divide y ordena recursivamente los subrangos */
void Merge(mergeSort *m, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        Merge(m, p, q);
        Merge(m, q + 1, r);
        Sort(m, p, q, r);
    }
}

/* Combina dos mitades ordenadas */
void Sort(mergeSort *m, int p, int q, int r)
{
    int k, l, i, j;
    l = r - p + 1;
    i = p;
    j = q + 1;
    k = 0;

    for (k = 0; k < l; k++)
    {
        if (i <= q && j <= r)
        {
            if ((*m)->datos[i].numero < (*m)->datos[j].numero)
            {
                (*m)->auxiliar[k].numero = (*m)->datos[i].numero;
                i++;
            }
            else
            {
                (*m)->auxiliar[k].numero = (*m)->datos[j].numero;
                j++;
            }
        }
        else if (i <= q)
        {
            (*m)->auxiliar[k].numero = (*m)->datos[i].numero;
            i++;
        }
        else
        {
            (*m)->auxiliar[k].numero = (*m)->datos[j].numero;
            j++;
        }
    }

    k = p;
    for (i = 0; i < l; i++)
    {
        (*m)->datos[k].numero = (*m)->auxiliar[i].numero;
        k++;
    }
}