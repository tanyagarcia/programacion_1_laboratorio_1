#include <stdio.h>
#include <stdlib.h>
#include "Untitled1.h"
#include <string.h>
#define C 10 //CLIENTES
#define S 5 //SERIES

/*
1- mostrar series
2- mostrar clientes
3- mostrar clientes con su serie
4- por cada serie los clientes que la estan viendo
5- todos los clientes que ven TBBT (100)
6- La serie menos popular
Crear una cuarta estructura que permita relacionar un cliente con una serie, de esta manera podremos obtener una relacion
muchos a muchos (Un cliente que ve muchas series)
7- Todas las series que ven los clientes de nombre "Juan"
*/

//motrar series

int main()
{
    eSerie vectorSerie[S];
    eCliente vectorCliente[C];
    cargarClientes(vectorCliente);
    cargarSeries(vectorSerie);

    int i;

   for(i=0; i<S; i++)
    {

            printf("%d\n%s\n%s\%d\n%d\t\n", vectorSerie[i].estado, vectorSerie[i].titulo, vectorSerie[i].genero, vectorSerie[i].temporadas, vectorSerie[i].idSerie);
    }


    for(i=0; i<C; i++)
    {
        if(vectorCliente[i].estado==1)
        {
            printf("\nEstado[%d] Serie\n[%d]\n Nombre[%s]\n",vectorCliente[i].estado, vectorCliente[i].idSerie,vectorCliente[i].nombre);
        }
    }


    mostrarClientesConSerie(vectorCliente, vectorSerie, S, C); //muestra por cada cliente que serie esta viendo
    //le paso el tamaño de las series y el tamaño de los clientes

    mostrarSeriesConClientes(vectorCliente, vectorSerie, S, C);

    mostrarSerieLoser(vectorCliente, vectorSerie, S, C);



    return 0;
}
