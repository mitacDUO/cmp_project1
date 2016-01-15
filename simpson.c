#include <stdio.h>	/*a library to print, input/output files to terminal and interchange from terminal to output*/
#include <math.h>	/*a library to use common math equations*/

#define N 1000000 //number of loop iterations	/*define constants*/

// Declare functions 
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
	
	// declare arrays
	double Fn, y, z;
	
	y=0;
	
	//simpson method
	for(i=0;i<=N;i++)	
	{
		
		if(i==a)	//defining the function at point a
		{
			y = 1;
		}		   
		else if(i==N)	//defining the function at point b
		{
			y = y + function(i/(double)N);
		}
		else if(i%2 == 0)	//defining y for even values of N
		{
			y = y + 2*function(i/(double)N);
		}
		else if(i%2 != 0)	//defining y for odd values of N
		{
			y = y + 4*function(i/(double)N);
		}

		
		Fn = h/3 * y;	//defining the integral Fn
		
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