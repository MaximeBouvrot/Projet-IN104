#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int cherche(char *s, char carac){
    int i;
    for(i = 0; s[i] != '\0';i++)
        if(s[i] == carac)
            return i;
    return 6;
}


int comparaison(char*mot_utilisateur, char*mot){
    /*char t[5];
    for (int i=0; i<5; i++){
        t[i]=0;
    }*/
    for (int i=0; i<5; i++){
        char lettre_courante =mot_utilisateur[i];
        int position = cherche(mot,lettre_courante);
        if (position == 6){
            printf(" %c lettre noire \n",lettre_courante);
        } else {
            if (position == i ){
                printf(" %c lettre verte \n",lettre_courante);
            } else {
                printf(" %c lettre jaune \n",lettre_courante);
            }            
        }
    }
    printf("vous pouvez saisir un nouveau mot\n");
    return 0;
}
