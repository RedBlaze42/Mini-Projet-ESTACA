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
    printf("C'est donc le joueur "); color(COULEUR_JAUNE,0); printf("jaune"); color(15,0); printf(" qui commence\n");
    system("pause");

    int gagnant=0;
    while(gagnant==0){
        system("cls");
        affichagePlateau(plateau,player1,player2,arrivee);
        printf("\n\n");
        tourDeJeux(plateau,tour_en_cours,arrivee);
        tour_en_cours=(tour_en_cours+1);
        if(tour_en_cours>2) tour_en_cours=1;
        system("pause");
        if(arrivee[0]==1 && arrivee[1]==1) gagnant=1;
        if(arrivee[2]==1 && arrivee[3]==1) gagnant=2;
    }
    color(0,player1);
    if(gagnant==2) color(0,player2);
    printf("Le joueur %d a gagne !!",gagnant);
    color(15,0); printf("\n");
}

void avancerCheval(int *plateau, int id_cheval, int valeur_de, int *arrivee){
    int coord_cheval=coordCheval(plateau,id_cheval, arrivee);
    int nouvelle_coord_cheval=(coord_cheval+valeur_de)%34;
    if(plateau[nouvelle_coord_cheval]!=0){
        printf("Deplacement impossible: un canasson est present sur la case %d\n",nouvelle_coord_cheval+1);
        return NULL;
    }else{
        plateau[nouvelle_coord_cheval]=id_cheval;
        plateau[coord_cheval]=0;
    }
    int enclos_player=enclosPlayer1;
    if(id_cheval>2){
        printf("Votre canasson numero %d a avance de %d cases !\n",id_cheval-2,valeur_de);
    }else{
        printf("Votre canasson numero %d a avance de %d cases !\n",id_cheval,valeur_de);
    }
    if(id_cheval>2) enclos_player=enclosPlayer2;
    if(nouvelle_coord_cheval==enclos_player){
        printf("Votre canasson est arrive !\n");
        plateau[nouvelle_coord_cheval]=0;
        arrivee[id_cheval-1]=1;
    }
}

