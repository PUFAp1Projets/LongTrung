//--------------------PONG-Project--------------------

//----------la bibliotheque----------
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include <string>
using namespace std;

//----------les valeurs constante----------
const int SCREEN_WIDTH = 960;      
const int SCREEN_HEIGHT = 540;
const int SCREEN_BPP = 32;
const int ball_large = 44;     //---largeur du balle---
const int ball_long = 44;      //---longueur du balle---
const int gallet_large = 47;   //---largeur du gallet---
const int gallet_long = 97;    //---longuer du gallet---
const int gallet_vitesse = 20; //---vitesse du gallet---
const int ball_vitesse = 5;    //---vitesse du balle---

//----------les variables SDL----------
SDL_Surface *screen=NULL;
SDL_Surface *background=NULL;
SDL_Surface *image=NULL;
SDL_Surface *image2=NULL;
SDL_Surface *image3=NULL;
SDL_Surface *image4=NULL;
SDL_Surface *image5=NULL;
SDL_Surface *number=NULL;
SDL_Rect src, dest;
SDL_Event event;
Uint32 colorkey;

//----------la structure du balle----------
typedef struct kieu_banh
{
  int x, y;
  int dx, dy;
} banh;
static banh ball;

//----------structures des gallet----------

//-----gallet droite-----
typedef struct kieu_thanh_phai
{
  int x, y;
  int dx, dy;
} thanhphai;
static thanhphai gallet_r;

//-----gallet gauche-----
typedef struct kieu_thanh_trai
{
  int x, y;
  int dx, dy;
} thanhtrai;
static thanhtrai gallet_l;

//----------dessiner background----------
void hien_thi()
{
  src.x = 0;
  src.y = 0;
  src.w = background->w;
  src.h = background->h;
  dest.x = 0;
  dest.y = 0;
  dest.w = background->w;
  dest.h = background->h;
  SDL_BlitSurface(background, &src, screen, &dest); 
}

void chu_point_trai()
{
  colorkey = SDL_MapRGB(image5->format, 255, 255, 255);
  
  SDL_SetColorKey(image5, SDL_SRCCOLORKEY, colorkey);
  src.x = 0;
  src.y = 0;
  src.w = 60;
  src.h = 45;
  dest.x = SCREEN_WIDTH/2 - 30 - 70 - 20;
  dest.y = 10;
  dest.w = 60;
  dest.h = 45;
  SDL_BlitSurface(image5, &src, screen, &dest);
}

void chu_point_phai()
{
  colorkey = SDL_MapRGB(image5->format, 255, 255, 255);
  
  SDL_SetColorKey(image5, SDL_SRCCOLORKEY, colorkey);
  src.x = 0;
  src.y = 0;
  src.w = 60;
  src.h = 45;
  dest.x = SCREEN_WIDTH/2 + 30;
  dest.y = 10;
  dest.w = 60;
  dest.h = 45;
  SDL_BlitSurface(image5, &src, screen, &dest);
}


//----------dessiner le balle----------
void ve_banh()
{
  colorkey = SDL_MapRGB(image2->format, 255, 255, 255);
  
  SDL_SetColorKey(image2, SDL_SRCCOLORKEY, colorkey);
  src.x = 0;
  src.y = 0;
  src.w = ball_large;
  src.h = ball_long;
  dest.x = ball.x;
  dest.y = ball.y;
  dest.w = ball_large;
  dest.h = ball_long;
  SDL_BlitSurface(image2, &src, screen, &dest);
}

//----------dessiner les gallets----------

//-----gallet droite-----
void ve_thanh_phai()
{
  src.x = 0;
  src.y = 0;
  src.w = gallet_large;
  src.h = gallet_long;
  dest.x = gallet_r.x;
  dest.y = gallet_r.y;
  dest.w = gallet_large;
  dest.h = gallet_long;
  SDL_BlitSurface(image, &src, screen, &dest);
}

