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

char* new_name(char* nom)
{
	int n=0;       // Pour passer les caractères
	char *triplet = malloc(4*sizeof(char)); // extraction des 3 numeros du fichier de base
	int chiffre;   // Numero du futur fichier en int
	char *numero = malloc(4*sizeof(char));  // Numero+1 du futur fichier en char
	//char *prefixe = malloc(9*sizeof(char)); // prefixe avant le numero du fichier
	
	if(numero == NULL || triplet == NULL)
	{
		printf("Erreur allocation memoire variable dans ecrire fichier\n");
		exit(-1);
	}
	
	
	while(nom[n] != '.'){n++;}
	
	triplet[0]=nom[n+1]; triplet[1]=nom[n+2]; triplet[2]=nom[n+3]; triplet[4]='\0';
	chiffre = atoi(triplet)+1;
	sprintf(numero, "%d", chiffre);

	char *prefixe;
	char *extension = ".sudoku"; // extension du fichier
	if(chiffre>=100)
	{
		char* debut= "jeux.";
		prefixe = strcat(debut, numero);
	}
	else if(chiffre>=10)
	{
		char* debut= "jeux.0";
		prefixe = strcat(debut, numero);
	}
	else if(chiffre>=0)
	{
		char* debut= "jeux.00";
		prefixe = strcat(debut, numero); // <---- ERREURE A CET ENDROIT
	}
		// PROBLEME DE CONCATENATION SEGMENTATION FAULT
		char* newFile = strcat(prefixe, extension);
		
		free(numero); free(triplet);
		return newFile;		
}

void ecrire_fichier(SUDOKU S, char *nom) {
	
	FILE* F = fopen(new_name(nom),"w+");

	if(F == NULL) {
		printf("Erreur écriture fichier\n");
		exit(-1);
	}
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
