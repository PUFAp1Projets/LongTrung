#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <map>
#include <sstream>
#include <string>
// Définition de la taille de la grille
const int TAILLE = 15;

// Définition du type TGrille
typedef int TGrille[TAILLE][TAILLE];

using namespace std;


/*****************************************/
/* Remarque : la constante TAILLE est    */
/* déclarée dans le fichier en-tête      */
/* morpion.h   Elle est donc connue dans */
/* tout le fichier                       */
/* (grâce au include "morpion.h")        */
/* c'est une constante globale           */
/*****************************************/

TGrille grille; // Déclaration de ma gille de morpion


/****************************************/
/* Action d'initialisation de la grille */
/* On affecte la valeur 0 à chaque case */
/****************************************/
void initGrille(TGrille grille)
{
  for (int i = 0 ; i < TAILLE ; i++)
    for (int j = 0 ; j < TAILLE ; j++)
      grille[i][j] = 0;
}



/****************************************/
/* Action d'affichage de la grille */
/* On affecte la valeur 0 à chaque case */
/****************************************/
void afficherGrille(TGrille grille)
{
  cout << endl << "\t-";
  for (int j = 0 ; j < TAILLE ; j++)
      cout << "---+" ;
  cout << endl;
      
  for (int i = 0 ; i < TAILLE ; i++)
    {
      cout << i+1 << "\t|";
      for (int j = 0 ; j < TAILLE ; j++)
	{
	  switch (grille[i][j])
	    {
	    case 0 : cout << "   "; break;
	    case 1 : cout << " 0 "; break;
	    case 2 : cout << " 1 "; break;
	    default : cout << "***";
	    }
	  cout << "|";
	}

      cout << endl << "\t-";
      for (int j = 0 ; j < TAILLE ; j++)
           cout << "---+" ;
      cout << endl;
    }

}

/*******************************************/
/* Action de verifier de la grille vide    */
/* Grille vide: la valeur 0 à chaque case  */
/*******************************************/
bool estVide(TGrille grille)
{
     for (int i = 0 ; i < TAILLE ; i++){
        for (int j = 0 ; j < TAILLE ; j++){
	        if (grille[i][j]!= 0)
    	       return false;
        }
     }
     return true;
}

/*******************************************/
/* Action de verifier de la grille vide    */
/* Grille vide: la valeur 0 à chaque case  */
/*******************************************/
bool entranceValide(int x, int y, bool joueur)
{
     if (grille[x-1][y-1]!=0) return false;
     if (joueur) grille[x-1][y-1]=1;
     else grille[x-1][y-1]=2;
     return true;
}



/*******************************************/
/*Est-ce que le joueur a-t-il gagne		?*/
/*******************************************/

bool victoire(int x, int y)

{
	 //ligne verticales  et lignes horizonales 
  if (   grille[x-1][y-1] == grille[x-2][y-1] 
      && grille[x-2][y-1] == grille[x-3][y-1]
      && grille[x-3][y-1] == grille[x-4][y-1]
      && grille[x-4][y-1] == grille[x-5][y-1]
     )

    return 1;

  
  else if (   grille[x-1][y-1] == grille[x][y-1] 
      && grille[x][y-1] == grille[x+1][y-1]
      && grille[x+1][y-1] == grille[x+2][y-1]
      && grille[x+2][y-1] == grille[x+3][y-1]
     )

    return 1;

  else if (   grille[x-1][y-1] == grille[x-1][y-2] 
      && grille[x-1][y-2] == grille[x-1][y-3]
      && grille[x-1][y-3] == grille[x-1][y-4]
      && grille[x-1][y-4] == grille[x-1][y-5]
     )

    return 1;

  else if (   grille[x-1][y-1] == grille[x-1][y] 
      && grille[x-1][y] == grille[x-1][y+1]
      && grille[x-1][y+1] == grille[x-1][y+2]
      && grille[x-1][y+2] == grille[x-1][y+3]
     )

    return 1;

// les quatres  lignes diagonales 

  else if (   grille[x-1][y-1] == grille[x-2][y-2] 
      && grille[x-2][y-2] == grille[x-3][y-3]
      && grille[x-3][y-3] == grille[x-4][y-4]
      && grille[x-4][y-4] == grille[x-5][y-5]
     )

    return 1;

  else if (   grille[x-1][y-1] == grille[x][y] 
      && grille[x][y] == grille[x+1][y+1]
      && grille[x+1][y+1] == grille[x+2][y+2]
      && grille[x+2][y+2] == grille[x+3][y+3]
     )

     return 1;

  else if (   grille[x-1][y-1] == grille[x-2][y] 
      && grille[x-2][y] == grille[x-3][y+1]
      && grille[x-3][y+1] == grille[x-4][y+2]
      && grille[x-4][y+2] == grille[x-5][y+3]
     )

    return 1;

  else  if (   grille[x-1][y-1] == grille[x][y-2] 
      && grille[x][y-2] == grille[x+1][y-3]
      && grille[x+1][y-3] == grille[x+2][y-4]
      && grille[x+2][y-4] == grille[x+3][y-5]
     )

    return 1;
	
	else //if()
	return 0;	
	
}









/*******************************************/
/* Main                                    */
/*******************************************/

int main()
{  
  initGrille(grille);
  int x,y;
  bool c, v, joueur =true;
  
  do{
     afficherGrille(grille);
     
     do{
        cout << "Entrez (x,y) de joueur ";
        if (joueur) cout << "A";
        else  cout << "B";
        cout << " : (quittez si valeur donnee n'est pas positive)";
        cin >> x >> y;
        c= entranceValide(x,y,joueur);    
          
			    
        if (!c) cout << "Les valeurs donnees n'est pas valides !!!" << endl;
     }while(!c && (x>0) && (y>0) );
     v=victoire(x ,y);
	 joueur = !joueur;
     system("cls");
  }while((x>0)&&(y>0) &&(!v)  );
 
 if (v) cout<<"Bravo joueur celebre s'appelle "<<joueur <<" a gagne ! ";
}
