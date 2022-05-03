#include <stdio.h>

int search (char *s, char carac)
{
    int i;
    for(i = 0; s[i] != '\0';i++)
        if(s[i] == carac)
            return i;
    return 0;
}
 
int main (void)
{
    char *s = "abcdefghijklmnopqrstuvwxyz";
    char c = 'k';
    int pos = search(s, c);
    printf("caractere %c à la position %d, \ndans la chaine %s", c, pos, s);
    printf("caractere %c à la position %d, \ndans la chaine %s", c, pos, s);
    return 0;
}

 //On demande un mot à l'utilisateur et on vérifie que son mot est valide (5 lettres et  existe ds le dico)
    
    char* mot_utilisateur=malloc(26*sizeof(char));
    scanf("%s",mot_utilisateur);
    while (! mot_valide(mot_utilisateur, dico)){
        scanf("%s",mot_utilisateur);
        fclose(dico);  
        FILE* dico = fopen("dico.txt","r");
        // alternative avec rewind
        void rewind(FILE* dico);
        }





int main(void){

    // ouvrir le dico 

    FILE* dico = fopen("dico.txt","r");

    // on vérifie que le dico est bien ouvert 
    if (dico == NULL){
        printf("\nImpossible de charger le dictionnaire\n");
        return 0;
    }
    char mot_utilisateur[25] = "voter";
    mot_valide(mot_utilisateur, dico);
    char l = mot_utilisateur[1];
    printf("lettre no1 : %c\n",l);

    return 0;
}