//
// Created by hechm on 08/05/2024.
//


#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include <stdio.h>
#include <stdlib.h>
#include "colonne.h"  // Include the definition of Column
#include "cdataframe.h"


#define REALOC_SIZE 256
typedef struct {
    COLUMN **colonnes_df;//tableau de pointeurs qui pointe vers des colonne
    int nb_col_df;//taille physique du tableau de pointeurs
    int TP;//taille physique du tableau
} CDataframe;


CDataframe* creation_du_cdatframe();
void remplir_dataframe_en_dur(CDataframe *df);
void afficher_dataframe(const CDataframe *df);
void ajouter_colonne(CDataframe *df, COLUMN *colonne);
void afficher_partie_lignes(const CDataframe* df, int debut, int fin);
void afficher_partie_colonnes(const CDataframe* df, int debut, int fin);
void ajouter_ligne(CDataframe* df, int* valeurs, int nb_valeurs);
void supprimer_ligne(CDataframe* df, int index);
void supprimer_colonne(CDataframe* dataframe, int index);
// Nouvelles fonctions ajoutées
void renommer_titre_colonne(CDataframe* df, int index, const char* nouveau_titre);
int verifier_existence_valeur(CDataframe* df, int valeur);
int acceder_remplacer_valeur(CDataframe* df, int ligne, int colonne, int nouvelle_valeur);
void afficher_noms_colonnes(CDataframe* df);
void afficher_nombre_lignes(CDataframe* df);
void afficher_nombre_colonnes(CDataframe* df);
int nombre_cellules_egales(CDataframe* df, int x);
int nombre_cellules_superieures(CDataframe* df, int x);
int nombre_cellules_inferieures(CDataframe* df, int x);


#endif //CDATAFRAME_CDATAFRAME_H
