/*
Mini-Projet ESTACA
Emile Azema
Hugo Allaire
*/
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include <time.h>

void selectionCouleurs(int* player1,int* player2);

int main(){



}

void selectionCouleurs(int* player1,int* player2){
   int age1;
    int age2;
    srand(time(NULL));
    printf("quel est votre age joueur numero 1?\n");
    scanf("%d",&age1);
    system("clear");
    printf("quel est votre age joueur numero 2");
    scanf("%d",&age2);

    if (age1<age2){
        *player1=COULEUR_JAUNE;
        *player2=COULEUR_VERTE;
    }else{
        if (age1>age2){
            *player1=COULEUR_VERTE ;
            *player2=COULEUR_JAUNE ;
        }else{
            int aléatoire = rand(%)2;
            if (aléatoire=0){
                *player1=COULEUR_JAUNE;
                *player2=COULEUR_VERTE;
            }else{
            *player1=COULEUR_VERTE;
            *player2=COULEUR_JAUNE;
            }
             
            
            
            
        }
       
        
        
    }    
        
        
        
    }





}