void deplacement_joueur()
{

Point arr={700,450};

Point p = {0,0} ;
p.x = b.x*UNITE ;
p.y = b.y*UNITE ;
int largeur = NB_CASES_X * 10 ;
int hauteur = NB_CASES_Y * 10 ;
int cote_carre = UNITE ;
int plateau[NB_CASES_X][NB_CASES_Y]={{0}}; 
    
    dessiner_rectangle(p, cote_carre, cote_carre, rouge);
    actualiser() ;



    int dx = 5 ;
    int dy = 2 ;
	int x, y ;



   while( (p.x != arr.x) || (p.y != arr.y) || (p.x != arr.y) || (p.y != arr.x)) 
    {
		for (x=0 ; x!=80 ; x++)
		{
			for ( y=0 ; y!=60 ; y++ )
			{
			
	        	if (plateau[x][y]==0) 
	        	dessiner_rectangle(p, cote_carre, cote_carre, noir);
				else
				dessiner_rectangle(p, cote_carre, cote_carre, blanc);
			}
		}       
        

        if ((p.x + dx <0) || (p.x + dx > largeur-cote_carre) )
        	{
            dx = -dx ;
       		 }
        if ( (p.y + dy <0) || (p.y + dy > hauteur-cote_carre) )
        	{
            dy = -dy ;
       		}

        p.x += dx ;
        p.y += dy ;

        dessiner_rectangle(p, cote_carre, cote_carre, rouge);
        actualiser();
    }

	
}
