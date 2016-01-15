#include <stdio.h>	/*a library to print, input/output files to terminal and interchange from terminal to output*/
#include <math.h>	/*a library to use common math equations*/


// Declare functions
double function(double x);	//this will be used to define the desired function inputed
double h;	//the space between steps from points of integration
double Fns;	//simpson function
double Fnt;	//trapazoid function
double y;	//y or function(x)
double ans;	//anilytical answer
double e_t;	//error in trapazoid_method
double e_s;	//error in simpson_method

void main()	//main code

{
	printf("\nN		trapezoid_method	simpson_method		answer		error_trap.		error_sim.\n");	//display integration = Fn
	
	double N = 1;	//let N to begin with be = 10
	double n;
	
	while(N<=1000000)
	{
		ans = (M_PI*M_PI)/12.0;	//what the analytical answer is
		
// declare points to integrate over (a,b)
		int a = 0;
		int b = 1;
	
		//the space between steps from a to b is h
		double h = (b-a)/N;
		int i;
	
		// declare arrays of N real numbers
		double Fn, y;
		y=0;
	
		//trapozoid method
		for(i=0;i<=N;i++)	//defining what ax is equal to
		{
		
			if(i==a)	//because ax[i] function is undefined numerically at 0, but in fact equals to 1 
			{
			y = 1;
			}   
			else if(i==N)	// otherwise ax[i] is defined to be below
			{
				y = y + function(i/N);
			}
			else if(i<N)
			{
				y = y + 2*function(i/N);
			}
		
			Fnt = h/2 * y;
			
			e_t = fabs(Fnt-ans);	//the error for the trapazoid_method
		}
	
		//simpson method
		for(i=0;i<=N;i++)	
		{
		
			if(i==a)	//defining the function at point a
			{
			y = 1;
			}		   
			else if(i==N)	//defining the function at point b
			{
				y = y + function(i/N);
			}
			else if(i%2 == 0)	//defining y for even values of N
			{
				y = y + 2*function(i/N);
			}
			else if(i%2 != 0)	//defining y for odd values of N
			{
				y = y + 4*function(i/N);
			}

		Fns = h/3 * y;	//defining the integral Fn
		
		e_s = fabs(Fns-ans);	//the error for the simpson_method
		
		}
	
	N=N*10;	//the increase in N for each subsequent loop until 10^6
	
	n=N/10;
	
	printf("%e	%.10f		%.10f		%.10f	%e		%e	\n",n,Fnt,Fns,ans,e_t,e_s);	//the output values for N, trap. method, simp. method, answer and errors
	
	}
}

double function(double x)

{ double y;

	y = log(x+1)/x;

	return y;
}