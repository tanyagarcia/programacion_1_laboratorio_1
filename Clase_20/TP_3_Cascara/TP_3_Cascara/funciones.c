#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

void muestraTitulo()
{
    printf("*** MENU DE OPCIONES ***\n");
}


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void agregarPelicula(EMovie* movie, EMovie* listaPeliculas[], int cant)
{

    char buffer[100], link[100];
    int duracion, puntaje;
    char titulo[20], genero[20];
    int i, cont=0;

    for(i=0; i<cant; i++)
    {
        printf("Ingrese nombre de pelicula: \n");
        fflush(stdin);
        gets(titulo);
        printf("Ingrese duracion: \n");
        scanf("%d", &duracion);
        printf("Ingrese genero: \n");
        fflush(stdin);
        gets(genero);
        printf("Ingrese puntaje: \n");
        scanf("%d", &puntaje);
        printf("Ingrese descripcion\n");
        fflush(stdin);
        gets(buffer);
        while(strlen(buffer)>50)
        {
            printf("Reingrese descripcion mas corta");
            fflush(stdin);
            gets(buffer);
        }
        printf("Ingrese link de imagen\n");
        fflush(stdin);
        gets(link);
        system("pause");

        movie = newMovieParametros(titulo, duracion, genero, buffer, puntaje, link);

        listaPeliculas[cont]= movie;
        cont++;

    }

}


int guardarEnArchivo(EMovie* listaPeliculas[], int cant)
{
    FILE* bin;
    int i;
    bin=fopen("bin.dat", "ab+");
    if(bin==NULL)
    {
        printf("Error al abrir archivo");
        return 0;
    }
    for(i=0; i<cant; i++)
    {
        fwrite(listaPeliculas, sizeof(EMovie), 1, bin);
    }


    fclose(bin);

    return 1;

}

EMovie* newMovie(void)
{
    EMovie* pelicula;
    pelicula=(EMovie*) malloc(sizeof(EMovie));
    return pelicula;
    //free(pelicula);
}


EMovie* newMovieParametros(char titulo[], int duracion, char genero[], char descripcion[], int puntaje, char link[])
{
    EMovie* p;

    p=newMovie();

    strcpy(p->titulo, titulo);
    strcpy(p->genero, genero);
    strcpy(p->descripcion,descripcion);
    strcpy(p->linkImagen,link);
    p->duracion = duracion;
    p->puntaje = puntaje;

    return p;
}
/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);







/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* listaPeliculas[], char arch_html[], int cant, EMovie* movie)
{
    FILE *archivo;
    int i;
    char aux[50];
    strcpy(aux, arch_html);//chequear esto
    strcat(aux, ".html");

    archivo = fopen(aux,"w");

    if(archivo != NULL)
    {
        for(i=0; i<cant; i++)
        {
            fprintf(archivo, "<!DOCTYPE html> <html lang='en'> <head> <meta charset='utf-8'><meta http-equiv='X-UA-Compatible'"
                    "content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title>"
                    "<link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'><!--[if lt IE 9]>"
                    "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'>"
                    "</script><![endif]--></head><body><div class='container'><div class='row'>"
                    "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n"
                    "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                    "</a>\n"
                    "<h3>\n"
                    "<a href='#'>%s</a>\n"
                    "</h3>\n"
                    "<ul>\n"
                    "<li>Genero:%s</li>\n"
                    "<li>Puntaje:%d</li>\n"
                    "<li>Duracion:%d minutos</li>\n"
                    "</ul>\n"
                    "<p>%s</p>\n"
                    " </article>\n"
                    "</div>"
                    "<!-- /.row -->"
                    "</div>"
                    "<!-- /.container -->"
                    "<!-- jQuery -->"
                    "<script src='js/jquery-1.11.3.min.js'></script>"
                    "<script src='js/bootstrap.min.js'></script>"
                    "<!-- IE10 viewport bug workaround -->"
                    "<script src='js/ie10-viewport-bug-workaround.js'></script>"
                    "<script src='js/holder.min.js'></script>"
                    "</body>"
                    "</html>",(movie+i)->linkImagen,(movie+i)->titulo,(movie+i)->genero,(movie+i)->puntaje, (movie+i)->duracion,(movie+i)->descripcion);

        }
    }


    fclose(archivo);
}




