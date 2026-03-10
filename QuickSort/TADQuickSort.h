/*TAD Quick Sort, dirigido a ordenar un arreglo de números.
Autor: Flores González Carlos Enrique
Fecha: 09/03/26
*/
#ifndef TADQUICKSORT_H
#define TADQUICKSORT_H

#define TRUE 1
#define FALSE 0
typedef unsigned char boolean;

typedef struct elemento {
    int numero;
} elemento;

typedef struct arreglo {
    elemento *datos;
    int tamano;
} arreglo;

typedef arreglo* quickSort;

/* Reserva el espacio necesario para crear el arreglo */
void Inicializar(quickSort *q, int n);

/* Libera la memoria del arreglo */
void Destruir(quickSort *q);

/* Lee un valor en la posición dada */
elemento LeerPosicion(quickSort *q, int i);

/* Escribe un valor en la posición dada */
void EscribirPosicion(quickSort *q, int i, int valor);

/* Verifica si el arreglo está vacío */
boolean Vacio(quickSort *q);

/* Devuelve el tamaño del arreglo */
int Tamano(quickSort *q);

/* Ordena el arreglo completo usando Quick Sort */
void Ordenar(quickSort *q);

/* Divide recursivamente el arreglo */
void QuickSort(quickSort *q, int p, int r);

/* Encuentra la posición del pivote y reordena */
int Pivot(quickSort *q, int p, int r);

/* Intercambia dos elementos del arreglo */
void Intercambio(quickSort *q, int i, int j);

#endif