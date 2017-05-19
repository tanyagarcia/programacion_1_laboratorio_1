#include <stdio.h>
#include <stdlib.h>
#define T 4

int main()
{
    int vector[T];
    int* puntero;
    int* auxPuntero;
    int i;

    puntero=(int*) malloc(sizeof(int)*T);

    if(puntero!=NULL)
    {
        for(i=0; i<T; i++)
        {
            printf("Ingrese numero ");
            scanf("%d", puntero+i);
        }
        for(i=0; i<T; i++)
        {
            printf("%d\n", *(puntero+i));
        }
    }

    int posicion;
    printf("Ingrese posicion a eliminar: ");
    scanf("%d", posicion-1);
    for(i=0; i<T; i++)
        {
                if(i==(posicion-1))
                {
                    puntero+(posicion-1) = (*(puntero+(posicion));
                    puntero+(posicion) = (*(puntero+(posicion+1)));

                }

        }

    auxPuntero = realloc(puntero,sizeof(int)*(T-1));
    if(auxPuntero!=NULL)
    {
        puntero = auxPuntero;

        for(i=0; i<T-1; i++)
        {
            printf("%d\n", *(puntero+i));
        }

        return 0;
    }
