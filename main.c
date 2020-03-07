/*
Mini-Projet ESTACA
Emile Azema
Hugo Allaire
*/
#include<stdlib.h>
#include<stdio.h>

#ifndef linux
#include<windows.h>//Uniquement pour windows
#endif

#include <time.h>
#define enclosPlayer1 0
#define enclosPlayer2 17
#define COULEUR_JAUNE 14
#define COULEUR_VERTE 10
int plateau[34];
int arrivee[4];

int selectionCouleurs(int *player1,int *player2);
int tirageDe();
int chevalSurPlateau(int *plateau, int quelCanasson, int *arrivee);
void affichagePlateau(int *plateau,int player1,int player2, int *arrivee);
void afficherCase(int *plateau, int player1, int player2, int i);
void color (int couleurDuTexte, int couleurDuFond);
int coordCheval(int *plateau, int id_cheval, int *arrivee);//Retourne la position du cheval sur le plateau ou -1 si le cheval n'est pas sur le plateau
void avancerCheval(int *plateau, int id_cheval, int valeur_de, int *arrivee);
int tourDeJeux(int *plateau, int player, int *arrivee);
int quelPlayer(int tourDeJeux);

int main(){
    int player1;
    int player2;
    printf("Bonjour\n");
    sleep(1);
    system("cls");
    printf("Bienvenue dans le jeu des petits canassons\n");
    sleep(3);
    system("cls");
    int tour_en_cours=selectionCouleurs(&player1,&player2);
    printf("La partie commence\n puisse le sort vous etre favorable\n");
    printf("Couleurs: "); color(player1,0); printf("Joueur 1 "); color(player2,0); printf("Joueur 2"); color(15,0); printf("\n");
    system("pause");
    int partie_non_finie=1;
    while(partie_non_finie==1){
        system("cls");
        affichagePlateau(plateau,player1,player2,arrivee);
        printf("\n\n");
        tourDeJeux(plateau,tour_en_cours,arrivee);
        tour_en_cours=(tour_en_cours+1);
        if(tour_en_cours>2) tour_en_cours=1;
    }
    
}

void avancerCheval(int *plateau, int id_cheval, int valeur_de, int *arrivee){
    int coord_cheval=coordCheval(plateau,id_cheval, arrivee);
    int nouvelle_coord_cheval=(coord_cheval+valeur_de)%33;
    if(plateau[nouvelle_coord_cheval]!=0){
        printf("Déplacement impossible: un canasson est présent sur la case %d",nouvelle_coord_cheval+1);
    }else{
        plateau[nouvelle_coord_cheval]=id_cheval;
        plateau[coord_cheval]=0;
    }
    int enclos_player=enclosPlayer1;
    if(id_cheval>2) enclos_player=enclosPlayer2;
    if(nouvelle_coord_cheval==enclos_player){
        printf("Votre canasson est arrivé !");
        plateau[nouvelle_coord_cheval]=0;
        arrivee[id_cheval-1]=1;
    }
}

int selectionCouleurs(int* player1,int *player2){
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
        return 1;
    }else if (age1>age2){
            *player1=COULEUR_VERTE ;
            *player2=COULEUR_JAUNE ;
            return 2;
        }else{
            int aleatoire = rand()%2;
        if (aleatoire==0){
            *player1=COULEUR_JAUNE;
            *player2=COULEUR_VERTE;
            return 1;
        }else{ 
            *player1=COULEUR_VERTE;
            *player2=COULEUR_JAUNE;
            return 2;
        }   
    }   
}


int tirageDe(){
    srand(time(NULL));
    printf("Tirage du dé");
    for(int i=0; i<3; i++){
        sleep(0.5);
        printf(".");
    }
    int resultatDe=rand()%6+1;
    printf("\nRésultat du dé: %d",resultatDe);
    return resultatDe;
}
int chevalSurPlateau(int *plateau, int quelCanasson, int *arrivee){
    if(arrivee[quelCanasson-1]==1) return 0;
    for(int i=0;i<34;i++){
        if(plateau[i]==quelCanasson){
            return 1;
        }
    }
    return 0;
}

