#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
//Se definen las variables

  double m = 1000.0;
  double k = 2000.0;
  double gamm = 0.0;
  double dt = 0.05;
  //double omega=1.0*poomega((k/m),0.5);
  double Forzado(double omega,double t) {
    return sin(omega*t);
  }
  // Para realizar el ejercicio se deben generar dos ecuaciones diferenciales de primer grado acopladas donde y1 es la primera derivada es decir la vel y y2 es la segunda que contiene los argumentos de cuando se despeja la segunda derivada
  //Se definen ecuaciones para el cuerpo 1
  double y1(double vel){
    return vel;
  }
  double y2_1(double t, double u1, double u2,double v1, double omega){
    double y2a=(-gamm*v1-2*k*u1+k*u2+Forzado(omega,t))*(1/m);
    return y2a;
  }

  double y2_2(double u1, double u2, double u3,double v2){
    double y2b=(1/m)*(-gamm*v2+k*u1-2*k*u2+k*u3);
    return y2b;
  }

  double y2_3(double u2,double u3,double v3){
    double y2c=(1/m)*(-gamm*v3+k*u2-k*u3);
    return y2c;
  }
  // Debido a que se quiere que los cambios de los parametros realizados en la función se conserven hasta hacer el return se deben llamar como referencia y no como valor por eso se tiene & antes de los parametros, lo aprendí de http://c.conclase.net/curso/?cap=015
  //Los parametros que varian con el tiempo son llamados como referencia, los demas son llamados como valorn intente hacer velocidades y posicion con arreglos y no pude :(
  void matrizK_runge_kutta4( double t, double &u1, double &u2, double &u3, double &v1, double &v2, double &v3, double omega ){
//Se crea matriz con los k en las filas de ambas y1 y y2
  	double matrizK[4][6];

  	matrizK[0][0] = y1(v1);
  	matrizK[0][1] = y1(v2);
  	matrizK[0][2] = y1(v3);
  	matrizK[0][3] = y2_1(t, u1, u2, v1, omega);
  	matrizK[0][4] = y2_2(u1, u2, u3, v2);
  	matrizK[0][5] = y2_3(u2, u3, v3);

  	matrizK[1][0] = y1(v1+0.5*matrizK[0][3]*dt);
  	matrizK[1][1] = y1(v2+0.5*matrizK[0][4]*dt);
  	matrizK[1][2] = y1(v3+0.5*matrizK[0][5]*dt);
  	matrizK[1][3] = y2_1(t+0.5*dt,u1+0.5*matrizK[0][0]*dt, u2+0.5*matrizK[0][1]*dt, v1+0.5*matrizK[0][3]*dt, omega );
  	matrizK[1][4] = y2_2(u1+0.5*matrizK[0][0]*dt, u2+0.5*matrizK[0][1]*dt, u3+0.5*matrizK[0][2]*dt, v2+0.5*matrizK[0][4]*dt);
  	matrizK[1][5] = y2_3(u2+0.5*matrizK[0][1]*dt, u3+0.5*matrizK[0][2]*dt, v3+0.5*matrizK[0][5]*dt);

  	matrizK[2][0] = y1(v1+0.5*matrizK[1][3]*dt);
  	matrizK[2][1] = y1(v2+0.5*matrizK[1][4]*dt);
  	matrizK[2][2] = y1(v3+0.5*matrizK[1][5]*dt);
  	matrizK[2][3] = y2_1(t+0.5*dt, u1+0.5*matrizK[1][0]*dt, u2+0.5*matrizK[1][1]*dt, v1+0.5*matrizK[1][3]*dt, omega );
  	matrizK[2][4] = y2_2(u1+0.5*matrizK[1][0]*dt, u2+0.5*matrizK[1][1]*dt, u3+0.5*matrizK[1][2]*dt, v2+0.5*matrizK[1][4]*dt);
  	matrizK[2][5] = y2_3(u2+0.5*matrizK[1][1]*dt, u3+0.5*matrizK[1][2]*dt, v3+0.5*matrizK[1][5]*dt);

  	matrizK[3][0] = y1(v1+matrizK[2][3]*dt);
  	matrizK[3][1] = y1(v2+matrizK[2][4]*dt);
  	matrizK[3][2] = y1(v3+matrizK[2][5]*dt);
  	matrizK[3][3] = y2_1(t+dt, u1+matrizK[2][0]*dt, u2+matrizK[2][1]*dt, v1+matrizK[2][3]*dt, omega );
  	matrizK[3][4] = y2_2(u1+matrizK[2][0]*dt, u2+matrizK[2][1]*dt, u3+matrizK[2][2]*dt, v2+matrizK[2][4]*dt);
  	matrizK[3][5] = y2_3(u2+matrizK[2][1]*dt, u3+matrizK[2][2]*dt, v3+matrizK[2][5]*dt);
   //Se obtiene el y+1 con runge-kutta de cuarto orden
  	u1 += ( matrizK[0][0] + 2*(matrizK[1][0] + 2*matrizK[2][0]) + matrizK[3][0] )*(1/6.0)*dt;
  	u2 += ( matrizK[0][1] + 2*(matrizK[1][1] + 2*matrizK[2][1]) + matrizK[3][1] )*(1/6.0)*dt;
  	u3 += ( matrizK[0][2] + 2*(matrizK[1][2] + 2*matrizK[2][2]) + matrizK[3][2] )*(1/6.0)*dt;
  	v1 += ( matrizK[0][3] + 2*(matrizK[1][3] + 2*matrizK[2][3]) + matrizK[3][3] )*(1/6.0)*dt;
  	v2 += ( matrizK[0][4] + 2*(matrizK[1][4] + 2*matrizK[2][4]) + matrizK[3][4] )*(1/6.0)*dt;
  	v3 += ( matrizK[0][5] + 2*(matrizK[1][5] + 2*matrizK[2][5]) + matrizK[3][5] )*(1/6.0)*dt;
  }
