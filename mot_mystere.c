#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


int nombre_de_mot(FILE* texte){
    int nb_lignes = 0 ;
    
    char* c = malloc(sizeof(char));
    while (! feof(texte)){
        fscanf(texte,"%s",c);
        nb_lignes ++ ;
    }
    free(c);
    return nb_lignes;
}

int nombrealea(int n){
    srand(time(NULL));
    return (rand() % n);
}

void choisir_un_mot_alea(int n, char* mot ){
    FILE* dico = fopen("liste_francais.txt","r");
     if (dico == NULL){
        printf("\nImpossible de charger le dictionnaire\n"); 
        return ;
    }
    int j = 0;
    while(j != n){
        fscanf(dico,"%s",mot);
        j ++;
    }
    while (strlen(mot)!=5){
        fscanf(dico,"%s",mot);
        }
} 

