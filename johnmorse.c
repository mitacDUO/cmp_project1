// Morse Potential
// John Koo 583231

#include<stdio.h>
#include<math.h>


// declare functions
double fy(double x, double epsilon);
double simp(double a, double b, double epsilon);
double search(int n);
double falseposition(double a, double b, int n);
double func(double epsilon, int n);

// declare variables
double N= 100; 	// number of loops
double a = .501; //a parameter
double V0 = 4.747;	//V_naught
double rmin = 0.74166;	// rmin
double lama = 33.6567; 	// gamma
void main()
{
int n;
printf("\nPlease wait...\n\n");
printf("a	n	Energy(eV)");
for (n=0; n<=14; n++)
  search(n);			// main function activates root finding by calling onto the search function 
}

double search(int n)	// Search algorithm 
{
  double root, i;
  for (i=-5; i<0; i = i + .01)	// Searches Energy (i) between -5 and 0
	{  
		if (func(i,n)*func(i+1,n)<0)	// When it crosses the axis 2 values multiplied together will give a negative result
		{
			root = falseposition(i, i+1,n);	// Sends 2 values to the False position loop and returns with the roots
		}
	}
		printf("\n%.3f	%d	%f",a ,n , root);	// prints energies
	
}

double falseposition(double a, double b, int n)
{
  double val, i, tolerance = 0.0000000001;	
  for (i=0; i<10; i++)
	{
		val = b - (func(b,n)*(b-a))/(func(b,n)-func(a,n));	// False position formula

		if (func(val,n)*func(b,n)<0)	//Set new x-axis value
		{
			a = val;
		}
		else if (func(val,n)*func(a,n)<0)	// sets new y-axis value
		{
			b = val;
		}
		if (fabs(b-a) <= tolerance )	// Stops loop when tolerance reached 
		{
			return val;
		}
		return val;
	}
}

double func(double epsilon, int n) // Sets new integrated function
{
 double val, xin, xout;
	xin = (rmin/a) - log(1.+sqrt(fabs((epsilon/V0) +1.)));
	xout = (rmin/a) - log(1.-sqrt(fabs((epsilon/V0) +1.)));

	val = lama*a*simp(xin,xout,epsilon) - ((n+(1.0/2.0))*M_PI);	// integrates from xin to xout and then -(n+0.5)*pi from the equation

	return val;

}

double simp(double a, double b, double epsilon)	// function that integrates fy using the Simpson rule.
{
  double i, y, sum, integral;
  sum = 0;
  for (i = 0; i<=N; i++)
	{
		y = fy(a+(i/N)*(b-a),epsilon);	// calls the fy function to integrate  
  
		if ( i == 0. || i == N)	// End points	
		{
			sum = sum + y;
		}
		else if ((int)i%2 !=0)	// Odd numbers
		{
			sum = sum + 4*y;
		}
		else 					// Left over (Even numbers) 
		{
			sum = sum + 2*y;
		}
	}
	integral = ((b - a)/(3.0*N))*sum;	//Simpson approx.

	return integral;
}
double fy(double x, double epsilon) // function that needs to be integrated
{
  double y;
  y = (epsilon/V0) - (1. - exp(rmin/a -x))*(1. - exp(rmin/a -x))+1.;
	return sqrt(y);
}