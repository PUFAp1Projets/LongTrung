					//----------CASSEBRIQUE----------
//----------Le bibliotheque----------

#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

//----------Les Definis et les variables----------

#define N 20	//-----N:ligne-----
#define M 45	//-----M:collone-----
#define L 8	//-----L:largeur de gallet-----
#define P 6	//-----P:ligne brique-----
#define Q 6	//-----Q:largeur et collone de brique-----
#define NBRE_GOUTTE 1

bool touche_appuyee();

char screen[N][M];

void paysage();
void affiche_screen();
void affiche_print();

typedef struct {
  double x;
  double y;
  double dx;
  double dy;
} Sprite;

typedef struct {
  int x1;
  int y1[Q];
  bool apparait;
  } Block;


void init_sprite(Sprite & s, double x, double y, double dx, double dy);
void mise_a_jour_sprite(Sprite & s, Sprite u[]);

/*void init_block(Block b[][], double x1, double y1);*/

//----------Le Main----------

	//----------Les valeurs au debut----------
	
int main () {
  Sprite goutte[NBRE_GOUTTE];
  init_sprite(goutte[0], 5, 5, 0.5, 0.5);
 
  Sprite gallet[L];
  for (int l=0; l<L; l++)
    {
      gallet[0].y = 6;
      gallet[l+1].y = gallet[l].y +1;
      init_sprite(gallet[l], 16, gallet[l].y, 0, 0);
    }
     
  /*Sprite brique1[Q];
  for (int i=0; i<Q; i++)
    {
      brique1[0].y = 2;
      brique1[i+1].y = brique1[i].y +1;
      init_sprite(brique1[i], 2, brique1[i].y, 0, 0);
    }*/

  
  Block brique[P][Q];
  for (int i=0; i<P; i++)
    for (int j=0; j<Q; j++)
      {
	brique[i][j].x1 = i+2;
	for (int k=0; k<P; k++)
	  {
	    brique[i][j].apparait = true;
	    brique[i][j].y1[k] = 7*j + 2 + k;
	  }
      }
	
	//----------Controler le gallet avec le clavier----------
	
  for (int t=0; t<1000; t++) 
    {
      system ("stty raw");
    usleep(40 * 1000);
    if (touche_appuyee()) {
      char c = getchar();     
      system ("stty cooked");
      switch (c) {
     
		//----------(Tricher)Controler la balle ^^~----------
    /*
      case 'a':
        goutte[0].dx = 0.3;
        break;
      case 'b':
        goutte[0].dx = -0.3;
        break;
    */
    		//----------Controler le gallet: f pour gauche, g pour droite----------
    		
      case 'f':
	for(int k=L-1;k>=0;k--)	  
	  gallet[k].y -=1;		
	break;
      case 'g':
	for(int k=0;k<L;k++)	
	  gallet[k].y +=1;            
	break;
      case 13:
	system ("stty cooked");
	exit(0);
      }              
    } 
    system ("stty cooked"); 
	
	//----------Les fonctions----------
    
    mise_a_jour_sprite (goutte[0], gallet);
    paysage();

    screen[(int) goutte[0].x][(int) goutte[0].y] = 'O';
    for (int g=0; g<L; g++)
      screen[(int) gallet[g].x][(int) gallet[g].y] = '=';
	
	//----------Les conditions pour arranger les briques----------
	
    for (int i=P; i>=0; i--)
      for (int j=0; j<Q; j++)
	for (int k=0; k<Q; k++)
	  if ((int) goutte[0].x + 1 == brique[i][j].x1 && (int) goutte[0].y == brique[i][j].y1[k] && brique[i][j].apparait == true)
	    { 
	      goutte[0].dx = 0.7;
	      brique[i][j].apparait = false;
	    }
    
    for (int i = 0 ; i<P ; i++)
      for (int j = 0 ; j<Q ; j++)
	for (int k = 0 ; k<Q ; k++)
	  if (brique[i][j].apparait)
	    screen[brique[i][j].x1][brique[i][j].y1[k]] = 'H'; 

    affiche_screen();

	//----------Les conditions pour la balle----------
	
    if ((int) goutte[0].x == 15)
      for (int k=0; k<L; k++)
	if((int)goutte[0].y == (int)gallet[k].y) goutte[0].dx = -0.6;
    
    if ( brique[0][0].apparait == false
         && brique[0][1].apparait == false
         && brique[0][2].apparait == false
         && brique[0][3].apparait == false
         && brique[0][4].apparait == false
	 && brique[0][5].apparait == false)
      { 
	cout << "-----------------C'EST NORMAL----------------" << endl;
	exit(0);
      }      
    
    if ((int) goutte[0].x >= N-2)
      {
	cout << "------------BLEU BLEU TU AS PERDU------------" << endl;
	exit(0);
      }
  }
}

//----------Donner les coordonnes de la balle et le gallet----------

void init_sprite(Sprite & s,
                 double x, 
                 double y, 
                 double dx, 
                 double dy) {
  s.x = x;
  s.y = y;
  s.dx = dx;
  s.dy = dy;
}

void init_sprite(Sprite u[],
		 double x,
		 double y,
		 double dx,
		 double dy) {
  for(int r=0; r<L-1; r++)
    {
      u[r].x=x;
      u[r].y=y;
      u[r].dx=dx;
      u[r].dy=dy;
    }
}

//----------Les conditions----------

void mise_a_jour_sprite(Sprite & s, Sprite u[]) {

	//----------Pour encadrer la balle----------
	
  s.x += s.dx;
  s.y += s.dy;
  
  if (s.x < 2) s.dx = 0.8;
  if (s.x > N-2) s.dx = -0.8;
  if (s.y < 3) s.dy = 1.4;
  if (s.y > M-2) s.dy = -1.4;
	
	//----------Pour la balle rebondit lorsqu'elle touche le gallet----------
	
  for( int r=L-1; r>=0; r--)    
    if(u[0].y < 2) u[r].y +=1;
      
  for( int r=0; r<L; r++)
    if(u[L-1].y > M-3) u[r].y -=1;
  
}

//----------Le cadre----------

void paysage() {
  for (int i=0; i<N; i++)
    for (int j=0; j<M; j++)
      if (i==0 || i==N-1 || j==0 || j==M-1)
        screen[i][j] = '#';
      else
        screen[i][j] = ' ';
}

void affiche_screen() {
  system("clear");
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++)
      cout << screen[i][j];
    cout << endl;
  }
}

//----------Qu'est ce que c'est??? >.<----------

bool touche_appuyee()  
{
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return (FD_ISSET(0, &fds));
}




