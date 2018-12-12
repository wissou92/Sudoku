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
	if(S.T == NULL)// en raison d'un pick sur une pile vide
	{
		printf("Sudoku vide\n");
		exit(EXIT_FAILURE);
	}
	else {
		afficher_quadrillage();
		POINT P, T;
		T.x = 2.5*TAILLE_CASE + 1; T.y = HAUTEUR - 7;
		aff_pol(nom, TAILLE_POLICE_TITRE, T, COUL_TITRE);
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
	}
	affiche_all();
}

void gagner(){
	POINT P, T;
	POINT C1, C2;
	
	P.x = LARGEUR/2; P.y = HAUTEUR*0.75;
	fill_screen(COUL_FOND);
	aff_pol_centre("GAGNE", TAILLE_POLICE_GAGNE, P, COUL_VAL_TRAVAIL);
	
	C1.x = LARGEUR/2 - 2*TAILLE_CASE - 10 ; C1.y = 3* TAILLE_CASE;
	C2.x = LARGEUR/2 + 2*TAILLE_CASE  + 10; C2.y = 4* TAILLE_CASE;
	draw_fill_rectangle(C1, C2, COUL_VAL_TRAVAIL);
	T.x = LARGEUR/2; T.y = 3.5*TAILLE_CASE;
	aff_pol_centre("REJOUER", TAILLE_POLICE, T, COUL_FOND);
	affiche_all();
}

void menu(){
	fill_screen(COUL_FOND);
	POINT C1, C2, P1, P2, P3, P;
	P1.y = HAUTEUR/2+2*TAILLE_CASE; P1.x = LARGEUR/2;
	P2.x = LARGEUR/2; P2.y = HAUTEUR/2 - 1.5*TAILLE_CASE;
	P3 = P2;
	P3.y -= TAILLE_CASE;
	C1.x = LARGEUR/2 - 2*TAILLE_CASE - 10 ; C1.y = 3* TAILLE_CASE;
	C2.x = LARGEUR/2 + 2*TAILLE_CASE  + 10; C2.y = 4* TAILLE_CASE;
	draw_rectangle(C1, C2, COUL_VAL_DEPART);
	C1.x++; C1.y++; C2.x--; C2.y--;
	draw_rectangle(C1, C2, COUL_VAL_DEPART);
	
	C1.x--; C2.x++; C1.y = C1.y - TAILLE_CASE-4; C2.y = C2.y - TAILLE_CASE-4;
	draw_fill_rectangle(C1, C2, COUL_VAL_DEPART);
	
	aff_pol_centre("SUDOKU", TAILLE_CASE, P1, COUL_VAL_DEPART);
	aff_pol_centre("JOUER", TAILLE_POLICE, P2, COUL_VAL_DEPART);
	aff_pol_centre("QUITTER", TAILLE_POLICE, P3, COUL_FOND);
	
	affiche_all();
	P = wait_clic();
	if((P.x>=C1.x && P.x <= C2.x) && (P.y<=C2.y && P.y>= C1.y))
	{
		printf("\n##########\nFIN DE JEU\n##########\n");
		exit(0);
	}
	else if((P.x>=C1.x && P.x <= C2.x) && (P.y<=(C2.y+TAILLE_CASE-4) && P.y>= (C1.y+TAILLE_CASE-4)))
	{
		;
	}
	else menu();
}


