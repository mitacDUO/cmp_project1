/*
 *  Author:  A. Phan, 2010
 *    modified from S.Wyithe
 *
 *  This code demonstrates some simple comands,
 *  functions and plotting in pgplot
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cpgplot.h>


// Defined constants
#define N 100  // number of loop iterations

// Declare functions (mean and variance too)
float fy(float x);
float mean(float x[]);
float variance(float x[]);

// Main code
int main()
{
  /**** Count to 10 in integers ****/

  // Declare integer for loop counting
  int i;

  // Loop from 0 to 10, printing at each step
  for(i=0; i<10; i++)
  {
    printf("i= %d\n", i);
  }

  /**** Plot a function y=f(x) ****/


  float aylow[N];  // lower error in y
  float ayhigh[N]; // upper error in y

  // Set minimum and maximum for x
  float xmin = 0.0;
  float xmax = 10.0;
  float ymin = 0;
  float ymax = 0;

  // Assigning ax with N values for x between xmin and xmax
  for(i=0;i<N;i++)
  {
    ax[i] = xmin + (xmax-xmin)*(float)i/(float)(N-1);
  }

  // Fill ay using function fy
  for(i=0;i<N;i++)
  {
    ay[i] = fy(ax[i]);
  }
  
    // Fill aylow and ayhigh using sfloat yvariance = variance(ay);qrt(y) as the error
  for(i=0;i<N;i++)
  {
    aylow[i]  = ay[i] - sqrt(fabs(ay[i]));
    ayhigh[i] = ay[i] + sqrt(fabs(ay[i]));
  }
  
// logic for ymax and ymin
  for(i=0;i<N;i++)
  { 
    if (ymin > aylow[i])
    {
      ymin = aylow[i];  
    }
  }
  
  for(i=0;i<N;i++)
  { if (ymax < ayhigh[i])
    {
      ymax = ayhigh[i];
    }
  }
  
  
  
  // mean
  float yvariance = variance(ay);
  
  /**** Use pgplot to plot this function ****/

  // cpgbeg starts a plotting page, in this case with 2x1 panels
  cpgbeg(0,"?",2,1);

  // sets colour: 1-black, 2-red, 3-green, 4-blue
  cpgsci(1);

  // sets line style 1-solid, 2-dashed, 3-dot-dashed, 4-dotted
  cpgsls(1);

  // sets charachter height, larger number = bigger
  cpgsch(2.);

  // cpgpage() moves to the next panel
  cpgpage();

  // sets the axes limits in the panel
  cpgswin(xmin,xmax,ymin,ymax);

  // draw the axes
  cpgbox("BCNST", 0.0, 0, "BCNST", 0.0, 0);

  // label the bottom axis
  cpgmtxt("B",2.,.5,.5,"x");
  // label the left axis
  cpgmtxt("L",2.5,.5,.5,"f");

  // connect N points in ax and ay with a line
  cpgline(N,ax,ay);

  // cpgpage() moves to the next panel
  cpgpage();

  // sets the axes limits in the panel
  cpgswin(xmin,xmax,ymin,ymax);

  // draw the axes
  cpgbox("BCNST", 0.0, 0, "BCNST", 0.0, 0);

  // label the bottom axis
  cpgmtxt("B",2.,.5,.5,"x");
  // label the left axis
  cpgmtxt("L",2.5,.5,.5,"f");

  // draw N points in ax and ay
  //   17 - filled circles, 16 - filled squares, 13 - filled triangles
  cpgpt(N,ax,ay,17);

  // draw y error bars on the points
  cpgerry(N,ax,aylow,ayhigh,1.0);

  // close all pgplot applications
  cpgend();
  
  // end program
  return 0;
}


// Returns the function y = val
float fy(float x)
{
  float val;

  val = x;

  return val;
}

// mean value display
float mean(float x[])
  { float val;
    val=0;
    int i;
    
    {
    val = val + x[i];
    }
    float avg= val/N;
      printf("\nmean is %f\n",avg);
      return avg;
  }
  
 // variance value display
 float variance(float x[])
 { float val;
	float m = mean (x);
    val=0;
    int i;
     for(i=0;i<N;i++)
     {
      val = val + (x[i] - m)*(x[i] - m);
     }
   float variance = val/N;
     printf("\nvariance = %f\n",variance);
     
 }