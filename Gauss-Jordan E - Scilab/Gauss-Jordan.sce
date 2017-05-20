// Author: Michelle Sagnelli D'urzo

// Create an augmented matrix using two given matrices.
AUGM = [A B]
X = AUGM
VARIABLES = []
ERRORS = []

// Display the complete matrix
disp("Augmented Matrix")
disp(X)

// Applying Gauss-Jordan
X = rref(X);

// Display Gauss-Jordan matrix
disp(X)

// Adding variables solutions to vector
[rX cX] = size(X)
VARIABLES(rX) = X(rX, cX)/X(rX, cX-1)
for i = 1:1:rX
    VARIABLES(i) = X(i,rX+1)
end

// Getting errors
ERRORS(rX) = X(rX, cX)/X(rX, cX-1)
for i = 1:1:rX
    acum = 0
    for j = 1:1:rX
       acum = acum + (A(i,j)* VARIABLES(j));
    end
    ERRORS(i) = (B(i) - acum)/B(i);
end

//Accumulate variable solutions to the equation system
r = ""
for i = 1:1:rX
    r = r +" X" + string(i) + " = " + string(VARIABLES(i)) + " rError = " + string(ERRORS(i)) + ","
end
disp("Equation variable results")
disp(r)
