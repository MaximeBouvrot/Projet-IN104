#ifndef __MOT_MYSTERE_H__
#define __MOT_MYSTERE_H__
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int nombre_de_mot(FILE* texte);
void mot_ideal_dico(FILE* texte,char* mot_ideal);
int nombrealea(int n);
int choisir_un_mot_alea(int alea, char* mot, FILE* texte );

#endif
