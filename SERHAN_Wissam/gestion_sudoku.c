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

void valeur_disponible(int *tab, SUDOKU S, int i, int j) {
	for(int a=0; a<9; a++)
	{
		tab[S.T[a][j].valeur] = (a==i) ? 1 : 0;
	}
	for(int b=0; b<9; b++)
	{
		tab[S.T[i][b].valeur] = (b==j) ? 1 : 0;
	}
	tab[S.T[i+1][j-1].valeur]= 0;
	tab[S.T[i+1][j+1].valeur]= 0;
	tab[S.T[i-1][j-1].valeur]= 0;
	tab[S.T[i-1][j+1].valeur]= 0;
	
	tab[0] = 1;
}

void changer_case(SUDOKU S, int i, int j) {
	int tab[10];
	valeur_disponible(tab, S, i, j);
	
	for(int n=S.T[i][j].valeur+1; n != S.T[i][j].valeur; n=(n+1)%10)
	{
		if(tab[n]==1)
		{
			S.T[i][j].valeur = n;
			break;
		}
	}
}
