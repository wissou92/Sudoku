#include <stdlib.h>
#include <stdio.h>
#include "gestion_sudoku.h"
#include "constantes.h"


PILE* creer_pile() {
	PILE *p;
	p = malloc(sizeof(struct pile));
	if(p == NULL)
	{
		exit(-1);
	}
	return p;
}

void push(PILE **p, SUDOKU S) {
	PILE *p_tmp = creer_pile();
	if(p_tmp == NULL)
	{
		exit(-1);
	}
	p_tmp->valeur = S;
	p_tmp->precedent = *p;
	*p = p_tmp;
}

void pop(PILE **p) {
	if(p != NULL)
	{
		PILE *p_tmp;
		p_tmp = *p;
		*p = p_tmp->precedent;
	}
	
}

SUDOKU pick(PILE* p) {
	if(p != NULL)
	{
		return p->valeur;
	}
}

SUDOKU depiler(PILE **p) {
	SUDOKU S = pick(*p);
	pop(p);
	return S;
}

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
	int l, c;
	
	if(i<=2) l = 1;
	else if(i<=5 && i>2) l = 4;
	else l = 7;
	
	if(j<=2) c = 1;
	else if(j<=5 && j>2) c = 4;
	else c = 7;	
	
	for(int n=l-1; n<=l+1; n++)
	{
		for(int m=c-1; m<=c+1;m++)
		{
			tab[S.T[n][m].valeur]=0;
		}
	}
	
	tab[S.T[i][j].valeur]=1;
	tab[0]=1;
}

SUDOKU changer_case(SUDOKU S, int i, int j) {
	int *tab= malloc(10*sizeof(int));
	valeur_disponible(tab, S, i, j);
	int n = S.T[i][j].valeur;
	do {
		n = (n+1)%10;
	}while(tab[n]!=1);
	
	S.T[i][j].valeur = n;
	free(tab);
	return S;
}

int sudoku_complet(SUDOKU S) {
	int compteur=0;
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			compteur += (S.T[i][j].valeur ==0) ? 0 : 1;
		}
	}
	return (compteur==81) ? 1 : 0;
}

SUDOKU undo(PILE **p, 

