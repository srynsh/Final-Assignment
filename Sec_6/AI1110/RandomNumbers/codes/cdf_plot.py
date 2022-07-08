#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib.pyplot as plt
import scipy as sp
import math
import mpmath as mp
import functions as fp

#if using termux
# import subprocess
# import shlex
#end if


maxrange=30
maxlim=4.0
x = np.linspace(-maxlim,maxlim,maxrange)#points on the x axis
xx = np.linspace(-maxlim,maxlim,maxrange*5) #more points
simlen = int(1e6) #number of samples
err = [] #declaring probability list
#randvar = np.random.normal(0,1,simlen)
# randvar = np.loadtxt('uni.dat',dtype='double')
# randvar = np.loadtxt('gau.dat',dtype='double')
randvar = np.loadtxt('ray.dat',dtype='double')
for i in range(0,maxrange):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list


vec_unit_cdf = np.vectorize(fp.unit_cdf, otypes=[np.float])
vec_gau_cdf = np.vectorize(fp.gau_cdf, otypes=[np.float])
vec_log_cdf = np.vectorize(fp.log_cdf, otypes=[np.float])
vec_tri_cdf = np.vectorize(fp.tri_cdf, otypes=[np.float])
vec_q_gau_cdf = np.vectorize(fp.q_gau_cdf, otypes=[np.float])
vec_chi_cdf = np.vectorize(fp.chi_cdf, otypes=[np.float])
vec_ray_cdf = np.vectorize(fp.ray_cdf, otypes=[np.float])

a = []

for i in range(1,11):
	a.append(i*0.1)




# plt.plot(np.array(a), np.loadtxt('proberr_graph.dat',dtype='double'),'o') #plotting proberr graph
# plt.plot(xx,vec_q_gau_cdf(xx))
	




plt.plot(x.T, err, 'o')#plotting the CDF
# plt.plot(xx,vec_unit_cdf(xx)) #plotting theoretical unit CDF
# plt.plot(xx,vec_gau_cdf(xx)) #plotting theoretical gaussian CDF
# plt.plot(xx,vec_log_cdf(xx)) #plotting theoretical logarithmic CDF
# plt.plot(xx, vec_tri_cdf(xx))
# plt.plot(xx, vec_chi_cdf(xx))
plt.plot(xx, vec_ray_cdf(xx))
plt.grid() #creating the grid
plt.xlabel('$A$')
plt.ylabel('$P_e$')
plt.legend(["Numerical","Theory"])

#if using termux
# plt.savefig('../figs/uni_cdf.pdf')
# plt.savefig('../figs/uni_cdf.eps')
# subprocess.run(shlex.split("termux-open ../figs/uni_cdf.pdf"))
#if using termux
#plt.savefig('../figs/gauss_cdf.pdf')
#plt.savefig('../figs/gauss_cdf.eps')
#subprocess.run(shlex.split("termux-open ../figs/gauss_cdf.pdf"))
#else
plt.show() #opening the plot window

