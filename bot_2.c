#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "mot_mystere.h"
#include "mot_valide.h"
#include "contraintes.h"

char* bot_2(FILE* texte, char* mot_buffer,int* tableau, char* mot_vert){

    vert_ajout(tableau, mot_vert, mot_buffer);
    rewind(texte);
    int n = nombre_de_mot(texte);
    int k = nombrealea(n);
    choisir_un_mot_alea(k, mot_buffer,texte);
    printf("%s\n",mot_buffer);
    rewind(texte);
    while(!vert_valide(mot_vert,mot_buffer)){    
        while (!mot_valide(mot_buffer,texte)){
            rewind(texte);
            int p = nombrealea(n);
            choisir_un_mot_alea(p, mot_buffer,texte);
            rewind(texte);
        }
        printf("hello %s\n",mot_buffer);
        rewind(texte);
        int p = nombrealea(n);
        choisir_un_mot_alea(p, mot_buffer,texte);
        rewind(texte);
    }
    printf("%s",mot_buffer);
    return(mot_buffer);
}