#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BORNE 10




int main()
{
    srand(time(NULL));//permet d'initier la fonction random

    int aleatoire;
    int i;

    aleatoire = rand()%BORNE;

    printf("essai nombre aleatoire : %d\n",aleatoire);

    for(i=1;i<=20;i++)
    {
        aleatoire = rand()%BORNE;//nombre aleatoire compris entre 0 et BORNE-1
        printf("essai nombre aleatoire %d : %d\n",i+1,aleatoire);
    }


    for(i=1;i<=20;i++)
    {
        aleatoire = rand()%BORNE + 1;//nombre aleatoire compris entre 1 et BORNE
        printf("essai nombre aleatoire %d : %d\n",i+1,aleatoire);
    }

    system("PAUSE");


    return 0;
}
