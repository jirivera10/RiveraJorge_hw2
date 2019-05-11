import numpy as np
import matplotlib.pyplot as plt



y = np.genfromtxt("ev_amplitudes.dat")
t = y[:,0]
u1 = y[:,1]
u2 = y[:,2]
u3 = y[:,3]



plt.figure()
plt.subplot(3,1,1)
plt.ylabel(r"$u_1(t)$")
plt.plot(t,u1,c='red')

plt.subplot(3,1,2)
plt.ylabel(r"$u_2(t)$")
plt.plot(t,u2,c='gold')

plt.subplot(3,1,3)
plt.xlabel(r"t")
plt.ylabel(r"$u_3(t)$")
plt.plot(t,u3,c='darkgreen')
plt.show()
