/*TAD Merge Sort, dirigido a ordenar un arreglo de números.
Autor: Flores González Carlos Enrique
Fecha: 09/03/26
*/
#ifndef TADMERGESORT_H
#define TADMERGESORT_H

#define TRUE 1
#define FALSE 0
typedef unsigned char boolean;

typedef struct elemento {
    int numero;
} elemento;

typedef struct arreglo {
    elemento *datos;
    elemento *auxiliar;
    int tamano;
} arreglo;

typedef arreglo* mergeSort;

/* Reserva el espacio necesario para crear el arreglo y su auxiliar */
void Inicializar(mergeSort *m, int n);

/* Libera la memoria del arreglo y su auxiliar */
void Destruir(mergeSort *m);

/* Lee un valor en la posición dada */
elemento LeerPosicion(mergeSort *m, int i);

/* Escribe un valor en la posición dada */
void EscribirPosicion(mergeSort *m, int i, int valor);

/* Verifica si el arreglo está vacío */
boolean Vacio(mergeSort *m);

/* Devuelve el tamaño del arreglo */
int Tamano(mergeSort *m);

/* Ordena el arreglo completo usando Merge Sort */
void Ordenar(mergeSort *m);

/* Divide y ordena recursivamente los subrangos */
void Merge(mergeSort *m, int p, int r);

/* Combina dos mitades ordenadas */
void Sort(mergeSort *m, int p, int q, int r);

#endif