#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include <stdio.h>
#include <stdlib.h>
#include "colonne.h"  // Include the definition of Column
#include "colonne.h"
#define REALOC_SIZE 256
typedef struct {
    COLUMN **columns;
    int num_columns;
} CDataframe;

CDataframe* create_dataframe();
CDataframe* creer_dataframe();
void remplir_dataframe_avec_saisie_utilisateur(CDataframe *df);
void remplir_dataframe_en_dur(CDataframe *df);
void afficher_dataframe(const CDataframe *df);
void ajouter_ligne(CDataframe *df, int *donnees_ligne);
void supprimer_ligne(CDataframe *df, int indice_ligne);
void ajouter_colonne(CDataframe *df, COLUMN *colonne);
void supprimer_colonne(CDataframe *df, const char *titre);
void liberer_dataframe(CDataframe *df);






























#endif //PROJETC_PROJET_H
