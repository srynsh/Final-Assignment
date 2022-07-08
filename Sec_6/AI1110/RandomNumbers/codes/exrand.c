#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

int  main(void) //main function begins
{
 
//Uniform random numbers
// uniform("uni.dat", 1000000);

// Gaussian random numbers
// gaussian("gau.dat", 1000000);

//Logarithmic random numbers
// logarithmic("log.dat");

//Triangular random numbers
	// triangular("tri.dat", 1000000);

//Maximal Likelihood Random Numbers
//  maxlike("maxlike.dat", 0.5);

//Bernoulli random numbers
// bernoulli("ber.dat", 1000000);

//Chi-Square random numbers
// chi("chi.dat", 1000000);

//Rayleigh random numbers
ray("ray.dat", 1000000);


//Mean of uniform
// printf("mean = %lf\n",mean("gau.dat"));
// printf("variance = %lf",variance("gau.dat"));


//Calculating error probabilities
// printf("P_(e|0) = %lf\n",maxlike_proberr(1));
// printf("P_(e|1) = %lf\n",maxlike_proberr(-1));
// printf("P_e = %lf\n", (maxlike_proberr(1)+maxlike_proberr(-1))/2);

//Array function for graph of error probabilities
// proberr_graph("proberr_graph.dat");


return 0;
}


