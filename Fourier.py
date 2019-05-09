import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq
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
plt.xlabel(u'Tiempo (s)')
plt.ylabel(u'Fourier')
plt.savefig('Fourier_trans1.pdf')
plt.close()
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
plt.xlabel(u'Tiempo (s)')
plt.ylabel(u'Fourier')
plt.savefig('Fourier_transSuma.pdf')
plt.close()
#Espectograma de las dos señales aprendí a hacer el specgram con https://www.pybonacci.org/2012/09/29/transformada-de-fourier-discreta-en-python-con-scipy/
import numpy as np
import matplotlib.pylab as plt
Pxx, freqs, bins, im = plt.specgram(signal, NFFT=256, Fs=2)
plt.colorbar(im).set_label(u'')
plt.xlabel(u'Tiempo (s)')
plt.ylabel(u'Señales')
plt.savefig('EspectogramaSeñales.pdf')
plt.close()
#Se almacenan los datos del temblor
Sismo=np.genfromtxt('temblor.txt')
seismicSignal=Sismo[:]
plt.plot(seismicSignal,color='tomato')
plt.title('Señal sismica. Rate 100 Hz')
plt.xlabel(u'Tiempo (s)')
plt.ylabel(u'Señal Sismica')
plt.close()
#Transformada de Fourier de la señal sismica con paquetes de scipy
FourierTemblor=np.fft.fft(seismicSignal)
nT=len(seismicSignal)
dtSismo=0.01
frqSismo= np.fft.fftfreq(nT, dtSismo) 
plt.plot(frqSismo,FourierTemblor,color='chocolate')
plt.title('Trasformada de Fourier temblor')
plt.xlabel(u'Tiempo (s)')
plt.ylabel(u'Fourier')
plt.close()
#Espectograma sismo
Pxx, freqs, bins, im = plt.specgram(seismicSignal, NFFT=256, Fs=2)
plt.colorbar(im).set_label(u'')
plt.xlabel(u'Tiempo (s)')
plt.ylabel(u'Señal sismica')
plt.savefig('EspectogramaSismica.pdf')
plt.close()