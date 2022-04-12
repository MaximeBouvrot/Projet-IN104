#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <stdbool.h>
#include "mot_valide.h"


int main(){

    // ouvrir le dico 

    FILE* dico = fopen("/home/mahe/Documents/Cours 1A/in104/Projet-IN104/dico.txt","r");

    // on vérifie que le dico est bien ouvert 
    if (dico == NULL){
        printf("\nImpossible de charger le dictionnaire\n");
        return 0;
    }

        choisir_un_mot_alea(dico);


    char* mot_utilisateur=malloc (sizeof(char));
    scanf("%s",mot_utilisateur);
    while (! mot_valide(mot_utilisateur, dico)){
        scanf("%s",mot_utilisateur);
        }

}

