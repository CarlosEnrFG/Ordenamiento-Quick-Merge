/*TAD Arbol Binario de Búsqueda ABB, dirigido a ordenar un arreglode números.
Autor: Saul Ascencion Cruz
Fecha: 25 de Febrero del 2026
*/
#define TRUE 1
#define FALSE 0

typedef unsigned char boolean;

typedef struct elemento{
  int numero;
} elemento;

typedef struct nodo{
  elemento valor;
  struct nodo* hijoIzq;
  struct nodo* hijoDer;
} nodo;

typedef nodo* arbolBinario;
typedef nodo* posicion;

/*Reserva el espacio necesario para crear el ABB*/
void Inicializar(arbolBinario *a);
/*Libera la memoria necesaria para crear el ABB*/
void Destruir(arbolBinario *a);

/*Regresa el nodo raíz del subárbol*/
posicion Raiz(arbolBinario *a);
/*Regresa el hijo derecho del nodo actual*/
posicion HijoDerecho(arbolBinario *a,posicion p); 
/*Regresa el hijo izquierdo del nodo actual*/
posicion HijoIzquierdo(arbolBinario *a,posicion p);
/*Verifica si un nodo está vacío. Si el nodo está vacío regresa FALSE, por el contrario si el nodo NO
está vacío regresa TRUE*/
boolean Vacio(arbolBinario *a);
/*Verifica si el nodo dado pertenece al ABB*/
boolean NodoNulo(arbolBinario *a,posicion p);
/*Regresa el elemento del nodo dado*/
elemento LeerNodo(arbolBinario *a,posicion p);

/*Inserta un elemento en un árbol siguiendo las reglas del ABB*/
void Insert(arbolBinario *a, int number);

/*Recorre el ABB y sobreescribe el arreglo dado*/
void InOrden(arbolBinario *a, posicion p, int array[], int *i);