//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <cmath>

using namespace std;

double errorAbsoluto (double real, double aprox){
  double error;
  return error = fabs(real - aprox);
}

int main(){
    double x1, x2, y1, y2, x, y;
    //Definici�n de puntos
    cout << "Punto 1 x: "; cin >> x1;
    cout << "Punto 1 y: "; cin >> y1;
    cout << "Punto 2 x: "; cin >> x2;
    cout << "Punto 2 y: "; cin >> y2;
    cout << endl << "x a calcular: "; cin >> x;

    y = y1 + (((y2-y1)*(x-x1))/(x2-x1));

    cout << "y = " << y1 << " + " << y2 - y1 << " * (x - " << x1 << ") / " << x2-x1 << endl;
    cout << "Aproximacion de y: " << y << endl;
    cout << "Error absoluto: " << errorAbsoluto(7.986, y) << endl;

    return 0;
}