//-----gallet gauche-----
void ve_thanh_trai()
{
  src.x = 0;
  src.y = 0;
  src.w = gallet_large;
  src.h = gallet_long;
  dest.x = gallet_l.x;
  dest.y = gallet_l.y;
  dest.w = gallet_large;
  dest.h = gallet_long;
  SDL_BlitSurface(image, &src, screen, &dest);
}

void cong_diem_trai()
{
  colorkey = SDL_MapRGB(image4->format, 0, 0, 0);
  
  SDL_SetColorKey(image4, SDL_SRCCOLORKEY, colorkey);
  src.x = 0;
  src.y = 0;
  src.w = 100;
  src.h = 200;
  dest.x = (SCREEN_WIDTH/2 - 100)/2;
  dest.y = (SCREEN_HEIGHT - 200)/2;
  dest.w = 100;
  dest.h = 200;
  SDL_BlitSurface(image4, &src, screen, &dest);
}

void cong_diem_phai()
{
  colorkey = SDL_MapRGB(image4->format, 0, 0, 0);
  
  SDL_SetColorKey(image4, SDL_SRCCOLORKEY, colorkey);
  src.x = 0;
  src.y = 0;
  src.w = 100;
  src.h = 200;
  dest.x = (SCREEN_WIDTH/2 - 100)/2 + SCREEN_WIDTH/2;
  dest.y = (SCREEN_HEIGHT - 200)/2;
  dest.w = 100;
  dest.h = 200;
  SDL_BlitSurface(image4, &src, screen, &dest);
}

void so_diem(int &diem_trai, int &diem_phai)
{
  colorkey = SDL_MapRGB(number->format, 255, 255, 255);
  
  SDL_SetColorKey(number, SDL_SRCCOLORKEY, colorkey);
  for (int i=0; i<=10; i++)
    if(diem_phai == i)
      src.x = 40*i;
  src.y = 0;
  src.w = 40;
  src.h = 40;
  dest.x = SCREEN_WIDTH/2 - 50;
  dest.y = 10;
  dest.w = 40;
  dest.h = 40;
  
   SDL_BlitSurface(number, &src, screen, &dest);
   //colorkey = SDL_MapRGB(image4->format, 255, 255, 255);
   
   //SDL_SetColorKey(image4, SDL_SRCCOLORKEY, colorkey);
   for (int i=0; i<=10; i++)
     if(diem_trai == i)
       src.x = 40*i;
   src.y = 0;
   src.w = 40;
   src.h = 40;
   dest.x = SCREEN_WIDTH/2 + 100;
   dest.y = 10;
   dest.w = 40;
   dest.h = 40;
   SDL_BlitSurface(number, &src, screen, &dest);
}

void win(int hienwin) 
{
colorkey = SDL_MapRGB(image3->format, 0, 0, 0);
  
  SDL_SetColorKey(image3, SDL_SRCCOLORKEY, colorkey);
  src.x = 20;
  src.y = 30;
  src.w = 100;
  src.h = 50;
  dest.x = hienwin;
  dest.y = 120;
  dest.w = 100;
  dest.h = 50;   
  SDL_BlitSurface(image3, &src, screen, &dest);
}

void lose(int hienlose)
{
  colorkey = SDL_MapRGB(image3->format, 0, 0, 0);
  
  SDL_SetColorKey(image3, SDL_SRCCOLORKEY, colorkey);
  src.x = 130;
  src.y = 30;
  src.w = 130;
  src.h = 50;
  dest.x = hienlose;
  dest.y = 120;
  dest.w = 100;
  dest.h = 50;
  SDL_BlitSurface(image3, &src, screen, &dest);
  
}


