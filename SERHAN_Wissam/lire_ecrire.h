
#ifndef __LIRE_ECRIRE_H
#define __LIRE_ECRIRE_H
// Lecture d'un fichier .sudoku et stockage dans une variable de type SUDOKU qui est renvoyée
SUDOKU lire_fichier (char *nom);

// Créé le nouveau nom du fichier à partir du précedent
char *new_name(char *nom);

// Ecriture d'un sudoku dans un fichier
int ecrire_fichier(SUDOKU S, char* nom);
#endif
