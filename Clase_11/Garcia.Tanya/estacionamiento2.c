#include <conio.h>
#include "estacionamiento2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

/** \brief funcion para inicializar duenios
 *
 * \param eDuenio arrayDuenio array de duenios
 * \param tamD tamanio del array
 * \return no tiene
 *
 */

void inicializarDuenios(eDuenio arrayDuenio[], int tamD)
{
    int i;
    for(i=0; i<tamD; i++)
    {
        arrayDuenio[i].flagEstado=0;
    }
}
/** \brief funcion para cargar duenios
 *
 * \param eDuenio arrayDuenio array de duenios
 * \param tamD es el tamaño del array
 * \return no tiene
 *
 */

void cargarDuenios(eDuenio arrayDuenio[], int tamD)
{
    int idDuenio[5]= {1, 2, 3, 4, 5};
    char nombre[5][50]= {"JOSE", "LUIS", "RICARDO", "LUCIA", "JIMENA"};
    char apellido[5][50]= {"GOMEZ", "GONZALES", "GUTIERREZ", "GARCIA", "DAMIANO"};
    char direccion[5][255]= {"Irala 234", "Montes de Oca 574", "Samperio 987", "Uspallata 345", "Brandsen 1246"};
    int tarjeta[5]= {3333, 4444, 5555, 6666, 7777};
    int flagEstado[5]= {1, 1, 1, 1, 1};
    int i;

    for(i=0; i<5; i++)
    {
        arrayDuenio[i].idDuenio=idDuenio[i];
        strcpy(arrayDuenio[i].nombre, nombre[i]);
        strcpy(arrayDuenio[i].apellido, apellido[i]);
        strcpy(arrayDuenio[i].direccion, direccion[i]);
        arrayDuenio[i].tarjeta=tarjeta[i];
        arrayDuenio[i].flagEstado=flagEstado[i];
    }

    for(i=0; i<tamD; i++)
    {
        if(arrayDuenio[i].flagEstado==1)
        {
            printf("%s--%s\n",arrayDuenio[i].nombre,arrayDuenio[i].apellido);
        }

    }

}
/** \brief funcion para modificar una tarjeta de duenio
 *
 * \param eDuenio arrayDuenio array de duenio
 * \param tamD es el tamaño del array
 * \return no tiene
 *
 */

void modificarTarjeta(eDuenio arrayDuenio[], int tamD)
{
    int i;
    int auxTarjeta;
    int numero;
    char respuesta;
    int flagModifica=0;

    printf("Ingrese tarjeta de duenio a modificar: ");
    scanf("%d", &auxTarjeta);

    for(i=0; i<tamD; i++)
    {
        if(arrayDuenio[i].flagEstado==1 && arrayDuenio[i].tarjeta== auxTarjeta)
        {
            printf("%s\t%s\t\n", arrayDuenio[i].nombre, arrayDuenio[i].apellido);

            printf("Ingrese nuevo numero: ");
            scanf("%d", &numero);
            printf("Esta seguro de modificar el numero? s/n: \n");
            respuesta =getche();
            if(respuesta == 's')
            {
                arrayDuenio[i].tarjeta=numero;
            }
            else
            {
                printf("Accion cancelada por el usuario");
            }
            flagModifica = 1;
            break;
        }

    }
    if(flagModifica == 0)
    {
        printf("Tarjeta inexistente!!!");
    }

    for(i=0; i<tamD; i++)
    {
        if(arrayDuenio[i].flagEstado==1)
        {
            printf("%d\t%d\t\n", arrayDuenio[i].tarjeta, arrayDuenio[i].idDuenio);
        }
    }

}
void inicializarEstacionamiento(eEstacionamiento arrayEstacionamiento[], int tamE)
{
    int i;
    for(i=0; i<tamE; i++)
    {
        arrayEstacionamiento[i].flagEstado= 0;
        //arrayEstacionamiento[i].horarioSalida= 0;
        //arrayEstacionamiento[i].totalEstadia= 0;
    }
}
/** \brief funcion para cargar el estacionamiento
 *
 * \param eEstacionamiento arrayEstacionamiento nombre de array
 * \param tamE tamaño del array
 * \return no tiene
 *
 */

