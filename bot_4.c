#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "mot_mystere.h"
#include "mot_valide.h"
#include "contraintes.h"

char* bot_4(FILE* texte, char* mot_buffer,int* tableau,char* mot_noir,int* z){

    noir_ajout(tableau, mot_noir, mot_buffer);
    rewind(texte);
    *z=choisir_un_mot_alea(*z, mot_buffer,texte)+1;
    printf("%s\n",mot_buffer);
    rewind(texte);
    while(!noir_valide(mot_noir,mot_buffer)){    
        while (!mot_valide(mot_buffer,texte)){
            rewind(texte);
            *z=choisir_un_mot_alea(*z, mot_buffer,texte)+1;
            rewind(texte);
        }
        printf("hello %s\n",mot_buffer);
        rewind(texte);
        *z=choisir_un_mot_alea(*z, mot_buffer,texte)+1;
        rewind(texte);
    }
    printf("%s",mot_buffer);
    return(mot_buffer);
}