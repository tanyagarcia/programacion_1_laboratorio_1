#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char apeNombre[200];

    printf("Ingrese nombre ");
    fflush(stdin);
    gets(apeNombre);

    while(strlen(apeNombre)>19)
    {
        printf("Reingrese nombre mas corto ");
        fflush(stdin);
        gets(apeNombre);
    }
    strcpy(nombre, apeNombre);

    printf("Su nombre es %s", nombre);



    return 0;
}
