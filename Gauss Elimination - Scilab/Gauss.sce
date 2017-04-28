// Author: Michelle Sagnelli D'urzo

// Create an augmented matrix using two given matrices.
AUGM = [A B]
X = AUGM
VARIABLES = []
[rX cX] = size(X)

// Display the complete matrix
disp("Augmented Matrix")
disp(X)

// Gaussian forward elimination
for p = 1:1:rX-1
    pivot = X(p,p);
    for i = p+1: 1: rX
        prim_fila = X(i,p)
        X(i,:) = X(i,:) - (X(p,:)/pivot)*prim_fila
    end
end

// Display the reduced matrix
disp("Reduced Matrix")
disp(X)

//Substition to find solutions to the equation system
VARIABLES(rX) = X(rX, cX)/X(rX, cX-1)
for i = rX-1: -1: 1
    s = X(i, cX)
    for j = rX: -1: i
        s = s - X(i, j)*VARIABLES(j)
    end
    VARIABLES(i) = s/X(i, i)
end

//Accumulate variable solutions to the equation system
r = ""
for i = 1: rX
    r = r +" X" + string(i) + " = " + string(VARIABLES(i)) +","
end
disp("Equation variable results")
disp(r)
