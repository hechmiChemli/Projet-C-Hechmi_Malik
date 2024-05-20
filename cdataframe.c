//
// Created by hechm on 08/05/2024.
//

#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string.h>
#include "colonne.h"
#include "cdataframe.h"
#include "cdataframe.h"




COLUMN* create_column(char* titre) {
    COLUMN* colonne = (COLUMN*)malloc(sizeof(COLUMN));
    if (colonne == NULL) {
        return NULL;
    }


    colonne->titre = (char*)malloc(strlen(titre) + 1); // +1 pour le caractère nul '\0'
    // La vérification du résultat de malloc est omise ici, mais elle est fortement recommandée.
    strcpy(colonne->titre, titre); // Copie le titre dans l'espace nouvellement alloué


    colonne->donnee = NULL; // Initialise à NULL car il n'y a pas de données au début
    colonne->taille_logique = 0; // La taille logique est 0 car il n'y a pas encore d'éléments
    colonne->taille_physique = 0; // La taille physique est 0 car aucune allocation pour les données n'est faite


    return colonne;// Retourne le pointeur vers la nouvelle structure COLUMN


}
int insert_value(COLUMN* colonne,int value)
{

    if (colonne->taille_logique==colonne->taille_physique){



        int *nvl_donnee=realloc(colonne->donnee, 256 * sizeof(int));
        if (nvl_donnee== NULL){//si la nouvelle donnee n'a pas ete allouer en memoire ,donc que la valeur n'a pax ete inserer car pas reussi a augmenter la taille du tableau eet l'allocation en memoire de l'ordi
            return 0;
        }
        colonne->donnee=nvl_donnee;
        colonne->taille_physique+=256;//mise a jour des attributs de la colonne





    }
    colonne->donnee[colonne->taille_logique]=value;
    colonne->taille_logique++;
    return 1;


}

void delete_column(COLUMN **colonne) {
    if (*colonne !=NULL){//si le pointeur qui pointe vers la colonne n'est pas vide ,donc pointe vers quelqun ,donc la colonne à de la memoire,on libere de la memoire
        free((*colonne)->donnee);//libere de la memeoire sur le tableau de donnee
        free(*colonne);//libere de la memoire de la colonne elle meme car le pointeur pointe vers la structure
        // Mettre le pointeur de la colonne à NULL pour éviter les références invalides
        *colonne = NULL;

    }

}
void print_col(COLUMN *colonne) {
    if (colonne == NULL) {
        printf("La colonne est vide ! Veuillez la remplir\n");
        return;
    }

    for (int i = 0; i < colonne->taille_logique; i++) {
        printf("[%d] %d\n", i, colonne->donnee[i]);
    }
}
void nombre_occurence(COLUMN *colonne,int x){
    if (colonne == NULL) {
        printf("La colonne est vide ! Veuillez la remplir\n");
        return;
    }int val=0;
    for (int i=0;i< colonne->taille_logique;i++){
        if (colonne->donnee[i]==x){
            val+=1;
        }

    }printf("le nombre d'occurence de la valeur %d est %d\n",x,val);

}
int  get_val_pos(COLUMN *colonne,int x){
    if (colonne == NULL) {
        printf("La colonne est vide ! Veuillez la remplir\n");
        return -1;
    }
    if (x<0 || x>=colonne->taille_logique){
        printf("L'indice dépasse la limite ! Choisis un autre ");
        return -1;

    }return colonne->donnee[x];
}
int val_superieur(COLUMN *colonne,int x){
    if (colonne == NULL) {
        printf("La colonne est vide ! Veuillez la remplir\n");
        return -1;
    }int somme=0;
    for (int i=0;i<colonne->taille_logique;i++){
        if (colonne->donnee[i]>x){
            somme+=1;

        }
    }return somme;
}
int val_inferieur(COLUMN* colonne, int x) {
    int somme = 0;
    for (int i = 0; i < colonne->taille_logique; i++) {
        if (colonne->donnee[i] < x) {
            somme++;
        }
    }
    return somme;
}

