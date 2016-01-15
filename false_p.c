#include <stdio.h>	/*a library to print, input/output files to terminal and interchange from terminal to output*/
#include <math.h>	/*a library to use common math equations*/

#define tol 0.00001	/*the tolerance for the final answer */

// Declare functions
double function(double x), y;

void main()

{
	double p1 = 1;
	double p2 = 7;
	double i;
	
	while(fabs(function(i))>tol)	//false position
	{
		if(function(p1)*function(p2)<=0)	//p1 is a point that returns a positive function, p2 is the opposite
		{
			i = p2-((function(p2)*(p2-p1))/(function(p2)-function(p1)));
		}
		
		else if(function(p1)==0)
		{
			i = p1;
		}
		
		else
		{
			p2 = i;
		}
		
		if(function(i)*function(p2)<=0)
		{
			p1 = i;
		}
		
		else
		{
			p2 = i;
		}
	
	}
	
	printf("\nroot = %f\n\n",i);
}

double function(double x)

{ double y;

	y = x*x-5*x-11;

	return y;
}