int selectionCouleurs(int* player1,int *player2){
    int age1;
    int age2;
    srand(time(NULL));
    printf("Quel est votre age joueur numero 1 ? ");
    scanf("%d",&age1);
    printf("Quel est votre age joueur numero 2 ? ");
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
    printf("Tirage du de");
    for(int i=0; i<3; i++){
        sleep(1);
        printf(".");
    }
    int resultatDe=rand()%6+1;
    printf("\nResultat du de: %d\n",resultatDe);
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

int sortirCheval(int *plateau, int player,int *arrivee){
    if(player==1){
        if(plateau[enclosPlayer1]!=0){
            printf("La case est deja occupee vous ne pouvez pas sortir le canasson\n");
            return 0;
        }
        if(chevalSurPlateau(plateau,1,arrivee)==0 && arrivee[0]==0){
            plateau[enclosPlayer1]=1;
            printf("Vous avez sorti un canasson !\n");
        }else if(chevalSurPlateau(plateau,2,arrivee)==0 && arrivee[1]==0){
            plateau[enclosPlayer1]=2; 
            printf("Vous avez sorti un canasson !\n");         
        }else{
            printf("Vous avez deja sorti tous vos canassons, vous ne pouvez pas en sortir d'autres\n");
            return 0;
        }
    }else{
        if(plateau[enclosPlayer2]!=0){
            printf("La case est deja occupee vous ne pouvez pas sortir le canasson\n");
            return 0;
        }
        if(chevalSurPlateau(plateau,3,arrivee)==0 && arrivee[2]==0){
            plateau[enclosPlayer2]=3;
            printf("Vous avez sorti un canasson !");
        }else if(chevalSurPlateau(plateau,4,arrivee)==0 && arrivee[3]==0){
            plateau[enclosPlayer2]=4;          
            printf("Vous avez sorti un canasson !");
        }else{
            printf("Vous avez deja sorti tous vos canassons, vous ne pouvez pas en sortir d'autres\n");
            return 0;
        }
    }
}


void affichagePlateau(int *plateau,int player1,int player2, int *arrivee){
    printf("Plateau de jeu: \n");
    if(chevalSurPlateau(plateau,1,arrivee)==0 && arrivee[0]==0){//Enclos joueur 1
        color(0,player1);
        printf("1");
    }else{
        color(0,7);
        printf(" ");
    }
    color(15,0); printf("\n");
    if(chevalSurPlateau(plateau,2,arrivee)==0 && arrivee[1]==0){
        color(0,player1);
        printf("2");
    }else{
        color(0,7);
        printf(" ");
    }
    color(15,0); printf("\n");
    for(int i=0;i<16;i++){//Première ligne du plateau
        afficherCase(plateau,player1,player2,i);
    }
    color(15,0);
    printf("\n");
    afficherCase(plateau,player1,player2,33);
    color(7,0);
    for(int i=1;i<15;i++) printf("|");//affiche 15 espaces
    afficherCase(plateau,player1,player2,16);
    color(15,0);
    printf("\n");
    for(int i=32;i>16;i--){//Deuxième ligne du plateau
        afficherCase(plateau,player1,player2,i);
    }
    color(15,0);
    printf("\n");
    for(int i=0;i<15;i++) printf(" ");
    if(chevalSurPlateau(plateau,3,arrivee)==0 && arrivee[2]==0){//Enclos joueur 2
        color(0,player2);
        printf("1");
    }else{
        color(0,7);
        printf(" ");
    }
    color(15,0); printf("\n");
    for(int i=0;i<15;i++) printf(" ");
    if(chevalSurPlateau(plateau,4,arrivee)==0 && arrivee[3]==0){
        color(0,player2);
        printf("2");
    }else{
        color(0,7);
        printf(" ");
    }
    color(15,0); printf("\n");
    printf("Canassons arrives:\n");
    color(player1,0);
    printf("Joueur 1: ");
    for(int i=0;i<2;i++){
        if(arrivee[i]==1){
            color(0,player1); printf("%d",i+1);
        }else{
            color(0,7); printf(" ");
        }
    }
    color(15,0); printf("\n");
    color(player2,0);
    printf("Joueur 2: ");
    for(int i=2;i<4;i++){
        if(arrivee[i]==1){
            color(0,player2); printf("%d",i-1);
        }else{
            color(0,7); printf(" ");
        }
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

int coordCheval(int *plateau, int id_cheval, int *arrivee){
        for(int i=0;i<34;i++){
            if(plateau[i]==id_cheval){
                return i;
        }
    }  
    return -1;    
}

int tourDeJeux(int *plateau, int player, int *arrivee){
    printf("Au tour du joueur %d de jouer\n", player);
    system("pause");
    int pion=1;//Premier pion du joueur
    if(player==2) pion=3;

    int resultatDe=tirageDe();
    if(resultatDe==6 && (chevalSurPlateau(plateau, pion, arrivee)==0 || chevalSurPlateau(plateau, pion+1, arrivee)==0)){
        printf("Le de est tombe sur un six, vous pouvez donc sortir un canasson, tapez 1 pour accepter ou 0 pour refuser\n");
        int input=0;
        scanf("%d",&input);
        if(input==1){
            sortirCheval(plateau,player,arrivee);
            return 1;
        }else{
            printf("Vous ne sortez pas de canassons, maintenant passons à la suite du tour\n");
        }
    }

    if(chevalSurPlateau(plateau, pion, arrivee)==0 && chevalSurPlateau(plateau, pion+1, arrivee)==0){
        printf("Vous n'avez aucun canasson sur le plateau, vous ne pouvez donc pas jouer, passont au tour suivant.\n");
        return 0;
    }
    printf("Voulez vous avancer un canasson (0) ou passez votre tour (1)? ");
    int input=0;
    scanf("%d",&input);
    if(input==1){
        printf("Vous avez passe votre tour.\n");
        return 0;
    }
    int id_canasson;
    if(chevalSurPlateau(plateau, pion, arrivee)+chevalSurPlateau(plateau, pion+1, arrivee)==2){
        do{
        printf("Vous avez plusieurs canassons sur le plateau, lequel voulez vous avancer ? (1/2) ");
        scanf("%d",&id_canasson);
        }while(id_canasson!=1 && id_canasson!=2);
        id_canasson=id_canasson-1+pion;//id_canason-1 (0 ou 1) +pion (1 ou 3)=pion 1 à 4
    }else{
        if(chevalSurPlateau(plateau, pion, arrivee)==1){
            id_canasson=pion;
        }else{
            id_canasson=pion+1;
        }
    }
    avancerCheval(plateau, id_canasson, resultatDe, arrivee);
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