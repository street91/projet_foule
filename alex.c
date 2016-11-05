#include "../lib/libgraphique.h"
#include "../lib/lib_foule.h"
#include <unistd.h>

#define UNITE 10    //côté d'une case en pixels
#define NB_CASES_X 80  // nb de cases en abscisse (et dans le tableau 'plateau')
#define NB_CASES_Y 60  // nb de cases en ordonnée (et dans le tableau 'plateau')
#define FICHIER_PLAN "/home/adevie/Documents/Projet_1/Data/plan.txt"


/******************************************************************************/
/* Déclaration des structures et variables globales                           */
/******************************************************************************/

//contient des 1 et des 0 suivant qu'il y ait un mur ou non
int plateau[NB_CASES_X][NB_CASES_Y]={{0}};  
void afficher_plateau();
Point deplacement_joueur(Point depart,int diffx,int diffy);
int absox(Point depart,Point arrivee);
int absoy(Point depart,Point arrivee);

/******************************************************************************/
/* Déclaration de vos fonctions                                               */
/******************************************************************************/



/******************************************************************************/
/* main                                                                       */
/******************************************************************************/
int main(void)
{
	
    ouvrir_fenetre(NB_CASES_X*UNITE,NB_CASES_Y*UNITE);
    charge_plan(FICHIER_PLAN, plateau);
    //a vous !
	int diffx;
	int diffy;
		
	
	afficher_plateau();
	Point depart = attendre_clic();
	depart.x = depart.x/UNITE;
	depart.y = depart.y/UNITE; 	
	
	plateau[depart.x][depart.y] = 2;
	afficher_plateau();
	
	Point arrivee = attendre_clic();
	arrivee.x = arrivee.x/UNITE; 
	arrivee.y = arrivee.y/UNITE;
	
	
	plateau[arrivee.x][arrivee.y] = 3;
	afficher_plateau();
 
	
    
    
	
    diffx = absox(depart,arrivee);
    
	diffy = absoy(depart,arrivee); 

   
    while (diffx != 0 || diffy !=0)
    {
	    	
	  	
		depart = deplacement_joueur(depart,diffx,diffy);
    	plateau[depart.x][depart.y] = 2;   	
    	afficher_plateau();
		
		
    	diffx = absox(depart,arrivee);
    	
		diffy = absoy(depart,arrivee);
    	
		
	
    }
		
	
    
	
    // fin du programme
    attendre_clic();
    fermer_fenetre();
    return 0;
}

/******************************************************************************/
/*  Définitions des autres fonctions                                          */
/******************************************************************************/
//void pour afficher le plan
void afficher_plateau()
{
	int x,y;		
	for (x=0;x <= NB_CASES_X;x++)
	{
		for(y=0; y<= NB_CASES_Y; y++)
		{
			if ( plateau[x][y]== 1 )
			{
				Point coin={x * UNITE,y*UNITE};				
				dessiner_rectangle(coin, UNITE, UNITE,blanc);
			}
			else if ( plateau[x][y] == 2)
			{
				Point coin={x*UNITE, y * UNITE};
				dessiner_rectangle(coin,UNITE,UNITE,vert);
			}
			else if ( plateau [x][y] == 3)
			{
				Point coin={x*UNITE, y*UNITE};
				dessiner_rectangle(coin, UNITE, UNITE, jaune);
			}
			else if ( plateau [x][y] == 0)
			{
				Point coin={x * UNITE, y * UNITE};
				dessiner_rectangle(coin, UNITE, UNITE,noir);
			}
		}
	}
	actualiser();
}
int absox(Point depart,Point arrivee)
{
	int c;	
	if ( depart.x < arrivee.x)
	{
		c = ((arrivee.x - depart.x)*-1);
		
	}
	else if ( depart.x > arrivee.x)
	{
		c = (depart.x - arrivee.x);
		
	}
	else if (depart.x == arrivee.x)
	{
		c = 0;
			
	}
	return c;
}
int absoy(Point depart,Point arrivee)
{
	int c;	
	if ( depart.y < arrivee.y)
	{
		c = ((arrivee.y - depart.y)*-1);
		
	}
	else if ( depart.y > arrivee.y)
	{
		c = (depart.y - arrivee.y);
		
	}
	else if (depart.y == arrivee.y)
	{
		c = 0;
			
	}
	return c;
}


Point deplacement_joueur(Point depart,int diffx,int diffy)
{
		if(diffx > 0 && diffy >0)
		{
			depart.x --;
			depart.y --;
		}
		else if (diffx >0 && diffy < 0 )
		{
			depart.x --;
			depart.y ++;
		}
		else if(diffx <0 && diffy >0)
		{
			depart.x ++;
			depart.y --;
		}
		else if(diffx<0 && diffy<0)
		{
			depart.x ++;
			depart.y ++;
		}
		else if(diffx == 0 && diffy<0)
	    {
			depart.y  ++ ;
		}
		else if(diffx == 0 && diffy>0)
	    {
			depart.y --;
		}
		else if(diffx<0 && diffy == 0)
	        {
			depart.x ++;
		}
		else if(diffx>0 && diffy == 0)
	        {
			depart.x--;
		}
		
return depart;
}