int sortirCheval(int *plateau, int player){
    if(player==1){
        if(chevalSurPlateau(plateau,1, arrivee)==0){
            if(plateau[enclosPlayer1]==0){
                plateau[0]=1;
            }else{
                printf("La case est déja occupée vous ne pouvez pas sortir le canasson\n");
                return 0;
            }
        }else{
            if(chevalSurPlateau(plateau, 2, arrivee)==0){
                if(plateau[enclosPlayer1]==0){
                    plateau[0]=2;
                }else{
                    printf("Vous avez déja sorti tous vos canassons, vous ne pouvez pas en sortir d'autres\n");
                    return 0;
                }
            }
        }
    }else{
        if(chevalSurPlateau(plateau,3, arrivee)==0){
            if(plateau[enclosPlayer2]==0){
                plateau[0]=3;
            }else{
           printf("la case est déja occupée vous ne pouvez pas sortir le canasson\n");
           return 0;
            }
        }else{
            if(chevalSurPlateau(plateau,4, arrivee)==0){
                plateau[0]=3;
            }else{
                printf("vous avez déja sorti tous vos canassons, vous ne pouvez pas en sortir d'autres\n");
                return 0;
            }
        }
    }
}

void affichagePlateau(int *plateau,int player1,int player2, int *arrivee){
    for(int i=0;i<16;i++){
        afficherCase(plateau,player1,player2,i);
    }
    color(15,0);
    printf("\n");
    afficherCase(plateau,player1,player2,33);
    color(0,0);
    for(int i=1;i<15;i++) printf(" ");//affiche 15 espaces
    afficherCase(plateau,player1,player2,16);
    color(15,0);
    printf("\n");
    for(int i=32;i>16;i--){
        afficherCase(plateau,player1,player2,i);
    }
    color(15,0);
}

void afficherCase(int *plateau, int player1, int player2, int i){
    if(plateau[i]==1 || plateau[i]==2){//player 1
        color(0,player1);
        printf("%d",plateau[i]);
    }else if(plateau[i]==3 || plateau[i]==4){//player 2
        color(0,player2);
        printf("%d",plateau[i]-2);
    }else{
        color(0,7);
        printf(" ");
    }
}

int coordCheval(int *plateau, int id_cheval, int *arrivee){
        for(int i=0;i<34;i++){
            if(plateau[i]==id_cheval){
                return i;
        }
    }  
    return -1;    
}

int tourDeJeux(int *plateau, int player, int *arrivee){
    printf("Au tour du joueur %d de jouer", player);
    system("pause");
    int pion=1;
    if(player==2) pion=3;

    int resultatDe=tirageDe();
    if(resultatDe==6 && (chevalSurPlateau(plateau, pion, arrivee)==0 || chevalSurPlateau(plateau, pion+1, arrivee)==0)){
        printf("Le dé est tombé sur un six, vous pouvez donc sortir un canasson, tapez 1 pour accepter ou 0 pour refuser");
        int input=0;
        scanf("%d",&input);
        if(input>1){
            sortirCheval(plateau,player);
            return 1;
        }else{
            printf("Vous ne sortez pas de canassons, maintenant passons à la suite du tour");
        }
    }

    if(chevalSurPlateau(plateau, pion, arrivee)==0 && chevalSurPlateau(plateau, pion+1, arrivee)==0){
        printf("Vous n'avez aucun canasson sur le plateau, vous ne pouvez donc pas jouer, passont au tour suivant.");
        return 0;
    }
    int id_canason;
    if(chevalSurPlateau(plateau, pion, arrivee)==0+chevalSurPlateau(plateau, pion+1, arrivee)==2){
        printf("Vous avez plusieurs canassons sur le plateau, lequel voulez vous avancer ? (1/2)");
        scanf("%d",id_canason);
        id_canason=id_canason-1+pion;
    }else{
        if(chevalSurPlateau(plateau, pion, arrivee)==0){
            id_canason=pion;
        }else{
            id_canason=pion+1;
        }
    }
    avancerCheval(plateau, id_canason, resultatDe, arrivee);
}

#ifndef linux
void color (int couleurDuTexte, int couleurDuFond){//Version windows
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
#else
void color (int couleurDuTexte, int couleurDuFond){//Version linux
    if(couleurDuTexte==14){
        printf("\e[38;5;226m");
    }else if(couleurDuTexte==10){
        printf("\e[38;5;118m");
    }else if(couleurDuTexte==0){
        printf("\e[38;5;232m");
    }else if(couleurDuTexte==15){
        printf("\e[38;5;255m");
    }else if(couleurDuTexte==7){
        printf("\e[38;5;250m");
    }else if(couleurDuTexte==5){
        printf("\e[38;5;201m");
    }
    if(couleurDuFond==14){
        printf("\e[48;5;226m");
    }else if(couleurDuFond==10){
        printf("\e[48;5;118m");
    }else if(couleurDuFond==0){
        printf("\e[48;5;232m");
    }else if(couleurDuFond==15){
        printf("\e[48;5;255m");
    }else if(couleurDuFond==7){
        printf("\e[48;5;250m");
    }else if(couleurDuFond==5){
        printf("\e[48;5;201m");
    }
}
#endif