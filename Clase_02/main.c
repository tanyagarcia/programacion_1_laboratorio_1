#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int main()
{
    int numero;
    int contPares=0;
    int contImpares=0;
    int sumadorImpares=0;
    int contNumeros=0;
    int sumadorNumeros=0;
    int flagNumero=0;
    int numeroMinimoImpar;
    int numeroMaximo;
    int contNum3a15=0;
    int conNum16a29=0;
    int conNum30=0;
    float promedio;
    char seguir="s";

    while(seguir=="s")
    {
        printf("Ingrese numero: ");
        scanf("%i",&numero);
        while(numero<0)
        {
            printf("Reingrese numero: ");
            scanf("%i",&numero);
        }

        if(numero%2==0)
        {
            contPares++;
        }
        else
        {
            contImpares++;
            sumadorImpares=sumadorImpares+numero;
        }

        if(flagNumero==0 || numero>numeroMaximo)
        {
            numeroMaximo=numero;
            flagNumero=1;
        }

        if()//flag bandera para impar minimo

        if(numero>2&&numero<16)
        {
            contNum3a15++;
        }
        else
        {
            if(numero>15&&numero<30)
            {
                contNum16a29++;
            }
            else
            {
                if(numero>29)
                {
                    contNum30++;
                }
            }
        }
        contNumeros++;
        sumadorNumeros=+numero;

        printf("Desea seguir? s/n");
        seguir=tolower(getche());

    }


     promedio=(float)sumadorNumeros/contNumeros; //tengo que convetir una de las variables a float

     printf("Los numeros pares son: %d", contPares);
     printf("Los numeros impares son: %d", contImpares);
     printf("La sumatoria de los numeros impares es: %d", sumadorImpares);
     printf("El promedio de los numeros es %f",promedio);
     printf("El numero maximo ingresado es %d",numeroMaximo);
     printf("El numero minimo impar ingresado es %d",numeroMinimoImpar);
     printf("Los numeros entre 3 y 15 son %d", contNum3a15,)

    return 0;
}