int main( ){
  //Se abre el archivo donde van a ser guardados los datos
  ofstream datos1;
  datos1.open("ev_amplitudes.dat");
  //Se crean condiciones iniciales para los tres cuerpos y omega
  double omega = sqrt(k/m);
  double u1 = 0.0;
  double u2 = 0.0;
  double u3 = 0.0;
  double v1 = 0.0;
  double v2 = 0.0;
  double v3 = 0.0;
  // Se genera un ciclo que corre el tiempo un dt que llamaa runge-kutta para solucionar las ecuaciones diferenciales
  for( double t = 0.0; t < 100; t += dt ){
    matrizK_runge_kutta4( t, u1, u2, u3, v1, v2, v3, omega );
    datos1 << t << " " << u1 << " " << u2 << " " << u3 << " " << v1 << " " << v2 << " " << v3 << endl;
  }
  datos1.close();
  //Se generan 100 distintos valores frecuencias para variar entre 0.2 y 3.0
  ofstream datos2;
	datos2.open("amplitud_maxima.dat");

	double wmin = 0.2*sqrt(k/m);
	double wmax = 3.0*sqrt(k/m);
	double dw = ( wmax - wmin )/99.0;
  for( double W = wmin; W < wmax; W += dw ){
		u1 = 0.0;
		u2 = 0.0;
		u3 = 0.0;
		v1 = 0.0;
		v2 = 0.0;
		v3 = 0.0;
    //Se crea un vectores
    vector<double> U1, U2, U3;
    // se guardan las amplitudes con una funcion similar al append de pyhton
		for( double t = 0.0; t < 300; t += dt ){
			matrizK_runge_kutta4( t, u1, u2, u3, v1, v2, v3, W );
			U1.push_back(u1);
			U2.push_back(u2);
			U3.push_back(u3);
		}
    // se ordenan los elementos de menor a mayor en los vectores
		sort( U1.begin(), U1.end() );
		sort( U2.begin(), U2.end() );
		sort( U3.begin(), U3.end() );
    // Una vez arreglados de menor a mayor el ultimo valor hace referencia a las frecuencias maximas, entonces se toma el ultimo valor de los vectores
		double u1m = U1[U1.size()-1];
		double u2m = U2[U2.size()-1];
		double u3m = U3[U3.size()-1];
		datos2 << W << " " << u1m << " " << u2m << " " << u3m << endl;
  }
  datos2.close();
  // Bono se realiza teniendo en cuenta la friccion que se opone al movimiento
  // Se declara un nuevo gama de 0.4, no se distingue de coeficiente de friccion estatica y dinamica por simplicidad del ejercicio
  ofstream datos3;
  datos3.open("friccion.dat");
  omega = sqrt(k/m);
  u1 = 0.0;
  u2 = 0.0;
  u3 = 0.0;
  v1 = 0.0;
  v2 = 0.0;
  v3 = 0.0;
  for( double t = 0.0; t < 100; t += dt ){
    gamm = 1.4;
    matrizK_runge_kutta4( t, u1, u2, u3, v1, v2, v3, omega);
    datos3 << t << " " << u1 << " " << u2 << " " << u3 << " " << v1 << " " << v2 << " " << v3 << endl;
  }
  datos3.open("friccion.dat");
  return 0;
}