//----------mouvement du balle----------
void banh_chay(int &diem_trai, int &diem_phai)
{
  ball.x += ball.dx;
  ball.y += ball.dy;
  
  if (ball.x < 1 || ball.x > (screen->w - 1 - ball_large))
    ball.dx = -ball.dx;
  

  /* -------------------------------------------
    |  si joueur ne peut pas recevoir le balle, |
    |  le balle va tomber et joueur a perdu. Le |
    |   balle revient au milieu de l'ecran et   |
    |  jeux va continuer.                       |
     -------------------------------------------  */
  if (ball.x < 1 )
   {
     ball.x = SCREEN_WIDTH/2;
     ball.y = SCREEN_HEIGHT/2;
     cong_diem_phai();
     ve_thanh_trai();
     ve_thanh_phai();
     SDL_Flip(screen);
     SDL_Delay(2000);
     diem_trai++;
   }
  if (ball.x > (screen->w - 1 - ball_large))
    {
      ball.x = SCREEN_WIDTH/2;
      ball.y = SCREEN_HEIGHT/2;
      cong_diem_trai();
      ve_thanh_trai();
      ve_thanh_phai();
      SDL_Flip(screen);
      SDL_Delay(2000);
      diem_phai++;
    }
  
  //----------le balle rebondit lorsqu'il touche le cadre----------
  if (ball.y < 1 || ball.y > (screen->h - 1 - ball_long))
    ball.dy = -ball.dy;
  
  //----------le balle rebondit lorsqu'il touche le gallet----------
  if ((ball.x <= gallet_l.x + gallet_large) &&
      (ball.y > gallet_l.y - ball_long/2) && 
      (ball.y < gallet_l.y + gallet_long - ball_long/2)) 
    ball.dx = -ball.dx;
  if ((ball.x + ball_large >= gallet_r.x) &&
      (ball.y > gallet_r.y - ball_long/2) &&
      (ball.y < gallet_r.y + gallet_long - ball_long/2))
    ball.dx = -ball.dx;
}

//----------limiter le mouvement des gallet----------
void gioi_han_thanh()
{
  if (gallet_l.y < 0)
    gallet_l.y += gallet_vitesse;
  if (gallet_l.y + gallet_long > screen->h)
    gallet_l.y -= gallet_vitesse;
  if (gallet_r.y < 0)
    gallet_r.y += gallet_vitesse;
  if (gallet_r.y + gallet_long > screen->h)
    gallet_r.y -= gallet_vitesse;
}

/*void chien_thang()
{
  src.x = 0;
  src.y = 0;
  src.w = 200;
  src.h = 100;
  dest.x = 150;
  dest.y = 150;
  dest.w = 200;
  dest.h = 100;
  SDL_BlitSurface(image3, &src, screen, &dest);
  }*/

void tinh_diem(int &diem_trai, int &diem_phai)
{
  if (ball.x < 1)
    diem_trai += 1;
  if (ball.x > (screen->w - 1 - ball_long))
    diem_phai += 1;
  
}

//----------former images----------
SDL_Surface *xulyhinh (string filename)
{
  SDL_Surface* hinh = NULL;
  SDL_Surface* ep_hinh = NULL;
  hinh = SDL_LoadBMP( filename.c_str() );
  if( hinh != NULL )
    {
      ep_hinh = SDL_DisplayFormat( hinh );
      SDL_FreeSurface( hinh);
    }
  return ep_hinh;
}

//----------telecharger images apres former----------
bool nhan_hinh()
{
  background = xulyhinh( "mission.bmp" );
  image = xulyhinh("barre.bmp");
  image2 = xulyhinh("modifie.bmp");
  image3 = xulyhinh("win-lose.bmp");
  image4 = xulyhinh("plus1.bmp");
  image5 = xulyhinh("point.bmp");
  number = xulyhinh("0_9.bmp");
  if( background == NULL )
    return false;
  if( image == NULL )
    return false;
  if( image2 == NULL )
    return false;
  if( image3 == NULL )
    return false;
  if( image4 == NULL )
    return false;
  if( image5 == NULL )
    return false;
  if( number == NULL )
    return false;
  
  return true;
}

