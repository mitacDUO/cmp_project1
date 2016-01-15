#include <stdio.h>	/*a library to print, input/output files to terminal and interchange from terminal to output*/
#include <math.h>	/*a library to use common math equations*/

//define constants
#define tol 0.00001

// Declare functions
double function(double t), f_p(double p1, double p2), find (double x), integral(double a, double b); 

//variables
double N = 100000;

void main()

{
	double i;
	double root;
	
	printf("\nroots for equation 5\n");
	for(i=-3; i<2; i++)
	{
		root = f_p(i,i+1);
	}
}

double f_p(double p1, double p2)
{

	double i = p1;
	
	while(fabs(find(i))>tol)	//false position
	{
		if(find(p1)*find(p2)<0)	//p1 is a point that returns a positive function, p2 is the opposite
		{
			i = p2-((find(p2)*(p2-p1))/(find(p2)-find(p1)));
		}
		
		else if(find(p1)==0)
		{
			i = p2;
		}
		
		else
		{
			return i;
		}
		
		if(find(i)*find(p2)<0)
		{
			p1 = i;
		}
		
		else
		{
			p2 = i;
		}
	}
	
	printf("%f\n", i);
	return i;
}

double find(double x)
{
	double z;
	z = integral(0,x) - x;
	
	return z;
}

//simpson method
double integral(double a, double b)
{
	//the space between steps from a to b is h
	double h = (b-a)/N;
	int i;
	
	// declare arrays
	double sm, y;
	
	y=0;
	
		for(i=0;i<=N;i++)	
		{
			if(i==0)	//defining the function at point a
			{
			y = y;
			}		   
			
			else if(i==N)	//defining the function at point b
			{
				y = y + function(a+i*h);
			}
			
			else if(i%2 == 0)	//defining y for even values of N
			{
				y = y + 2*function(a+i*h);
			}
			
			else if(i%2 != 0)	//defining y for odd values of N
			{
				y = y + 4*function(a+i*h);
			}

		sm = h/3 * y;	//defining the integral Fn
		}
		
	return sm;
}

// input function into the simpson method
double function(double t)
{ double y;

	y = t*t;

	return y;
}