int val_egale(COLUMN* colonne, int x) {
    int somme = 0;
    for (int i = 0; i < colonne->taille_logique; i++) {
        if (colonne->donnee[i] == x) {
            somme++;
        }
    }
    return somme;
}
//IMPLEMENTATION DU CDATAFRAME
CDataframe* creation_du_cdatframe(){
    CDataframe* data_frame=malloc(sizeof(CDataframe));
    data_frame->colonnes_df=NULL;//pointeur qui pointe vers un tableau et initialisé a NULL
    data_frame->nb_col_df=0;
    data_frame->TP=0;
    return data_frame;

}
void ajouter_colonne(CDataframe* dataframe, COLUMN* colonne) {
    if (dataframe == NULL || colonne == NULL) {
        return;
    }
    if (dataframe->nb_col_df >= dataframe->TP) {
        int nvl_TP = dataframe->TP + 256;
        COLUMN** nvl_colonne = realloc(dataframe->colonnes_df, nvl_TP * sizeof(COLUMN*));
        if (nvl_colonne == NULL) {
            return;
        }
        dataframe->colonnes_df = nvl_colonne;
        dataframe->TP = nvl_TP;
    }
    dataframe->colonnes_df[dataframe->nb_col_df] = colonne;
    dataframe->nb_col_df ++;
}
// Remplissage en dur du dataframe avec des valeurs prédéfinies
void remplir_dataframe_en_dur(CDataframe* dataframe) {
    if (dataframe == NULL) { // Vérifie si le dataframe est nul
        return; // Si c'est le cas, quitte la fonction
    }
    COLUMN* colonne = create_column("Premiere colonne"); // Crée une nouvelle colonne avec le titre "Premiere colonne"
    int tableau_val[] = {10, 20, 30, 40, 50}; // Initialise un tableau de valeurs à ajouter à la colonne
    for (int i = 0; i < sizeof(tableau_val) / sizeof(int); i++) { // Parcourt le tableau de valeurs
        insert_value(colonne, tableau_val[i]); // Insère chaque valeur dans la colonne
    }
    ajouter_colonne(dataframe, colonne); // Ajoute la colonne remplie au dataframe
}

// Affichage du contenu complet du dataframe
void afficher_dataframe(const CDataframe* dataframe) {
    if (dataframe == NULL) { // Vérifie si le dataframe est nul
        printf("Le dataframe est vide !\n"); // Si c'est le cas, affiche un message d'erreur
        return; // Quitte la fonction
    }
    printf("Dataframe :\n"); // Affiche un titre pour le dataframe
    for (int i = 0; i < dataframe->nb_col_df; i++) { // Parcourt chaque colonne du dataframe
        printf("Colonne %d : ", i + 1); // Affiche le numéro de la colonne
        print_col(dataframe->colonnes_df[i]); // Affiche les valeurs de la colonne
    }
}

// Affiche une partie des lignes du dataframe selon une limite fournie par l’utilisateur
void afficher_partie_lignes(const CDataframe* dataframe, int debut, int fin) {
    if (dataframe == NULL || debut < 0 || fin >= dataframe->colonnes_df[0]->taille_logique || debut > fin) {
        // Vérifie les paramètres et la validité des indices de début et de fin
        printf("Paramètres invalides !\n"); // Affiche un message d'erreur si les paramètres sont invalides
        return; // Quitte la fonction
    }
    printf("Affichage des lignes %d à %d :\n", debut, fin); // Affiche les indices des lignes à afficher
    for (int i = debut; i <= fin; i++) { // Parcourt chaque ligne
        for (int j = 0; j < dataframe->nb_col_df; j++) { // Parcourt chaque colonne
            printf("%d\t", dataframe->colonnes_df[j]->donnee[i]); // Affiche la valeur de la cellule
        }
        printf("\n"); // Passe à la ligne suivante
    }
}

// Affiche une partie des colonnes du dataframe selon une limite fournie par l’utilisateur
void afficher_partie_colonnes(const CDataframe* dataframe, int debut, int fin) {
    if (dataframe == NULL || debut < 0 || fin >= dataframe->nb_col_df || debut > fin) {
        // Vérifie les paramètres et la validité des indices de début et de fin
        printf("Paramètres invalides !\n"); // Affiche un message d'erreur si les paramètres sont invalides
        return; // Quitte la fonction
    }
    printf("Affichage des colonnes %d à %d :\n", debut, fin); // Affiche les indices des colonnes à afficher
    for (int i = debut; i <= fin; i++) {
        printf("%s\t", dataframe->colonnes_df[i]->titre); // Affiche les titres des colonnes
    }
    printf("\n");
    for (int i = 0; i < dataframe->colonnes_df[0]->taille_logique; i++) {//Cette boucle parcourt chaque ligne du dataframe
        for (int j = debut; j <= fin; j++) {//Cette boucle parcourt chaque colonne du dataframe
            printf("%d\t", dataframe->colonnes_df[j]->donnee[i]); // Affiche la valeur de la cellule située à la ligne i et à la colonne j
        }
        printf("\n");
    }
}

