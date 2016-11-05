#include "../lib/libgraphique.h"
#include "../lib/lib_foule.h"
#include <unistd.h>

#define UNITE 10    //côté d'une case en pixels
#define NB_CASES_X 80  // nb de cases en abscisse (et dans le tableau 'plateau')
#define NB_CASES_Y 60  // nb de cases en ordonnée (et dans le tableau 'plateau')
#define TAB_x 50
#define TAB_y 4
#define FICHIER_PLAN "../data/plan.txt"
#define FICHIER_JOUEUR "../data/joueurs"

/******************************************************************************/
/* Déclaration des structures et variables globales                           */
/******************************************************************************/


int plateau[NB_CASES_X][NB_CASES_Y]={{0}};  
//contient des 1 et des 0 suivant qu'il y ait un mur ou non
int tab[TAB_x][TAB_y];
//tableau que nous voullions utiliser pour "charge_joueur"

Point joueur={50,80};
Point arr={720,500};
int compteur;
int x,y;
char false, true;

/******************************************************************************/
/* Déclaration de vos fonctions                                               */
/******************************************************************************/
void afficher_plan();
void deplacement_joueur();
void case_mur();
/******************************************************************************/
/* main                                                                       */
/******************************************************************************/
int main(void)
{
	ouvrir_fenetre(NB_CASES_X*UNITE,NB_CASES_Y*UNITE);
        charge_plan(FICHIER_PLAN, plateau);
        //a vous !
        
        afficher_plan ();
        dessiner_rectangle(joueur,10,10, vert);
	actualiser();
	attendre_clic();
	deplacement_joueur();
   
	// fin du programme
	attendre_clic();
	fermer_fenetre();
	return 0;
}

/******************************************************************************/
/*  Définitions des autres fonctions                                          */
/******************************************************************************/

void afficher_plan()
//fonction qui affiche le plan ainsi que le point de départ et donc le joueur 
{

	Point p;
        int i,j;
        for (i=0 ; i!=80 ; i++)
        {
                for ( j=0 ; j!=60 ; j++ )
                {
                p.x=i*UNITE;
                p.y=j*UNITE;
                        if (plateau[i][j]==1)
                        {
                                
                                
                                dessiner_rectangle(p,UNITE,UNITE,blanc);    
                        }
                        else 
                        {        
				
				dessiner_rectangle(p,UNITE,UNITE,noir);
			}
                }
	dessiner_rectangle(arr,10,10, vert);
	actualiser();

        }
                
}

void deplacement_joueur()
{	
//cette fonction permet de gérer le déplacement du joueur
		
	while((joueur.x!=arr.x) || (joueur.y!=arr.y))
	{
		dessiner_rectangle(joueur,10,10, vert);
		
		if((plateau[x-1][y]==0) && (plateau[x][y-1]==0) && (plateau[x+1][y]==0) && (plateau[x][y+1]==0))
                {
			if ( (joueur.x > arr.x) && (joueur.x < 600-UNITE))
                	{
                		joueur.x -= UNITE;
                		actualiser();
                	}
                	else 
                	{
                		if ((joueur.x < arr.x) && (joueur.x > UNITE))
                		{
                        	joueur.x += UNITE;
                        	actualiser();
                		}
                	}
			if ( (joueur.y > arr.y) && (joueur.y < 800-UNITE))
			{
				joueur.y -= UNITE;
				actualiser();
 			}
			else 
			{
                        	if ((joueur.y < arr.y) && (joueur.y > UNITE))
                        	{
                        		joueur.y += UNITE;
                        		actualiser();
                        	}
                    	}
		}
		afficher_plan();
		dessiner_rectangle(joueur,10,10, vert);
		actualiser();
		compteur++;
	}
}


void case_mur()
//fonction qui permettra de verifier si il y a un mur ou non (nous n'avons pas réussi à la faire fonctionner)
{
	if (plateau[x+1][y] == 0) 
	{
                //la place à droite est libre 
                joueur.x +=1;
                return true;
        }
        else if (plateau[x][y+1] == 0) 
        {
                //la place dessous est libre
                joueur.y +=1;
                return true;
        }
        else if (plateau[x-1][y] == 0)
        {
        	//la place à gauche est libre
                joueur.x -=1;
                return true;
        }
        else if (plateau[x][y-1] == 0)
        {
        	//la place de dessus est libre
        	joueur.y -=1;
                return true;
        }
        else 
        	return false;
        	 actualiser();
}

//Dans le fichier "lib_foule.c" se situe la fonction "charge_joueur" que nous avons tenté de faire 
