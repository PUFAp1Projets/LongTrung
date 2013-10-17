
                           //-----------CASSEBRIQUE--------------
                           
//----------La bibliothèque----------

#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <termios.h>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

//----------Definis et Présentation des variables----------

#define N 20
#define M 40
#define NBRE_GOUTTE 1

bool touche_appuyee();

char screen[N][M];  

void paysage(); 
void affiche_screen();

typedef struct {
  double x;
  double y;
  double dx;
  double dy;
} Sprite;

void init_sprite(Sprite & s, double x, double y, double dx, double dy);
void mise_a_jour_sprite(Sprite & s, Sprite u[]);

//----------Le corp MAIN()----------

int main () {
  
		//----------Donné au debut:La balle----------
		
  Sprite goutte[NBRE_GOUTTE];
  init_sprite(goutte[0], 5, 5, 0.5, 0.5);
  
  		//----------Donné au debut:Le gallet----------
  		
  Sprite gallet[4];
  init_sprite(gallet[0], 16, 6, 0, 0);
  init_sprite(gallet[1], 16, 7, 0, 0);
  init_sprite(gallet[2], 16, 8, 0, 0);
  init_sprite(gallet[3], 16, 9, 0, 0);

		//----------Controler le gallet avec le clavier----------
		
  for (int t=0; t<1000; t++) 
  {
    system ("stty raw");
    usleep(40 * 1000);
    if (touche_appuyee()) {
      char c = getchar();     
      system ("stty cooked");
      switch (c) {
      
      *******(Tricher)Utiliser pour controler la balle si vous ne pouvez pas gagner ^^~ LOL*******
     
     /* 
     
      case 'a':
        goutte[0].dx = 0.3;
        break;
      case 'b':
        goutte[0].dx = 0.9;
        break;
        
        
    */    
    
    //*******controler: f pour la gauche, g pour la droite*******
        
      case 'f':
	for(int k=3;k>=0;k--)	  
	  gallet[k].y -=1;		
	break;
      case 'g':
	for(int k=0;k<4;k++)	
	  gallet[k].y +=1;            
	break;
      case 13:
	system ("stty cooked");
	exit(0);
      }              
    } 
    system ("stty cooked"); 
    		
    		//----------Les fonctions----------
    
    paysage();
    screen[(int) goutte[0].x][(int) goutte[0].y] = 'O';
    for (int g=0; g<4; g++)
      screen[(int) gallet[g].x][(int) gallet[g].y] = '=';
    
    affiche_screen();
    mise_a_jour_sprite (goutte[0], gallet);
    
    
  }
}

//----------Donner les coordonnés à la balle et au gallet----------

	//*******Pour la balle*******
	
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

	//*******Pour le gallet*******
	
void init_sprite(Sprite u[],
		 double x,
		 double y,
		 double dx,
		 double dy) {
  for(int r=0; r<3; r++)
    {
      u[r].x=x;
      u[r].y=y;
      u[r].dx=dx;
      u[r].dy=dy;
    }
}

//----------(importants)Les conditions----------

void mise_a_jour_sprite(Sprite & s, Sprite u[]) {

		//----------Encadrer la balle----------  
		
  s.x += s.dx;
  s.y += s.dy;
  
  if (s.x < 2) s.dx = 0.8;
  if (s.x > N-2) s.dx = -0.8;
  if (s.y < 3) s.dy = 1.4;
  if (s.y > M-2) s.dy = -1.4;
  
  		//----------Limiter le gallet sur une ligne----------
  
  for( int r=3; r>=0; r--)    
    if(u[0].y < 2) u[r].y +=1;
      
  for( int r=0; r<4; r++)
    if(u[3].y > M-3) u[r].y -=1;

		//----------La balle rebondit lorsqu'elle touche le gallet----------

  if(s.x == u[0].x -1 && (s.y == u[0].y || s.y == u[1].y || s.y == u[2].y || s.y == u[3].y)) s.dx = -0.5;
  
}

//----------Images----------

	//----------Le cadre----------
	
void paysage() {
  for (int i=0; i<N; i++)
    for (int j=0; j<M; j++)
      if (i==0 || i==N-1 || j==0 || j==M-1)
        screen[i][j] = '#';
      else
        screen[i][j] = ' ';
}

	//----------La balle----------
	
void affiche_screen() {
  system("clear");
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++)
      cout << screen[i][j];
    cout << endl;
  }
}

//----------Qu'est-ce que c'est ???----------

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

