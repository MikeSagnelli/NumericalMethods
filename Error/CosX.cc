//                     Author: Michelle Sagnelli D'urzo
//program to calculate Cos(x) using series and comparing it to the built in cos function

//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <cmath>

#define ITERACIONES 10

using namespace std;

double factorial(double n){
    double f = 1;
    for(int c = 2; c<=n; c++){
        f=f*c;
    }
    return (f);
}

int main(){
    double x, coseno = 0;
    double e_abs,e_rel;
    cout<<"Dame el ángulo en radianes: ";
    cin >>x;

    int i=0;
    do{
        coseno = coseno + (pow(-1,i)*pow(x,2*i))/factorial(2*i);
        e_abs = cos(x) - coseno;
        e_rel = abs(e_abs/cos(x));
        i++;
    }while(e_rel > 1E-10);

    cout<<"Coseno aproximado: "<<coseno<<endl;
    cout<<"Coseno por función: "<<cos(x)<<endl;
    cout<<"Iteraciones: "<<i<<endl;

    cout<<"Error absoluto: "<<cos(x)-coseno<<endl;
    cout<<"Error relativo: "<<(cos(x)-coseno)/cos(x)<<endl;

    return(0);
}
