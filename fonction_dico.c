#include <stdlib.h>
#include <stdio.h>
#include <time.h>



int nombre_de_mot(FILE* texte){
    int nb_lignes = 0 ;
    
    char* c = malloc(sizeof(char));
    fscanf(texte,"%s",c);

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


char* choisir_un_mot_alea(FILE* dico ){
    int n = nombre_de_mot(dico);
    int aleat = nombrealea(n);
    while(n>0){
        fscanf(dico);
    }
    char* mot_alea;
    fscanf(dico,"%s",&mot_alea);
    return mot_alea ;
}


