//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double inFunction(double x){
    return (0.2 + 25*x - 200*pow(x,2) + 675*pow(x,3) - 900*pow(x,4) + 400*pow(x,5));
}

double riemmanSumRight(int n, double a, double b){
    double width = (b - a) / n;

    double X[n + 1];

    X[0] = a;
    X[n] = b;

    for(int i = 1; i < n; i++){
        X[i] = X[i-1] + width;
    }

    double accum = 0;
    for(int i = 1; i <= n; i++){
        accum = accum + (inFunction(X[i]));
    }

    return (accum * width);

}

double riemmanSumLeft(int n, double a, double b){
    double width = (b - a) / n;

    double X[n + 1];

    X[0] = a;
    X[n] = b;

    for(int i = 1; i < n; i++){
        X[i] = X[i-1] + width;
    }

    double accum = 0;
    for(int i = 0; i < n; i++){
        accum = accum + (inFunction(X[i]));
    }

    return (accum * width);
}

int main(){
    int intervals;
    cout << "How many intervals? ";
    cin >> intervals;

    char side;
    cout << "Is it from left or from right? (r/l) ";
    cin >> side;
    while(side != 'r' && side != 'l'){
        cout << "Please answer with r or l: ";
        cin >> side;
    }

    double a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    if(side == 'r'){
        cout << riemmanSumRight(intervals, a, b);
    }
    else if(side == 'l'){
        cout << riemmanSumLeft(intervals, a, b);
    }

    return 0;
}
