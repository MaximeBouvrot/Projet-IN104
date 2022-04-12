#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int nombre_de_mot(FILE* texte){
    int nb_lignes = 0 ;
    fscanf(texte);
    while (texte != feof){
        fscanf(texte);
        nb_lignes ++ ;
    }

}

int nombrealea(int n){
    srand(time(NULL));
    return (rand() % n);
}


char* choisir_un_mot_alea(FILE* dico ){
    int n = nombre_de_mot(dico);
    int aleat = nombrealea(n);
    while(n>0){
        fscanf(dico);
    }
    char* mot_alea;
    fscanf(dico,"%s",&mot_alea);
    return mot_alea ;
}






int main(){

    // ouvrir le dico 

    FILE* dico = fopen("/home/mahe/Documents/Cours 1A/in104/Projet-IN104/dico.txt","r");

    // on vérifie que le dico est bien ouvert 
    if (dico == NULL){
        printf("\nImpossible de charger le dictionnaire\n");
        return 0;
    }

    choisir_un_mot_alea(dico);


}

