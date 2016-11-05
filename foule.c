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

char false, true ;
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
int deplacement_joueur();

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
                if (deplacement_joueur() == false)
                {
                        //afficher erreur ou deplacement impossible
                        break; //on arrete la boucle voir le prog mais normalement cas impossible sauf si le tableau est modifié en meme temps que le deplaceme,t du joueur
                }
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

int deplacement_joueur()
{
        if (tableau[b.x+1] == 0) 
        {
                //la place a droite est libre 
                b.x +=1;
                return true;
        }
        else if (tableau[b.y+1] == 0) 
        {
                //la place desuus est libre
                b.y +=1;
                return true;
        }
        else if (tableau[b.y-1] == 0)
        {
        	b.y-=1;
        	return true ;
        }
        else if (tableau[b.x-1] == 0)
        {
        	b.x-=1;
        	return true;
        }
        

        //le p^robleme de ca est que il est pas intelligetn dans son depaclement  il regarde si les cases sont libres dans un ordre precis. Rajouter de l'aletoire pour choisir le mvt est pas interressa,t non plus car ca sera pas plus intelligent

        //aucun deplacelemnt posssible ?
        return false;
                b.x +=2 ;
                b.y +=1;
        actualiser();
}
