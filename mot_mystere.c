#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char* alphabet = "abcdefghijklmnopqrstuvwxyz";

int cherche_max(int* t){
    int max = 0, indice = 0;
    for (int i =0; i<26; i++){
        if(t[i]>max ){
            max = t[i];
            indice = i;
        }
    }
    return indice;
}

void mot_ideal_dico(FILE* texte,char* mot_ideal){
    int t_lettres[26];
    for(int i=0; i<26; i++){t_lettres[i]=0;}
    char* c = malloc(25*sizeof(char));
    while (! feof(texte)){
        fscanf(texte,"%s",c);
        for (int i =0; i<strlen(c); i++){
            for (int k = 0; k<strlen(alphabet); k ++){
                if (c[i]==alphabet[k]){
                    t_lettres[k] ++;
                }
            }
        }
    }
    // for (int i =0; i<26; i++){
    //     printf("occurence lettre %c : %d\n",alphabet[i], t_lettres[i] );
    // }
    int k =0;
    while(strlen(mot_ideal)!=5){
        int indice = cherche_max(t_lettres);
        mot_ideal[k]= alphabet[indice];
        t_lettres[indice] = 0;
        k ++ ;
    }
    free(c);
    rewind(texte);
    return ;
}

int nombre_de_mot(FILE* texte){
    int nb_lignes = 0 ;
    char* c = malloc(25*sizeof(char));
    while (! feof(texte)){
        fscanf(texte,"%s",c);
        nb_lignes ++ ;
    }
    free(c);
    rewind(texte);
    return nb_lignes;
}

int nombrealea(int n){
    return (rand() % n);
}

int choisir_un_mot_alea(int alea, char* mot, FILE* texte ){
    int j = 0;
    while(j != alea){
        fscanf(texte,"%s",mot);
        j ++;
    }
    while (strlen(mot)!=5){
        fscanf(texte,"%s",mot);
        j++;
        }
    rewind(texte);
    return(j);
} 