void cargarAutos(eEstacionamiento arrayEstacionamiento[], int tamE)
{
    /*int i;
    int posicion=0;

    posicion = buscarLibre(arrayEstacionamiento, 5);

    while(posicion!= -1)
    {
        printf("Ingrese ID de duenio \n");
        scanf("%d", &arrayEstacionamiento[posicion].idDuenio);

        printf("Ingrese patente \n");
        fflush(stdin);
        gets(arrayEstacionamiento[posicion].patente);

        printf("Ingrese marca del vehiculo: 1-ALPHA ROMEO 2-AUDI 3-FERRARI 4-OTROS \n");
        scanf("%d", &arrayEstacionamiento[posicion].marca);

        printf("Ingrese horario de entrada \n");
        scanf("%d ", &arrayEstacionamiento[posicion].horarioEntrada);

        arrayEstacionamiento[posicion].flagEstado=1;

        posicion=0;
    }
        */


    char patente[5][100]= {"ABC3333", "AGF4444", "ART5555", "RET6666", "ETY7777"};
    int marca[5]= {ALPHA_ROMEO, AUDI, FERRARI, ALPHA_ROMEO, ALPHA_ROMEO};
    int idDuenio[5]= {11, 22, 33, 44, 55};
    int horarioEntrada[5]= {14, 15, 20, 23, 6};
    int horarioSalida[5]= {0};
    int totalEstadia[5]= {0};
    int flagEstado[5]= {1, 1, 1, 1, 1};
    int i;

    for(i=0; i<5; i++)
    {
        strcpy(arrayEstacionamiento[i].patente, patente[i]);
        arrayEstacionamiento[i].marca= marca[i];
        arrayEstacionamiento[i].idDuenio=idDuenio[i];
        arrayEstacionamiento[i].horarioEntrada=horarioEntrada[i];
        arrayEstacionamiento[i].horarioSalida=horarioSalida[i];
        arrayEstacionamiento[i].totalEstadia=totalEstadia[i];
        arrayEstacionamiento[i].flagEstado=flagEstado[i];
    }

    for(i=0; i<tamE; i++)
    {
        if(arrayEstacionamiento[i].flagEstado==1)
        {
            printf("%d--%s---%d--%d\n",arrayEstacionamiento[i].idDuenio, arrayEstacionamiento[i].patente, arrayEstacionamiento[i].marca, arrayEstacionamiento[i].horarioEntrada);
        }

    }
}

