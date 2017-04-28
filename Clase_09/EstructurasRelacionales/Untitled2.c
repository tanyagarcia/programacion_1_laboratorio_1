#include "Untitled1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void cargarSeries(eSerie series[])
{
   int idSerie[5]={100,101,102,103,104};
    int estado[5]={1,1,1,1,1};
    char titulo[5][30]={"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]={9,7,7,6,1};
    char genero[5][30]={"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
     for(i=0; i<5;i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]={"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
    int idSerie[10]={100,100,101,103,103,101,102,103,100,100};
    int i;

    for(i=0; i<10;i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];
        clientes[i].idSerie = idSerie[i];
    }

}

void mostrarClientesConSerie(eCliente vectorCliente[], eSerie vectorSerie[], int tamSeries, int tamClientes)//
{
    int i, j;

    for(i=0; i<tamClientes; i++)
    {
        for(j=0; j<tamSeries; j++)
        {
            if(vectorSerie[j].idSerie==vectorCliente[i].idSerie)
            {
                printf("\nNombre Serie[%s] \n\n\t Nombre Cliente[%s]\n", vectorSerie[j].titulo, vectorCliente[i].nombre);
                break;//porque un cliente solo ve UNA serie
            }
        }
    }

}
void mostrarSeriesConClientes(eCliente vectorCliente[], eSerie vectorSerie[], int tamClientes, int tamSeries)
{
    int i, j;
    for(j=0; j<tamSeries; j++)
    {
        printf("%s", vectorSerie[j].titulo); //porque una serie puede ser vista por muchos clientes
        for(i=0; i<tamClientes; i++)
        {
            if(vectorCliente[i].idSerie==vectorSerie[j].idSerie)
            {
                printf("%s\n\n", vectorCliente[i].nombre);
            }
        }
    }

}

void mostrarSerieLoser(eCliente vectorCliente[], eSerie vectorSerie[], int tamSeries , int tamClientes)
{
    int i, j;
    int flag=0;
    int min;
    eLoser serieLoser[tamSeries];

    for(i=0; i<tamSeries; i++)//temgo que inicializar el array. el contador em 0 y el array de id en cada id de series
    {
        serieLoser[i].idSerie=vectorSerie[i].idSerie;
        serieLoser[i].cont=0;
    }

    /*for(i=0; i<tamSeries; i++)
    {
        printf("%d--%d\n", serieLoser[i].idSerie, serieLoser[i].cont);
    }
    system("pause");
    */

    for(i=0; i<tamSeries; i++)
    {
        for(j=0; j<tamClientes; j++)
        {
            if(serieLoser[i].idSerie==vectorCliente[j].idSerie)
            {
                serieLoser[i].cont++;
            }
        }

    }

    for(i=0; i<tamSeries; i++)
    {
        if(flag==0 || serieLoser[i].cont <min)
        {
            flag=1;
            min=serieLoser[i].cont;
        }

    }

    for(i=0; i<tamSeries; i++)//busco en el vector de series la serie con el contador mas chico
    {
        if(serieLoser[i].cont==min)//me fijo que el contador coincida con el minimo
        {
            for(j=0; j<tamSeries; j ++)//busco el array series que el ID coincida con el ID del array Loser
            {

                if(serieLoser[i].idSerie==vectorSerie[j].idSerie)//hago la condicion para que matcheen el ID del array LOSER y SERIE
                {
                    printf("%s\n ", vectorSerie[j].titulo);//muestro el titulo de la serie menos vista
                    break; //pongo un break para que cuando la encuentre rompa y pase a la siguiente posicion minima si hay mas de una
                    //solo va a entrar en la proxima posicion que sea minima
                }

            }
        }

    }
}


