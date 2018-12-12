#include <stdlib.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"

SUDOKU jouer(SUDOKU S, char* nom) {
	POINT P;
	P.y = 9*TAILLE_CASE;
	char touche;
	int fleche;
	
	wait_key_arrow_clic(&touche, &fleche, &P);
	if(touche=='Q' || touche=='q')
	{
		printf("\n##########\nFIN DE JEU\n##########\n");
		exit(0);
	}
	else if(touche=='S' || touche=='s')
	{
		if(ecrire_fichier(S, nom))
		{
			printf("\n###############\nSAUVEGARDE EFFECTUEE\n###############\n");
		}
		else
		{
			printf("\n###############\nECHEC SAUVEGARDE\n###############\n");
		}
	}
	else if(P.y < 9 * TAILLE_CASE)
	{
		int ligne = P.y/TAILLE_CASE;
		int colonne = P.x/TAILLE_CASE;
		if(S.T[ligne][colonne].modifiable==TRUE) S = changer_case(S,ligne,colonne);
	}
	
	return S;
}


int main (int argc, char **argv) {
	initialiser_fenetre_graphique();
	SUDOKU S;
	S = lire_fichier(argv[1]);
	menu();	
	sudoku_afficher(S, argv[1]);
	
	while(!sudoku_complet(S)) {
		S = jouer(S, argv[1]);
		sudoku_afficher(S, argv[1]);
	}
	gagner();
	terminer_fenetre_graphique();
	exit(0);
}












