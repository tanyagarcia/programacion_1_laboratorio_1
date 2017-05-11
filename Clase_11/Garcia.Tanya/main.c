#include <stdio.h>
#include <stdlib.h>
#include "estacionamiento2.h"

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

int main()
{
    eDuenio arrayDuenio[5];
    eEstacionamiento arrayEstacionamiento[5];
    inicializarDuenios(arrayDuenio, 5);
    inicializarEstacionamiento(arrayEstacionamiento, 5);

    int opcion=0;
    char seguir='s';

    while(seguir=='s')
    {

        printf("1-ALTA DE DUENIO\n");
        printf("2-MODIFICACION DE DATOS DE DUENIO\n");
        printf("3-INGRESO DE AUTOMOVIL\n");
        printf("4-EGRESO DE AUTOMOVIL\n");
        printf("5-Listado de autos con sus dueños\n");
        printf("6-Propietarios de la marca AUDI\n");
        printf("7-Recaudacion por marca y total de estacionamiento\n");
        printf("8-SALIR\n");

        printf("Introduzca opcion\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarDuenios(arrayDuenio, 5);
            break;
        case 2:
            modificarTarjeta(arrayDuenio, 5);
            break;
        case 3:
            cargarAutos(arrayEstacionamiento, 5);
            break;
        case 4:
           egresoDeAuto(arrayEstacionamiento, 5);
            break;
        case 5:
            ordenarEstacionamiento(arrayEstacionamiento, 5);
            break;
        case 6:
            marcaAudi(arrayEstacionamiento, 5);
            break;
        case 7:
            informesDeRecaudacion(arrayEstacionamiento, 5);
             break;
        case 8:
            seguir='n';
            break;
        default:
            printf("Opcion invalida");
            break;
        }
    }
    return 0;
}
