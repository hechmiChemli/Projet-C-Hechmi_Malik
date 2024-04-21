//
// Created by hechm on 16/04/2024.
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

    printf("Création d'un CDataframe vide :\n");
    printf("Création d'un CDataframe vide :\n");
    CDataframe *df = creer_dataframe();

    // Remplissage du CDataframe à partir des saisies utilisateurs
    printf("Remplissage du CDataframe à partir des saisies utilisateur :\n");
    remplir_dataframe_avec_saisie_utilisateur(df);

    // Remplissage en dur du CDataframe
    printf("Remplissage en dur du CDataframe :\n");
    remplir_dataframe_en_dur(df);

    // Afficher tout le CDataframe
    printf("\nAfficher tout le contenu du CDataframe :\n");
    afficher_dataframe(df);

    // Afficher une partie des lignes du CDataframe
    int limite;
    printf("Afficher une partie des lignes du CDataframe ( avec une limite fournie par l'utilisateur) : ");
    scanf("%d", &limite);
    // Afficher les lignes jusqu'à la limite fournie par l'utilisateur
    for (int i = 0; i < limite && i < df->num_columns; i++) {
        printf("Ligne %d : ", i + 1);
        for (int j = 0; j < df->num_columns; j++) {
            printf("%d ", df->columns[j]->donnee[i]);
        }
        printf("\n");
    }

    // Afficher une partie des colonnes du CDataframe
    printf("Afficher une partie des colonnes du CDataframe  : ");
    scanf("%d", &limite);
    // Afficher les colonnes jusqu'à la limite fournie par l'utilisateur
    for (int i = 0; i < limite && i < df->num_columns; i++) {
        printf("Colonne %d : ", i + 1);
        for (int j = 0; j < df->columns[i]->taille_logique; j++) {
            printf("%d ", df->columns[i]->donnee[j]);
        }
        printf("\n");
    }

    // Ajouter une ligne de valeurs au CDataframe
    printf("\nAjouter une ligne de valeurs  :\n");
    int nouvelle_ligne[] = {1, 2, 3}; // Exemple de données pour une nouvelle ligne
    ajouter_ligne(df, nouvelle_ligne);

    // Supprimer une ligne de valeurs du CDataframe
    printf("\nSupprimer une ligne de valeurs (saisir l'indice  de la ligne) : ");
    int index_a_supprimer;
    scanf("%d", &index_a_supprimer);
    supprimer_ligne(df, index_a_supprimer);

    // Ajouter une colonne au CDataframe
    printf("\nAjouter une colonne au CDataframe :\n");
    COLUMN *nouvelle_colonne = create_column("Nouvelle colonne");
    ajouter_colonne(df, nouvelle_colonne);

    // Supprimer une colonne du CDataframe
    printf("Supprimer une colonne du CDataframe (saisir le titre de la colonne) : ");
    char titre_a_supprimer[100];
    scanf("%s", titre_a_supprimer);
    supprimer_colonne(df, titre_a_supprimer);

    // Libération de la mémoire allouée pour le CDataframe
    liberer_dataframe(df);



    return 0;

    // Libérez la mémoire de la colonne
    delete_column(&mycol);
    }









