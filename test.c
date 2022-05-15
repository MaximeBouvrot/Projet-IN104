#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include <stdbool.h>

#include "contraintes.h"

int main (void)
{

    char* s = malloc(5*sizeof(char));
        for (int i=0;i<5;i++){
    s[i]='*';}

    char *c = "azect";

    if (vert_valide(s,c)){
        printf("hello");
    }
    printf("%c,%c \n", s[3],c[3]);
    if (s[2]=='*'){
        printf("heo\n");
    }
    
    int t[5];
    t[0]=1;
    t[1]=2;
    t[2]=0;
    t[3]=1;
    t[4]=1;
    vert_ajout(t,s,c);
    printf("%s",s);
    free(s);
    return 0;
}