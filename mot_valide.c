#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool mot_valide (char* mot_utilisateur, FILE* dico){
    if (strlen(mot_utilisateur)!=5){
        printf("Le mot ne fait pas 5 lettres.\n");
        return false;
        }
    
    char* buffer=malloc(26*sizeof(char));
    while (fscanf(dico,"%[^\n]", buffer )!=EOF){
        if (buffer==mot_utilisateur)
            {return true;
    }
    }
    printf("Le mot n'est pas dans le dictionnaire.\n");
    return false;
}
