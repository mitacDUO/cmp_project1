#include <stdio.h>	/*a library to print, input/output files to terminal and interchange from terminal to output*/
#include <math.h>	/*a library to use common math equations*/

//define constants
#define tol 0.00001

// Declare functions
double function(double t, double e), f_p(double p1, double p2, int n), find(double e, int n), integral(double a, double b, double e); 

//variables
double N = 100000;

void main()

{
	double i;
	int n;
	double root;
	
	printf("\nn	epsilon\n");
	
	for(i=0; i<14; i=i+1)
	{
		for(n=0; n<4; n++)
		{
		root = f_p(i,i+1,n);
		}
		
	}
}

double f_p(double p1, double p2, int n)
{

	double e = p1;
	
	while(fabs(find(e,n))>tol)	//false position
	{
		if(find(p1,n)*find(p2,n)<0)	//p1 is a point that returns a positive function, p2 is the opposite
		{
			e = p2-((find(p2,n)*(p2-p1))/(find(p2,n)-find(p1,n)));
		}
		
		else if(find(p1,n)==0)
		{
			e = p2;
		}
		
		else
		{  
			return e;
		}
		
		if(find(e,n)*find(p2,n)<0)
		{
			p1 = e;
		}
		
		else
		{
			p2 = e;
		}
	}
	
	printf("%i	%f\n",n,e);
	return e;
}

double find(double e, int n)
{
	double xin = 1.5-0.5*sqrt(fabs(1+e));
	double xout = 1.5+0.5*sqrt(fabs(1+e));
	double z;
	z = integral(xin,xout,e)-(n+0.5)*(M_PI);
	
	return z;
}

//simpson method
double integral(double a, double b, double e)
{
	//the space between steps from a to b is h
	double h = (b-a)/N;
	int i;
	
	// declare arrays
	double sm, y;
	
	y=0;
	
		for(i=0;i<=N;i++)	
		{
				//defining the function at point a
			if(i==N)	//defining the function at point b
			{
				y = y + function(a+i*h,e);
			}
			
			else if(i%2 == 0)	//defining y for even values of N
			{
				y = y + 2*function(a+i*h,e);
			}
			
			else if(i%2 != 0)	//defining y for odd values of N
			{
				y = y + 4*function(a+i*h,e);
			}

		sm = h/3 * y;	//defining the integral Fn
		}
		
	return sm;
}

// input function into the simpson method
double function(double t, double e)
{ double y;

	y = e-4*(t-1.0)*(t-2.0);
	
	if(y<0)
	{
		return 0;
	}
	
	return sqrt(y);
}





