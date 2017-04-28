//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float x1, x2, y1, y2, x, y;
    //Definición de puntos
    cout << "Punto 1 x: "; cin >> x1;
    cout << "Punto 1 y: "; cin >> y1;
    cout << "Punto 2 x: "; cin >> x2;
    cout << "Punto 2 y: "; cin >> y2;
    cout << endl << "x a calcular: "; cin >> x;

    y = y1 + (((y2-y1)*(x-x1))/(x2-x1));

    cout << "Aproximacion de y: " << y << endl;

    return 0;
}
