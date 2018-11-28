#include <stdlib.h>
#include "gestion_sudoku.h"
#include "constantes.h"

SUDOKU initialiser_sudoku(SUDOKU S) {
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			S.T[i][j].modifiable = TRUE;
		}
	}
	return S;
}

void changer_case(SUDOKU S, int i, int j) {

}
