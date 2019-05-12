import numpy as np
import matplotlib.pyplot as plt

x = np.genfromtxt("amplitud_maxima.dat")
w = x[:,0]
u1m = x[:,1]
u2m = x[:,2]
u3m = x[:,3]

y = np.genfromtxt("ev_amplitudes.dat")
t = y[:,0]
u1 = y[:,1]
u2 = y[:,2]
u3 = y[:,3]

plt.figure()
plt.xlabel("frecuencia")
plt.ylabel("Amplitud maxima")
plt.plot(w,u1m, "-g", label="$u_1$")
plt.plot(w,u2m, "-b", label="$u_2$")
plt.plot(w,u3m, "-r", label="$u_3$")
plt.legend()

plt.figure()
plt.subplot(3,1,1)
plt.ylabel(r"$u_1(t)$")
plt.plot(t,u1,c='gold')

plt.subplot(3,1,2)
plt.ylabel(r"$u_2(t)$")
plt.plot(t,u2,c='darkgreen')

plt.subplot(3,1,3)
plt.xlabel(r"t")
plt.ylabel(r"$u_3(t)$")
plt.plot(t,u3,c="red")
plt.show()

z = np.genfromtxt("friccion.dat")
tBono = z[:,0]
u1Bono= z[:,1]
u2Bono= z[:,2]
u3Bono= z[:,3]

plt.figure()
plt.subplot(3,1,1)
plt.ylabel(r"$u_1(t)$")
plt.plot(tBono,u1Bono,c='gold')

plt.subplot(3,1,2)
plt.ylabel(r"$u_2(t)$")
plt.plot(tBono,u2Bono,c='darkgreen')

plt.subplot(3,1,3)
plt.xlabel(r"tiempo")
plt.ylabel(r"$u_3(t)$")
plt.plot(tBono,u3Bono,c="red")
plt.show()
