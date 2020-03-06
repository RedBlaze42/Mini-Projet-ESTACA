/*
Mini-Projet ESTACA
Emile Azema
Hugo Allaire
*/
#include<stdlib.h>
#include<stdio.h>
#define linux
#ifndef linux
#include<windows.h>//Uniquement pour windows
#endif

#include <time.h>
#define enclosPlayer1 0
#define enclosPlayer2 17
#define COULEUR_JAUNE 14
#define COULEUR_VERTE 10
int plateau[34];

void selectionCouleurs(int *player1,int *player2);
int TirageDe();
int chevalSurPlateau(int *plateau, int quelCanasson);
void affichagePlateau(int *plateau,int player1,int player2);
void afficherCase(int *plateau, int player1, int player2, int i);
void color (int couleurDuTexte, int couleurDuFond);
int coordCheval(int *plateau, int id_cheval);//Retourne la position du cheval sur le plateau ou -1 si le cheval n'est pas sur le plateau
void avancerCheval(int *plateau, int id_cheval, int valeur_de);
int tourDeJeux(int coordcheval, int tirageDe);
int quelPlayer(int tourDeJeux);

int main(){
    int player1;
    int player2;
    printf("Bonjour\n");
    Sleep(1);
    system("cls");
    printf("Bienvenue dans le jeu des petits canassons\n");
    Sleep(3);
    system("cls");
    selectionCouleurs(&player1,&player2);
    printf("La partie commence\n puisse le sort vous etre favorable\n");
    printf("Couleurs: "); color(player1,0); printf("Joueur 1 "); color(player2,0); printf("Joueur 2"); color(15,0); printf("\n");
    printf("C'est donc le joueur "); color(COULEUR_JAUNE,0); printf("jaune"); color(15,0); printf(" qui commence\n");

    Sleep(3);
    system("cls");
    plateau[3]=2;
    affichagePlateau(plateau,player1,player2);
}

void avancerCheval(int *plateau, int id_cheval, int valeur_de){
    int coord_cheval=coordCheval(plateau,id_cheval);
    int nouvelle_coord_cheval=(coord_cheval+valeur_de)%33;
    if(plateau[nouvelle_coord_cheval]!=0){
        printf("Déplacement impossible: un canasson est présent sur la case %d",nouvelle_coord_cheval+1);
    }else{
        plateau[nouvelle_coord_cheval]=id_cheval;
        plateau[coord_cheval]=0;
    }
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
    }else if (age1>age2){
            *player1=COULEUR_VERTE ;
            *player2=COULEUR_JAUNE ;
        }else{
            int aleatoire = rand()%2;
        if (aleatoire==0){
                *player1=COULEUR_JAUNE;
                *player2=COULEUR_VERTE;
            }else{ 
            *player1=COULEUR_VERTE;
            *player2=COULEUR_JAUNE;
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

int sortirCheval(int *plateau, int player){
    if(player==1){
        if(chevalSurPlateau(plateau,1)==0){
            if(plateau[enclosPlayer1]==0){
                plateau[0]=1;
            }else{
                printf("La case est déja occupée vous ne pouvez pas sortir le canasson\n");
                return 0;
            }
        }else{
            if(chevalSurPlateau(plateau, 2)==0){
                if(plateau[enclosPlayer1]==0){
                    plateau[0]=2;
                }else{
                    printf("Vous avez déja sorti tous vos canassons, vous ne pouvez pas en sortir d'autres\n");
                    return 0;
                }
            }
        }
    }else{
        if(chevalSurPlateau(plateau,3)==0){
            if(plateau[enclosPlayer2]==0){
                plateau[0]=3;
            }else{
           printf("la case est déja occupée vous ne pouvez pas sortir le canasson\n");
           return 0;
            }
        }else{
            if(chevalSurPlateau(plateau,4)==0){
                plateau[0]=3;
            }else{
                printf("vous avez déja sorti tous vos canassons, vous ne pouvez pas en sortir d'autres\n");
                return 0;
            }
        }
    }
}


void affichagePlateau(int *plateau,int player1,int player2){
    if(chevalSurPlateau(plateau,1)==0){
        color(0,player1);
        printf("1");
    }else{
        color(0,7);
        printf(" ");
    }
    color(15,0); printf("\n");
    if(chevalSurPlateau(plateau,2)==0){
        color(0,player1);
        printf("2");
    }else{
        color(0,7);
        printf(" ");
    }
    color(15,0); printf("\n");


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
    printf("\n");
    for(int i=0;i<15;i++) printf(" ");
    if(chevalSurPlateau(plateau,3)==0){
        color(0,player2);
        printf("1");
    }else{
        color(0,7);
        printf(" ");
    }
    color(15,0); printf("\n");
    for(int i=0;i<15;i++) printf(" ");
    if(chevalSurPlateau(plateau,4)==0){
        color(0,player2);
        printf("2");
    }else{
        color(0,7);
        printf(" ");
    }
    color(15,0); printf("\n");
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
int coordCheval(int *plateau, int id_cheval){
        for(int i=0;i<34;i++){
            if(plateau[i]==id_cheval){
                return i;
        }
    }  
    return -1;    
}
/*
int tourDeJeux(int coordcheval, int tirageDe){
    printf("le dé affiche la valeur %d", tirageDe);
    if(tirageDe==6){
        int i;
        printf("Si vous voulez sortir un votre deuxieme cheval tapez 1 sinon tapez 2");
        scanf("%d", i);
        if(quelPlayer==1){
            if(i==1){
                sortirCheval( plateau, 2);
            }else{
                avancerCheval( plateau, 1, tirageDe);
            }
        }else{
           if(i==1){
                sortirCheval( plateau, 3);
            }else{
                avancerCheval( plateau, 4, tirageDe);      
        }
    }else{
        int quelChev;
        printf("quel cheval voulez vous avancer ?");
        scanf("%d", quelChev);
        if(quelPlayer==1){
            avancerCheval( plateau, quelChev, tirageDe);
            return 1;
        }else{
            avancerCheval( plateau, quelChev+2, tirageDe);
            return 2;
        }
    }
}*/
int quelPlayer(int tourDeJeux){
    if(tourDeJeux==1){ 
         return 1;
    }else{
        return 2; 
    }
}

#ifndef linux
void color (int couleurDuTexte, int couleurDuFond){//Version windows
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
#else
void Sleep(int seconds){
    sleep(seconds);
}
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