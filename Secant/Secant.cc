//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <cmath>

//defining number of iterations and minimal error possible
#define ITER 100
//ERROR PARCIAL2
#define ERROR 0.1

//namespace std
using namespace std;

//definition of function
double isFunction(double x){
    return (9 * cos(4*x) * exp(-0.7*x) - 3.5);
}

//secant method
double secant(double x0, double x1){
  //4 variables needed
  double xFunction,
         x1Function,
         x2,
         x2Function,
         ePorcentual;

  //iterator
  int i = 0;

  //repeatable process
  do{
    //define f(x)
    xFunction = isFunction(x0);
    x1Function = isFunction(x1);

    //check if x0 and x1 are roots
    if(abs(xFunction) <= ERROR){
        cout << "n of iterations: " << i << " approximation: ";
        return x0;
    }

    if(abs(x1Function) <= ERROR){
        cout << "n of iterations: " << i << " approximation: ";
        return x1;
    }
    //use formula for x2
    x2 = x1 - ((x1Function * (x0-x1))/(xFunction - x1Function));
    //define f(x2)
    x2Function = isFunction(x2);

    //ERROR PARCIAL2
    ePorcentual = 100 * abs((x2- x1)/x2);

    //check if x2 is a root
    if(ePorcentual < ERROR){
        cout << "n of iterations: " << i << " approximation: ";
        return x2;
    }

    //if x2 is not a root x2 is now x1 and x1 is now x0
    x0 = x1;
    x1 = x2;
    cout << "n of iterations: " << i << " approximation: " << x2 << endl;
    i++;
  }while(i < ITER);
}

int main(){
    float x0, x1;
    cout << "Introduzca el punto x0: ";
    cin >> x0;
    cout << "Introduzca el punto x1: ";
    cin >> x1;
    cout << secant(x0, x1) << endl;
    return 0;
}