// Ajoute une ligne de valeurs au dataframe
void ajouter_ligne(CDataframe* dataframe, int* valeurs, int nb_valeurs) {
    if (dataframe == NULL || valeurs == NULL || nb_valeurs != dataframe->nb_col_df) {
        // Vérifie la validité des paramètres
        printf("Paramètres invalides !\n"); // Affiche un message d'erreur si les paramètres sont invalides
        return; // Quitte la fonction
    }
    for (int i = 0; i < nb_valeurs; i++) {
        if (!insert_value(dataframe->colonnes_df[i], valeurs[i])) { // Insère chaque valeur dans la colonne correspondante
            printf("Erreur lors de l'insertion de la valeur %d dans la colonne %d\n", valeurs[i], i); // Affiche un message d'erreur si l'insertion échoue
        }
    }
}

// Supprime une ligne de valeurs du dataframe
void supprimer_ligne(CDataframe* dataframe, int index) {
    if (dataframe == NULL || index < 0 || index >= dataframe->colonnes_df[0]->taille_logique) {
        // Vérifie la validité des paramètres
        printf("Paramètres invalides !\n"); // Affiche un message d'erreur si les paramètres sont invalides
        return; // Quitte la fonction
    }
    for (int i = 0; i < dataframe->nb_col_df; i++) { // Parcourt chaque colonne
        for (int j = index; j < dataframe->colonnes_df[i]->taille_logique - 1; j++) {
            dataframe->colonnes_df[i]->donnee[j] = dataframe->colonnes_df[i]->donnee[j + 1]; // Décale les valeurs pour supprimer la ligne
        }
        dataframe->colonnes_df[i]->taille_logique--; // Décrémente la taille logique de la colonne
    }
}

// Supprime une colonne du dataframe
void supprimer_colonne(CDataframe* dataframe, int index) {
    if (dataframe == NULL || index < 0 || index >= dataframe->nb_col_df) {
        // Vérifie la validité des paramètres
        printf("Paramètres invalides !\n"); // Affiche un message d'erreur si les paramètres sont invalides
        return; // Quitte la fonction
    }
    delete_column(&(dataframe->colonnes_df[index])); // Supprime la colonne spécifiée
    for (int i = index; i < dataframe->nb_col_df - 1; i++) {
        dataframe->colonnes_df[i] = dataframe->colonnes_df[i + 1]; // Décale les colonnes pour combler le vide
    }
    dataframe->nb_col_df--; // Décrémente le nombre de colonnes
}

// Renomme le titre d'une colonne du dataframe
void renommer_titre_colonne(CDataframe* dataframe, int index, const char* nouveau_titre) {
    if (dataframe == NULL || index < 0 || index >= dataframe->nb_col_df) {
        // Vérifie la validité des paramètres
        printf("Paramètres invalides !\n"); // Affiche un message d'erreur si les paramètres sont invalides
        return; // Quitte la fonction
    }
    COLUMN* colonne = dataframe->colonnes_df[index]; // Récupère la colonne à renommer
    free(colonne->titre); // Libère l'ancienne mémoire allouée pour le titre
    colonne->titre = (char*)malloc(strlen(nouveau_titre) + 1); // Alloue de la mémoire pour le nouveau titre
    strcpy(colonne->titre, nouveau_titre); // Copie le nouveau titre dans la mémoire allouée
}

// Vérifie l'existence d'une valeur (recherche) dans le dataframe
int verifier_existence_valeur(CDataframe* dataframe, int valeur) {
    if (dataframe == NULL) { // Vérifie si le dataframe est nul
        printf("Le dataframe est vide !\n"); // Affiche un message d'erreur si c'est le cas
        return 0; // Retourne 0 pour indiquer que la valeur n'existe pas
    }
    for (int i = 0; i < dataframe->nb_col_df; i++) { // Parcourt chaque colonne
        for (int j = 0; j < dataframe->colonnes_df[i]->taille_logique; j++) { // Parcourt chaque ligne  de la colonne
            if (dataframe->colonnes_df[i]->donnee[j] == valeur) { // Vérifie si la valeur correspond
                return 1; // Retourne 1 pour indiquer que la valeur a été trouvée
            }
        }
    }
    return 0; // Retourne 0 pour indiquer que la valeur n'a pas été trouvée
}

