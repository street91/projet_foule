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

//contient des 1 et des 0 suivant qu'il y ait un mur ou non
int plateau[NB_CASES_X][NB_CASES_Y]={{0}};  
int tab[TAB_x][TAB_y];

typedef struct Bonhomme 
{
    int x;
    int y;
} Bonhomme;


//variable globale
Bonhomme b = {5 , 10} ;
/******************************************************************************/
/* Déclaration de vos fonctions                                               */
/******************************************************************************/
void afficher_plan();
void deplacement_joueur();

/******************************************************************************/
/* main                                                                       */
/******************************************************************************/
int main(void)
{

	ouvrir_fenetre(NB_CASES_X*UNITE,NB_CASES_Y*UNITE);
	charge_plan(FICHIER_PLAN, plateau);
	//a vous !
	
	afficher_plan ();
	
	actualiser();
	int tour ;
	for(tour=0;tour<100;tour++)
	{
		deplacement_joueur();
		afficher_plan();
		actualiser();
	}

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
	 Point p= {0,0};
	dessiner_rectangle(p,NB_CASES_X*UNITE, NB_CASES_Y*UNITE,noir);
	for (x=0 ; x!=80 ; x++)
	{
		for ( y=0 ; y!=60 ; y++ )
		{
		
			if (plateau[x][y]==1)
			{
				
				p.x=x*UNITE;
            			p.y=y*UNITE;
            			dessiner_rectangle(p,UNITE,UNITE,blanc);    
				
			}
				

		}


	}
	Point arr={700,450};
	dessiner_rectangle(arr, UNITE, UNITE, vert);
	actualiser();
	
	p.x = b.x*UNITE ;
	p.y = b.y*UNITE ;
	dessiner_rectangle(p,UNITE,UNITE,rouge);
	actualiser();	
	
}

void deplacement_joueur()
{
    		b.x +=2 ;
    		b.y +=1;
	actualiser();
	}
	
//bon alors cette partie est censée gérer le deplacement du joueur (appelé Bonhomme , il y a une structure plus haut dans le pgroamme, pour linstant je voudrai juste le faire allez jusqu'au point darrivé balek des murs mais a chaque fois que je fais une boucle rien ne s'affiche !! et jarrive pas a donner des limites au deplacement ! lier a la struct ? jsp ....... :(