//----------revision les conditons SDL----------
bool kiemtra()
{
  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
      return false;
    }
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  
  if( screen == NULL )
    {
      return false;
    }
  SDL_WM_SetCaption( "Bai Pong cua Long", NULL );
  
  return true;
}

//----------effacer quand le jeux finit----------
void dondep()
{
  SDL_FreeSurface( image );
  SDL_FreeSurface( image2 );
  SDL_FreeSurface( image3 );
  SDL_FreeSurface( image4 );
  SDL_FreeSurface( image5 );
  SDL_FreeSurface( number );
  SDL_FreeSurface( background );
  SDL_Quit();
}

//----------le corp main----------
int main() {
  bool thoat =false;
  if (kiemtra() == false)
    return 1;
  if( nhan_hinh() == false )
    return 1;
  int i=0;
  int diem_trai, diem_phai;
  diem_trai = 0;
  diem_phai = 0;
  int hienwin;
  int hienlose;

  //----------valeurs initiales du balle et des gallets----------
  ball.dx = ball_vitesse; ball.dy = ball_vitesse;
  
  ball.x = SCREEN_WIDTH/2;      // le balle est au milieu quand
  ball.y = SCREEN_HEIGHT/2;     // le jeux commence
  
  //-----position des gallets-----
  gallet_r.x = SCREEN_WIDTH - 15 - gallet_large; 
  gallet_r.y = SCREEN_HEIGHT/2 - gallet_long/2;
  gallet_l.x = 15; 
  gallet_l.y = SCREEN_HEIGHT/2 - gallet_long/2; 
  //gallet_r.dx = 5;
  //gallet_l.dx = 5;
  gallet_r.dy = gallet_vitesse;
  gallet_l.dy = gallet_vitesse;
  
  /*demander SDL a updater sur l'ecran */
  SDL_UpdateRect(screen, 0, 0, 0, 0);
  
  while (thoat == false)
    {
      hien_thi();
      chu_point_trai();
      chu_point_phai();
      so_diem(diem_trai, diem_phai);
      banh_chay(diem_trai, diem_phai);
      gioi_han_thanh();
      ve_banh();
      ve_thanh_phai();
      ve_thanh_trai();
      SDL_Delay(50);
      if (diem_trai == 10)
	{
	  hienwin = 650;
	  hienlose = 200;
	  win(hienwin);
	  lose(hienlose);
	  SDL_Flip (screen);
	  SDL_Delay(5000);
	  diem_trai = 0;
	  diem_phai = 0;
	  thoat = true;
	}
      if (diem_phai == 10)
	{
	  hienwin = 200;
	  hienlose = 650;
	  win(hienwin);
	  lose(hienlose);
	  SDL_Flip (screen);
	  SDL_Delay(5000);
	  diem_trai = 0;
	  diem_phai = 0;
	  thoat = true;
	}


      //SDL_UpdateRect(screen, 0, 0, 0, 0);
      
      //----------controle le gallet----------
      while (SDL_PollEvent(&event) != 0) {
	SDL_keysym nut;
	switch (event.type) {
	case SDL_KEYDOWN:
	  nut = event.key.keysym;
	  
	  //----------gallet gauche----------
	  if (nut.sym == SDLK_a) 
	    gallet_l.y += gallet_l.dy;//-----key a: en bas-----
	  if (nut.sym == SDLK_q)
	    gallet_l.y -= gallet_l.dy;//-----key q: en haut-----
	  
	  //----------gallet droite----------
	  if (nut.sym == SDLK_l)
	    gallet_r.y += gallet_r.dy;//-----key l: en bas-----
	  if (nut.sym == SDLK_p)
	    gallet_r.y -= gallet_r.dy;//-----key p: en haut-----
	  break;
       	  
	  //----------quitter du jeux----------
	case SDL_QUIT:
	  thoat = true;
	}
      }
      if( SDL_Flip( screen ) == -1 )
	{
	  return 1;
	}
    }    
  dondep();
  return 0;
  
}

