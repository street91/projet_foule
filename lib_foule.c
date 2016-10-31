/******************************************************************************/
/* LIB FOULE                                                                   */
/******************************************************************************/
#include "./lib_foule.h"

/******************************************************************************/
/* CHARGE PLAN                                                                */
/******************************************************************************/

//charge dans le tableau tab des 0 et des 1 suivant le motif de char fait
//de _ et * dessiné dans le fichier *fplan.
//LARGEUR_CASE_X et TAB_X, LARGEUR_CASE_Y et TAB_Y, ainsi que les dimensions
void charge_plan(char *fplan, int tab[TAB_X][TAB_Y])
{
    FILE *f = fopen(fplan,"r");
    int dimx, dimy, i, j;
    char c;

    if(!f)
    {
        printf("Fichier '%s': ouverture impossible\n",fplan);
        exit(1);
    }

    fscanf(f,"%d %d\n",&dimx,&dimy);
    if(dimx!=TAB_X || dimy != TAB_Y)
    {
        printf("Fichier '%s': dimensions du tableau lues dans incorrectes\n",fplan);
        exit(1);
    }

    for(j=0;j!=dimy;j++)
    {
        i=0;
        while(1)
        {
            fscanf(f,"%c",&c);
            if(c=='*')
                tab[i][j]=1;
            else if(c=='\n')
                break; 
            else if(c=='_')
                tab[i][j]=0;       
            else
            {
                printf("Fichier '%s': ligne %d caractère %d: caractère incorrect\n",fplan,j+1,i+1);
                exit(1);
            }

            i++;
        }
    }
    fclose(f);
       
}
/******************************************************************************/
/* CHARGE JOUEUR                                                                */
/******************************************************************************/

void charge_joueur(char *fjoueurs, int tab[TAB_x][TAB_y]) // [TAB_x] c'est la ligne pour le personnage (de 1 à 50) et [TAB_y] contient les 4 coordonnées .
{
	int i=0;
	int xDepart[i];
	int yDepart[i];
	int xArrivee[i];
	int yArrivee[i];
	
	
	FILE *f = fopen(fjoueurs,"r");
	
	if (f != NULL)
	{
		
		while (EOF != fscanf(f, "%d %d %d %d", &xDepart[i], &yDepart[i], &xArrivee[i], &yArrivee[i]))
		//EOF => End Of File 
		{
			for (i=1; i < sizeof(xDepart); i++)
			{
			//on parcours les colonnes pour avoir un tableau ou l'on puisse stocker les 4 coordonnées
				tab[i][0] = xDepart[i];
				tab[i][1] = yDepart[i];
				tab[i][2] = xArrivee[i];
				tab[i][3] = yArrivee[i];
			}
		
		}
		
		fclose(f);
	}
	else
	{
		printf("Impossible d'ouvrir le fichier");
	}
// pour l'instant ça marche 	
	

}
