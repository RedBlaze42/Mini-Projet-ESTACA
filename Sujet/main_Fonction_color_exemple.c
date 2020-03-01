//Renaud ROY
//Fonctoin color avec un exemple d'affichage
//21/02/2012

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void color (int couleurDuTexte, int couleurDuFond);

int main()
{
    srand(time(NULL));//Afin de ne pas imposer de couleur, celle ci est choisie pour l'exemple de fa�on al�atoire
    int i,j,ct,cf;//ct=couleurtexte et cf=couleurfond

    for(i=0;i<5;i++)
    {
        printf("\n");
        for(j=0;j<5;j++)
        {
            ct=rand()%16;
            cf=rand()%16;
            color(ct,cf);
            printf("#");
            color(15,0);
            printf("|");
        }
    }
    color(0,15);
    printf("\n\n\nFin de l'exemple\n");

    system("PAUSE");
    return 0;
}


//Sous-programme permettant de mettre de la couleur dans le programme
//couleurDuTexte : change la couleur du texte
//couleurDuFond : change la couleur derriere le texte
void color (int couleurDuTexte, int couleurDuFond)
{
     HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
// 0.Noir
// 1.Bleu fonc�
// 2.Vert fonc�
// 3.Turquoise
// 4.Rouge fonc�
// 5.Violet
// 6.Vert caca d'oie
// 7.Gris clair
// 8.Gris fonc�
// 9.Bleu fluo
// 10.Vert fluo
// 11.Turquoise
// 12.Rouge fluo
// 13.Violet 2
// 14.Jaune
// 15.Blanc
