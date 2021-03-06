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
#include "bot_3.h"
#include "bot_4.h"
#include "contraintes.h"


int main(void){

    srand(time(NULL));
    float temps;
    clock_t t1,t2;
    t1=clock();


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
    rewind(dico);

    //Sélection du mode de jeu entre l'utilisateur et les différents bots
    printf("Veuillez saisir le mode.\n 0 pour jouer manuellement\n 1 pour le bot 1 \n 2 pour le bot 2\n 3 pour le bot 3\n 4 pour le bot 4\n");
    printf("mode choisi : ");
    int mode = 0;
    scanf("%d",&mode);
    if (mode!=0){
        printf("mot mystère : %s\n",mot);
    }

    //Comparaison des mots utilisateur et du mot mystère :
    int i=1;
    char* mot_utilisateur=malloc(26*sizeof(char));
    int t[5];
    char* mot_vert = malloc(5*sizeof(char)); 
    int* indice=malloc(2*sizeof(int));

    switch(mode){
        case 0:;
            
    printf("Veuillez saisir un mot de 5 lettres : ");
    //printf("mot utilisateur : %s\n",mot_utilisateur);

    scanf(" %s",mot_utilisateur);
	while (strcmp(mot_utilisateur,mot)!=0 && i<7){
        if (mot_valide(mot_utilisateur,dico)== true){
            comparaison(mot_utilisateur,mot,t);
            i+=1;
        }
        if (i<7){
            printf("Veuillez saisir le mot numéro %d : ",i);
            scanf("%s",mot_utilisateur);
            rewind(dico);
        }
    }
        break;
        
        case 1:;
    mot_utilisateur = bot_1(dico,mot_utilisateur);
    printf("mot testé : %s\n",mot_utilisateur);
	while (strcmp(mot_utilisateur,mot)!=0 && i<6){
            comparaison(mot_utilisateur,mot,t);
        i+=1;
        mot_utilisateur = bot_1(dico,mot_utilisateur);
        printf("mot testé : %s\n",mot_utilisateur);
    }

        break;

        case 2:;
    
    *indice=choisir_un_mot_alea(1, mot_utilisateur,dico);  
     
    init_mot_vert(mot_vert);
    while (strcmp(mot_utilisateur,mot)!=0){
        comparaison(mot_utilisateur,mot,t);
        i+=1;
        mot_utilisateur = bot_2(dico,mot_utilisateur,t,mot_vert,indice);
        printf("mot testé : %s\n",mot_utilisateur);

    }
        break;


        case 3:;
    *indice=choisir_un_mot_alea(1, mot_utilisateur,dico);   
    init_mot_vert(mot_vert);
    init_mot_bot(mot_utilisateur);
    while (strcmp(mot_utilisateur,mot)!=0){
        comparaison(mot_utilisateur,mot,t);
        i+=1;
        mot_utilisateur = bot_3(dico,mot_utilisateur,t,mot_vert,indice);
        printf("mot testé : %s\n",mot_utilisateur);

    }
        break;


        case 4:;
    char* mot_ideal = malloc(25*sizeof(char));
    mot_ideal_dico(dico, mot_ideal);
    printf("Mot idéal pour ce dictionnaire : %s\n",mot_ideal);
    free(mot_ideal);

    *indice=choisir_un_mot_alea(1, mot_utilisateur,dico);
    char* mot_lettres_noires = malloc(26*sizeof(char));
    mot_lettres_noires[0]='\0';
    init_mot_vert(mot_vert);
    init_mot_bot(mot_utilisateur);

    while (strcmp(mot_utilisateur,mot)!=0){
        comparaison(mot_utilisateur,mot,t);
        i+=1;
        mot_utilisateur = bot_4(dico,mot_utilisateur,t,mot_lettres_noires,mot_vert,indice);
        printf("mot testé : %s\n",mot_utilisateur);
    }
    free(mot_lettres_noires);
        break;

    }
    
    t2=clock();

    //Affichage des résultats :

    if (strcmp(mot_utilisateur,mot)!=0){
        printf("Perdu, relance le jeu pour réessayer\n");
        printf("Le mot mystère était %s\n",mot);
        }

    else if (strcmp(mot_utilisateur,mot)==0){
        printf("Bravo, félicitations c'était bien %s, tu l'as trouvé en %d tentatives\n",mot,i );
    }
 
    temps=(float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps=%f\n",temps);
    free(mot_utilisateur);
    fclose(dico);
    free(mot_vert);
    free(indice);
    free(mot);
    return 0;
}

