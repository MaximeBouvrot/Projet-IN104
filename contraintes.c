#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void vert_ajout(int*tableau, char* mot_vert, char* mot_precedent){
    for (int i=0;i<5;i++){
        if (tableau[i]==2){
            mot_vert[i]=mot_precedent[i];
        }
        
    }
}

void noir_ajout(int*tableau, char* mot_noir, char* mot_precedent){
    for (int i=0;i<5;i++){
        if (tableau[i]==0){
            if (!(strchr(mot_noir,mot_precedent[i]))){}
        }
    }
}

void init_mot_vert(char*mot_vert){
    for (int i=0;i<5;i++){
        mot_vert[i]='*';
    }
}


void init_mot_bot (char* mot_bot){
    mot_bot[0]='s';
    mot_bot[1]='o';
    mot_bot[2]='a';
    mot_bot[3]='r';
    mot_bot[4]='e';
}

bool vert_valide(char* mot_vert, char* mot_buffer){
    for (int i=0;i<5;i++){
        if (mot_vert[i]!='*'){
            if (mot_buffer[i]!=mot_vert[i]){
                return false;
            }
        }    
    }
    return true;
}

bool noir_valide(char* mot_noir, char* mot_buffer){
    for (int i=0;i<strlen(mot_noir);i++){
        for (int j=0;i<strlen(mot_buffer);i++){
            if (mot_noir[i]!=mot_buffer[j]){
                return false;
            }
        }    
    }
    return true;
}