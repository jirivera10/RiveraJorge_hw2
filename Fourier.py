import numpy as np
import matplotlib.pylab as plt
#Lectura de datos
signal1=np.genfromtxt('signal.dat')
tiempo1=signal1[:,0]
signal=signal1[:,1]
signalSuma=np.genfromtxt('signalSuma.dat')
tiempo2=signalSuma[:,0]
Suma=signalSuma[:,1]
#Grafica señal y suma
plt.figure(figsize=(18,6))
plt.subplot(1,2,1)
plt.title("Señal")
plt.ylabel("Signal")
plt.xlabel("Tiempo")
plt.plot(tiempo1,signal,color='darkgreen')
plt.subplot(1,2,2)
plt.title("Suma señales")
plt.ylabel("Signal")
plt.xlabel("Tiempo")
plt.plot(tiempo2,Suma,color='gold')
plt.savefig("signal&Suma.pdf")
plt.close()
#Transformada de Fourier señales
N=len(tiempo1)
fourier1=[]
for h in range(0,N):
    a=0
    for i in range(0,N):
        a+=signal[i]*np.exp(-1j*2*np.pi*i*(h/N))
    fourier1.append(a)    
fourier = np.fft.fft(signal)
n = signal.size
timestep = tiempo1[1]-tiempo1[0]
freq = np.fft.fftfreq(n, d=timestep)
plt.plot(freq,fourier1,color='indigo')
plt.title('Trasformada de Fourier señales')
plt.savefig('Fourier_trans1.pdf')
plt.show()
#Transformada de suma 
N=len(tiempo2)
fourier2=[]
for h in range(0,N):
    b=0
    for i in range(0,N):
        b+=Suma[i]*np.exp(-1j*2*np.pi*i*(h/N))
    fourier2.append(b)    
fourierSuma = np.fft.fft(Suma)
n = Suma.size
timestep = tiempo2[1]-tiempo2[0]
freqSuma = np.fft.fftfreq(n, d=timestep)
plt.plot(freqSuma,fourier2,color='firebrick')
plt.title('Trasformada de Fourier suma señales')
plt.savefig('Fourier_transSuma.pdf')
plt.show()