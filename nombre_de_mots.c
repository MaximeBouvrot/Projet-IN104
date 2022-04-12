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

int main(){

    FILE* dico = fopen("/home/mahe/Documents/Cours 1A/in104/Projet-IN104/liste_francais.txt","r");

    // on vérifie que le dico est bien ouvert 
    if (dico == NULL){
        printf("\nImpossible de charger le dictionnaire\n"); 
        return 0;
    }
    int n = nombre_de_mot(dico);
     fclose(dico);

     int p = nombrealea(n);

    return printf("nombre de lignes : %d\nnombre aléatoire : %d\n",n,p);
}