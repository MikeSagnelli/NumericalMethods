//                     Author: Michelle Sagnelli D'urzo
//including cmath for math functions and iostream for cout and cin
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

double product(vector<double> &X, int i, int degree, double x){
    double accum = 1;
    for(int j = 0; j <= degree; j++){
        if(j!=i){
            accum = accum * ((x - X[j])/(X[i] - X[j]));
        }
    }

    return accum;
}


double sum(vector<double> &X, vector<double> &Y, int degree, double x){
    double accum = 0;
    for(int i = 0; i <= degree; i++){
        accum = accum + ((product(X, i, degree, x)) * Y[i]);
    }

    return accum;
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

        double xr, yr;
        cout << "Give a value for x: ";
        cin >> xr;

        yr = sum(X, Y, degree, xr);
        cout << yr;
    }

    else{
        cerr << "ERROR - File cannot be opened." << endl;
        return 1;
    }

    return 0;
}

