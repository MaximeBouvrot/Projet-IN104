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

    // On choisit un mot de 5 lettres dans le dictionnaire
        mot_mystere=choisir_un_mot_alea(dico);


    //On demande un mot à l'utilisateur et on vérifie que son mot est valide (5 lettre et  existe ds le dico)
    char* mot_utilisateur=malloc (sizeof(char));
    scanf("%s",mot_utilisateur);
    while (! mot_valide(mot_utilisateur, dico)){
        scanf("%s",mot_utilisateur);
        }
    
    //On compare le mot de l'utilisateur et le mot mystère
	int i=1;
	while (strcmp(mot_utilisateur,mot_mystere)!=0 || i<6){
        //On regarde les différences et on les liste

        //On fait un affichage qui permet à l'utilisateur de savoir les positions/ce qui est faux

    i+=1;
    }

    if (strcmp(mot_utilisateur,mot_mystere)!=0){
        printf("Perdu, relance le jeu pour réessayer")
        return 0
    }

    else {
        printf("Bravo, félicitations c'était bien %s",mot_mystere )
        return 0
    }
}

