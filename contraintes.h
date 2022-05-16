#ifndef __CONTRAINTES_H__
#define __CONTRAINTES_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


bool vert_valide(char* mot_vert, char* mot_buffer);
void init_mot_vert(char*mot_vert);
void vert_ajout(int*tableau, char* mot_vert, char* mot_precedent);
void init_mot_bot (char* mot_bot);
bool noir_valide(char* mot_noir, char* mot_buffer);

#endif
