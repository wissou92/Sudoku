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
	int ligne = 1; int colonne=1; // pour la detection d'erreure
	char caractere;
	FILE *F;
	F = fopen(nom, "r");
	if(F == NULL){
		printf("Impossible d'ouvrir le fichier %s\n", nom);
		exit(0);
	}	
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
					colonne++;
					j++;
					break;
				case '*':
					S.T[i][j].modifiable = FALSE;
					colonne++;
					break;
				case '0':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				case '1':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				case '2':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				case '3':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				case '4':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				case '5':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				case '6':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				case '7':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				case '8':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				case '9':
					S.T[i][j].valeur = atoi(&caractere);
					S.T[i][j].modifiable = (S.T[i][j].modifiable) ? TRUE : FALSE;
					j++;
					colonne++;
					break;
				default:
					printf("######\nErreure dans le fichier\nLigne: %d Colonne: %d\nErreure detectee: %c\n######\n",ligne, colonne, caractere);
					exit(-2);
					break;
			}
		}
		colonne = 1;
		ligne++;
		i--;
	}
	fclose(F);
	return S;
}

void ecrire_fichier(SUDOKU S, char *nom) {
	int n=0;       // Passer les caractères
	int chiffre;   // Numero du futur fichier en int
	char *numero;  // Numero du futur fichier en char
	char *newFile; // Futur nom de fichier
	
	while(nom[n] != '.')n++;
	chiffre = atoi(&nom[n+1])*100+atoi(&nom[n+2])*10+atoi(&nom[n+3]);
	sprintf(numero, "%d", chiffre);
	newFile = strcat("exemple.",strcat(numero,".sudoku"));
	FILE* F = fopen(newFile,"w+");
	for(int i=8; i>=0; i--)
	{
		for(int j=0; j<9; j++)
		{
			switch(S.T[i][j].modifiable)
			{
				case TRUE:
					if(S.T[i][j].valeur!=0)fprintf(F, "%c", S.T[i][j].valeur);
					else fprintf(F, ".");
				case FALSE:
					fprintf(F, "*%c", S.T[i][j].valeur);
			}
		}
	}
	fclose(F);
}
