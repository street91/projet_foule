#include "../lib/libgraphique.h"
#include "../lib/lib_foule.h"
#include <unistd.h>

#define UNITE 10    //côté d'une case en pixels
#define NB_CASES_X 80  // nb de cases en abscisse (et dans le tableau 'plateau')
#define NB_CASES_Y 60  // nb de cases en ordonnée (et dans le tableau 'plateau')
#define FICHIER_PLAN "../data/plan.txt"

/******************************************************************************/
/* Déclaration des structures et variables globales                           */
/******************************************************************************/

//contient des 1 et des 0 suivant qu'il y ait un mur ou non
int plateau[NB_CASES_X][NB_CASES_Y]={{0}};  


/******************************************************************************/
/* Déclaration de vos fonctions                                               */
/******************************************************************************/
void afficher_plan();


/******************************************************************************/
/* main                                                                       */
/******************************************************************************/
int main(void)
{

	ouvrir_fenetre(NB_CASES_X*UNITE,NB_CASES_Y*UNITE);
	charge_plan(FICHIER_PLAN, plateau);
	afficher_plan ();

	// fin du programme
	attendre_clic();
	fermer_fenetre();
	return 0;
}

/******************************************************************************/
/*  Définitions des autres fonctions                                          */
/******************************************************************************/

void afficher_plan()
{
int x,y;

	for (x=0 ; x<80 ; x++)
	{
		for ( y=0 ; y<60 ; y++ )
		{
		Point c1={x*10,y*10};
			if (plateau[x][y]==1)
			{
				
				dessiner_rectangle(c1,10, 10, blanc);
				
			}
			else
			{
				dessiner_rectangle(c1,10, 10, noir);
				
			}
				

		}


	}
	actualiser();	
}
