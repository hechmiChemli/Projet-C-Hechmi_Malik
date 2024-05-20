//
// Created by hechm on 08/05/2024.
//

#ifndef CDATAFRAME_COLONNE_H
#define CDATAFRAME_COLONNE_H


#define UNTITLED1_PROJETC_H
#include <stdio.h>
#include <stdlib.h>



#define REALLOC_SIZE 256
typedef struct {
    char* titre; // Supposons que cette partie est déjà définie ailleurs.
    int* donnee;
    int taille_logique;
    int taille_physique;
} COLUMN;


COLUMN* create_column(char* titre);
int insert_value(COLUMN* colonne,int value);
void delete_column(COLUMN **colonne);
void print_col(COLUMN* col);
void nombre_occurence(COLUMN *colonne,int x);
int get_val_pos(COLUMN *colonne,int x);
int val_superieur(COLUMN *colonne,int x);
int val_inferieur(COLUMN* colonne, int x);
int val_egale(COLUMN* colonne, int x);

#endif //CDATAFRAME_COLONNE_H
