//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double inFunction(double x){
    return (sin(x));
}

double trapezoid(int n, double a, double b){
  double width = (b - a) / n;

  double X[n + 1];
  X[0] = a;
  X[n] = b;

  for(int i = 1; i < n; i++){
      X[i] = X[i-1] + width;
  }

  double accum = 0;
  for(int i = 1; i < n; i++){
    accum = accum + (2 * inFunction(X[i]));
  }
  accum = accum + inFunction(a) + inFunction(b);
  accum = accum * (width / 2);

  return accum;
}

int main(){
  int intervals;
  cout << "How many intervals? ";
  cin >> intervals;

  double a, b;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;

  cout << trapezoid(intervals, a, b);

  return 0;
}
