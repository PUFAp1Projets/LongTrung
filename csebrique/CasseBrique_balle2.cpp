
				//----------CASSEBRIQUE----------

//----------Le bibliothèque----------

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>

using namespace std;

void design();

//----------Le corp MAIN----------

int main ()
{

	//----------Les variables et les fontions----------
	
  int N;
  system ("clear");
  cout<<"Combien de tours ?";
  cin>>N;
  design();
  /* usleep(6*22*8000*N); */ // OL: inutile    //merci OL
}


void design()
{system("clear");
  int row=24,column=72,h=1,k=1;
  char c;
  bool a=false,b=false;
  
  	//----------(important)Les conditions pour créer le cadre et encadrer la balle----------
  	
  cout << a << b;
  // OL: la ligne suivante est illisible, il faut l'�crire diff�remment.   //merci OL
  
  for (;;((a==0 && b==0)?(h++, k++):((a==1 && b==0)? (h--,k++): ((a==1 && b==1)?(h--, k--):(h++, k--)))))
	{
	  for (int i=0; i<row; i++)
	    {
	      for (int j=0; j<column; j++)
		{
		  if (i==0 || i==row-1 || j==0 || j==column-1)
		    cout << "$";
		  else if (h==i && k==j)
		    cout << "&"; 
		  else
		    cout << " ";
		}
	      cout << endl;
	    }
	  if (h==row-2)
	    a = true;
	  if (k==column-2)
	    b = true;
	  if (h == 1)
	    a = false;
	  if (k == 1)
	    b = false;
	  usleep (16000);
   
	}
}
