#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


int nombre_de_mot(FILE* texte){
    int nb_lignes = 0 ;
    
    char* c = malloc(sizeof(char));
    fscanf(texte,"%s",c);
    printf("mot : %s\n",c);
    while (! feof(texte)){
        fscanf(texte,"%s",c);
        nb_lignes ++ ;
    }
    printf("mot : %s\n",c);
    free(c);
    return nb_lignes;
}

int nombrealea(int n){
    srand(time(NULL));
    return (rand() % n);
}

void mot_aleatoire_valide(int n){
    FILE* dico = fopen("liste_francais.txt","r");
     if (dico == NULL){
        printf("\nImpossible de charger le dictionnaire\n"); 
        return ;
    }
    int j = 0;
    char* c = malloc(sizeof(char));
    while(j != n){
        fscanf(dico,"%s",c);
        j ++;
    }
    while (strlen(c)!=5){
        fscanf(dico,"%s",c);
        }
    printf("mot aléatoire est : %s\n",c);
    free(c);
    return ;
} 


int main(){
    FILE* dico = fopen("liste_francais.txt","r");
    if (dico == NULL){
       printf("\nImpossible de charger le dictionnaire\n"); 
       return 0;
    }
    int n = nombre_de_mot(dico);
    fclose(dico);
    int p = nombrealea(n);

    mot_aleatoire_valide(p);
    
    return printf("nombre de lignes : %d\nnombre aléatoire : %d\n",n,p);
}