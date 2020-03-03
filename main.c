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

void selectionCouleurs(int* player1,int* player2);
int TirageDe();

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

void selectionCouleurs(int* player1,int* player2){
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
int TirageDe(){
    srand(time(NULL));
    int resultatDe=rand()%6+1;
    return resultatDe;
}
int sortircheval(){


}