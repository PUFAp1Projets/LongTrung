
			//----------CASSEBRIQUE----------
			
//----------Le bibliothèque----------			

#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <termios.h>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

//----------Definis et les variables----------

#define N 20
#define NBRE_GOUTTE 1

bool touche_appuyee();

char screen[N][N];

void paysage();
void affiche_screen();

typedef struct {
  double x;
  double y;
  double dx;
  double dy;
} Sprite;

void init_sprite(Sprite & s, double x, double y, double dx, double dy);
void mise_a_jour_sprite(Sprite & s);

//----------Le corp MAIN----------

int main () 
{
	//----------Donnés au debut----------
	
  Sprite goutte[NBRE_GOUTTE];
  init_sprite(goutte[0], 4, 5, 0.5, 0.5);
 	
 	//----------Changer la direction et la vitesse de la balle avec le clavier----------

  for (int t=0; t<1000; t++) 
  {
    system ("stty raw");
    usleep(40 * 1000);
    if (touche_appuyee()) {
      char c = getchar();
      system ("stty cooked");
      switch (c) {
      
      			//*******Le f,g pour le verticale; le t,h pour l'horizontale*******
      			
      case 'f':
        goutte[0].dx = 0.3;
        break;
      case 'g':
        goutte[0].dx = -0.3;
        break;
	case 't': goutte[0].dy = 0.3;
	break;
	case 'h': goutte[0].dy= -0.3;
	break;
      case 13:
        system ("stty cooked");
        exit(0);
      }
    }
    system ("stty cooked");
	
	//----------Les fonctions----------

    paysage();
      screen[(int) goutte[0].x][(int) goutte[0].y] = '@';
      affiche_screen();
     mise_a_jour_sprite(goutte[0]);
  }
}

//----------Donner les coordonnés à la balle----------

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

//----------(important)Les conditions pour encadre la balle----------

void mise_a_jour_sprite(Sprite & s) {
  s.x += s.dx;
s.y += s.dy;
if(s.x < 2) s.dx=0.8;
if(s.x > N-2) s.dx= -0.8;
if(s.y <2) s.dy=1.2;
if(s.y >N-2)s.dy=-1.2;

}

//----------Images----------

	//----------Le cadre----------

void paysage() {
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      if (i==0 || i==N-1 || j==0 || j==N-1)
        screen[i][j] = '&';
      else
        screen[i][j] = ' ';
}

	//----------La balle----------

void affiche_screen() {
  system("clear");
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++)
      cout << screen[i][j];
    cout << endl;
  }
}

//----------Pas nécessaire de comprendre maintenant ^_^----------

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
