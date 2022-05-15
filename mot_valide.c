#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool mot_valide (char* mot_utilisateur, FILE* dico){
    rewind(dico);
    if (strlen(mot_utilisateur)!=5){
        printf("Le mot ne fait pas 5 lettres.\n");
        return false;
        }
    
    char* mot_courant=malloc(26*sizeof(char));
    while  (strcmp(mot_utilisateur,mot_courant)!=0){
        if (fscanf(dico, "%s ", mot_courant) == EOF ){
            printf("fin du fichier, le mot n'est pas dans le dico\n");
            printf("vous pouvez saisir un nouveau mot\n");
            free(mot_courant);
            return false;
            }
        
        while (strlen(mot_courant)!=5){
            if (fscanf(dico,"%s",mot_courant)==EOF){
                printf("fin du fichier, le mot n'est pas dans le dico\n");
                printf("vous pouvez saisir un nouveau mot\n");
                free(mot_courant);
                return false;
            }
        }
    }

    printf("le mot est bien dans le dico\n");
    free(mot_courant);
    return true;
}
