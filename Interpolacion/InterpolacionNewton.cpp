//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

double finite_dif(double xi, double xj, double yi, double yj){
    return ((yi - yj) / (xi - xj));
}

void newton_interpolation(vector<double> &X, vector<double> &Y, int n, double x){
    double T[n-1], B[n-1];

    for(int i = 0; i < n; i++){
        T[i] = Y[i];
    }

    B[0] = T[0];

    cout << "B0 = " << B[0] << endl;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n - i; j++){
            T[j] = finite_dif(X[j+i], X[j], T[j+1], T[j]);
        }
        B[i] = T[0];
        cout << "B" << i << " = " << B[i] << endl;
    }

    double yr = 0;
    double xr = 0;
    for(int i = 0; i < n; i++){
        xr = B[i];
        for(int j = 0; j < i; j++){
            xr *= (x - X[j]);
        }
        yr += xr;
    }

    cout << "f("<< x <<") = " << yr << endl;
}

int main(){
    int nPoints = 0;
    int degree;

    ifstream file_x;
    ifstream file_y;
    file_x.open("x.txt");
    file_y.open("y.txt");

    if (file_x.is_open() & file_y.is_open()) {
        vector<double> X, Y;
        while(!file_x.eof() && !file_y.eof()){
            nPoints = nPoints + 1;
            X.push_back(0);
            file_x >> X[X.size() - 1];
            Y.push_back(0);
            file_y >> Y[Y.size() - 1];
        }
        X.pop_back();
        Y.pop_back();
        file_x.close();
        file_y.close();

        degree = nPoints - 1;

        double x;
        cout << "Give me a value x: ";
        cin >> x;

        newton_interpolation(X, Y, nPoints, x);
    }
    else{
        cerr << "ERROR - File cannot be opened." << endl;
        return 1;
    }

    return 0;
}

