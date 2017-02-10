//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin

#include <iostream>
#include <cmath>

//defining number of iterations and minimal error possible
#define ITER 10
#define ERROR 1E-15

//namespace std
using namespace std;

//definition of function
double isFunction(double x){
    return (log(x + 1) + 1);
}

//definition of derivative
double isDerivative(double x){
    return (1 / (x + 1));
}

//NewtonRaphson method
double newtonRaphson(double x0){
    //4 variables needed, x1, x0 inFunction, x0 inDerivative, x1 inFunction
    double x1,
           xFunction,
           x1Function,
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

        //Check if x1 is a root
        if(abs(x1Function) <= ERROR){
            return x1;
        }

        //If x1 is not a root, x0 is now the value of x1
        x0 = x1;
        cout << "n of Iterations: " << i << " Approximation: " << x1 << endl;
        i++;
    }while(i < ITER);


}

int main(){
    cout << newtonRaphson(-0.01) << endl;
    return 0;
}
