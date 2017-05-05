#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a =7;
    int *punt;
    int *otro;

    punt=&a;// A y punt apuntan a la misma direccion y tienen el mismo valor

    printf("%p\n", &a );//apunta a la direccion de memoria del puntero
    printf("%p\n", punt);//apunta a la direccion de memoria del puntero

    printf("%d\n", a);//apunta al valor de la variable
    printf("%d\n", *punt);//apunta al valor de la variable

    printf("%p\n", &punt); //apunta a la direccion de memoria del puntero


    otro=punt;// "otro" pasa a tomar la direccion de memoria de punt es decir la posicion de A

    *otro=4; //otro apunta a A por lo tanto A pasa a valer 4
    *punt=5; //PUNT tambien apunta a A por lo tanto A pasa a valer 5

    printf("%p\n", &punt);

    //ARITMETICA DE PUNTEROS
    printf("%p\n", &punt+1);//4 bits mas respecto de la posicion anterior

    return 0;
}
