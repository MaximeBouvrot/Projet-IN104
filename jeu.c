#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "mot_valide.h"
#include "mot_mystere.h"
#include "comparaison.h"


int main(void){

    // ouvrir le dico 

    FILE* dico = fopen("dico.txt","r");

    // on vérifie que le dico est bien ouvert 
    if (dico == NULL){
        printf("\nImpossible de charger le dictionnaire\n");
        return 0;
    }

    // On choisit un mot de 5 lettres dans le dictionnaire
    int n = nombre_de_mot(dico);
    int p = nombrealea(n);
    char* mot = malloc(sizeof(char));
    choisir_un_mot_alea(p, mot);
    printf("nombre de lignes : %d\nnombre aléatoire : %d\nmot mystère : %s\n",n,p,mot);

    //Comparaison des mots utilisateur et du mot mystère :
    rewind(dico);
    printf("veuillez saisir un mot de 5 lettres\n");
	int i=1;
    char* mot_utilisateur=malloc(26*sizeof(char));
    scanf("%s",mot_utilisateur);
	while (strcmp(mot_utilisateur,mot)!=0 && i<6){
        if (mot_valide(mot_utilisateur,dico)== true){
            comparaison(mot_utilisateur,mot);
        }
        i+=1;
        scanf("%s",mot_utilisateur);

    }

    free(mot_utilisateur);
    fclose(dico);

    //Affichage des résultats :

    if (strcmp(mot_utilisateur,mot)!=0){
        printf("Perdu, relance le jeu pour réessayer\n");
        return 0;
    }

    else {
        printf("Bravo, félicitations c'était bien %s, tu l'as trouvé en %d tentatives\n",mot,i );
        return 0;
    }
}

