#include <stdlib.h>
#include <stdio.h>
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
	for(int t=0; t<10; t++)
	{
		tab[t]=1;
	}
	for(int a=0; a<9; a++)
	 {
		 tab[S.T[a][j].valeur]=0;
	 }
	 for(int b=0; b<9; b++)
	 {
		 tab[S.T[i][b].valeur]=0;
	 }
		
	if(i != 8)
	{
		if(j!=0) tab[S.T[i+1][j-1].valeur]=0;
		if(j!=8) tab[S.T[i+1][j+1].valeur]=0;
	}
	if(i != 0)
	{
		if(j!=0) tab[S.T[i-1][j-1].valeur]=0;
		if(j!=8) tab[S.T[i-1][j+1].valeur]=0;
	}
	tab[S.T[i][j].valeur]=1;
	tab[0]=1;
}

SUDOKU changer_case(SUDOKU S, int i, int j) {
	int tab[10];
	valeur_disponible(tab, S, i, j);
	int n = S.T[i][j].valeur;
	do {
		printf("n: %d; tab[n]: %d;\n", n, tab[n]);
		n = (n+1)%10;
	}while(tab[n]!=1);
	
	S.T[i][j].valeur = n;
	return S;
}
