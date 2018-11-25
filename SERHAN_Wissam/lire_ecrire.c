#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_sudoku.h"
#include "constantes.h"


SUDOKU lire_fichier (char *nom) {
	SUDOKU S;
	S = initialiser_sudoku(S);
	int i = 8; // axe y
	int j; // axe x
	char caractere;
	FILE *F;
	F = fopen(nom, "r");
	
	while(i >= 0)
	{
		j = 0;
		while(j < 9)
		{
			fscanf(F, "%c", &caractere);
			switch(caractere)
			{
				case ' ':
					break;
				case '\n':
					break;
				case '.':
					S.T[i][j].valeur = 0;
					S.T[i][j].modifiable = TRUE;
					j++;
					break;
				case '*':
					S.T[i][j].modifiable = FALSE;
					break;
				default:  // demander au prof si faire tt les cas ou default suffit
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE; // on verifie que la case n'a pas deja été mise à FAUX
					j++;
					break;
			}
		}
		i--;
	}
	fclose(F);
	return S;
}

void ecrire_fichier(SUDOKU S) {
}
