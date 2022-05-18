#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "mot_mystere.h"
#include "mot_valide.h"
#include "contraintes.h"

char* bot_4(FILE* texte, char* mot_buffer,int* tableau,char* mot_noir,char* mot_v,int* z){

    vert_ajout(tableau,mot_v, mot_buffer);
    noir_ajout(tableau, mot_noir, mot_buffer, mot_v);
    rewind(texte);

    *z=choisir_un_mot_alea(*z, mot_buffer,texte)+1;
    while ((!vert_valide(mot_v,mot_buffer)||!noir_valide(mot_noir,mot_buffer))||!mot_valide(mot_buffer,texte)){
                rewind(texte);
                *z=choisir_un_mot_alea(*z, mot_buffer,texte)+1;
    }
    return(mot_buffer);
}