#include <stdio.h>	/*a library to print, input/output files to terminal and interchange from terminal to output*/
#include <math.h>	/*a library to use common math equations*/

#define N 1000000 //number of loop iterations	/*define constants*/

// Declare functions (mean and variance too)
double function(float x);
double h;
double Fn;
double y;
double z;

void main()	//main code

{
	// declare points to integrate over (a,b)
	int a = 0;
	int b = 1;
	
	//the space between steps from a to b is h
	double h = (b-a)/(double)N;
	int i;
	
	// declare arrays of N real numbers
	double Fn, y;
	y=0;
	
	//trapozoid method
	for(i=0;i<=N;i++)	//defining what ax is equal to
	{
		
		if(i==0)	//because ax[i] function is undefined numerically at 0, but in fact equals to 1 
		{
			y = 1;
		}		   
		else if(i==N)	// otherwise ax[i] is defined to be below
		{
			y = y + function(i/(double)N);
		}
		else if(i<N)
		{
			y = y + 2*function(i/(double)N);
		}
		
		Fn = h/2 * y;
		z = M_PI*M_PI/12;
		
	}
	printf("\nintergration = %.20f\n\n",Fn);	//display integration = Fn
	printf("answer = %.20f\n\n",z);
}

double function(float x)

{ double y;

	y = log(x+1)/x;

	return y;
}