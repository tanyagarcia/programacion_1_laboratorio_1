#include "EstructurasRelacionales.h"
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
                break;
            }
        }
    }

}
void mostrarSeriesConClientes(eCliente vectorCliente[], eSerie vectorSerie[], int tamClientes, int tamSeries)
{
    int i, j;
    for(j=0; j<tamSeries; j++)
    {
        for(i=0; i<tamClientes; i++)
        {
            if(vectorSerie[j].idSerie==vectorCliente[i].idSerie)
            {
                printf("%s\n\n%s", vectorSerie[j].titulo, vectorCliente[i].nombre);
            }
        }
    }

}



