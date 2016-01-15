#include <stdio.h>	/*a library to print, input/output files to terminal and interchange from terminal to output*/
#include <math.h>	/*a library to use common math equations*/

// Declare functions
double function(double t, double E), f_p(double p1, double p2, int n), find(double E, int n), integral(double a, double b, double E); 

//variables
double N = 1000;
double A = 0.515;
double V0 = 4.747;
double rmin = 0.74166;
double Y = 33.6567;

void main()

{
	double i;
	double root;
	int n;
	
	printf("\nn	E(eV)\n");

	for(n=0; n<15; n++)
	{
		for(i=-5; i<0; i=i+0.1)
		{
			root = f_p(i,i+0.1,n);
		}
	}
}

double f_p(double p1, double p2, int n)
{

	double E = p1;
	double tol = 0.0000001;
	
	while(fabs(find(E,n))>tol)	//false position
	{
		if(find(p1,n)*find(p2,n)<0)	//p1 is a point that returns a positive function, p2 is the opposite
		{
			E = p2-((find(p2,n)*(p2-p1))/(find(p2,n)-find(p1,n)));
		}
		
		else if(find(p1,n)==0)
		{
			E = p2;
		}
		
		else
		{  
			return E;
		}

		if(find(E,n)*find(p2,n)<0)
		{
			p1 = E;
		}
		
		else
		{
			p2 = E;
		}

	}
	
	printf("%i	%f\n",n,E);
	return E;
}

double find(double E, int n)
{
	double xin = (rmin/A)-log(1.0+sqrt(fabs((E/V0)+1.0)));
	double xout = (rmin/A)-log(1.0-sqrt(fabs((E/V0)+1.0)));
	double z;
	
	z = Y*A*integral(xin,xout,E)-((n+0.5)*(M_PI));

	return z;
}

//simpson method
double integral(double a, double b, double E)
{
	//the space between steps from a	
	double h = (b-a)/N;
	int i;
	
	// declare arrays
	double sm, y;
	
	y=0;
	
		for(i=0;i<=N;i++)	
		{
			if(i==N)	//defining the function at point b
			{
				y = y + function(a+i*h,E);
			}
			
			else if(i%2 == 0)	//defining y for even values of N
			{
				y = y + 2*function(a+i*h,E);
			}
			
			else if(i%2 != 0)	//defining y for odd values of N
			{
				y = y + 4*function(a+i*h,E);
			}

		sm = h/3 * y;	//defining the integral Fn
		}
	
	return sm;
}

// input function into the simpson method
double function(double x, double E)
{ 
	double y;
	
	y = (E/V0)-(1.0-exp((rmin/A)-x))*(1.0-exp((rmin/A)-x))+1.0;
	
	if(y<0)
	{
		return 0;
	}
	
	return sqrt(y);
}





