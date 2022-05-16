#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


int cherche(char *s, char carac){
    for(int i = 0; s[i] != '\0';i++)
        if(s[i] == carac)
            return i;
    return 6;
}

char* oter(int i, char* mot){
    char* mot_copie = malloc(26*sizeof(char));
    for (int k=0; k<5; k++){
        if (k != i){
            mot_copie[k]= mot[k];
        }
        else {
            mot_copie[k]= ' ' ;
        }
    }
    return mot_copie ;
}

int comparaison(char*mot_utilisateur, char*mot, int* tableau){
    /* 
        Principe du code : 
        On créé un tableau de 5 entiers initialisés à 0.
        On commence par traiter les lettres vertes. On créé une copie du mot où les lettres vertes sont remplacées par des
        espaces, qu'on nomme mot_jaune (il n'y a plus que des espaces ou des lettres jaunes ou noires dedans). 
        On traite ensuite les lettres jaunes. On créé une copie du mot_jaune où les lettres vertes sont remplacées par des
        espaces, qu'on nomme mot_noir.
        On complète pour chaque étape le tableau : 2 si vert, 1 si jaune, 0 si noir.
        On affiche ensuite les lettres avec leur couleur.
    */
    for(int i=0; i<5; i++){tableau[i]=0;}
    char* mot_jaune =malloc(26*sizeof(char)); //il n'y aura plus que des lettres jaunes et noires dedans
    char* mot_noir = malloc(26*sizeof(char)); //il n'y aura plus que des lettres noires dedans
    char* mot_utilisateur_jaune = malloc(26*sizeof(char));
    char* mot_utilisateur_noir = malloc(26*sizeof(char));

    mot_jaune = mot;
    mot_utilisateur_jaune = mot_utilisateur;
    for (int i=0; i<5; i++){
        char lettre_courante =mot_utilisateur[i];
        int position = cherche(mot_jaune,lettre_courante);
        if (position == i ){
                printf("%c\n",lettre_courante);
                tableau[i]=2;
                mot_jaune = oter(position,mot_jaune);
                mot_utilisateur_jaune = oter(position,mot_utilisateur_jaune);
            } 
    }
    for(int i=0; i<5; i++){printf("%d ",tableau[i]);}
    printf("\n");

    mot_noir= mot_jaune;
    mot_utilisateur_noir = mot_utilisateur_jaune;
    
    for (int i=0; i<5; i++){
        char lettre_courante =mot_utilisateur_noir[i];
        int position = cherche(mot_noir,lettre_courante);
        if (position < 5 && lettre_courante != ' '){
            tableau[i]=1;
            mot_noir = oter(position,mot_noir);
            mot_utilisateur_noir = oter(position,mot_utilisateur_noir);
        } 
    }
    for(int i=0; i<5; i++){printf("%d ",tableau[i]);}
    printf("\n");


    printf(" mot jaune : %s\n mot_utilisateur_jaune : %s\n",mot_jaune, mot_utilisateur_jaune);
    printf(" mot noir : %s\n mot_utilisateur_noir : %s\n",mot_noir, mot_utilisateur_noir);
    // Affichage 
    for (int i=0; i<5; i++){
        char lettre_courante =mot_utilisateur[i];
        if (tableau[i]==2){
            printf(" %c lettre verte \n",lettre_courante);
        }
        else if (tableau[i]==1){
            printf(" %c lettre jaune \n",lettre_courante);
        }
        else{
            printf(" %c lettre noire \n",lettre_courante); 
        }
    }

    free(mot_noir);
    //free(mot_jaune);
    //free(mot_utilisateur_jaune);
    free(mot_utilisateur_noir);
    printf("vous pouvez saisir un nouveau mot\n");
    return(0);
}


// int main(){
//     // char* mot_copie = oter(2,"lilas");
//     // printf("mot copié %s \n", mot_copie);
//     int t[5];
//     comparaison("lilsr","lilas",t);
//     return 0;
// }
