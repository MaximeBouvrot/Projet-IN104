#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "mot_valide.h"
#include "mot_mystere.h"


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
    fclose(dico);
    int p = nombrealea(n);
    char* mot = malloc(sizeof(char));
    choisir_un_mot_alea(p, mot);
    printf("nombre de lignes : %d\nnombre aléatoire : %d\nmot mystère : %s\n",n,p,mot);

    //On demande un mot à l'utilisateur et on vérifie que son mot est valide (5 lettre et  existe ds le dico)
    char* mot_utilisateur=malloc(26*sizeof(char));
    scanf("%s",mot_utilisateur);
    while (! mot_valide(mot_utilisateur, dico)){
        scanf("%s",mot_utilisateur);
        fclose(dico);  
        FILE* dico = fopen("dico.txt","r");
        // alternative avec rewind
        void rewind(FILE* dico);
        }
    
    //On compare le mot de l'utilisateur et le mot mystère
	int i=1;
	while (strcmp(mot_utilisateur,mot)!=0 || i<6){
        //On regarde les différences et on les liste

        //On fait un affichage qui permet à l'utilisateur de savoir les positions/ce qui est faux

    i+=1;
    }

    if (strcmp(mot_utilisateur,mot)!=0){
        printf("Perdu, relance le jeu pour réessayer");
        return 0;
    }

    else {
        printf("Bravo, félicitations c'était bien %s",mot );
        return 0;
    }
    
    free(mot);

}

