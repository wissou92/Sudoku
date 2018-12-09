
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

typedef struct pile {
	SUDOKU valeur;
	struct pile* precedent;
}PILE;


// PROTOTYPES

// Initialiser toute les cases du Sudoku a 0 ainsi qu'à TRUE (modifiable)
SUDOKU initialiser_sudoku(SUDOKU S);

// Test les valeurs disponible
void valeur_disponible(int* tab, SUDOKU S, int i, int j);

// Change la case d'un Sudoku avec la prochaine valeur disponible
SUDOKU changer_case(SUDOKU S, int i, int j);

// Test si toute les cases du sudoku ont une valeur;
int sudoku_complet(SUDOKU S);

// Creer une pile vide
PILE* creer_pile();

// Insere un element dans la pile
void push(PILE **p, SUDOKU S);

// Retire le dernier element de la pile
void pop(PILE **p);

// Retourne la valeur au sommet de la pile
SUDOKU pick(PILE* p);

// Retire le dernier element et retourne sa valeur au sommet
SUDOKU depiler(PILE **p);

#endif
