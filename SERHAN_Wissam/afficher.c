#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_sudoku.h"

void initialiser_fenetre_graphique() {
	init_graphics(LARGEUR,HAUTEUR);
	affiche_auto_off();
}

void terminer_fenetre_graphique() {
	wait_escape();
}

void afficher_quadrillage() {
	
	fill_screen(COUL_FOND);
	POINT P1, P2, P3, P4;
	POINT B1, B2;

	// Lignes verticales
	for(P1.x = 0; P1.x < LARGEUR; P1.x += TAILLE_CASE)
	{
		P1.y = 0; P2.y = (HAUTEUR - TAILLE_CASE); P2.x = P1.x;
		draw_line(P1, P2, black);
		// BOLD
		if(P1.x == 3*TAILLE_CASE || P1.x == 6*TAILLE_CASE || P1.x == 0)
		{
			B1 = P1; B1.x++;
			B2 = P2; B2.x++;
			draw_line(B1, B2, black);
		}
		else if(P1.x == 9*TAILLE_CASE)
		{
			B1 = P1; B1.x--;
			B2 = P2; B2.x--;
			draw_line(B1, B2, black);
		}
	}
	// Lignes horizontales
	for(P3.y = 0; P3.y <= (HAUTEUR - TAILLE_CASE); P3.y += TAILLE_CASE)
	{
		P3.x = 0; P4.x = LARGEUR; P4.y = P3.y;
		draw_line(P3, P4, black);
		// BOLD
		if(P3.y == 3*TAILLE_CASE || P3.y == 6*TAILLE_CASE || P3.y == 0 || P3.y == 9* TAILLE_CASE)
		{
			B1 = P3; B1.y++;
			B2 = P4; B2.y++;
			draw_line(B1, B2, black);
		}
	}
}

void sudoku_afficher(SUDOKU S, char* nom) {
	afficher_quadrillage();
	POINT P, T;
	T.x = 3*TAILLE_CASE; T.y = HAUTEUR - 3;
	aff_pol(nom, TAILLE_POLICE, T, COUL_TITRE);
	for(int i=0; i<9; i++)
	{
		P.y = (i*TAILLE_CASE) + (TAILLE_CASE/2) + 20;
		
		for(int j=0; j<9; j++)
		{
			P.x = (j*TAILLE_CASE) + (TAILLE_CASE/2) - 10; 
			if(S.T[i][j].valeur != 0)
			{
				aff_int(S.T[i][j].valeur, TAILLE_POLICE, P, (S.T[i][j].modifiable == TRUE) ? COUL_VAL_TRAVAIL : COUL_VAL_DEPART);
			}
		}
	}
	affiche_all();
}
