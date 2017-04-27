#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define C 10
#define S 5

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



int main()
{
    eSerie miSerie[S];//declaro el array de la estructura SERIE
    eCliente miCliente[S]; //declaro el array de la estructura CLIENTE
    int i;

    //1- mostrar series
    cargarSeries(miSerie); //llamo a la funcion. tengo que pasarle el vector. NO la estructura
    for(i=0; i<S; i++)
         {
             printf("\n%d\t%s\t%d\t%s\t%d\n", miSerie[i].idSerie, miSerie[i].titulo, miSerie[i].temporadas, miSerie[i].genero, miSerie[i].estado);
         }

    //2- mostrar clientes

    cargarClientes(miCliente);// llamo a la funcion y le paso el array

    for(i=0; i<S; i++)
    {
        printf("\n%d\t%s\t%d\t%d\n", miCliente[i].idCliente, miCliente[i].nombre, miCliente[i].estado, miCliente[i].idSerie);
    }

    //3- mostrar clientes con su serie

    mostrarClientesConSerie(miCliente[], miSerie[], 5, 10);


    return 0;
}