int buscarLibre(eEstacionamiento arrayEstacionamiento[], int tamE)
{
    int lugar= -1;
    int i;
    for(i=0; i<tamE; i++)
    {
        if(arrayEstacionamiento[i].flagEstado==0)
        {
            lugar= i;
            break;
        }
    }

    return lugar;
}


    /** \brief funcion para el egreso de un auto
     *
     * \param eEstacionamiento arrayEstacionamiento nombre de array
     * \param tamE tamaño del array
     * \return no tiene
     *
     */

    void egresoDeAuto(eEstacionamiento arrayEstacionamiento[], int tamE)
    {
        int i;
        int flagModifica=0;
        int auxId=0;
        int horasEstadia;

        printf("Ingrese ID de duenio que egresa: ");
        scanf("%d", &auxId);

        for(i=0; i<tamE; i++)
        {

            if(arrayEstacionamiento[i].idDuenio == auxId)
            {
                printf("Ingrese horario de salida");
                scanf("%d", &arrayEstacionamiento[i].horarioSalida);

                horasEstadia=arrayEstacionamiento[i].horarioSalida- arrayEstacionamiento[i].horarioEntrada;

                if(arrayEstacionamiento[i].marca== ALPHA_ROMEO)
                {

                    arrayEstacionamiento[i].totalEstadia= horasEstadia *150;
                    printf("El valor es %d\n", arrayEstacionamiento[i].totalEstadia);
                }


                else if (arrayEstacionamiento[i].marca== FERRARI)
                {

                    arrayEstacionamiento[i].totalEstadia=horasEstadia *175;
                    printf("El valor es %d\n", arrayEstacionamiento[i].totalEstadia);
                }
                else if (arrayEstacionamiento[i].marca== AUDI)
                {

                    arrayEstacionamiento[i].totalEstadia=horasEstadia *200;
                    printf("El valor es %d\n", arrayEstacionamiento[i].totalEstadia);
                }

                else
                {
                    arrayEstacionamiento[i].totalEstadia=horasEstadia *250;
                    printf("El valor es %d\n", arrayEstacionamiento[i].totalEstadia);
                }

            }

            flagModifica = 1;
            break;
        }


        if(flagModifica == 0)
        {
            printf("ID inexistente!!!");
        }

    }
    /** \brief funcion para ordenar array estacionamiento por patente y horario de entrada
     *
     * \param eEstacionamiento arrayEstacionamiento nombre de array
     * \param tamE tamaño del array
     * \return no tiene
     *
     */

    void ordenarEstacionamiento(eEstacionamiento arrayEstacionamiento[], int tamE)
    {
        int i, j;
        eEstacionamiento auxE;

        for(i=0; i<tamE-1; i++)
        {
            for(j=i+1; j<tamE; j++)
            {
                if(strcmp(arrayEstacionamiento[i].patente, arrayEstacionamiento[j].patente)>0)
                {
                    auxE = arrayEstacionamiento[i];
                    arrayEstacionamiento[i] = arrayEstacionamiento[j];
                    arrayEstacionamiento[j] = auxE;
                }
                else if (arrayEstacionamiento[i].horarioEntrada>arrayEstacionamiento[j].horarioEntrada)
                {
                    auxE = arrayEstacionamiento[i];
                    arrayEstacionamiento[i] = arrayEstacionamiento[j];
                    arrayEstacionamiento[j] = auxE;
                }
            }
        }
        for(i=0; i<tamE; i++)
        {
            if(arrayEstacionamiento[i].flagEstado==1)
            {
                printf("%s--%d---\n",arrayEstacionamiento[i].patente, arrayEstacionamiento[i].horarioEntrada);
            }

        }

    }
    /** \brief funcion para filtrar duenios con auto marca audi
     *
     * \param eEstacionamiento arrayEstacionamiento nombre de array
     * \param tamE tamaño del array
     * \return no tiene
     *
     */

    void marcaAudi(eEstacionamiento arrayEstacionamiento[], int tamE)
    {
        int i;
        for(i=0; i<tamE; i++)
        {
            if(arrayEstacionamiento[i].flagEstado==1 && arrayEstacionamiento[i].marca==AUDI)
            {
                printf("%s--%d---\n",arrayEstacionamiento[i].patente, arrayEstacionamiento[i].horarioEntrada);
            }

        }
    }

    /** \brief funcion para calcular la recaudacion por cada marca y el total
     *
     * \param eEstacionamiento arrayEstacionamient nombre del array
     * \param tamE int tamaño del array
     * \return no tiene
     *
     */


    void informesDeRecaudacion (eEstacionamiento arrayEstacionamiento[], int tamE)
    {

        int i;
        int acumAlpha=0;
        int acumAudi=0;
        int acumFerrari=0;
        int acumOtros=0;
        int sumaTotales;

        for(i=0; i<tamE; i++)
        {
            if(arrayEstacionamiento[i].marca== ALPHA_ROMEO)
            {
                acumAlpha= acumAlpha + arrayEstacionamiento[i].totalEstadia;
                printf("La recaudacion por ALPHA ROMEO es %d\n", acumAlpha);
            }
            else if (arrayEstacionamiento[i].marca== FERRARI)
            {
                acumFerrari= acumFerrari + arrayEstacionamiento[i].totalEstadia;
                printf("La recaudacion por FERRARI %d\n", acumFerrari);
            }
            else if (arrayEstacionamiento[i].marca== AUDI)
            {
                acumAudi= acumAudi + arrayEstacionamiento[i].totalEstadia;
                printf("La recaudacion por AUDI %d\n", acumAudi);
            }
            else
            {
                acumOtros= acumOtros + arrayEstacionamiento[i].totalEstadia;
                printf("La recaudacion por OTRAS MARCAS %d\n", acumOtros);
            }
        }

        sumaTotales= acumAlpha + acumAudi + acumFerrari + acumOtros;

        printf("La recaudacion total del estacionamiento es %d\n ", sumaTotales);

    }
