//
// Created by hechm on 08/05/2024.
//
#include "cdataframe.h"

int main() {
    COLUMN *mycol = create_column("My column");//mycol est un pointeur qui pointe vers la colonne  avec create_column
    int val = 5;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");

    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);
    nombre_occurence(mycol,5);
    int position=3;
    int valeur= get_val_pos(mycol,position);
    if (valeur!=-1){
        printf(" la valeur a la position %d est %d\n",position,valeur);
    }
    else{
        printf("La valeur à la position %d n'existe pas !\n");

    }
    int x = 10;
    printf("Nombre de valeurs superieures a %d : %d\n", x, val_superieur(mycol, x));
    printf("Nombre de valeurs inferieures a %d : %d\n", x, val_inferieur(mycol, x));
    printf("Nombre de valeurs egales a %d: %d\n", x, val_egale(mycol, x));
    printf("Ajoutons la valeur 35 à la ligne 2\n");
    insert_value(mycol, 35);
    print_col(mycol);

    printf("Création d'un CDataframe vide :\n");
    printf("Création d'un CDataframe vide :\n");
    CDataframe* df = creation_du_cdatframe();

    // Ajout d'une colonne au CDataframe
    printf("Ajout d'une colonne au CDataframe :\n");
    ajouter_colonne(df, mycol);
    printf("Ajout d'une ligner au CDataframe :\n");
    // Ajout d'une ligne au dataframe
    int nouvelle_ligne[] = {70, 75, 80}; // Valeurs pour la nouvelle ligne
    ajouter_ligne(df, nouvelle_ligne, 3); // Ajoute la ligne au dataframe

    // Afficher le dataframe complet après l'ajout de la nouvelle ligne
    afficher_dataframe(df);


    // Remplissage en dur du CDataframe
    printf("Remplissage en dur du CDataframe :\n");
    remplir_dataframe_en_dur(df);
    afficher_dataframe(df);

    int debut = 1;
    int fin = 3;
    printf("Affichage d'une partie des lignes du CDataframe :\n");
    afficher_partie_lignes(df, debut, fin);

    printf("Affichage d'une partie des colonnes du CDataframe :\n");
    afficher_partie_colonnes(df, debut, fin);

    printf("Suppression de la ligne d'index 2 du CDataframe :\n");
    supprimer_ligne(df, 2);
    afficher_dataframe(df);

    printf("Suppression de la colonne d'index 1 du CDataframe :\n");
    supprimer_colonne(df, 1);
    afficher_dataframe(df);

    printf("Renommer la première colonne du CDataframe :\n");
    renommer_titre_colonne(df, 0, "Nouvelle colonne");
    afficher_noms_colonnes(df);

    int valeur_a_rechercher = 20;
    printf("Vérification de l'existence de la valeur %d dans le CDataframe : %s\n",
           valeur_a_rechercher, verifier_existence_valeur(df, valeur_a_rechercher) ? "trouvée" : "non trouvée");

    printf("Accéder et remplacer la valeur dans la cellule (1, 0) par 99\n");
    acceder_remplacer_valeur(df, 1, 0, 99);
    afficher_dataframe(df);

    printf("Afficher le nombre de lignes du CDataframe :\n");
    afficher_nombre_lignes(df);

    printf("Afficher le nombre de colonnes du CDataframe :\n");
    afficher_nombre_colonnes(df);

    int valeur_a_comparer = 30;
    printf("Nombre de cellules contenant la valeur égale à %d : %d\n", valeur_a_comparer, nombre_cellules_egales(df, valeur_a_comparer));
    printf("Nombre de cellules contenant une valeur supérieure à %d : %d\n", valeur_a_comparer, nombre_cellules_superieures(df, valeur_a_comparer));
    printf("Nombre de cellules contenant une valeur inférieure à %d : %d\n", valeur_a_comparer, nombre_cellules_inferieures(df, valeur_a_comparer));

    return 0;
}
