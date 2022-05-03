#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "mot_mystere.h"
#include "mot_valide.h"

int main(){
    FILE* dico = fopen("dico.txt","r");

    int n = nombre_de_mot(dico);
    fclose(dico);
    char* mot = malloc(sizeof(char));
    rewind(dico);
    int p = nombrealea(n);
    choisir_un_mot_alea(p, mot);
    rewind(dico);

    while (!mot_valide(mot,dico)){
    printf("bonour");
    rewind(dico);
    int p = nombrealea(n);
    choisir_un_mot_alea(p, mot);
    }
    printf("%s",mot);
    fclose(dico);
    return(1);
    
}