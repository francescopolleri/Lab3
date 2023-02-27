import numpy as np
import matplotlib.pyplot as plt

def b_n(n):
    return 4/(np.pi*(2*n+1))

N_points=1000
N=np.array([10,50,100,200])
L=5

x=np.linspace(-10,10,N_points)

def f(M,x,L):
    s=0
    for n in range (0,M):
        s += b_n(n)*np.sin(2*np.pi*(2*n+1)*x/L)
    return s

y0=np.array([])
for i in range(0,N_points):
    y0=np.append(y0,f(N[0],x[i],L))
y1=np.array([])
for i in range(0,N_points):
    y1=np.append(y1,f(N[1],x[i],L))
y2=np.array([])
for i in range(0,N_points):
    y2=np.append(y2,f(N[2],x[i],L))
y3=np.array([])
for i in range(0,N_points):
    y3=np.append(y3,f(N[3],x[i],L))

fig,ax=plt.subplots(len(N),1,sharex='col')
ax[0].plot(x,y0)
ax[1].plot(x,y1)
ax[2].plot(x,y2)
ax[3].plot(x,y3)

plt.show()

