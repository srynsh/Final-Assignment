import mpmath as mp
import math
import numpy as np


def unit_cdf(x):
	if(x < 0):
		return 0
	elif(x > 1):
		return 1
	else:
		return x

def q_gau_cdf(x):
	return(mp.erfc(x/math.sqrt(2))/2)

def gau_cdf(x):
	return(1-q_gau_cdf(x))

def log_cdf(x):
    if(x < 0):
        return 0
    else:
        return (1 - math.exp(-x/2))

def tri_cdf(x):
	if(x < 0):
		return 0
	elif(x > 0 and x < 1):
		return (x**2)/2
	elif(x > 1 and x < 2):
		return 2*x - (x**2)/2 - 1
	else:
		return 1

def gauss_pdf(x):
	return 1/mp.sqrt(2*np.pi)*np.exp(-x**2/2.0)

def tri_pdf(x):
	if(x < 0):
		return 0
	elif(x > 0 and x < 1):
		return x
	elif(x > 1 and x < 2):
		return 2 - x
	else:
		return 0

def chi_pdf(x):
	if(x < 0):
		return 0
	else:
		return 1/2*math.exp(-x/2)
	
def chi_cdf(x):
	if(x < 0):
		return 0
	else:
		return 1-math.exp(-x/2)

def ray_cdf(x):
	if(x < 0):
		return 0
	else:
		return 1-math.exp(-(x**2)/2)
	
def ray_pdf(x):
	if(x < 0):
		return 0
	else: 
		return x*math.exp(-(x**2)/2)