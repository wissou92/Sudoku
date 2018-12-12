#include "gestion_sudoku.h"

#ifndef __AFFICHER_H
#define __AFFICHER_H
// Fonction a appeler au début poour créer la fenêtre grapĥique
void initialiser_fenetre_graphique();

// Fonction a appeler à la fin poour terminer proprement la fenêtre grapĥique
void terminer_fenetre_graphique();

// Fonction qui affiche l'état courant du sudoku
void sudoku_afficher(SUDOKU S, char* nom);

// Fonction qui dessine le quadrillage seul
void afficher_quadrillage();

// Affiche gagné quand c'est le cas
void gagner();

// créer un menu de demarrage
void menu();
#endif
