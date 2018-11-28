
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
// Change la case d'un Sudoku avec la prochaine valeur disponible
void changer_case(SUDOKU S, int i, int j);
#endif
