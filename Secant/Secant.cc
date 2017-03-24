//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <cmath>

//defining number of iterations and minimal error possible
#define ITER 100
#define ERROR 1E-5

//namespace std
using namespace std;

//definition of function
double isFunction(double x){
    return (pow(x, 1.0/3));
}

//secant method
double secant(double x0, double x1){
  //4 variables needed
  double xFunction,
         x1Function,
         x2,
         x2Function,
         eAbsoluto;


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

    eAbsoluto = fabs(x2 - x1);

    //check if x2 is a root
    if(eAbsoluto <= ERROR){
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
