#include <stdio.h>
#include <stdlib.h>

/*
HEAP COMO ARRAY:
***************************************************               *****************************
* ELEMENT_0 * ELEMENT_1 * ELEMENT_2 * ELEMENT_1,3 *   .   .   .   *         ELEMENT_N-1       *
*           *           *           *   Son of 1  *               *       Son of (i-2)/2      *
***************************************************               *****************************
            \                       /\
             \_____________________/  \_____________________/
                    Depth 1                   Depth 2
                    
HEAP COMO ÁRBOL
            *************
            * ELEMENT_0 *
            *************
          ______|___________        ========
         |                  |               \
    *************      *************        I
    * ELEMENT_1 *      * ELEMENT_2 *        I Depth 1
    *************     *************         I
      ___|_____             |               /
     |      . . .        . . .     =========
*************                       
* ELEMENT_3 *
*  Son of 1 *
*************
            .       .       .
        /
*******************                       
* ELEMENT_N-1     *
*  Son of (i-2)/2 *
*******************


*/

typedef struct element
{
    int number;
} element;

typedef struct Heap
{
    element *data; // apuntador para arreglo dinámico de elementos
    int size;
    int capacity;
} Heap;

void Initialize_Heap(Heap *h, int capacity);

void Insert_Heap(Heap *h, element e);

element Remove_Heap(Heap *h);

void Destroy_Heap(Heap *h);