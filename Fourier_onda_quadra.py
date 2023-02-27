import numpy as np
import matplotlib.pyplot as plt

def b_n(n):
    return 4/(np.pi*(2*n+1))

N_points=1000
N=np.array([5,10,20,30,40,50])
L=5

x=np.linspace(-10,10,N_points)

def f(M,x,L):
    s=0
    for n in range (0,M):
        s += b_n(n)*np.sin(2*np.pi*(2*n+1)*x/L)
    return s

def y_f(M):
    y=np.array([])
    for i in range (0,N_points):
        y=np.append(y,f(M,x[i],L))
    return y

fig,ax=plt.subplots(len(N),1,sharex='col')
for j in range(len(N)):
    ax[j].plot(x,y_f(N[j]),color='r')

plt.show()


