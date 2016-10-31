/******************************************************************************
* lib_foule.h 
*
*****************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

#define TAB_X 80
#define TAB_Y 60
#define TAB_x 4 //pas sur encore
#define TAB_y 50 // pas sur encore 

// PROTOTYPES

//charge dans le tableau tab des 0 et des 1 suivant le motif de char fait
//de _ et * dessiné dans le fichier *fplan.
//LARGEUR_CASE_X et TAB_X, LARGEUR_CASE_Y et TAB_Y, ainsi que les dimensions
//inscrites sur la première ligne du fichier doivent correspondre.
void charge_plan(char *fplan, int tab[TAB_X][TAB_Y]);
void charge_joueur(char *fjoueur, int tab[TAB_x][TAB_y]);
