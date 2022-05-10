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

char* oter(int i, char* mot){
    char* mot_copie = malloc(26*sizeof(char));
    //char* mot_copie[5];
    int j = 0;
    for (int k=0; k<5; k++){
        if (k != i){
            mot_copie[j]= mot[k];
            printf("%c\n",mot_copie[k]);
            j++;
        }
    }
    printf("fin\n");
    return mot_copie ;
}

int comparaison(char*mot_utilisateur, char*mot){
    for (int i=0; i<5; i++){
        char lettre_courante =mot_utilisateur[i];
        int position = cherche(mot,lettre_courante);
        if (position == 6){
            printf(" %c lettre noire \n",lettre_courante);
        } 
        else {
            if (position == i ){
                printf(" %c lettre verte \n",lettre_courante);
            } 
            else {
                printf(" %c lettre jaune \n",lettre_courante);
            }            
        }
    }
    printf("vous pouvez saisir un nouveau mot\n");
    return 0;
}

int main(){
    char* mot_copie = oter(2,"lilas");
    printf("mot copié %s \n", mot_copie);
    //comparaison("lilas","alors");
    free(mot_copie);
    return 0;
}