// Accède/remplace la valeur d'une cellule du dataframe
int acceder_remplacer_valeur(CDataframe* dataframe, int ligne, int colonne, int nouvelle_valeur) {
    if (dataframe == NULL || colonne < 0 || colonne >= dataframe->nb_col_df || ligne < 0 || ligne >= dataframe->colonnes_df[colonne]->taille_logique) {
        // Vérifie la validité des paramètres
        printf("Parametre invalides\n") ;
        return 0; // Retourne 0 pour indiquer une erreur
    }
    dataframe->colonnes_df[colonne]->donnee[ligne] = nouvelle_valeur; // Remplace la valeur dans la cellule spécifiée
    return 1; // Retourne 1 pour indiquer le succès
}

// Affiche les noms des colonnes du dataframe
void afficher_noms_colonnes(CDataframe* dataframe) {
    if (dataframe == NULL) { // Vérifie si le dataframe est nul
        printf("Le dataframe est vide !\n"); // Affiche un message d'erreur si c'est le cas
        return; // Quitte la fonction
    }
    printf("Noms des colonnes :\n"); // Affiche un titre
    for (int i = 0; i < dataframe->nb_col_df; i++) { // Parcourt chaque colonne
        printf("%s\n", dataframe->colonnes_df[i]->titre); // Affiche le titre de la colonne
    }
}

// Affiche le nombre de lignes du dataframe
void afficher_nombre_lignes(CDataframe* dataframe) {
    if (dataframe == NULL || dataframe->nb_col_df == 0) { // Vérifie si le dataframe est nul ou vide
        printf("Le dataframe est vide !\n"); // Affiche un message d'erreur si c'est le cas
        return; // Quitte la fonction
    }
    printf("Nombre de lignes : %d\n", dataframe->colonnes_df[0]->taille_logique); // Affiche le nombre de lignes (suppose que toutes les colonnes ont le même nombre de lignes)
}

// Affiche le nombre de colonnes du dataframe
void afficher_nombre_colonnes(CDataframe* dataframe) {
    if (dataframe == NULL) { // Vérifie si le dataframe est nul
        printf("Le dataframe est vide !\n"); // Affiche un message d'erreur si c'est le cas
        return; // Quitte la fonction
    }
    printf("Nombre de colonnes : %d\n", dataframe->nb_col_df); // Affiche le nombre de colonnes
}

// Compte le nombre de cellules contenant une valeur égale à x dans le dataframe
int nombre_cellules_egales(CDataframe* dataframe, int x) {
    if (dataframe == NULL) { // Vérifie si le dataframe est nul
        return 0; // Retourne 0 si c'est le cas
    }
    int compteur = 0; // Initialise un compteur à 0
    for (int i = 0; i < dataframe->nb_col_df; i++) { // Parcourt chaque colonne
        compteur += val_egale(dataframe->colonnes_df[i], x); // Ajoute le nombre de valeurs égales à x dans la colonne au compteur
    }
    return compteur; // Retourne le nombre total de cellules contenant la valeur égale à x
}

// Compte le nombre de cellules contenant une valeur supérieure à x dans le dataframe
int nombre_cellules_superieures(CDataframe* dataframe, int x) {
    if (dataframe == NULL) { // Vérifie si le dataframe est nul
        return 0; // Retourne 0 si c'est le cas
    }
    int compteur = 0; // Initialise un compteur à 0
    for (int i = 0; i < dataframe->nb_col_df; i++) { // Parcourt chaque colonne
        compteur += val_superieur(dataframe->colonnes_df[i], x); // Ajoute le nombre de valeurs supérieures à x dans la colonne au compteur
    }
    return compteur; // Retourne le nombre total de cellules contenant une valeur supérieure à x
}

// Compte le nombre de cellules contenant une valeur inférieure à x dans le dataframe
int nombre_cellules_inferieures(CDataframe* dataframe, int x) {
    if (dataframe == NULL) { // Vérifie si le dataframe est nul
        return 0; // Retourne 0 si c'est le cas
    }
    int compteur = 0; // Initialise un compteur à 0
    for (int i = 0; i < dataframe->nb_col_df; i++) { // Parcourt chaque colonne
        compteur += val_inferieur(dataframe->colonnes_df[i], x); // Ajoute le nombre de valeurs inférieures à x dans la colonne au compteur
    }
    return compteur; // Retourne le nombre total de cellules contenant une valeur inférieure à x
}


