//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin

#include <iostream>
#include <cmath>

//defining number of iterations and minimal error possible
#define ITER 1000
#define ERROR 1E-3

//namespace std
using namespace std;

//returns true if both numbers share sign
bool sameSign(double x, double y) {
    return (x <= 0 && y <= 0) || (x >= 0 && y >= 0);
}

//definition of function
double isFunction(double x) {
    return (log(pow(x,2) + 1) - exp(x / 2) * cos(3.1416 * x));
}

//bisection method
double bisection(double x0, double x1) {
    double y0 = isFunction(x0); //Evaluating values in function
    double y1 = isFunction(x1);

    double eAbsoluto; //Evaluating absolute error

    if (sameSign(y0, y1)) { //If those evaluations are of the same sign, error
        cout << "Invalid argument" << endl;
        return 0;
    }
    if (y0 == 0) { //It is already a root
        return x0;
    }
    else if (y1 == 0) {
        return x1;
    }

    int i = 0; //local variable for while loop
    double x, y; //for intermediate values
    while (i < ITER) {
        x = (x0 + x1) / 2; //Getting the intermediate value of the interval
        y = isFunction(x);

        eAbsoluto = fabs(y0 - y1);

        if (eAbsoluto <= ERROR) { //Getting a close approximation to 0
              return x;
        }

        if (sameSign(y, y0)) {
              // go left
              x0 = x;
              y0 = y;
        } else {
              // go right
              x1 = x;
              y1 = y;
        }
        cout << "n of Iterations: " << i << " Approximation: "<< x << endl;
        i++;
    }
    return x;
}

int main() {
    float x0, x1;
    cout << "Introduzca x0: ";
    cin >> x0;
    cout << "Introduzca x1: ";
    cin >> x1;
    cout << bisection(x0, x1) << endl;
    //cout << bisection(0, 1) << endl;
    //cout << bisection(0, 3) << endl;
    //cout << bisection(0, 4) << endl;
    return 0;
}
