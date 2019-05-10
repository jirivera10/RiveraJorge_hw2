#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
//Se definen las variables
  float m, k, gamma, dt;
  m = 1000.0;
  k = 2000.0;
  gamma = 0.0;
  dt = 0.05;
  //float omega=1.0*pow((k/m),0.5);
  float Forzado(float omega,float t) {
    return sin(w*t);
  }
  // Para realizar el ejercicio se deben generar dos ecuaciones diferenciales de primer grado acopladas donde y1 es la primera derivada es decir la vel y y2 es la segunda que contiene los argumentos de cuando se despeja la segunda derivada
  //Se definen ecuaciones para el cuerpo 1
  float y1(double v1){
    return v1;
  }
  float y2_1(float v1, float u1, float u2,float omega, float t){
    double y2a=(-gamma*v1-2*k*u1+k*u2+Forzado(omega,t))*(1/m);
    return y2a;
  }
  //Se definene ecuaciones para el cuerpo 2
  float y1_2(double v2){
    return v2;
  }
  float y2_2(float v2, float u1, float u2,float u3){
    double y2b=(1/m)*(-gamma*v2+k*u1-2*k*u2+k*u3);
    return y2b;
  }
  //Se definen ecuaciones para el cuerpo 1
  float y1_3(double v2){
    return v3;
  }
  float y2_3(float v3,float u2,float u3){
    double y2c=(1/m)*(-gamma*v3+k*u2-k*u3);
    return y2c;
  }
  // Debido a que se quiere que los cambios de los parametros realizados en la función se conserven hasta hacer el return se deben llamar como referencia y no como valor por eso se tiene & antes de los parametros, lo aprendí de http://c.conclase.net/curso/?cap=015
  //Los parametros que varian con el tiempo son llamados como referencia, los demas son llamados como valorn intente hacer velocidades y posicion con arreglos y no pude :(
  void Runge_Kutta_CuartoOrde(float &u1,float &u2,float &u3,float &v1,float &v2,float &v3, double t, double omega){
    //Se crea matriz de los k de runge kutta para las y1 de los tres cuerpos
    double matriz_1[4][3];
    //columna cuerpo 1
    matriz_1[0][0]=y1(v1);
    matriz_1[1][0]=y1(v1)+(dt/2)*matriz_1[0][0];
    matriz_1[2][0]=
    matriz_1[3][0]=
    //columna cuerpo 2
    matriz_1[0][1]=y1_2(v2);
    matriz_1[1][1]=y1_2(v2)+(dt/2)*matriz_1[0][1];
    matriz_1[2][1]=
    matriz_1[3][1]=
    //columna cuerpo 3
    matriz_1[0][2]=y1_3(v3);
    matriz_1[1][2]=y1_3(v3)+(dt/2)*matriz_1[0][2];
    matriz_1[2][2]=
    matriz_1[3][2]=

    //Se crea matriz de los k de runge kutta para las y2 de los tres cuerpos
    double matriz_2[4][3];

    //columna cuerpo 1
    matriz_2[0][0]=y2_1(v1,u1,u2,omega,t);
    matriz_2[1][0]=matriz_2[0][0]+(dt/2)*y2_1(v1,u1,u2,omega,t+(dt/2));
    matriz_2[2][0]=
    matriz_2[3][0]=
    //columna cuerpo 2
    matriz_2[0][1]=y2_2(v2,u1,u2,u3);
    matriz_2[1][1]=matriz_2[0][1]+(dt/2)*matriz_2[0][1];
    matriz_2[2][1]=
    matriz_2[3][1]=
    //columna cuerpo 3
    matriz_2[0][2]=y2_3(v3,u2,u3);
    matriz_2[1][2]=matriz_2[0][2]+(dt/2)*matriz_2[0][2];
    matriz_2[2][2]=
    matriz_2[3][2]=


  }
int main( ){
  //Se abre el archivo donde van a ser guardados los datos
  ofstream datos1;
  datos1.open("ev_amplitudes.dat");
  //Se crean condiciones iniciales para los tres cuerpos y omega
  double w = sqrt(k/m);
  double u1 = 0.0;
  double u2 = 0.0;
  double u3 = 0.0;
  double v1 = 0.0;
  double v2 = 0.0;
  double v3 = 0.0;
  // Se genera un ciclo que corre el tiempo un dt que llamaa runge-kutta para solucionar las ecuaciones diferenciales
  for( double t = 0.0; t < 100; t += dt ){
    paso_runge_kutta4( t, u1, u2, u3, v1, v2, v3, w );
    datos1 << t << " " << u1 << " " << u2 << " " << u3 << " " << v1 << " " << v2 << " " << v3 << endl;
  }
  datos1.close();


  reurn 0;
}
