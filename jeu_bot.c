#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "mot_valide.h"
#include "mot_mystere.h"
#include "comparaison.h"
#include "bot_1.h"
#include "bot_2.h"
#include "contraintes.h"


int main(void){

    srand(time(NULL));

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
    char* mot = malloc(26*sizeof(char));
    choisir_un_mot_alea(p, mot, dico);
    printf("nombre de lignes : %d\nnombre aléatoire : %d\nmot mystère : %s\n",n,p,mot);
    rewind(dico);

    //Sélection du mode de jeu entre l'utilisateur et les différents bots
    
    int mode=2;

    //Comparaison des mots utilisateur et du mot mystère :
    int i=1;
    char* mot_utilisateur=malloc(26*sizeof(char));
    int t[5];

    switch(mode){
        case 0:
            
    printf("veuillez saisir un mot de 5 lettres\n");
    scanf("%s",mot_utilisateur);
	while (strcmp(mot_utilisateur,mot)!=0 && i<6){
        if (mot_valide(mot_utilisateur,dico)== true){
            comparaison(mot_utilisateur,mot,t);
            i+=1;
        }
        scanf("%s",mot_utilisateur);
        rewind(dico);

    }
        break;
        
        case 1:
    mot_utilisateur = bot_1(dico,mot_utilisateur);
    printf("%s",mot_utilisateur);
	while (strcmp(mot_utilisateur,mot)!=0 && i<6){
            comparaison(mot_utilisateur,mot,t);
        i+=1;
        mot_utilisateur = bot_1(dico,mot_utilisateur);
        printf("%s",mot_utilisateur);
    }

        break;

        case 2:
    mot_utilisateur = bot_1(dico,mot_utilisateur);
    int t[5];
    char* mot_vert = malloc(5*sizeof(char));
    printf("hello");
    init_mot_vert(mot_vert);
	while (strcmp(mot_utilisateur,mot)!=0 && i<6){
        comparaison(mot_utilisateur,mot,t);
        i+=1;
        mot_utilisateur = bot_2(dico,mot_utilisateur,t,mot_vert);
    }
    free(mot_vert);
        break;

    }


    //Affichage des résultats :

    if (strcmp(mot_utilisateur,mot)!=0){
        printf("Perdu, relance le jeu pour réessayer\n");
        return 0;
    }

    else {
        printf("Bravo, félicitations c'était bien %s, tu l'as trouvé en %d tentatives\n",mot,i );
        return 0;
    }
    free(mot_utilisateur);
    fclose(dico);

}

