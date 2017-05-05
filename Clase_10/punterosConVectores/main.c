#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[5];
    int* punt;
    punt=x;
    int i;

    for(i=0; i<5; i++)
    {
        *(punt+i)=0; //x[i]=0
    }
    for(i=0; i<5; i++)
    {
        printf("%d", *(punt+1));
    }




    return 0;
}
