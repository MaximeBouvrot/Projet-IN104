#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool mot_valide (char* mot_utilisateur, FILE* dico){
    if (strlen(mot_utilisateur)!=5){
        printf("Le mot ne fait pas 5 lettres.\n");
        return false;
        }
    
    char* mot_courant=malloc(26*sizeof(char));
    fscanf(dico,"%s",mot_courant);
    printf("mot courant : %s\n",mot_courant);
    while (strcmp(mot_utilisateur,mot_courant)!=0){
        fscanf(dico,"%s",mot_courant);
        /*if (strlen(mot_courant)==5){
            printf("mot courant : %s\n",mot_courant);
        }*/
        if(feof(dico) != 0){
            printf("fin du fichier, le mot n'est pas dans le dico\n");
            return false;
        }
    }
    printf("le mot est bien dans le dico\n");
    
    free(mot_courant);
    return true;
}

int main(void){

    // ouvrir le dico 

    FILE* dico = fopen("dico.txt","r");

    // on vérifie que le dico est bien ouvert 
    if (dico == NULL){
        printf("\nImpossible de charger le dictionnaire\n");
        return 0;
    }
    char* mot_utilisateur = "voter";
    mot_valide(mot_utilisateur, dico);
    printf("lettre no1 : %d\n",mot_utilisateur[0]);

    return 0;
}