//Calcular el determinante del sistema de ecuaciones
dS = det(A);
//Utilizado para conocer el número de incógnitas a calcular
[rX cX] = size(A);
//Vector de tamaño 10 genérico para almacenar los resultados
incognitas = [0, 0, 0, 0, 0, 0, 0, 0, 0];
//ciclo para abarcar cualquier número de incógnitas
for i = 1:1:rX
    //Creando submatriz para aplicación del método
    X = A;
    //Sustituir columna de incógnita en cuestión por valores independientes
    X(:,i) = B;
    //Calcular el determinante de esta nueva matriz para la incógnita
    dX = det(X);
    //Calcular el valor de la incógnita dividiendo por el determinante del sistema
    incognitas(i) = dX/dS;
end
printf ("Se imprimen los valores de las incognitas de izquierda a derecha en los sistemas de ecuaciones.")
//ciclo utilizado para imprimir los valores de las incognitas
for i = 1:1:rX
    disp (incognitas(i))
end
