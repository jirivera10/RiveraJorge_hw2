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
  
int main( ){
  reurn 0;
}
