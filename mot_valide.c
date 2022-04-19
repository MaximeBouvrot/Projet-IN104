bool mot_valide (char* mot_utilisateur, FILE* dico){
    if (strlen(mot_utilisateur)!=5){
        printf("Le mot ne fait pas 5 lettres.\n");
        return false;
        }
    while (fscanf(dico,"%[^\n]", buffer )!=NULL){
        if (buffer==mot_utilisateur)
            {return true;
    }
    }
    printf("Le mot n'est pas dans le dictionnaire.\n");
    return false;
}