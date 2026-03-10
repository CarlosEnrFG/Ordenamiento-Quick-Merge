#include <stdio.h>
#include <stdlib.h>
#include "SortHeap.h"

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
          _____|___________        ========
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

void Initialize_Heap(Heap *h, int capacity)
{
    h->data = malloc(sizeof(element) * capacity);
    if (h->data == NULL)
    {
        printf("ERROR: Initialize_Heap(&h, capacity)\nNo se pudo reservar memoria\n");
        exit(EXIT_FAILURE);
    }
    h->size = 0;
    h->capacity = capacity;
}

void Insert_Heap(Heap *h, element e)
{
    int Father_i;
    int LastNode_i = h->size;
    element aux;
    if (h->size == h->capacity)
    {
        printf("ERROR: Insert_Heap(&h, element)\nHeap lleno\n");
        exit(EXIT_FAILURE);
    }

    h->data[LastNode_i] = e;
    h->size++;
    while (LastNode_i > 0)
    {
        Father_i = (LastNode_i - 1) / 2;
        if (h->data[LastNode_i].number < h->data[Father_i].number)
        {
            aux = h->data[Father_i];
            h->data[Father_i] = h->data[LastNode_i];
            h->data[LastNode_i] = aux;
            LastNode_i = Father_i;
        }
        else
        {
            break;
        }
    }
}

element Remove_Heap(Heap *h)
{
    if (h == NULL || h->size == 0)
    {
        printf("ERROR: Remove_Heap(&h)\nHeap vacío o inexistente\n");
        exit(EXIT_FAILURE);
    }

    int Node = 0;
    int SmallNode_i = 0;
    int LeftSon_i = (2 * Node) + 1;
    int RightSon_i = (2 * Node) + 2;
    int LastNode_i = (h->size) - 1;
    element aux;
    element ret = h->data[0];
    h->data[0] = h->data[LastNode_i];
    h->size--;
    while (LeftSon_i < h->size)
    {
        LeftSon_i = (2 * Node) + 1;
        SmallNode_i = LeftSon_i;
        RightSon_i = (2 * Node) + 2;
        if (RightSon_i < h->size && h->data[RightSon_i].number < h->data[LeftSon_i].number)
        {
            SmallNode_i = RightSon_i;
        }
        if (h->data[Node].number > h->data[SmallNode_i].number)
        {
            aux = h->data[Node];
            h->data[Node] = h->data[SmallNode_i];
            h->data[SmallNode_i] = aux;
            Node = SmallNode_i;
        }
        else
        {
            break;
        }
        LeftSon_i = (2 * Node) + 1;
    }
    return ret;
}

void Destroy_Heap(Heap *h)
{
    free(h->data);
    h->data = NULL;
    h->size = 0;
    h->capacity = 0;
}
