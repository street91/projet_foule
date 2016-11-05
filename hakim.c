#include "../lib/libgraphique.h"
#include "../lib/lib_foule.h"
#include <unistd.h>

#define UNITE 10    //côté d'une case en pixels
#define NB_CASES_X 80  // nb de cases en abscisse (et dans le tableau 'plateau')
#define NB_CASES_Y 60  // nb de cases en ordonnée (et dans le tableau 'plateau')
#define FICHIER_PLAN "../data/plan.txt"
#define COTECASE 10 // la valeur d'un coté de case

/******************************************************************************/
/* Déclaration des structures et variables globales                           */
/******************************************************************************/
Point joueur={50,80};
Point arrivee={720,500};
int x,y;
int compteur;
//contient des 1 et des 0 suivant qu'il y ait un mur ou non
int plateau[NB_CASES_X][NB_CASES_Y]={{0}};


/******************************************************************************/
/* Déclaration de vos fonctions                                               */
/******************************************************************************/
void dessiner_plan();
void deplacement_joueur();
void verification_mur();

/******************************************************************************/
/* main                                                                       */
/******************************************************************************/
int main(void)
{


    ouvrir_fenetre(NB_CASES_X*UNITE,NB_CASES_Y*UNITE);
    charge_plan(FICHIER_PLAN, plateau);
	dessiner_plan();

	//Maintenant créons le joueur

	dessiner_rectangle(joueur,10,10, green);
	actualiser();
	attendre_clic();
	deplacement_joueur();
    score();
    //a vous !



    // fin du programme
    attendre_clic();
    fermer_fenetre();
    return 0;
}

/******************************************************************************/
/*  Définitions des autres fonctions                                          */
void dessiner_plan()
	{//affiche le plan
	Point p;
	int i, j;

	for(i=0; i<80; i++)
		{
		for (j=0; j<60; j++)
			{
			p.x=i*10;
			p.y=j*10;

			if (plateau[i][j] == 0)
				{
				dessiner_rectangle(p,10,10, blue);//le fond

				}
			else
				{
				dessiner_rectangle(p,10,10, red);//les murs
				}
			}
		dessiner_rectangle(arrivee,10,10, green);
		actualiser();
		}
	}

void deplacement_joueur()
	{	//fonction qui fait bouger le joueur (carré)
		while((joueur.x!=arrivee.x) || (joueur.y!=arrivee.y))
		{

		    dessiner_rectangle(joueur,10,10, red);
		    if((plateau[x-1][y]==0) && (plateau[x][y-1]==0) && (plateau[x+1][y]==0) && (plateau[x][y+1]==0))
            {

				if ( (joueur.x > arrivee.x) && (joueur.x < 600-COTECASE))
                    {joueur.x -= COTECASE;
                     actualiser();
                    }
                else {
                        if ((joueur.x < arrivee.x) && (joueur.x > COTECASE))
                        {joueur.x += COTECASE;
                        actualiser();
                        }
                    }
                if ( (joueur.y > arrivee.y) && (joueur.y < 800-COTECASE))
                    {joueur.y -= COTECASE;
                     actualiser();
                    }
                else {
                        if ((joueur.y < arrivee.y) && (joueur.y > COTECASE))
                        {joueur.y += COTECASE;
                        actualiser();
                        }
                    }
            }
			dessiner_plan();
			dessiner_rectangle(joueur,10,10, red);
			actualiser();
			compteur++;
		}
	}

void verification_mur()
        {
            x=joueur.x/10;
            y=joueur.y/10;
            if (plateau[x+1][y]==1)
            {
                joueur.y+=COTECASE;
            }
            if (plateau[x][y+1]==1)
            {
            joueur.x+=COTECASE;
            }
            if (plateau[x-1][y]==1)
            {
                joueur.x+=COTECASE;
            }
            if (plateau[x][y-1]==1)
            {
                joueur.y+=COTECASE;
            }
        }









