#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void imprime_polinomio(double A[], int degree){
  for(int i = 0; i <= degree; i++){
    if ( i == degree){
      cout << A[i] << endl;
    }
    else{
      cout << A[i] << "x^" << degree - i << " + ";
    }
  }
}

int main()
{
    int n, m , w , np, contadorConver, k , z, nx, mx;
    float r,s,e,dr,error,newsize,r0,s0,ds;
    cout << "Introduzca el grado del polinomio: " << endl;
    cin >> n;
    n++;
    w = contadorConver = z =0;
    m = n-1;
    float C[n], Mr[n], Ms[n], Mat1[n], Mat2[m], raizReal[n], raizImaginaria[n], Mat[n];
    float raiz;
    for(int i = 0; i <n; i++){
        Mr[i] = Ms[i] = Mat[i] = raizReal[i] = raizImaginaria[i] = 0;
    }
    cout << "Introduzca los coeficientes del polinomio (en orden)";
    for(int i = 0 ; i < n; i++){
        cout << "Introduzca el coeficiente x^"<< -i + (n-1)<<" :" << endl;
        cin>> C[i];
        if(C[0] != 1){
            do{
                cout << "El coeficiente de x^" <<  n - 1 << "debe de ser = 1" << endl;
                cout << "Coeficiente de x^" << n - 1 << ": ";
                cin >> C[0];
            } while(C[0] != 1);
        }
    }
    cout<<"Introduzca el valor inicial de r : "<<endl;
    cin>>r0;
    cout<<"Introduzca el valor inicial de s : "<<endl;
    cin>>s0;
    cout<<"Introduzca el valor del error de convergencia: " <<endl;
    cin>>error;
    cout<<"Introduzca numero maximo de iteraciones : "<<endl;
    cin>>k;
    dr = ds = 1;

  for(int j = 0; j < 2*(n-1) ; j=j+2)    //Se necesita sumarle 2 al contador dado que en cada paso se guardan 2 valores en las raices (j y j+1)
  {
  dr=ds=1;
  np = (n-1)- 2*w; //np es el grado del polinomio a dividir
  nx = n-1 - 2*w;
  mx = nx-1;
    if (np <= 2)
    {
      if(np == 2)
      {
        raiz=(C[1]*C[1])-(4*C[2]);
        if (raiz < 0)
        {
          raiz = abs(raiz);
          raizReal[j]=(-C[1])/2;
          raizReal[j+1]=(-C[1])/2;
          raizImaginaria[j]=sqrt(raiz)/2;
          raizImaginaria[j+1]=-sqrt(raiz)/2;
        }
        else
        {
          raizReal[j]=((-C[1])+(sqrt(raiz)))/2;
          raizReal[j+1]=((-C[1])-(sqrt(raiz)))/2;
          raizImaginaria[j]=0;
          raizImaginaria[j+1]=0;
        }
      }
      else
      {
        raizReal[j]=-C[1];
      }
      break;
    }
  else{
  contadorConver=0;
  r=r0;
  s=s0;
  for (int i = 0; i<= np;i++)
  {
    Mr[i]=Ms[i]=Mat1[i]=Mat2[i]=0;    //regresa a 0 Mr y Ms
  }
  while (abs(dr) > error || abs(ds) > error){
  for (int i = 0; i <= np ; i++)
  {
    Mat1[i]=C[i]+Mr[i]+Ms[i];  //hace la primera division sintetica
    Mr[i+1]=(-r)*(Mat1[i]);
    Ms[i+2]=(-s)*(Mat1[i]);
  }
  for (int i = 0; i<= np;i++)
  {
    Mr[i]=Ms[i]=0;    //regresa a 0 Mr y Ms
  }
  for (int i = 0; i < np; i++)    //segunda division sintetica
  {
    Mat2[i]=-Mat1[i]+Mr[i]+Ms[i];
    Mr[i+1]=(-r)*(Mat2[i]);
    Ms[i+2]=(-s)*(Mat2[i]);
  }
  dr = (((Mat2[mx-1])*(-Mat1[nx-1]))-((-Mat1[nx])*(Mat2[mx-2])))/(((Mat2[mx-1])*(Mat2[mx-1]))-((Mat2[mx]+Mat1[nx-1])*(Mat2[mx-2])));  //cramer
  ds = (((-Mat1[nx])*(Mat2[mx-1]))-((Mat2[mx]+Mat1[nx-1])*(-Mat1[nx-1])))/(((Mat2[mx-1])*(Mat2[mx-1]))-((Mat2[mx]+Mat1[nx-1])*(Mat2[mx-2])));  //cramer
  r = r+dr;
  s = s+ds;
  contadorConver++;
  if (contadorConver > k)
  {
    cout<<"Fallo en la convergencia"<<endl;
    return 1;
  }
  z++;
  }
  raiz = (r*r)-(4*s);
  if (raiz < 0)
        {
          raiz = abs(raiz);
          raizReal[j]=-r/2;
          raizReal[j+1]=-r/2;
          raizImaginaria[j]=sqrt(raiz)/2;
          raizImaginaria[j+1]=-sqrt(raiz)/2;
        }
        else
        {
          raizReal[j]=((-r)+(sqrt(raiz)))/2;
          raizReal[j+1]=((-r)-(sqrt(raiz)))/2;
          raizImaginaria[j]=0;
          raizImaginaria[j+1]=0;
        }
  w++;
  newsize=(n-1)-(2*w);
  for(int i = 0; i<=newsize ; i++)
  {
    C[i]=Mat1[i];
  }
}
}
cout<<"Raices :"<<endl;
  for (int i = 0 ;i < n-1; i ++)
  {
    if (raizImaginaria[i]==0)
    {
      cout<<"X"<<i<<" = "<<raizReal[i]<<endl;
    }
    else
    {
      cout<<"X"<<i<<" = "<<raizReal[i];
      if(raizImaginaria[i]<0)
      {
        cout<<raizImaginaria[i]<<"i"<<endl;
      }
      else
      {
        cout<<"+"<<raizImaginaria[i]<<"i"<<endl;
      }
    }
  }
  return 1;
}
