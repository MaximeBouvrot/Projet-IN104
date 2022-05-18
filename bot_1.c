#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "mot_mystere.h"
#include "mot_valide.h"

char* bot_1(FILE* texte, char* mot_buffer){

    rewind(texte);
    int n = nombre_de_mot(texte);
    rewind(texte);
    int k = nombrealea(n);
    choisir_un_mot_alea(k, mot_buffer,texte);
    printf("%s\n",mot_buffer);
    while (!mot_valide(mot_buffer,texte)){
    rewind(texte);
    int p = nombrealea(n);
    choisir_un_mot_alea(p, mot_buffer,texte);
    }

    return(mot_buffer);
}