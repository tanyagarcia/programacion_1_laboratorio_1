#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"


int main()
{
    EMovie* movie;
    EMovie* listaPeliculas[4];
    char seguir='s';
    int opcion=0;
    char arch_html[100];

    while(seguir=='s')
    {
        muestraTitulo();
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar datos pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        printf("\nElija una opcion\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie, listaPeliculas, 4);
                guardarEnArchivo(listaPeliculas, 4);
                if(1)
                {
                    printf("Pelicula cargada correctamente\n");
                }
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                generarPagina(listaPeliculas, arch_html, 4, movie);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion valida\n");
                break;
        }
    }

    return 0;
}
