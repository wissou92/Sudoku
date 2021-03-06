
#ifndef __CONSTANTES_H
#define __CONSTANTES_H


// Les tailles de case et de police sont prévues
// pour tout avoir proportionel, il suffit de changer la valeur de TAILLE_CASE
// et tout s'affiche en proportion

// A changer éventuellement
#define TAILLE_CASE 50 // La taille d'une case

#define LARGEUR (9*TAILLE_CASE+1)   // La taille horizontale de la fenêtre
#define HAUTEUR ((9+1)*TAILLE_CASE) // La taille verticale   de la fenêtre
#define TAILLE_POLICE ((2*TAILLE_CASE)/3)
#define TAILLE_POLICE_GAGNE (2*TAILLE_CASE)
#define TAILLE_POLICE_TITRE TAILLE_POLICE - 10 

// Les différentes couleurs à changer éventuellement
#define COUL_TITRE 0x0000AA   // mediumslateblue  // Couleur du titre
#define COUL_FOND antiquewhite      // Couleur de fond d'une case
#define COUL_FOND_PB rouge          // Couleur de fond d'une case qui ne peut plus prendre aucune valeur
#define COUL_TRAIT noir             // Couleur des traits de séparation
#define COUL_VAL_DEPART darkred     // Couleur de la police des valeurs de départ
#define COUL_VAL_TRAVAIL orange     // Couleur de la police des valeurs de travail
// Booleen
#define TRUE 1
#define FALSE 0

#endif
