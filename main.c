/*
Mini-Projet ESTACA
Emile Azema
Hugo Allaire
*/
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include <time.h>
#define COULEUR_JAUNE 14
#define COULEUR_VERTE 10

void selectionCouleurs(int *player1,int *player2);
int TirageDe();
int chevalSurPlateau(int *plateau, int quelCanasson);


int main(){
    int player1;
    int player2;
printf("bonjour\n");
Sleep(500);
system("cls");
printf("bienvenu dans le jeux des petits canassons\n");
Sleep(1000);
system("cls");
selectionCouleurs(&player1,&player2);
printf("la partie commence\n puisse le sort vous etre favorable\n");
Sleep(1000);
system("cls");




}

void selectionCouleurs(int* player1,int *player2){
   int age1;
    int age2;
    srand(time(NULL));
    printf("quel est votre age joueur numero 1?\n");
    scanf("%d",&age1);
    system("cls");
    printf("quel est votre age joueur numero 2\n");
    scanf("%d",&age2);
    system("cls");
    if (age1<age2){
        *player1=COULEUR_JAUNE;
        *player2=COULEUR_VERTE;
    }else{
        if (age1>age2){
            *player1=COULEUR_VERTE ;
            *player2=COULEUR_JAUNE ;
        }else{
            int aleatoire = rand()%2;
            if (aleatoire=0){
                *player1=COULEUR_JAUNE;
                *player2=COULEUR_VERTE;
            }else{
            *player1=COULEUR_VERTE;
            *player2=COULEUR_JAUNE;
            }     
        }   
    } 
}
int tirageDe(){
    srand(time(NULL));
    int resultatDe=rand()%6+1;
    return resultatDe;
}
int chevalSurPlateau(int *plateau, int quelCanasson){
    for(int i=0;i<34;i++){
        if(plateau[i]==quelCanasson){
            return 1;
        }
    }
    return 0;
}

int sortiCheval(int *plateau, int player){
    if(player==1){
        if(chevalSurPlateau(plateau,1)==0){
            if(plateau[enclosPlayer1]==0){
                plateau[0]=1;
            }else{
                printf("la case est déja occupée vous ne pouvez pas sortir le canasson\n");
                return 0;
            }
        }else{
            if(chevalSurPlateau(plateau, 2)==0){
                if(plateau[enclosPlayer1==0]){
                    plateau[0]=1;
                }else{
                    printf("vous avez déja sorti tous vos canassons, vous ne pouvez pas en sortir d'autres\n");
                    return 0;
                }
            }
        }
    }else{
// fais pareil pour le joueur 2
    }
}