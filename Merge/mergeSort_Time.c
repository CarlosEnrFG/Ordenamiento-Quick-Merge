#include <stdio.h>
#include <stdlib.h>
#include "TAD-Merge-Sort.h"
//**************************************************
//Libreria necesaria para medir rendimiento en Linux
//#include "tiempo.h"
//**************************************************

int main(int argc, char *argv[])
{
//********************************************************
//Variables necesarias para poder medir el tiempo en Linux
//	double utime0, stime0, wtime0, utime1, stime1, wtime1;
//********************************************************

    int n = atoi(argv[1]);

    mergeSort m;
    Inicializar(&m, n);

    for (int j = 0; j < n; j++)
    {
        int val;
        scanf("%d", &val);
        EscribirPosicion(&m, j, val);
    }

//******************************************************************
//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
//	uswtime(&utime0, &stime0, &wtime0);
//******************************************************************

    Ordenar(&m);

//******************************************************************
//Evaluar los tiempos de ejecución
//	uswtime(&utime1, &stime1, &wtime1);
//******************************************************************

    Destruir(&m);
    printf("\n");

//***************************************************************************************************
//Cálculo del tiempo de ejecución del programa
//	printf("real (Tiempo total)            %.10f s\n",  wtime1 - wtime0);
//	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
//	printf("sys  (Tiempo en acciones de E/S)  %.10f s\n",  stime1 - stime0);
//	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
//	printf("\n");
//***************************************************************************************************

//***************************************************************************************************
//Mostrar los tiempos en formato exponencial
//	printf("real (Tiempo total)            %.10e s\n",  wtime1 - wtime0);
//	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
//	printf("sys  (Tiempo en acciones de E/S)  %.10e s\n",  stime1 - stime0);
//	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
//	printf("\n");
//***************************************************************************************************

    return 0;
}