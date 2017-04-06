//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin

#include <iostream>
#include <cmath>

//defining number of iterations and minimal error possible
#define ITER 1000
#define ERROR 1E-5

//namespace std
using namespace std;

//definition of function
double isFunction(double x){
    return (cos(3 * x) - x);
}

//definition of derivative
double isDerivative(double x){
    return (-3 * sin(3 * x) - 1);
}

//NewtonRaphson method
double newtonRaphson(double x0){
    //4 variables needed, x1, x0 inFunction, x0 inDerivative, x1 inFunction
    double x1,
           xFunction,
           x1Function,
           eAbsoluto,
           xDerivative;

    //iterator
    int i = 0;

    //repeatable process
    do{
        //Define f(x0)
        xFunction = isFunction(x0);

        //Check if x0 is already a root
        if(abs(xFunction) <= ERROR){
            return x0;
        }

        //Define f'(x0)
        xDerivative = isDerivative(x0);

        //Use formula for x1
        x1 = x0 - (xFunction/xDerivative);
        //Define f(x1)
        x1Function = isFunction(x1);

        eAbsoluto = fabs(x1 - x0);

        //Check if x1 is a root
        if(eAbsoluto <= ERROR){
            return x1;
        }

        //If x1 is not a root, x0 is now the value of x1
        x0 = x1;
        cout << "n of Iterations: " << i << " Approximation: " << x1 << endl;
        i++;
    }while(i < ITER);


}

int main(){
    float x;
    cout << "Introduzca la aproximacion: ";
    cin >> x;
    cout << newtonRaphson(x) << endl;
    return 0;
}
