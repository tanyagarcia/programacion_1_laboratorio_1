#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"


int main()
{
    EMovie pelicula;
    EMovie* movie;
    movie=&pelicula;

    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        muestraTitulo();
        printf("1- Contenido de archivo\n");
        printf("2- Agregar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Modificar datos pelicula\n");
        printf("5- Generar pagina web\n");
        printf("6- Salir\n");
        printf("\nElija una opcion\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                verEstadoDeArchivo(movie);
                break;
            case 2:
                agregarPelicula(movie);
                break;
            case 3:
                break;
            case 4:
               break;
            case 5:
                generarPagina(movie);
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion valida\n");
                break;
        }
    }

    return 0;
}
