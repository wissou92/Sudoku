
#ifndef __SUDOKU_H
#define __SUDOKU_H

// STRUCT
struct valeur_case{
	int valeur;
	int modifiable;
};

struct sudoku {
	struct valeur_case T[9][9];
};
typedef struct sudoku SUDOKU;

// PROTOTYPES

// Initialiser toute les cases du Sudoku a 0 ainsi qu'à TRUE (modifiable)
SUDOKU initialiser_sudoku(SUDOKU S);

// Test les valeurs disponible
void valeur_disponible(int* tab, SUDOKU S, int i, int j);

// Change la case d'un Sudoku avec la prochaine valeur disponible
SUDOKU changer_case(SUDOKU S, int i, int j);

// Test si toute les cases du sudoku ont une valeur;
int sudoku_complet(SUDOKU S);

#endif
